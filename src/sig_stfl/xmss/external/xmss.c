#include <stdint.h>

#include "params.h"
#include "xmss_core.h"
#include "utils.h"
#include "xmss.h"

/* This file provides wrapper functions that take keys that include OIDs to
identify the parameter set to be used. After setting the parameters accordingly
it falls back to the regular XMSS core functions. */

/**
 * The function generates a public-private key pair for the XMSS signature scheme using the specified
 * OID.
 * 
 * @param pk Pointer to the public key buffer where the generated public key will be stored.
 * @param sk sk is a pointer to an unsigned char array that will hold the secret key generated by the
 * XMSS key pair generation function. The secret key is used for signing messages and should be kept
 * confidential.
 * @param oid The `oid` parameter is an identifier for the XMSS variant to be used. It is used to
 * determine the parameters for the XMSS algorithm, such as the tree height and the number of signature
 * iterations. The `oid` value is typically encoded as a 32-bit integer
 * 
 * @return an integer value. If the function executes successfully, it will return 0. If there is an
 * error, it will return -1.
 */
int xmss_keypair(unsigned char *pk, unsigned char *sk, const uint32_t oid)
{
    xmss_params params;
    unsigned int i;

    if (xmss_parse_oid(&params, oid)) {
        return -1;
    }
    for (i = 0; i < XMSS_OID_LEN; i++) {
        pk[XMSS_OID_LEN - i - 1] = (oid >> (8 * i)) & 0xFF;
        /* For an implementation that uses runtime parameters, it is crucial
        that the OID is part of the secret key as well;
        i.e. not just for interoperability, but also for internal use. */
        sk[XMSS_OID_LEN - i - 1] = (oid >> (8 * i)) & 0xFF;
    }
    return xmss_core_keypair(&params, pk + XMSS_OID_LEN, sk + XMSS_OID_LEN);
}

/**
 * This function parses the XMSS OID from a secret key, uses it to determine the XMSS parameters, and
 * then calls the core signing function with those parameters.
 * 
 * @param sk The secret key used for signing the message.
 * @param sm A pointer to the buffer where the signed message will be stored.
 * @param smlen A pointer to a 64-bit unsigned integer that will be used to store the length of the
 * signed message (sm) after signing. The length is in bytes.
 * @param m The message to be signed, represented as an array of unsigned characters.
 * @param mlen The length of the message to be signed, in bytes.
 * 
 * @return an integer value. If the function executes successfully, it will return 0. If there is an
 * error, it will return -1.
 */
int xmss_sign(unsigned char *sk,
              unsigned char *sm, unsigned long long *smlen,
              const unsigned char *m, unsigned long long mlen)
{
    xmss_params params;
    uint32_t oid = 0;
    unsigned int i;

    for (i = 0; i < XMSS_OID_LEN; i++) {
        oid |= sk[XMSS_OID_LEN - i - 1] << (i * 8);
    }
    if (xmss_parse_oid(&params, oid)) {
        return -1;
    }
    return xmss_core_sign(&params, sk + XMSS_OID_LEN, sm, smlen, m, mlen);
}

/**
 * The function xmss_sign_open verifies a signature and retrieves the original message using the XMSS
 * signature scheme.
 * 
 * @param m Pointer to the buffer where the message will be stored after verification.
 * @param mlen A pointer to a 64-bit unsigned integer that will be used to store the length of the
 * message that is recovered during the signature verification process.
 * @param sm The signature to be verified. It is a byte array of length smlen.
 * @param smlen smlen is the length of the signature in bytes.
 * @param pk pk is a pointer to the public key used for verifying the signature.
 * 
 * @return The function `xmss_sign_open` returns an integer value. If the function is successful, it
 * returns 0. If there is an error, it returns -1.
 */
int xmss_sign_open(const unsigned char *m, unsigned long long mlen,
                   const unsigned char *sm, unsigned long long smlen,
                   const unsigned char *pk)
{
    xmss_params params;
    uint32_t oid = 0;
    unsigned int i;

    for (i = 0; i < XMSS_OID_LEN; i++) {
        oid |= pk[XMSS_OID_LEN - i - 1] << (i * 8);
    }
    if (xmss_parse_oid(&params, oid)) {
        return -1;
    }
    return xmss_core_sign_open(&params, m, mlen, sm, smlen, pk + XMSS_OID_LEN);
}

/**
 * The function calculates the remaining number of signatures that can be generated using a given XMSS
 * private key.
 * 
 * @param remain a pointer to a uint64_t variable that will store the number of remaining signatures
 * that can be generated with the given secret key.
 * @param sk The `sk` parameter is a pointer to an array of unsigned characters representing the secret
 * key used in the XMSS signature scheme.
 * 
 * @return This function returns an integer value. If the function executes successfully, it returns 0.
 * If there is an error, it returns -1.
 */
int xmss_remaining_signatures(unsigned long long *remain, const unsigned  char *sk)
{
    xmss_params params;
    uint32_t oid = 0;
    unsigned int i;
    unsigned long long idx, max; 

    for (i = 0; i < XMSS_OID_LEN; i++) {
        oid |= sk[XMSS_OID_LEN - i - 1] << (i * 8);
    }

    if (xmss_parse_oid(&params, oid)) {
        *remain = 0;
        return -1;
    }

    idx = bytes_to_ull(sk + XMSS_OID_LEN, params.index_bytes);
    max = ((1ULL << params.full_height) - 1);

    *remain = max - idx;

    return 0;
}

