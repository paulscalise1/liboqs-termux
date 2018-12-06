/* Kyber1024 compilation file for Windows */

#define KYBER_K 4
#define FUNC_PREFIX OQS_KEM_kyber_1024_cca_kem

#include "functions_renaming.h"
#include "ref/cbd.c"
#include "ref/indcpa.c"
#include "ref/kem.c"
#include "ref/ntt.c"
#include "ref/poly.c"
#include "ref/polyvec.c"
#include "ref/precomp.c"
#include "ref/reduce.c"
#include "ref/verify.c"
