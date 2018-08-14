#ifndef DISABLE_NTRU_ON_WINDOWS_BY_DEFAULT

#include <fcntl.h>
#if defined(_WIN32)
#include <windows.h>
#include <Wincrypt.h>
#else
#include <unistd.h>
#endif

#include <oqs/common.h>
#include <oqs/kex.h>
#include <oqs/kex_ntru.h>
#include <oqs/rand.h>

#define HAVE_BOOL
#include <ntru_crypto.h>

#if defined(_WIN32)
#define strdup _strdup // for strdup deprecation warning
#endif

#define NTRU_PARAMETER_SELECTION NTRU_EES743EP1
#define NTRU_PARAMETER_SELECTION_NAME "EES743EP1"

OQS_KEX *OQS_KEX_ntru_new(OQS_RAND *rand) {
	OQS_KEX *k = malloc(sizeof(OQS_KEX));
	if (k == NULL)
		return NULL;
	k->method_name = strdup("ntru " NTRU_PARAMETER_SELECTION_NAME);
	k->estimated_classical_security = 256; // http://eprint.iacr.org/2015/708.pdf Table 3 N=743 product form search cost
	k->estimated_quantum_security = 128;   // need justification
	k->rand = rand;
	k->params = NULL;
	k->alice_0 = &OQS_KEX_ntru_alice_0;
	k->bob = &OQS_KEX_ntru_bob;
	k->alice_1 = &OQS_KEX_ntru_alice_1;
	k->alice_priv_free = &OQS_KEX_ntru_alice_priv_free;
	k->free = &OQS_KEX_ntru_free; //  IGNORE free-check
	return k;
}

static uint8_t get_entropy_from_dev_urandom(ENTROPY_CMD cmd, uint8_t *out) {
	if (cmd == INIT) {
		return 1;
	}
	if (out == NULL) {
		return 0;
	}
	if (cmd == GET_NUM_BYTES_PER_BYTE_OF_ENTROPY) {
		*out = 1;
		return 1;
	}
	if (cmd == GET_BYTE_OF_ENTROPY) {
		// TODO: why is this called to get entropy bytes one by one?
		if (OQS_RAND_get_system_entropy(out, 1) != OQS_SUCCESS) {
			return 0;
		}
		return 1;
	}
	return 0;
}

typedef struct OQS_KEX_ntru_alice_priv {
	uint16_t priv_key_len;
	uint8_t *priv_key;
} OQS_KEX_ntru_alice_priv;

OQS_STATUS OQS_KEX_ntru_alice_0(UNUSED OQS_KEX *k, void **alice_priv, uint8_t **alice_msg, size_t *alice_msg_len) {

	OQS_STATUS ret = OQS_ERROR;
	uint32_t rc;
	DRBG_HANDLE drbg;
	OQS_KEX_ntru_alice_priv *ntru_alice_priv = NULL;

	*alice_priv = NULL;
	*alice_msg = NULL;

	/* initialize NTRU DRBG */
	rc = ntru_crypto_drbg_instantiate(256, (uint8_t *) "OQS Alice", strlen("OQS Alice"), (ENTROPY_FN) &get_entropy_from_dev_urandom, &drbg);
	if (rc != DRBG_OK)
		return OQS_ERROR;

	/* allocate private key */
	ntru_alice_priv = malloc(sizeof(OQS_KEX_ntru_alice_priv));
	if (ntru_alice_priv == NULL)
		goto err;
	ntru_alice_priv->priv_key = NULL;
	*alice_priv = ntru_alice_priv;

	/* calculate length of public/private keys */
	uint16_t ntru_alice_msg_len;
	rc = ntru_crypto_ntru_encrypt_keygen(drbg, NTRU_PARAMETER_SELECTION, &ntru_alice_msg_len, NULL, &(ntru_alice_priv->priv_key_len), NULL);
	if (rc != NTRU_OK)
		goto err;
	*alice_msg_len = (size_t) ntru_alice_msg_len;

	/* allocate private key bytes */
	ntru_alice_priv->priv_key = malloc(ntru_alice_priv->priv_key_len);
	if (ntru_alice_priv->priv_key == NULL)
		goto err;
	/* allocate public key */
	*alice_msg = malloc(*alice_msg_len);
	if (*alice_msg == NULL)
		goto err;

	/* generate public/private key pair */
	rc = ntru_crypto_ntru_encrypt_keygen(drbg, NTRU_PARAMETER_SELECTION, &ntru_alice_msg_len, *alice_msg, &(ntru_alice_priv->priv_key_len), ntru_alice_priv->priv_key);
	if (rc != NTRU_OK)
		goto err;
	*alice_msg_len = (size_t) ntru_alice_msg_len;

	ret = OQS_SUCCESS;
	goto cleanup;

err:
	ret = OQS_ERROR;
	if (ntru_alice_priv != NULL)
		OQS_MEM_secure_free(ntru_alice_priv->priv_key, ntru_alice_priv->priv_key_len);
	OQS_MEM_insecure_free(ntru_alice_priv);
	*alice_priv = NULL;
	OQS_MEM_insecure_free(*alice_msg);
	*alice_msg = NULL;
cleanup:
	ntru_crypto_drbg_uninstantiate(drbg);

	return ret;
}

