#ifndef SP800_185_H
#define SP800_185_H

#include <stddef.h>
#include <stdint.h>

#include "fips202.h"

#define cshake128_inc_init OQS_SHA3_cshake128_inc_init
#define cshake128_inc_absorb OQS_SHA3_cshake128_inc_absorb
#define cshake128_inc_finalize OQS_SHA3_cshake128_inc_finalize
#define cshake128_inc_squeeze OQS_SHA3_cshake128_inc_squeeze
#define cshake128 OQS_SHA3_cshake128

#define cshake256_inc_init OQS_SHA3_cshake256_inc_init
#define cshake256_inc_absorb OQS_SHA3_cshake256_inc_absorb
#define cshake256_inc_finalize OQS_SHA3_cshake256_inc_finalize
#define cshake256_inc_squeeze OQS_SHA3_cshake256_inc_squeeze
#define cshake256 OQS_SHA3_cshake256

#endif
