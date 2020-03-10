/*************************************************************************************
* qTESLA: an efficient post-quantum signature scheme based on the R-LWE problem
*
* Abstract: CDT constants for the Gaussian sampler
**************************************************************************************/

#ifndef CDTSAMP
#define CDTSAMP

#include <stdint.h>
#include "params.h"

#if defined(_qTESLA_p_I_)

// Sigma = 8.5, 64-bit precision

#define CDT_ROWS 78
#define CDT_COLS 2

static const int32_t cdt_v[CDT_ROWS * CDT_COLS] = {
	0x00000000L, 0x00000000L, // 0
	0x0601F22AL, 0x280663D4L, // 1
	0x11F09FFAL, 0x162FE23DL, // 2
	0x1DA089E9L, 0x437226E8L, // 3
	0x28EAB25DL, 0x04C51FE2L, // 4
	0x33AC2F26L, 0x14FDBA70L, // 5
	0x3DC767DCL, 0x4565C960L, // 6
	0x4724FC62L, 0x3342C78AL, // 7
	0x4FB448F4L, 0x5229D06DL, // 8
	0x576B8599L, 0x7423407FL, // 9
	0x5E4786DAL, 0x3210BAF7L, // 10
	0x644B2C92L, 0x431B3947L, // 11
	0x697E90CEL, 0x77C362C4L, // 12
	0x6DEE0B96L, 0x2798C9CEL, // 13
	0x71A92144L, 0x5765FCE4L, // 14
	0x74C16FD5L, 0x1E2A0990L, // 15
	0x7749AC92L, 0x0DF36EEBL, // 16
	0x7954BFA4L, 0x28079289L, // 17
	0x7AF5067AL, 0x2EDC2050L, // 18
	0x7C3BC17CL, 0x123D5E7BL, // 19
	0x7D38AD76L, 0x2A9381D9L, // 20
	0x7DF9C5DFL, 0x0E868CA7L, // 21
	0x7E8B2ABAL, 0x18E5C811L, // 22
	0x7EF7237CL, 0x00908272L, // 23
	0x7F4637C5L, 0x6DBA5126L, // 24
	0x7F7F5707L, 0x4A52EDEBL, // 25
	0x7FA808CCL, 0x23290599L, // 26
	0x7FC4A083L, 0x69BDF2D5L, // 27
	0x7FD870CAL, 0x42275558L, // 28
	0x7FE5FB5DL, 0x3EF82C1BL, // 29
	0x7FEF1BFAL, 0x6C03A362L, // 30
	0x7FF52D4EL, 0x316C2C8CL, // 31
	0x7FF927BAL, 0x12AE54AFL, // 32
	0x7FFBBA43L, 0x749CC0E2L, // 33
	0x7FFD5E3DL, 0x4524AD91L, // 34
	0x7FFE6664L, 0x535785B5L, // 35
	0x7FFF0A41L, 0x0B291681L, // 36
	0x7FFF6E81L, 0x132C3D6FL, // 37
	0x7FFFAAFEL, 0x4DBC6BEDL, // 38
	0x7FFFCEFDL, 0x7A1E2D14L, // 39
	0x7FFFE41EL, 0x4C6EC115L, // 40
	0x7FFFF059L, 0x319503C8L, // 41
	0x7FFFF754L, 0x5DDD0D40L, // 42
	0x7FFFFB43L, 0x0B9E9823L, // 43
	0x7FFFFD71L, 0x76B81AE1L, // 44
	0x7FFFFEA3L, 0x7E66A1ECL, // 45
	0x7FFFFF49L, 0x26F6E191L, // 46
	0x7FFFFFA1L, 0x2FA31694L, // 47
	0x7FFFFFCFL, 0x5247BEC9L, // 48
	0x7FFFFFE7L, 0x4F4127C7L, // 49
	0x7FFFFFF3L, 0x6FAA69FDL, // 50
	0x7FFFFFFAL, 0x0630D073L, // 51
	0x7FFFFFFDL, 0x0F2957BBL, // 52
	0x7FFFFFFEL, 0x4FD29432L, // 53
	0x7FFFFFFFL, 0x2CFAD60DL, // 54
	0x7FFFFFFFL, 0x5967A930L, // 55
	0x7FFFFFFFL, 0x6E4C9DFFL, // 56
	0x7FFFFFFFL, 0x77FDCCC8L, // 57
	0x7FFFFFFFL, 0x7C6CE89EL, // 58
	0x7FFFFFFFL, 0x7E6D116FL, // 59
	0x7FFFFFFFL, 0x7F50FA31L, // 60
	0x7FFFFFFFL, 0x7FB50089L, // 61
	0x7FFFFFFFL, 0x7FE04C2DL, // 62
	0x7FFFFFFFL, 0x7FF2C7C1L, // 63
	0x7FFFFFFFL, 0x7FFA8FE3L, // 64
	0x7FFFFFFFL, 0x7FFDCB1BL, // 65
	0x7FFFFFFFL, 0x7FFF1DE2L, // 66
	0x7FFFFFFFL, 0x7FFFA6B7L, // 67
	0x7FFFFFFFL, 0x7FFFDD39L, // 68
	0x7FFFFFFFL, 0x7FFFF2A3L, // 69
	0x7FFFFFFFL, 0x7FFFFAEFL, // 70
	0x7FFFFFFFL, 0x7FFFFE1BL, // 71
	0x7FFFFFFFL, 0x7FFFFF4DL, // 72
	0x7FFFFFFFL, 0x7FFFFFBFL, // 73
	0x7FFFFFFFL, 0x7FFFFFE9L, // 74
	0x7FFFFFFFL, 0x7FFFFFF8L, // 75
	0x7FFFFFFFL, 0x7FFFFFFDL, // 76
	0x7FFFFFFFL, 0x7FFFFFFFL, // 77
};                            // cdt_v

