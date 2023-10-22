// SPDX-License-Identifier: MIT

#include <oqs/oqs.h>
#include <string.h>
#include <stdbool.h>
#include "sig_stfl_xmss.h"

#if defined(__GNUC__) || defined(__clang__)
#define XMSS_UNUSED_ATT __attribute__((unused))
#else
#define XMSS_UNUSED_ATT
#endif

extern inline
OQS_SIG_STFL_SECRET_KEY *OQS_SECRET_KEY_XMSS_new(size_t length_secret_key) {

	// Initialize the secret key in the heap with adequate memory
	OQS_SIG_STFL_SECRET_KEY *sk = malloc(sizeof(OQS_SIG_STFL_SECRET_KEY));
	if (sk == NULL) {
		return NULL;
	}
	memset(sk, 0, sizeof(OQS_SIG_STFL_SECRET_KEY));

	sk->length_secret_key = length_secret_key;

	// Secret serialize/deserialize function
	sk->serialize_key = OQS_SECRET_KEY_XMSS_serialize_key;
	sk->deserialize_key = OQS_SECRET_KEY_XMSS_deserialize_key;

	// Initialize the key with length_secret_key amount of bytes.
	sk->secret_key_data = (uint8_t *)malloc(sk->length_secret_key * sizeof(uint8_t));

	if (sk->secret_key_data == NULL) {
		OQS_MEM_insecure_free(sk);
		return NULL;
	}

	memset(sk->secret_key_data, 0, sk->length_secret_key);

	// Set application specific context
	sk->context = NULL;

	// Point to associated OQS_SIG_STFL object
	sk->sig = NULL;

	// Mutual exclusion struct
	sk->mutex = NULL;

	// Set Secret Key locking function
	sk->lock_key = NULL;

	// Set Secret Key unlocking / releasing function
	sk->unlock_key = NULL;

	// Boolean if the secret key is locked
	sk->is_locked = false;

	// Set Secret Key saving function
	sk->secure_store_scrt_key = NULL;

	// Set Secret Key store callback function
	sk->set_scrt_key_store_cb = OQS_SECRET_KEY_XMSS_set_store_cb;

	// Set Secret Key free function
	sk->free_key = OQS_SECRET_KEY_XMSS_free;

	return sk;
}

/* Serialize XMSS secret key data into a byte string. */
OQS_STATUS OQS_SECRET_KEY_XMSS_serialize_key(OQS_SIG_STFL_SECRET_KEY *sk, size_t *sk_len, uint8_t **sk_buf_ptr) {
	if (sk == NULL || sk_len == NULL || sk_buf_ptr == NULL) {
		return OQS_ERROR;
	}

	/* Lock the key if possible */
	OQS_SECRET_KEY_XMSS_activate_lock(sk);

	uint8_t *sk_buf = malloc(sk->length_secret_key * sizeof(uint8_t));
	if (sk_buf == NULL) {
		return OQS_ERROR;
	}

	// Simply copy byte string of secret_key_data
	memcpy(sk_buf, sk->secret_key_data, sk->length_secret_key);

	*sk_buf_ptr = sk_buf;
	*sk_len = sk->length_secret_key;

	/* Unlock the key if possible */
	OQS_SECRET_KEY_XMSS_activate_unlock(sk);

	return OQS_SUCCESS;
}

/* Deserialize XMSS byte string into an XMSS secret key data. */
OQS_STATUS OQS_SECRET_KEY_XMSS_deserialize_key(OQS_SIG_STFL_SECRET_KEY *sk, const size_t sk_len, const uint8_t *sk_buf, XMSS_UNUSED_ATT void *context) {
	if (sk == NULL || sk_buf == NULL || (sk_len != sk->length_secret_key)) {
		return OQS_ERROR;
	}

	sk->secret_key_data = malloc(sk_len);
	if (sk->secret_key_data == NULL) {
		return OQS_ERROR;
	}

	memcpy(sk->secret_key_data, sk_buf, sk_len);
	sk->context = context;

	return OQS_SUCCESS;
}

void OQS_SECRET_KEY_XMSS_set_store_cb(OQS_SIG_STFL_SECRET_KEY *sk, secure_store_sk store_cb, void *context) {
	if (sk == NULL || store_cb == NULL) {
		return;
	}
	sk->secure_store_scrt_key = store_cb;
	sk->context = context;
}

void OQS_SECRET_KEY_XMSS_free(OQS_SIG_STFL_SECRET_KEY *sk) {
	if (sk == NULL) {
		return;
	}

	OQS_MEM_secure_free(sk->secret_key_data, sk->length_secret_key);
	sk->secret_key_data = NULL;
}

void OQS_SECRET_KEY_XMSS_activate_lock(OQS_SIG_STFL_SECRET_KEY *sk) {
	if (sk == NULL) {
		return;
	}

	if (sk->is_locked == false) {
		/* Lock the key if possible */
		if ((sk->lock_key != NULL) && (sk->mutex != NULL)) {
			sk->lock_key(sk->mutex);
			sk->is_locked = true;
		}
	}
}

void OQS_SECRET_KEY_XMSS_activate_unlock(OQS_SIG_STFL_SECRET_KEY *sk) {
	if (sk == NULL) {
		return;
	}

	if (sk->is_locked == true) {
		/* Unlock the key if possible */
		if ((sk->unlock_key != NULL) && (sk->mutex != NULL)) {
			sk->unlock_key(sk->mutex);
			sk->is_locked = false;
		}
	}
}