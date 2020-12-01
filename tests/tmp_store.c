// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STORE_PREFIX "/tmp/oqs-temp-file-"
#define MAXPATHLEN 64

static OQS_STATUS oqs_fstore(const char *fname, uint8_t *data, size_t len) {
	char fpath[MAXPATHLEN];
	strcpy(fpath, STORE_PREFIX);
	FILE *fp = fopen(strcat(fpath, fname), "wb");
	if (!fp) {
		fprintf(stderr, "Couldn't open %s for writing.\n", fpath);
		return OQS_ERROR;
	}
	fwrite(data, len, 1, fp);
	fclose(fp);
	return OQS_SUCCESS;
}

static OQS_STATUS oqs_fload(const char *fname, uint8_t *data, size_t len) {
	char fpath[MAXPATHLEN];
	strcpy(fpath, STORE_PREFIX);
	FILE *fp = fopen(strcat(fpath, fname), "r");
	if (!fp) {
		fprintf(stderr, "Couldn't open %s for reading.\n", fpath);
		return OQS_ERROR;
	}
	if (fread(data, len, 1, fp) != 1) {
		fprintf(stderr, "Couldn't read all %d bytes correctly (operations called in proper sequence?). Exiting.\n", (int)len);
		return OQS_ERROR;
	}
	fclose(fp);
	return OQS_SUCCESS;
}