// memory requirements:
//     2048 samples: 25512 bytes
//     1024 samples: 13224 bytes
//      512 samples:  7080 bytes
//      256 samples:  4008 bytes
//      128 samples:  2472 bytes
//       64 samples:  1704 bytes
//       32 samples:  1320 bytes
// table alone: 624 bytes

#elif defined(_qTESLA_p_III_)

// Sigma = 8.5, 128-bit precision

#define CDT_ROWS 111
#define CDT_COLS 4

static const int32_t cdt_v[CDT_ROWS * CDT_COLS] = {
	0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, // 0
	0x0601F22AL, 0x280663D4L, 0x2E1B038CL, 0x1E75FCA7L, // 1
	0x11F09FFAL, 0x162FE23DL, 0x403739B4L, 0x3F2AA531L, // 2
	0x1DA089E9L, 0x437226E8L, 0x115E99C8L, 0x68C472A6L, // 3
	0x28EAB25DL, 0x04C51FE2L, 0x13F63FD0L, 0x1E56BF40L, // 4
	0x33AC2F26L, 0x14FDBA70L, 0x6618880FL, 0x792CE93EL, // 5
	0x3DC767DCL, 0x4565C95FL, 0x7EAC4790L, 0x163F4D99L, // 6
	0x4724FC62L, 0x3342C78AL, 0x390873B2L, 0x13A12ACEL, // 7
	0x4FB448F4L, 0x5229D06DL, 0x09A6C84BL, 0x1D13CB0DL, // 8
	0x576B8599L, 0x7423407FL, 0x1287EE2FL, 0x7B908556L, // 9
	0x5E4786DAL, 0x3210BAF6L, 0x6881795CL, 0x13DF4F59L, // 10
	0x644B2C92L, 0x431B3946L, 0x63F188D9L, 0x22AFB6DEL, // 11
	0x697E90CEL, 0x77C362C3L, 0x600A627EL, 0x66AEDF96L, // 12
	0x6DEE0B96L, 0x2798C9CEL, 0x147A98F9L, 0x27427F24L, // 13
	0x71A92144L, 0x5765FCE4L, 0x0FF04C94L, 0x74183C18L, // 14
	0x74C16FD5L, 0x1E2A0990L, 0x13EB545FL, 0x1CD9A2ADL, // 15
	0x7749AC92L, 0x0DF36EEBL, 0x414629E5L, 0x66610A51L, // 16
	0x7954BFA4L, 0x28079289L, 0x29D5B127L, 0x29B69601L, // 17
	0x7AF5067AL, 0x2EDC2050L, 0x2B486556L, 0x43BF4664L, // 18
	0x7C3BC17CL, 0x123D5E7AL, 0x63D4DD26L, 0x3B1E3755L, // 19
	0x7D38AD76L, 0x2A9381D9L, 0x1D20D034L, 0x77C09C55L, // 20
	0x7DF9C5DFL, 0x0E868CA7L, 0x23627687L, 0x78864423L, // 21
	0x7E8B2ABAL, 0x18E5C810L, 0x7C85B42CL, 0x7AC98BCCL, // 22
	0x7EF7237CL, 0x00908272L, 0x3D4B170EL, 0x3CD572E3L, // 23
	0x7F4637C5L, 0x6DBA5125L, 0x5B0285ECL, 0x46661EB9L, // 24
	0x7F7F5707L, 0x4A52EDEBL, 0x50ECECB1L, 0x7384DC42L, // 25
	0x7FA808CCL, 0x23290598L, 0x704F7A4DL, 0x08532154L, // 26
	0x7FC4A083L, 0x69BDF2D4L, 0x73B67B27L, 0x3AE237ADL, // 27
	0x7FD870CAL, 0x42275557L, 0x6F2AE034L, 0x4E4B0395L, // 28
	0x7FE5FB5DL, 0x3EF82C1BL, 0x256E2EB0L, 0x09E42B11L, // 29
	0x7FEF1BFAL, 0x6C03A362L, 0x07334BD4L, 0x22B6B15FL, // 30
	0x7FF52D4EL, 0x316C2C8CL, 0x1C77A4C3L, 0x1C3A974EL, // 31
	0x7FF927BAL, 0x12AE54AEL, 0x6CC24956L, 0x3BA9A3E4L, // 32
	0x7FFBBA43L, 0x749CC0E2L, 0x044B3068L, 0x620F14DAL, // 33
	0x7FFD5E3DL, 0x4524AD91L, 0x31F84A1FL, 0x4D23AF51L, // 34
	0x7FFE6664L, 0x535785B4L, 0x683C9E5EL, 0x2BD857DFL, // 35
	0x7FFF0A41L, 0x0B291681L, 0x1CB4CE6FL, 0x32B314B9L, // 36
	0x7FFF6E81L, 0x132C3D6FL, 0x4C8771CCL, 0x67421A75L, // 37
	0x7FFFAAFEL, 0x4DBC6BEDL, 0x4E8644D2L, 0x5158A208L, // 38
	0x7FFFCEFDL, 0x7A1E2D14L, 0x2CF905AAL, 0x79BFABD9L, // 39
	0x7FFFE41EL, 0x4C6EC115L, 0x2D648F1AL, 0x4B01BA3EL, // 40
	0x7FFFF059L, 0x319503C8L, 0x2CBEB96AL, 0x52FF656EL, // 41
	0x7FFFF754L, 0x5DDD0D40L, 0x09D07206L, 0x6BF97EB5L, // 42
	0x7FFFFB43L, 0x0B9E9822L, 0x5B584BE0L, 0x4974ED83L, // 43
	0x7FFFFD71L, 0x76B81AE1L, 0x3C93755CL, 0x375F857BL, // 44
	0x7FFFFEA3L, 0x7E66A1ECL, 0x3E342087L, 0x44ED1696L, // 45
	0x7FFFFF49L, 0x26F6E190L, 0x7E3625F9L, 0x2F4F5849L, // 46
	0x7FFFFFA1L, 0x2FA31694L, 0x0D53F684L, 0x59931C0DL, // 47
	0x7FFFFFCFL, 0x5247BEC8L, 0x5CC20735L, 0x397CE966L, // 48
	0x7FFFFFE7L, 0x4F4127C6L, 0x64926788L, 0x01CFEF66L, // 49
	0x7FFFFFF3L, 0x6FAA69FDL, 0x26A67DC3L, 0x1FFA2528L, // 50
	0x7FFFFFFAL, 0x0630D072L, 0x7AA0C1B7L, 0x7E90AAE6L, // 51
	0x7FFFFFFDL, 0x0F2957BBL, 0x3ADCE1E6L, 0x5A311C28L, // 52
	0x7FFFFFFEL, 0x4FD29431L, 0x6429F9EDL, 0x04653965L, // 53
	0x7FFFFFFFL, 0x2CFAD60DL, 0x52ED82D1L, 0x26455881L, // 54
	0x7FFFFFFFL, 0x5967A92FL, 0x5C85AB2DL, 0x188033BEL, // 55
	0x7FFFFFFFL, 0x6E4C9DFEL, 0x76798EAFL, 0x0DC0BA65L, // 56
	0x7FFFFFFFL, 0x77FDCCC8L, 0x194FF9ACL, 0x2C3FA855L, // 57
	0x7FFFFFFFL, 0x7C6CE89EL, 0x01FA1A72L, 0x6C3DC40BL, // 58
	0x7FFFFFFFL, 0x7E6D116EL, 0x5F82B352L, 0x57B67FCEL, // 59
	0x7FFFFFFFL, 0x7F50FA31L, 0x31856599L, 0x579DC24BL, // 60
	0x7FFFFFFFL, 0x7FB50089L, 0x43E64BB5L, 0x7F498E42L, // 61
	0x7FFFFFFFL, 0x7FE04C2CL, 0x56CBFAEFL, 0x7FC9C15FL, // 62
	0x7FFFFFFFL, 0x7FF2C7C0L, 0x5D509634L, 0x41DCA82BL, // 63
	0x7FFFFFFFL, 0x7FFA8FE3L, 0x24F6020DL, 0x7B594401L, // 64
	0x7FFFFFFFL, 0x7FFDCB1BL, 0x2D294BB3L, 0x1D1631BFL, // 65
	0x7FFFFFFFL, 0x7FFF1DE1L, 0x5D75B704L, 0x323B12FEL, // 66
	0x7FFFFFFFL, 0x7FFFA6B6L, 0x7E983E86L, 0x23392636L, // 67
	0x7FFFFFFFL, 0x7FFFDD39L, 0x029CCA2CL, 0x035F7017L, // 68
	0x7FFFFFFFL, 0x7FFFF2A3L, 0x205DBF7BL, 0x173D7F90L, // 69
	0x7FFFFFFFL, 0x7FFFFAEFL, 0x3F79145BL, 0x642F005DL, // 70
	0x7FFFFFFFL, 0x7FFFFE1BL, 0x23B2C7E4L, 0x6CA216CFL, // 71
	0x7FFFFFFFL, 0x7FFFFF4DL, 0x1E959E3FL, 0x4A29BB03L, // 72
	0x7FFFFFFFL, 0x7FFFFFBEL, 0x7C23D3D9L, 0x71DC92E4L, // 73
	0x7FFFFFFFL, 0x7FFFFFE8L, 0x55110485L, 0x0E1813E2L, // 74
	0x7FFFFFFFL, 0x7FFFFFF7L, 0x5EBC7B7BL, 0x2DFEE922L, // 75
	0x7FFFFFFFL, 0x7FFFFFFDL, 0x0EDB0975L, 0x0C9F1639L, // 76
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x00DDA1A1L, 0x6DE86AA0L, // 77
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x54CF6D87L, 0x023F1F47L, // 78
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7186FF6AL, 0x5B71BF8CL, // 79
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7B375EBCL, 0x767A89DCL, // 80
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7E70BA89L, 0x44EBCEAAL, // 81
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7F7F98B5L, 0x44C8E44AL, // 82
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FD744C2L, 0x448EE5A4L, // 83
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FF34165L, 0x008855D0L, // 84
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFC1110L, 0x754A60B6L, // 85
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFECD77L, 0x44BE6D4AL, // 86
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFA3F4L, 0x7400A73EL, // 87
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFE4BDL, 0x1143830BL, // 88
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFF809L, 0x1A385059L, // 89
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFDB4L, 0x41CA0794L, // 90
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFF59L, 0x02FFB605L, // 91
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFD1L, 0x18360E8DL, // 92
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFF3L, 0x072A0E9AL, // 93
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFCL, 0x3C1BFEB0L, // 94
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x066EBCDDL, // 95
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x5FBE171AL, // 96
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x778EB81FL, // 97
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7DD211FEL, // 98
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7F71F071L, // 99
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FDC528FL, // 100
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FF7298CL, // 101
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFDD739L, // 102
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFF7ACAL, // 103
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFE056L, // 104
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFF893L, // 105
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFE48L, // 106
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFF9CL, // 107
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFE9L, // 108
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFBL, // 109
	0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, 0x7FFFFFFFL, // 110
};                                                      // cdt_v

// memory requirements:
//     2048 samples: 43180 bytes
//     1024 samples: 22700 bytes
//      512 samples: 12460 bytes
//      256 samples:  7340 bytes
//      128 samples:  4780 bytes
//       64 samples:  3500 bytes
//       32 samples:  2860 bytes
// table alone: 1776 bytes

#endif

#endif