/**
 * The function calculates the maximum number of signatures that can be generated for a given XMSS private key.
 * 
 * @param max a pointer to an unsigned long long variable that will store the maximum number of
 * signatures that can be generated with the given XMSS private key.
 * @param sk The secret key used for XMSS signature scheme. It is a pointer to an array of unsigned
 * characters.
 * 
 * @return an integer value. If the XMSS OID cannot be parsed, it returns -1. Otherwise, it sets the
 * value of the variable pointed to by the "max" parameter to the maximum number of signatures that can
 * be generated with the given XMSS private key and returns 0.
 */
int xmss_total_signatures(unsigned long long *max, const unsigned  char *sk)
{
    xmss_params params;
    uint32_t oid = 0;

    for (unsigned i = 0; i < XMSS_OID_LEN; i++) {
        oid |= sk[XMSS_OID_LEN - i - 1] << (i * 8);
    }

    if (xmss_parse_oid(&params, oid)) {
        *max = 0;
        return -1;
    }

    *max = ((1ULL << params.full_height) - 1);

    return 0;
}

int xmssmt_keypair(unsigned char *pk, unsigned char *sk, const uint32_t oid)
{
    xmss_params params;
    unsigned int i;

    if (xmssmt_parse_oid(&params, oid)) {
        return -1;
    }
    for (i = 0; i < XMSS_OID_LEN; i++) {
        pk[XMSS_OID_LEN - i - 1] = (oid >> (8 * i)) & 0xFF;
        sk[XMSS_OID_LEN - i - 1] = (oid >> (8 * i)) & 0xFF;
    }
    return xmssmt_core_keypair(&params, pk + XMSS_OID_LEN, sk + XMSS_OID_LEN);
}

int xmssmt_sign(unsigned char *sk,
                unsigned char *sm, unsigned long long *smlen,
                const unsigned char *m, unsigned long long mlen)
{
    xmss_params params;
    uint32_t oid = 0;
    unsigned int i;

    for (i = 0; i < XMSS_OID_LEN; i++) {
        oid |= sk[XMSS_OID_LEN - i - 1] << (i * 8);
    }
    if (xmssmt_parse_oid(&params, oid)) {
        return -1;
    }
    return xmssmt_core_sign(&params, sk + XMSS_OID_LEN, sm, smlen, m, mlen);
}

int xmssmt_sign_open(const unsigned char *m, unsigned long long mlen,
                     const unsigned char *sm, unsigned long long smlen,
                     const unsigned char *pk)
{
    xmss_params params;
    uint32_t oid = 0;
    unsigned int i;

    for (i = 0; i < XMSS_OID_LEN; i++) {
        oid |= pk[XMSS_OID_LEN - i - 1] << (i * 8);
    }
    if (xmssmt_parse_oid(&params, oid)) {
        return -1;
    }
    return xmssmt_core_sign_open(&params, m, mlen, sm, smlen, pk + XMSS_OID_LEN);
}


/**
 * The function calculates the remaining number of signatures that can be generated using a given
 * XMSSMT private key.
 * 
 * @param remain a pointer to an unsigned long long variable that will store the number of remaining
 * signatures that can be generated using the given secret key.
 * @param sk The `sk` parameter is a pointer to an array of unsigned characters representing the secret
 * key used in the XMSSMT signature scheme.
 * 
 * @return This function returns an integer value. If the function executes successfully, it returns 0.
 * If there is an error, it returns -1.
 */
int xmssmt_remaining_signatures(unsigned long long *remain, const unsigned  char *sk)
{
    xmss_params params;
    uint32_t oid = 0;
    unsigned int i;
    unsigned long long idx, max; 

    for (i = 0; i < XMSS_OID_LEN; i++) {
        oid |= sk[XMSS_OID_LEN - i - 1] << (i * 8);
    }

    if (xmssmt_parse_oid(&params, oid)) {
        *remain = 0;
        return -1;
    }

    idx = bytes_to_ull(sk + XMSS_OID_LEN, params.index_bytes);
    max = ((1ULL << params.full_height) - 1);

    *remain = max - idx;

    return 0;
}

/**
 * The function calculates the maximum number of signatures that can be generated for a given XMSSMT private key.
 * 
 * @param max a pointer to an unsigned long long variable that will store the maximum number of
 * signatures that can be generated with the given secret key.
 * @param sk The `sk` parameter is a pointer to an array of unsigned characters representing the secret
 * key used in the XMSS signature scheme.
 * 
 * @return an integer value. If the XMSS OID cannot be parsed, it returns -1. Otherwise, it returns 0.
 */
int xmssmt_total_signatures(unsigned long long *max, const unsigned  char *sk)
{
    xmss_params params;
    uint32_t oid = 0;

    for (unsigned i = 0; i < XMSS_OID_LEN; i++) {
        oid |= sk[XMSS_OID_LEN - i - 1] << (i * 8);
    }

    if (xmss_parse_oid(&params, oid)) {
        *max = 0;
        return -1;
    }

    *max = ((1ULL << params.full_height) - 1);

    return 0;
}