OQS_STATUS OQS_KEX_ntru_bob(OQS_KEX *k, const uint8_t *alice_msg, const size_t alice_msg_len, uint8_t **bob_msg, size_t *bob_msg_len, uint8_t **key, size_t *key_len) {

	OQS_STATUS ret;
	uint32_t rc;
	DRBG_HANDLE drbg;

	*bob_msg = NULL;
	*key = NULL;

	/* initialize NTRU DRBG */
	rc = ntru_crypto_drbg_instantiate(256, (uint8_t *) "OQS Bob", strlen("OQS Bob"), (ENTROPY_FN) &get_entropy_from_dev_urandom, &drbg);
	if (rc != DRBG_OK)
		return OQS_ERROR;

	/* generate random session key */
	*key_len = 256 / 8;
	*key = malloc(*key_len);
	if (*key == NULL)
		goto err;
	OQS_RAND_n(k->rand, *key, *key_len);

	/* calculate length of ciphertext */
	uint16_t ntru_bob_msg_len;
	rc = ntru_crypto_ntru_encrypt(drbg, alice_msg_len, alice_msg, *key_len, *key, &ntru_bob_msg_len, NULL);
	if (rc != NTRU_OK)
		goto err;
	*bob_msg_len = (size_t) ntru_bob_msg_len;

	/* allocate ciphertext */
	*bob_msg = malloc(*bob_msg_len);
	if (*bob_msg == NULL)
		goto err;

	/* encrypt session key */
	rc = ntru_crypto_ntru_encrypt(drbg, alice_msg_len, alice_msg, *key_len, *key, &ntru_bob_msg_len, *bob_msg);
	if (rc != NTRU_OK)
		goto err;
	*bob_msg_len = (size_t) ntru_bob_msg_len;

	ret = OQS_SUCCESS;
	goto cleanup;

err:
	ret = OQS_ERROR;
	OQS_MEM_insecure_free(*bob_msg);
	*bob_msg = NULL;
	OQS_MEM_secure_free(*key, *key_len);
	*key = NULL;
cleanup:
	ntru_crypto_drbg_uninstantiate(drbg);

	return ret;
}

OQS_STATUS OQS_KEX_ntru_alice_1(UNUSED OQS_KEX *k, const void *alice_priv, const uint8_t *bob_msg, const size_t bob_msg_len, uint8_t **key, size_t *key_len) {

	OQS_STATUS ret;
	uint32_t rc;

	*key = NULL;

	OQS_KEX_ntru_alice_priv *ntru_alice_priv = (OQS_KEX_ntru_alice_priv *) alice_priv;

	/* calculate session key length */
	uint16_t ntru_key_len;
	rc = ntru_crypto_ntru_decrypt(ntru_alice_priv->priv_key_len, ntru_alice_priv->priv_key, bob_msg_len, bob_msg, &ntru_key_len, NULL);
	if (rc != NTRU_OK)
		goto err;
	*key_len = (size_t) ntru_key_len;

	/* allocate session key */
	*key = malloc(*key_len);
	if (*key == NULL)
		goto err;

	/* decrypt session key */
	rc = ntru_crypto_ntru_decrypt(ntru_alice_priv->priv_key_len, ntru_alice_priv->priv_key, bob_msg_len, bob_msg, &ntru_key_len, *key);
	if (rc != NTRU_OK)
		goto err;
	*key_len = (size_t) ntru_key_len;

	ret = OQS_SUCCESS;
	goto cleanup;

err:
	ret = OQS_ERROR;
	OQS_MEM_secure_free(*key, *key_len);
	*key = NULL;
cleanup:

	return ret;
}

void OQS_KEX_ntru_alice_priv_free(UNUSED OQS_KEX *k, void *alice_priv) {
	if (alice_priv) {
		OQS_KEX_ntru_alice_priv *ntru_alice_priv = (OQS_KEX_ntru_alice_priv *) alice_priv;
		OQS_MEM_secure_free(ntru_alice_priv->priv_key, ntru_alice_priv->priv_key_len);
	}
}

void OQS_KEX_ntru_free(OQS_KEX *k) {
	if (k)
		OQS_MEM_insecure_free(k->method_name);
	OQS_MEM_insecure_free(k);
}

#endif
