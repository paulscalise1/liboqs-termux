#ifndef OQS_PICNIC_MACROS_H
#define OQS_PICNIC_MACROS_H

#include <oqs/common.h>

/* avoid printing debug output */
#ifndef NDEBUG
#define NDEBUG
#endif

/* use OQS's free function */
#define free OQS_MEM_insecure_free

/* add oqs_sig_picnic_ prefix to publicly exposed functions */
#define BitLength oqs_sig_picnic_BitLength
#define BitSequence oqs_sig_picnic_BitSequence
#define HashReturn oqs_sig_picnic_HashReturn
#define KeccakP1600_12rounds_FastLoop_Absorb oqs_sig_picnic_KeccakP1600_12rounds_FastLoop_Absorb
#define KeccakF1600_FastLoop_Absorb oqs_sig_picnic_KeccakF1600_FastLoop_Absorb
#define KeccakP1600_AddByte oqs_sig_picnic_KeccakP1600_AddByte
#define KeccakP1600_AddBytes oqs_sig_picnic_KeccakP1600_AddBytes
#define KeccakP1600_AddBytesInLane oqs_sig_picnic_KeccakP1600_AddBytesInLane
#define KeccakP1600_AddLanes oqs_sig_picnic_KeccakP1600_AddLanes
#define KeccakP1600_ExtractAndAddBytes oqs_sig_picnic_KeccakP1600_ExtractAndAddBytes
#define KeccakP1600_ExtractAndAddBytesInLane oqs_sig_picnic_KeccakP1600_ExtractAndAddBytesInLane
#define KeccakP1600_ExtractAndAddLanes oqs_sig_picnic_KeccakP1600_ExtractAndAddLanes
#define KeccakP1600_ExtractBytes oqs_sig_picnic_KeccakP1600_ExtractBytes
#define KeccakP1600_ExtractBytesInLane oqs_sig_picnic_KeccakP1600_ExtractBytesInLane
#define KeccakP1600_ExtractLanes oqs_sig_picnic_KeccakP1600_ExtractLanes
#define KeccakP1600_Initialize oqs_sig_picnic_KeccakP1600_Initialize
#define KeccakP1600_OverwriteBytes oqs_sig_picnic_KeccakP1600_OverwriteBytes
#define KeccakP1600_OverwriteBytesInLane oqs_sig_picnic_KeccakP1600_OverwriteBytesInLane
#define KeccakP1600_OverwriteLanes oqs_sig_picnic_KeccakP1600_OverwriteLanes
#define KeccakP1600_OverwriteWithZeroes oqs_sig_picnic_KeccakP1600_OverwriteWithZeroes
#define KeccakP1600_Permute_12rounds oqs_sig_picnic_KeccakP1600_Permute_12rounds
#define KeccakP1600_Permute_24rounds oqs_sig_picnic_KeccakP1600_Permute_24rounds
#define KeccakP1600_Permute_Nrounds oqs_sig_picnic_KeccakP1600_Permute_Nrounds
#define KeccakP1600times4_PermuteAll_12rounds oqs_sig_picnic_KeccakP1600times4_PermuteAll_12rounds
#define KeccakP1600times4_PermuteAll_24rounds oqs_sig_picnic_KeccakP1600times4_PermuteAll_24rounds
#define KeccakP1600times4_PermuteAll_4rounds oqs_sig_picnic_KeccakP1600times4_PermuteAll_4rounds
#define KeccakP1600times4_PermuteAll_6rounds oqs_sig_picnic_KeccakP1600times4_PermuteAll_6rounds
#define KeccakWidth1600_Sponge oqs_sig_picnic_KeccakWidth1600_Sponge
#define KeccakWidth1600_SpongeAbsorb oqs_sig_picnic_KeccakWidth1600_SpongeAbsorb
#define KeccakWidth1600_SpongeAbsorbLastFewBits oqs_sig_picnic_KeccakWidth1600_SpongeAbsorbLastFewBits
#define KeccakWidth1600_SpongeInitialize oqs_sig_picnic_KeccakWidth1600_SpongeInitialize
#define KeccakWidth1600_SpongeInstance oqs_sig_picnic_KeccakWidth1600_SpongeInstance
#define KeccakWidth1600_SpongeSqueeze oqs_sig_picnic_KeccakWidth1600_SpongeSqueeze
#define KeccakWidth1600_12rounds_SpongeInstance oqs_sig_picnic_KeccakWidth1600_12rounds_SpongeInstance
#define KeccakWidth1600times4_Sponge oqs_sig_picnic_KeccakWidth1600times4_Sponge
#define KeccakWidth1600times4_SpongeAbsorb oqs_sig_picnic_KeccakWidth1600times4_SpongeAbsorb
#define KeccakWidth1600times4_SpongeAbsorbLastFewBits oqs_sig_picnic_KeccakWidth1600times4_SpongeAbsorbLastFewBits
#define KeccakWidth1600times4_SpongeInitialize oqs_sig_picnic_KeccakWidth1600times4_SpongeInitialize
#define KeccakWidth1600times4_SpongeInstance oqs_sig_picnic_KeccakWidth1600times4_SpongeInstance
#define KeccakWidth1600times4_SpongeSqueeze oqs_sig_picnic_KeccakWidth1600times4_SpongeSqueeze
#define Keccak_HashFinal oqs_sig_picnic_Keccak_HashFinal
#define Keccak_HashInitialize oqs_sig_picnic_Keccak_HashInitialize
#define Keccak_HashInstance oqs_sig_picnic_Keccak_HashInstance
#define Keccak_HashSqueeze oqs_sig_picnic_Keccak_HashSqueeze
#define Keccak_HashUpdate oqs_sig_picnic_Keccak_HashUpdate
#define addMerkleNodes oqs_sig_picnic_addMerkleNodes
#define allocateCommitments oqs_sig_picnic_allocateCommitments
#define allocateCommitments2 oqs_sig_picnic_allocateCommitments2
#define allocateInputs oqs_sig_picnic_allocateInputs
#define allocateMsgs oqs_sig_picnic_allocateMsgs
#define allocateMsgsVerify oqs_sig_picnic_allocateMsgsVerify
#define allocateProof2 oqs_sig_picnic_allocateProof2
#define allocateRandomTape oqs_sig_picnic_allocateRandomTape
#define allocateSignature2 oqs_sig_picnic_allocateSignature2
#define bitstream_get_bits oqs_sig_picnic_bitstream_get_bits
#define bitstream_get_bits_32 oqs_sig_picnic_bitstream_get_bits_32
#define bitstream_get_bits_8 oqs_sig_picnic_bitstream_get_bits_8
#define bitstream_put_bits oqs_sig_picnic_bitstream_put_bits
#define bitstream_put_bits_32 oqs_sig_picnic_bitstream_put_bits_32
#define bitstream_put_bits_8 oqs_sig_picnic_bitstream_put_bits_8
#define buildMerkleTree oqs_sig_picnic_buildMerkleTree
#define cpu_supports oqs_sig_picnic_cpu_supports
#define createTree oqs_sig_picnic_createTree
#define freeCommitments oqs_sig_picnic_freeCommitments
#define freeCommitments2 oqs_sig_picnic_freeCommitments2
#define freeInputs oqs_sig_picnic_freeInputs
#define freeMsgs oqs_sig_picnic_freeMsgs
#define freeProof2 oqs_sig_picnic_freeProof2
#define freeRandomTape oqs_sig_picnic_freeRandomTape
#define freeSignature2 oqs_sig_picnic_freeSignature2
#define freeTree oqs_sig_picnic_freeTree
#define generateSeeds oqs_sig_picnic_generateSeeds
#define getBit oqs_sig_picnic_getBit
#define getLeaf oqs_sig_picnic_getLeaf
#define getLeaves oqs_sig_picnic_getLeaves
#define get_zkbpp_lowmc_implementation oqs_sig_picnic_get_zkbpp_lowmc_implementation
#define get_zkbpp_lowmc_verify_implementation oqs_sig_picnic_get_zkbpp_lowmc_verify_implementation
#define get_zkbpp_share_implentation oqs_sig_picnic_get_zkbpp_share_implentation
#define impl_sign oqs_sig_picnic_impl_sign
#define impl_sign_picnic3 oqs_sig_picnic_impl_sign_picnic3
#define impl_verify oqs_sig_picnic_impl_verify
#define impl_verify_picnic3 oqs_sig_picnic_impl_verify_picnic3
#define instance_get oqs_sig_picnic_instance_get
#define lowmc_compute_aux_get_implementation oqs_sig_picnic_lowmc_compute_aux_get_implementation
#define lowmc_get_implementation oqs_sig_picnic_lowmc_get_implementation
#define lowmc_simulate_online_get_implementation oqs_sig_picnic_lowmc_simulate_online_get_implementation
#define lowmc_store_get_implementation oqs_sig_picnic_lowmc_store_get_implementation
#define mpc_matrix_mul_s128_256 oqs_sig_picnic_mpc_matrix_mul_s128_256
#define mpc_matrix_mul_s256_192 oqs_sig_picnic_mpc_matrix_mul_s256_192
#define mpc_matrix_mul_s256_256 oqs_sig_picnic_mpc_matrix_mul_s256_256
#define mpc_matrix_mul_uint64_192 oqs_sig_picnic_mpc_matrix_mul_uint64_192
#define mpc_matrix_mul_uint64_256 oqs_sig_picnic_mpc_matrix_mul_uint64_256
#define mzd_addmul_v_s128_128 oqs_sig_picnic_mzd_addmul_v_s128_128
#define mzd_addmul_v_s128_129 oqs_sig_picnic_mzd_addmul_v_s128_129
#define mzd_addmul_v_s128_192 oqs_sig_picnic_mzd_addmul_v_s128_192
#define mzd_addmul_v_s128_256 oqs_sig_picnic_mzd_addmul_v_s128_256
#define mzd_addmul_v_s128_30_128 oqs_sig_picnic_mzd_addmul_v_s128_30_128
#define mzd_addmul_v_s128_30_192 oqs_sig_picnic_mzd_addmul_v_s128_30_192
#define mzd_addmul_v_s128_30_256 oqs_sig_picnic_mzd_addmul_v_s128_30_256
#define mzd_addmul_v_s256_128 oqs_sig_picnic_mzd_addmul_v_s256_128
#define mzd_addmul_v_s256_129 oqs_sig_picnic_mzd_addmul_v_s256_129
#define mzd_addmul_v_s256_192 oqs_sig_picnic_mzd_addmul_v_s256_192
#define mzd_addmul_v_s256_256 oqs_sig_picnic_mzd_addmul_v_s256_256
#define mzd_addmul_v_s256_30_128 oqs_sig_picnic_mzd_addmul_v_s256_30_128
#define mzd_addmul_v_s256_30_192 oqs_sig_picnic_mzd_addmul_v_s256_30_192
#define mzd_addmul_v_s256_30_256 oqs_sig_picnic_mzd_addmul_v_s256_30_256
#define mzd_addmul_v_uint64_128 oqs_sig_picnic_mzd_addmul_v_uint64_128
#define mzd_addmul_v_uint64_129 oqs_sig_picnic_mzd_addmul_v_uint64_129
#define mzd_addmul_v_uint64_192 oqs_sig_picnic_mzd_addmul_v_uint64_192
#define mzd_addmul_v_uint64_256 oqs_sig_picnic_mzd_addmul_v_uint64_256
#define mzd_addmul_v_uint64_30_128 oqs_sig_picnic_mzd_addmul_v_uint64_30_128
#define mzd_addmul_v_uint64_30_192 oqs_sig_picnic_mzd_addmul_v_uint64_30_192
#define mzd_addmul_v_uint64_30_256 oqs_sig_picnic_mzd_addmul_v_uint64_30_256
#define mzd_and_s128_128 oqs_sig_picnic_mzd_and_s128_128
#define mzd_and_s128_256 oqs_sig_picnic_mzd_and_s128_256
#define mzd_and_s256_128 oqs_sig_picnic_mzd_and_s256_128
#define mzd_and_s256_256 oqs_sig_picnic_mzd_and_s256_256
#define mzd_and_uint64_128 oqs_sig_picnic_mzd_and_uint64_128
#define mzd_and_uint64_192 oqs_sig_picnic_mzd_and_uint64_192
#define mzd_and_uint64_256 oqs_sig_picnic_mzd_and_uint64_256
#define mzd_copy_s128_128 oqs_sig_picnic_mzd_copy_s128_128
#define mzd_copy_s128_256 oqs_sig_picnic_mzd_copy_s128_256
#define mzd_copy_s256_128 oqs_sig_picnic_mzd_copy_s256_128
#define mzd_copy_s256_256 oqs_sig_picnic_mzd_copy_s256_256
#define mzd_copy_uint64_128 oqs_sig_picnic_mzd_copy_uint64_128
#define mzd_copy_uint64_192 oqs_sig_picnic_mzd_copy_uint64_192
#define mzd_copy_uint64_256 oqs_sig_picnic_mzd_copy_uint64_256
#define mzd_from_bitstream oqs_sig_picnic_mzd_from_bitstream
#define mzd_from_char_array oqs_sig_picnic_mzd_from_char_array
#define mzd_local_free oqs_sig_picnic_mzd_local_free
#define mzd_local_free_multiple oqs_sig_picnic_mzd_local_free_multiple
#define mzd_local_init_ex oqs_sig_picnic_mzd_local_init_ex
#define mzd_local_init_multiple_ex oqs_sig_picnic_mzd_local_init_multiple_ex
#define mzd_mul_v_parity_uint64_128_3 oqs_sig_picnic_mzd_mul_v_parity_uint64_128_3
#define mzd_mul_v_parity_uint64_128_30 oqs_sig_picnic_mzd_mul_v_parity_uint64_128_30
#define mzd_mul_v_parity_uint64_192_3 oqs_sig_picnic_mzd_mul_v_parity_uint64_192_3
#define mzd_mul_v_parity_uint64_192_30 oqs_sig_picnic_mzd_mul_v_parity_uint64_192_30
#define mzd_mul_v_parity_uint64_256_3 oqs_sig_picnic_mzd_mul_v_parity_uint64_256_3
#define mzd_mul_v_parity_uint64_256_30 oqs_sig_picnic_mzd_mul_v_parity_uint64_256_30
#define mzd_mul_v_s128_128 oqs_sig_picnic_mzd_mul_v_s128_128
#define mzd_mul_v_s128_128_640 oqs_sig_picnic_mzd_mul_v_s128_128_640
#define mzd_mul_v_s128_129 oqs_sig_picnic_mzd_mul_v_s128_129
#define mzd_mul_v_s128_192 oqs_sig_picnic_mzd_mul_v_s128_192
#define mzd_mul_v_s128_192_1024 oqs_sig_picnic_mzd_mul_v_s128_192_1024
#define mzd_mul_v_s128_256 oqs_sig_picnic_mzd_mul_v_s128_256
#define mzd_mul_v_s128_256_1280 oqs_sig_picnic_mzd_mul_v_s128_256_1280
#define mzd_mul_v_s256_128 oqs_sig_picnic_mzd_mul_v_s256_128
#define mzd_mul_v_s256_128_768 oqs_sig_picnic_mzd_mul_v_s256_128_768
#define mzd_mul_v_s256_129 oqs_sig_picnic_mzd_mul_v_s256_129
#define mzd_mul_v_s256_192 oqs_sig_picnic_mzd_mul_v_s256_192
#define mzd_mul_v_s256_192_1024 oqs_sig_picnic_mzd_mul_v_s256_192_1024
#define mzd_mul_v_s256_256 oqs_sig_picnic_mzd_mul_v_s256_256
#define mzd_mul_v_s256_256_1280 oqs_sig_picnic_mzd_mul_v_s256_256_1280
#define mzd_mul_v_uint64_128 oqs_sig_picnic_mzd_mul_v_uint64_128
#define mzd_mul_v_uint64_128_640 oqs_sig_picnic_mzd_mul_v_uint64_128_640
#define mzd_mul_v_uint64_129 oqs_sig_picnic_mzd_mul_v_uint64_129
#define mzd_mul_v_uint64_192 oqs_sig_picnic_mzd_mul_v_uint64_192
#define mzd_mul_v_uint64_192_960 oqs_sig_picnic_mzd_mul_v_uint64_192_960
#define mzd_mul_v_uint64_256 oqs_sig_picnic_mzd_mul_v_uint64_256
#define mzd_mul_v_uint64_256_1216 oqs_sig_picnic_mzd_mul_v_uint64_256_1216
#define mzd_rotate_left_uint64_128 oqs_sig_picnic_mzd_rotate_left_uint64_128
#define mzd_rotate_left_uint64_192 oqs_sig_picnic_mzd_rotate_left_uint64_192
#define mzd_rotate_left_uint64_256 oqs_sig_picnic_mzd_rotate_left_uint64_256
#define mzd_rotate_right_uint64_128 oqs_sig_picnic_mzd_rotate_right_uint64_128
#define mzd_rotate_right_uint64_192 oqs_sig_picnic_mzd_rotate_right_uint64_192
#define mzd_rotate_right_uint64_256 oqs_sig_picnic_mzd_rotate_right_uint64_256
#define mzd_shift_left_uint64_128 oqs_sig_picnic_mzd_shift_left_uint64_128
#define mzd_shift_left_uint64_192 oqs_sig_picnic_mzd_shift_left_uint64_192
#define mzd_shift_left_uint64_256 oqs_sig_picnic_mzd_shift_left_uint64_256
#define mzd_shift_right_uint64_128 oqs_sig_picnic_mzd_shift_right_uint64_128
#define mzd_shift_right_uint64_192 oqs_sig_picnic_mzd_shift_right_uint64_192
#define mzd_shift_right_uint64_256 oqs_sig_picnic_mzd_shift_right_uint64_256
#define mzd_shuffle_128_3 oqs_sig_picnic_mzd_shuffle_128_3
#define mzd_shuffle_128_30 oqs_sig_picnic_mzd_shuffle_128_30
#define mzd_shuffle_192_3 oqs_sig_picnic_mzd_shuffle_192_3
#define mzd_shuffle_192_30 oqs_sig_picnic_mzd_shuffle_192_30
#define mzd_shuffle_256_3 oqs_sig_picnic_mzd_shuffle_256_3
#define mzd_shuffle_256_30 oqs_sig_picnic_mzd_shuffle_256_30
#define mzd_shuffle_pext_128_3 oqs_sig_picnic_mzd_shuffle_pext_128_3
#define mzd_shuffle_pext_128_30 oqs_sig_picnic_mzd_shuffle_pext_128_30
#define mzd_shuffle_pext_192_3 oqs_sig_picnic_mzd_shuffle_pext_192_3
#define mzd_shuffle_pext_192_30 oqs_sig_picnic_mzd_shuffle_pext_192_30
#define mzd_shuffle_pext_256_3 oqs_sig_picnic_mzd_shuffle_pext_256_3
#define mzd_shuffle_pext_256_30 oqs_sig_picnic_mzd_shuffle_pext_256_30
#define mzd_to_bitstream oqs_sig_picnic_mzd_to_bitstream
#define mzd_to_char_array oqs_sig_picnic_mzd_to_char_array
#define mzd_xor_s128_1024 oqs_sig_picnic_mzd_xor_s128_1024
#define mzd_xor_s128_128 oqs_sig_picnic_mzd_xor_s128_128
#define mzd_xor_s128_1280 oqs_sig_picnic_mzd_xor_s128_1280
#define mzd_xor_s128_256 oqs_sig_picnic_mzd_xor_s128_256
#define mzd_xor_s128_640 oqs_sig_picnic_mzd_xor_s128_640
#define mzd_xor_s128_blocks oqs_sig_picnic_mzd_xor_s128_blocks
#define mzd_xor_s256_1024 oqs_sig_picnic_mzd_xor_s256_1024
#define mzd_xor_s256_128 oqs_sig_picnic_mzd_xor_s256_128
#define mzd_xor_s256_1280 oqs_sig_picnic_mzd_xor_s256_1280
#define mzd_xor_s256_256 oqs_sig_picnic_mzd_xor_s256_256
#define mzd_xor_s256_768 oqs_sig_picnic_mzd_xor_s256_768
#define mzd_xor_s256_blocks oqs_sig_picnic_mzd_xor_s256_blocks
#define mzd_xor_uint64_1216 oqs_sig_picnic_mzd_xor_uint64_1216
#define mzd_xor_uint64_128 oqs_sig_picnic_mzd_xor_uint64_128
#define mzd_xor_uint64_192 oqs_sig_picnic_mzd_xor_uint64_192
#define mzd_xor_uint64_256 oqs_sig_picnic_mzd_xor_uint64_256
#define mzd_xor_uint64_640 oqs_sig_picnic_mzd_xor_uint64_640
#define mzd_xor_uint64_960 oqs_sig_picnic_mzd_xor_uint64_960
#define openMerkleTree oqs_sig_picnic_openMerkleTree
#define openMerkleTreeSize oqs_sig_picnic_openMerkleTreeSize
#define picnic_clear_private_key oqs_sig_picnic_picnic_clear_private_key
#define picnic_get_lowmc_block_size oqs_sig_picnic_get_lowmc_block_size
#define picnic_get_param_name oqs_sig_picnic_get_param_name
#define picnic_get_private_key_size oqs_sig_picnic_get_private_key_size
#define picnic_get_public_key_size oqs_sig_picnic_get_public_key_size
#define picnic_instance_get oqs_sig_picnic_instance_get
#define picnic_keygen oqs_sig_picnic_keygen
#define picnic_read_private_key oqs_sig_picnic_read_private_key
#define picnic_read_public_key oqs_sig_picnic_read_public_key
#define picnic_sign oqs_sig_picnic_sign
#define picnic_sk_to_pk oqs_sig_picnic_sk_to_pk
#define picnic_signature_size oqs_sig_picnic_signature_size
#define picnic_validate_keypair oqs_sig_picnic_validate_keypair
#define picnic_verify oqs_sig_picnic_verify
#define picnic_write_private_key oqs_sig_picnic_write_private_key
#define picnic_write_public_key oqs_sig_picnic_write_public_key
#define rand_bits oqs_sig_picnic_rand_bits
#define reconstructSeeds oqs_sig_picnic_reconstructSeeds
#define revealSeeds oqs_sig_picnic_revealSeeds
#define revealSeedsSize oqs_sig_picnic_revealSeedsSize
#define setBit oqs_sig_picnic_setBit
#define verifyMerkleTree oqs_sig_picnic_verifyMerkleTree

#endif
