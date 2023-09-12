/**
  ******************************************************************************
  * Copyright © 2023 刘汲桐. All rights reserved. https://sulfurandcu.github.io/
  ******************************************************************************
  * Note :
  ******************************************************************************
  * 2023-09-09  sulfurandcu@gmail.com   first release (1.0.0)
  ******************************************************************************
  */

#include "crc.h"

static uint8_t reverse_08(uint8_t data)
{
    uint8_t temp = 0;
    for (int i = 0; i < 0x08; ++i)
    {
        temp |= (uint8_t)(((data >> i) & 0x01) << (0x07 - i));
    }
    return temp;
}

static uint16_t reverse_16(uint16_t data)
{
    uint16_t temp = 0;
    for (int i = 0; i < 0x10; ++i)
    {
        temp |= (uint16_t)(((data >> i) & 0x01) << (0x0F - i));
    }
    return temp;
}

static uint32_t reverse_32(uint32_t data)
{
    uint32_t temp = 0;
    for (int i = 0; i < 0x20; ++i)
    {
        temp |= (uint32_t)(((data >> i) & 0x01) << (0x1F - i));
    }
    return temp;
}

static uint64_t reverse_64(uint64_t data)
{
    uint64_t temp = 0;
    for (int i = 0; i < 0x40; ++i)
    {
        temp |= (uint64_t)(((data >> i) & 0x01) << (0x3F - i));
    }
    return temp;
}

#if crc_xx_table_calc_enable

#if crc_08_enable

#endif /* crc_08_enable */

#if crc_16_enable

#if crc_16_poly_8005_enable
static uint16_t crc_16_table_0x8005[] =
{
    0x0000, 0x8005, 0x800f, 0x000a, 0x801b, 0x001e, 0x0014, 0x8011,    0x8033, 0x0036, 0x003c, 0x8039, 0x0028, 0x802d, 0x8027, 0x0022,
    0x8063, 0x0066, 0x006c, 0x8069, 0x0078, 0x807d, 0x8077, 0x0072,    0x0050, 0x8055, 0x805f, 0x005a, 0x804b, 0x004e, 0x0044, 0x8041,
    0x80c3, 0x00c6, 0x00cc, 0x80c9, 0x00d8, 0x80dd, 0x80d7, 0x00d2,    0x00f0, 0x80f5, 0x80ff, 0x00fa, 0x80eb, 0x00ee, 0x00e4, 0x80e1,
    0x00a0, 0x80a5, 0x80af, 0x00aa, 0x80bb, 0x00be, 0x00b4, 0x80b1,    0x8093, 0x0096, 0x009c, 0x8099, 0x0088, 0x808d, 0x8087, 0x0082,
    0x8183, 0x0186, 0x018c, 0x8189, 0x0198, 0x819d, 0x8197, 0x0192,    0x01b0, 0x81b5, 0x81bf, 0x01ba, 0x81ab, 0x01ae, 0x01a4, 0x81a1,
    0x01e0, 0x81e5, 0x81ef, 0x01ea, 0x81fb, 0x01fe, 0x01f4, 0x81f1,    0x81d3, 0x01d6, 0x01dc, 0x81d9, 0x01c8, 0x81cd, 0x81c7, 0x01c2,
    0x0140, 0x8145, 0x814f, 0x014a, 0x815b, 0x015e, 0x0154, 0x8151,    0x8173, 0x0176, 0x017c, 0x8179, 0x0168, 0x816d, 0x8167, 0x0162,
    0x8123, 0x0126, 0x012c, 0x8129, 0x0138, 0x813d, 0x8137, 0x0132,    0x0110, 0x8115, 0x811f, 0x011a, 0x810b, 0x010e, 0x0104, 0x8101,
    0x8303, 0x0306, 0x030c, 0x8309, 0x0318, 0x831d, 0x8317, 0x0312,    0x0330, 0x8335, 0x833f, 0x033a, 0x832b, 0x032e, 0x0324, 0x8321,
    0x0360, 0x8365, 0x836f, 0x036a, 0x837b, 0x037e, 0x0374, 0x8371,    0x8353, 0x0356, 0x035c, 0x8359, 0x0348, 0x834d, 0x8347, 0x0342,
    0x03c0, 0x83c5, 0x83cf, 0x03ca, 0x83db, 0x03de, 0x03d4, 0x83d1,    0x83f3, 0x03f6, 0x03fc, 0x83f9, 0x03e8, 0x83ed, 0x83e7, 0x03e2,
    0x83a3, 0x03a6, 0x03ac, 0x83a9, 0x03b8, 0x83bd, 0x83b7, 0x03b2,    0x0390, 0x8395, 0x839f, 0x039a, 0x838b, 0x038e, 0x0384, 0x8381,
    0x0280, 0x8285, 0x828f, 0x028a, 0x829b, 0x029e, 0x0294, 0x8291,    0x82b3, 0x02b6, 0x02bc, 0x82b9, 0x02a8, 0x82ad, 0x82a7, 0x02a2,
    0x82e3, 0x02e6, 0x02ec, 0x82e9, 0x02f8, 0x82fd, 0x82f7, 0x02f2,    0x02d0, 0x82d5, 0x82df, 0x02da, 0x82cb, 0x02ce, 0x02c4, 0x82c1,
    0x8243, 0x0246, 0x024c, 0x8249, 0x0258, 0x825d, 0x8257, 0x0252,    0x0270, 0x8275, 0x827f, 0x027a, 0x826b, 0x026e, 0x0264, 0x8261,
    0x0220, 0x8225, 0x822f, 0x022a, 0x823b, 0x023e, 0x0234, 0x8231,    0x8213, 0x0216, 0x021c, 0x8219, 0x0208, 0x820d, 0x8207, 0x0202,
};
#endif

#if crc_16_poly_1021_enable
static uint16_t crc_16_table_0x1021[] =
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,    0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0,
};
#endif

#if crc_16_poly_xxxx_enable
static uint16_t crc_16_table_0x3d65[] =
{
    0x0000, 0x3d65, 0x7aca, 0x47af, 0xf594, 0xc8f1, 0x8f5e, 0xb23b,    0xd64d, 0xeb28, 0xac87, 0x91e2, 0x23d9, 0x1ebc, 0x5913, 0x6476,
    0x91ff, 0xac9a, 0xeb35, 0xd650, 0x646b, 0x590e, 0x1ea1, 0x23c4,    0x47b2, 0x7ad7, 0x3d78, 0x001d, 0xb226, 0x8f43, 0xc8ec, 0xf589,
    0x1e9b, 0x23fe, 0x6451, 0x5934, 0xeb0f, 0xd66a, 0x91c5, 0xaca0,    0xc8d6, 0xf5b3, 0xb21c, 0x8f79, 0x3d42, 0x0027, 0x4788, 0x7aed,
    0x8f64, 0xb201, 0xf5ae, 0xc8cb, 0x7af0, 0x4795, 0x003a, 0x3d5f,    0x5929, 0x644c, 0x23e3, 0x1e86, 0xacbd, 0x91d8, 0xd677, 0xeb12,
    0x3d36, 0x0053, 0x47fc, 0x7a99, 0xc8a2, 0xf5c7, 0xb268, 0x8f0d,    0xeb7b, 0xd61e, 0x91b1, 0xacd4, 0x1eef, 0x238a, 0x6425, 0x5940,
    0xacc9, 0x91ac, 0xd603, 0xeb66, 0x595d, 0x6438, 0x2397, 0x1ef2,    0x7a84, 0x47e1, 0x004e, 0x3d2b, 0x8f10, 0xb275, 0xf5da, 0xc8bf,
    0x23ad, 0x1ec8, 0x5967, 0x6402, 0xd639, 0xeb5c, 0xacf3, 0x9196,    0xf5e0, 0xc885, 0x8f2a, 0xb24f, 0x0074, 0x3d11, 0x7abe, 0x47db,
    0xb252, 0x8f37, 0xc898, 0xf5fd, 0x47c6, 0x7aa3, 0x3d0c, 0x0069,    0x641f, 0x597a, 0x1ed5, 0x23b0, 0x918b, 0xacee, 0xeb41, 0xd624,
    0x7a6c, 0x4709, 0x00a6, 0x3dc3, 0x8ff8, 0xb29d, 0xf532, 0xc857,    0xac21, 0x9144, 0xd6eb, 0xeb8e, 0x59b5, 0x64d0, 0x237f, 0x1e1a,
    0xeb93, 0xd6f6, 0x9159, 0xac3c, 0x1e07, 0x2362, 0x64cd, 0x59a8,    0x3dde, 0x00bb, 0x4714, 0x7a71, 0xc84a, 0xf52f, 0xb280, 0x8fe5,
    0x64f7, 0x5992, 0x1e3d, 0x2358, 0x9163, 0xac06, 0xeba9, 0xd6cc,    0xb2ba, 0x8fdf, 0xc870, 0xf515, 0x472e, 0x7a4b, 0x3de4, 0x0081,
    0xf508, 0xc86d, 0x8fc2, 0xb2a7, 0x009c, 0x3df9, 0x7a56, 0x4733,    0x2345, 0x1e20, 0x598f, 0x64ea, 0xd6d1, 0xebb4, 0xac1b, 0x917e,
    0x475a, 0x7a3f, 0x3d90, 0x00f5, 0xb2ce, 0x8fab, 0xc804, 0xf561,    0x9117, 0xac72, 0xebdd, 0xd6b8, 0x6483, 0x59e6, 0x1e49, 0x232c,
    0xd6a5, 0xebc0, 0xac6f, 0x910a, 0x2331, 0x1e54, 0x59fb, 0x649e,    0x00e8, 0x3d8d, 0x7a22, 0x4747, 0xf57c, 0xc819, 0x8fb6, 0xb2d3,
    0x59c1, 0x64a4, 0x230b, 0x1e6e, 0xac55, 0x9130, 0xd69f, 0xebfa,    0x8f8c, 0xb2e9, 0xf546, 0xc823, 0x7a18, 0x477d, 0x00d2, 0x3db7,
    0xc83e, 0xf55b, 0xb2f4, 0x8f91, 0x3daa, 0x00cf, 0x4760, 0x7a05,    0x1e73, 0x2316, 0x64b9, 0x59dc, 0xebe7, 0xd682, 0x912d, 0xac48,
};

static uint16_t crc_16_table_0x0589[] =
{
    0x0000, 0x0589, 0x0b12, 0x0e9b, 0x1624, 0x13ad, 0x1d36, 0x18bf,    0x2c48, 0x29c1, 0x275a, 0x22d3, 0x3a6c, 0x3fe5, 0x317e, 0x34f7,
    0x5890, 0x5d19, 0x5382, 0x560b, 0x4eb4, 0x4b3d, 0x45a6, 0x402f,    0x74d8, 0x7151, 0x7fca, 0x7a43, 0x62fc, 0x6775, 0x69ee, 0x6c67,
    0xb120, 0xb4a9, 0xba32, 0xbfbb, 0xa704, 0xa28d, 0xac16, 0xa99f,    0x9d68, 0x98e1, 0x967a, 0x93f3, 0x8b4c, 0x8ec5, 0x805e, 0x85d7,
    0xe9b0, 0xec39, 0xe2a2, 0xe72b, 0xff94, 0xfa1d, 0xf486, 0xf10f,    0xc5f8, 0xc071, 0xceea, 0xcb63, 0xd3dc, 0xd655, 0xd8ce, 0xdd47,
    0x67c9, 0x6240, 0x6cdb, 0x6952, 0x71ed, 0x7464, 0x7aff, 0x7f76,    0x4b81, 0x4e08, 0x4093, 0x451a, 0x5da5, 0x582c, 0x56b7, 0x533e,
    0x3f59, 0x3ad0, 0x344b, 0x31c2, 0x297d, 0x2cf4, 0x226f, 0x27e6,    0x1311, 0x1698, 0x1803, 0x1d8a, 0x0535, 0x00bc, 0x0e27, 0x0bae,
    0xd6e9, 0xd360, 0xddfb, 0xd872, 0xc0cd, 0xc544, 0xcbdf, 0xce56,    0xfaa1, 0xff28, 0xf1b3, 0xf43a, 0xec85, 0xe90c, 0xe797, 0xe21e,
    0x8e79, 0x8bf0, 0x856b, 0x80e2, 0x985d, 0x9dd4, 0x934f, 0x96c6,    0xa231, 0xa7b8, 0xa923, 0xacaa, 0xb415, 0xb19c, 0xbf07, 0xba8e,
    0xcf92, 0xca1b, 0xc480, 0xc109, 0xd9b6, 0xdc3f, 0xd2a4, 0xd72d,    0xe3da, 0xe653, 0xe8c8, 0xed41, 0xf5fe, 0xf077, 0xfeec, 0xfb65,
    0x9702, 0x928b, 0x9c10, 0x9999, 0x8126, 0x84af, 0x8a34, 0x8fbd,    0xbb4a, 0xbec3, 0xb058, 0xb5d1, 0xad6e, 0xa8e7, 0xa67c, 0xa3f5,
    0x7eb2, 0x7b3b, 0x75a0, 0x7029, 0x6896, 0x6d1f, 0x6384, 0x660d,    0x52fa, 0x5773, 0x59e8, 0x5c61, 0x44de, 0x4157, 0x4fcc, 0x4a45,
    0x2622, 0x23ab, 0x2d30, 0x28b9, 0x3006, 0x358f, 0x3b14, 0x3e9d,    0x0a6a, 0x0fe3, 0x0178, 0x04f1, 0x1c4e, 0x19c7, 0x175c, 0x12d5,
    0xa85b, 0xadd2, 0xa349, 0xa6c0, 0xbe7f, 0xbbf6, 0xb56d, 0xb0e4,    0x8413, 0x819a, 0x8f01, 0x8a88, 0x9237, 0x97be, 0x9925, 0x9cac,
    0xf0cb, 0xf542, 0xfbd9, 0xfe50, 0xe6ef, 0xe366, 0xedfd, 0xe874,    0xdc83, 0xd90a, 0xd791, 0xd218, 0xcaa7, 0xcf2e, 0xc1b5, 0xc43c,
    0x197b, 0x1cf2, 0x1269, 0x17e0, 0x0f5f, 0x0ad6, 0x044d, 0x01c4,    0x3533, 0x30ba, 0x3e21, 0x3ba8, 0x2317, 0x269e, 0x2805, 0x2d8c,
    0x41eb, 0x4462, 0x4af9, 0x4f70, 0x57cf, 0x5246, 0x5cdd, 0x5954,    0x6da3, 0x682a, 0x66b1, 0x6338, 0x7b87, 0x7e0e, 0x7095, 0x751c,
};

static uint16_t crc_16_table_0x8bb7[] =
{
    0x0000, 0x8bb7, 0x9cd9, 0x176e, 0xb205, 0x39b2, 0x2edc, 0xa56b,    0xefbd, 0x640a, 0x7364, 0xf8d3, 0x5db8, 0xd60f, 0xc161, 0x4ad6,
    0x54cd, 0xdf7a, 0xc814, 0x43a3, 0xe6c8, 0x6d7f, 0x7a11, 0xf1a6,    0xbb70, 0x30c7, 0x27a9, 0xac1e, 0x0975, 0x82c2, 0x95ac, 0x1e1b,
    0xa99a, 0x222d, 0x3543, 0xbef4, 0x1b9f, 0x9028, 0x8746, 0x0cf1,    0x4627, 0xcd90, 0xdafe, 0x5149, 0xf422, 0x7f95, 0x68fb, 0xe34c,
    0xfd57, 0x76e0, 0x618e, 0xea39, 0x4f52, 0xc4e5, 0xd38b, 0x583c,    0x12ea, 0x995d, 0x8e33, 0x0584, 0xa0ef, 0x2b58, 0x3c36, 0xb781,
    0xd883, 0x5334, 0x445a, 0xcfed, 0x6a86, 0xe131, 0xf65f, 0x7de8,    0x373e, 0xbc89, 0xabe7, 0x2050, 0x853b, 0x0e8c, 0x19e2, 0x9255,
    0x8c4e, 0x07f9, 0x1097, 0x9b20, 0x3e4b, 0xb5fc, 0xa292, 0x2925,    0x63f3, 0xe844, 0xff2a, 0x749d, 0xd1f6, 0x5a41, 0x4d2f, 0xc698,
    0x7119, 0xfaae, 0xedc0, 0x6677, 0xc31c, 0x48ab, 0x5fc5, 0xd472,    0x9ea4, 0x1513, 0x027d, 0x89ca, 0x2ca1, 0xa716, 0xb078, 0x3bcf,
    0x25d4, 0xae63, 0xb90d, 0x32ba, 0x97d1, 0x1c66, 0x0b08, 0x80bf,    0xca69, 0x41de, 0x56b0, 0xdd07, 0x786c, 0xf3db, 0xe4b5, 0x6f02,
    0x3ab1, 0xb106, 0xa668, 0x2ddf, 0x88b4, 0x0303, 0x146d, 0x9fda,    0xd50c, 0x5ebb, 0x49d5, 0xc262, 0x6709, 0xecbe, 0xfbd0, 0x7067,
    0x6e7c, 0xe5cb, 0xf2a5, 0x7912, 0xdc79, 0x57ce, 0x40a0, 0xcb17,    0x81c1, 0x0a76, 0x1d18, 0x96af, 0x33c4, 0xb873, 0xaf1d, 0x24aa,
    0x932b, 0x189c, 0x0ff2, 0x8445, 0x212e, 0xaa99, 0xbdf7, 0x3640,    0x7c96, 0xf721, 0xe04f, 0x6bf8, 0xce93, 0x4524, 0x524a, 0xd9fd,
    0xc7e6, 0x4c51, 0x5b3f, 0xd088, 0x75e3, 0xfe54, 0xe93a, 0x628d,    0x285b, 0xa3ec, 0xb482, 0x3f35, 0x9a5e, 0x11e9, 0x0687, 0x8d30,
    0xe232, 0x6985, 0x7eeb, 0xf55c, 0x5037, 0xdb80, 0xccee, 0x4759,    0x0d8f, 0x8638, 0x9156, 0x1ae1, 0xbf8a, 0x343d, 0x2353, 0xa8e4,
    0xb6ff, 0x3d48, 0x2a26, 0xa191, 0x04fa, 0x8f4d, 0x9823, 0x1394,    0x5942, 0xd2f5, 0xc59b, 0x4e2c, 0xeb47, 0x60f0, 0x779e, 0xfc29,
    0x4ba8, 0xc01f, 0xd771, 0x5cc6, 0xf9ad, 0x721a, 0x6574, 0xeec3,    0xa415, 0x2fa2, 0x38cc, 0xb37b, 0x1610, 0x9da7, 0x8ac9, 0x017e,
    0x1f65, 0x94d2, 0x83bc, 0x080b, 0xad60, 0x26d7, 0x31b9, 0xba0e,    0xf0d8, 0x7b6f, 0x6c01, 0xe7b6, 0x42dd, 0xc96a, 0xde04, 0x55b3,
};

static uint16_t crc_16_table_0xa097[] =
{
    0x0000, 0xa097, 0xe1b9, 0x412e, 0x63e5, 0xc372, 0x825c, 0x22cb,    0xc7ca, 0x675d, 0x2673, 0x86e4, 0xa42f, 0x04b8, 0x4596, 0xe501,
    0x2f03, 0x8f94, 0xceba, 0x6e2d, 0x4ce6, 0xec71, 0xad5f, 0x0dc8,    0xe8c9, 0x485e, 0x0970, 0xa9e7, 0x8b2c, 0x2bbb, 0x6a95, 0xca02,
    0x5e06, 0xfe91, 0xbfbf, 0x1f28, 0x3de3, 0x9d74, 0xdc5a, 0x7ccd,    0x99cc, 0x395b, 0x7875, 0xd8e2, 0xfa29, 0x5abe, 0x1b90, 0xbb07,
    0x7105, 0xd192, 0x90bc, 0x302b, 0x12e0, 0xb277, 0xf359, 0x53ce,    0xb6cf, 0x1658, 0x5776, 0xf7e1, 0xd52a, 0x75bd, 0x3493, 0x9404,
    0xbc0c, 0x1c9b, 0x5db5, 0xfd22, 0xdfe9, 0x7f7e, 0x3e50, 0x9ec7,    0x7bc6, 0xdb51, 0x9a7f, 0x3ae8, 0x1823, 0xb8b4, 0xf99a, 0x590d,
    0x930f, 0x3398, 0x72b6, 0xd221, 0xf0ea, 0x507d, 0x1153, 0xb1c4,    0x54c5, 0xf452, 0xb57c, 0x15eb, 0x3720, 0x97b7, 0xd699, 0x760e,
    0xe20a, 0x429d, 0x03b3, 0xa324, 0x81ef, 0x2178, 0x6056, 0xc0c1,    0x25c0, 0x8557, 0xc479, 0x64ee, 0x4625, 0xe6b2, 0xa79c, 0x070b,
    0xcd09, 0x6d9e, 0x2cb0, 0x8c27, 0xaeec, 0x0e7b, 0x4f55, 0xefc2,    0x0ac3, 0xaa54, 0xeb7a, 0x4bed, 0x6926, 0xc9b1, 0x889f, 0x2808,
    0xd88f, 0x7818, 0x3936, 0x99a1, 0xbb6a, 0x1bfd, 0x5ad3, 0xfa44,    0x1f45, 0xbfd2, 0xfefc, 0x5e6b, 0x7ca0, 0xdc37, 0x9d19, 0x3d8e,
    0xf78c, 0x571b, 0x1635, 0xb6a2, 0x9469, 0x34fe, 0x75d0, 0xd547,    0x3046, 0x90d1, 0xd1ff, 0x7168, 0x53a3, 0xf334, 0xb21a, 0x128d,
    0x8689, 0x261e, 0x6730, 0xc7a7, 0xe56c, 0x45fb, 0x04d5, 0xa442,    0x4143, 0xe1d4, 0xa0fa, 0x006d, 0x22a6, 0x8231, 0xc31f, 0x6388,
    0xa98a, 0x091d, 0x4833, 0xe8a4, 0xca6f, 0x6af8, 0x2bd6, 0x8b41,    0x6e40, 0xced7, 0x8ff9, 0x2f6e, 0x0da5, 0xad32, 0xec1c, 0x4c8b,
    0x6483, 0xc414, 0x853a, 0x25ad, 0x0766, 0xa7f1, 0xe6df, 0x4648,    0xa349, 0x03de, 0x42f0, 0xe267, 0xc0ac, 0x603b, 0x2115, 0x8182,
    0x4b80, 0xeb17, 0xaa39, 0x0aae, 0x2865, 0x88f2, 0xc9dc, 0x694b,    0x8c4a, 0x2cdd, 0x6df3, 0xcd64, 0xefaf, 0x4f38, 0x0e16, 0xae81,
    0x3a85, 0x9a12, 0xdb3c, 0x7bab, 0x5960, 0xf9f7, 0xb8d9, 0x184e,    0xfd4f, 0x5dd8, 0x1cf6, 0xbc61, 0x9eaa, 0x3e3d, 0x7f13, 0xdf84,
    0x1586, 0xb511, 0xf43f, 0x54a8, 0x7663, 0xd6f4, 0x97da, 0x374d,    0xd24c, 0x72db, 0x33f5, 0x9362, 0xb1a9, 0x113e, 0x5010, 0xf087,
};

static uint16_t crc_16_table_0xc867[] =
{
    0x0000, 0xc867, 0x58a9, 0x90ce, 0xb152, 0x7935, 0xe9fb, 0x219c,    0xaac3, 0x62a4, 0xf26a, 0x3a0d, 0x1b91, 0xd3f6, 0x4338, 0x8b5f,
    0x9de1, 0x5586, 0xc548, 0x0d2f, 0x2cb3, 0xe4d4, 0x741a, 0xbc7d,    0x3722, 0xff45, 0x6f8b, 0xa7ec, 0x8670, 0x4e17, 0xded9, 0x16be,
    0xf3a5, 0x3bc2, 0xab0c, 0x636b, 0x42f7, 0x8a90, 0x1a5e, 0xd239,    0x5966, 0x9101, 0x01cf, 0xc9a8, 0xe834, 0x2053, 0xb09d, 0x78fa,
    0x6e44, 0xa623, 0x36ed, 0xfe8a, 0xdf16, 0x1771, 0x87bf, 0x4fd8,    0xc487, 0x0ce0, 0x9c2e, 0x5449, 0x75d5, 0xbdb2, 0x2d7c, 0xe51b,
    0x2f2d, 0xe74a, 0x7784, 0xbfe3, 0x9e7f, 0x5618, 0xc6d6, 0x0eb1,    0x85ee, 0x4d89, 0xdd47, 0x1520, 0x34bc, 0xfcdb, 0x6c15, 0xa472,
    0xb2cc, 0x7aab, 0xea65, 0x2202, 0x039e, 0xcbf9, 0x5b37, 0x9350,    0x180f, 0xd068, 0x40a6, 0x88c1, 0xa95d, 0x613a, 0xf1f4, 0x3993,
    0xdc88, 0x14ef, 0x8421, 0x4c46, 0x6dda, 0xa5bd, 0x3573, 0xfd14,    0x764b, 0xbe2c, 0x2ee2, 0xe685, 0xc719, 0x0f7e, 0x9fb0, 0x57d7,
    0x4169, 0x890e, 0x19c0, 0xd1a7, 0xf03b, 0x385c, 0xa892, 0x60f5,    0xebaa, 0x23cd, 0xb303, 0x7b64, 0x5af8, 0x929f, 0x0251, 0xca36,
    0x5e5a, 0x963d, 0x06f3, 0xce94, 0xef08, 0x276f, 0xb7a1, 0x7fc6,    0xf499, 0x3cfe, 0xac30, 0x6457, 0x45cb, 0x8dac, 0x1d62, 0xd505,
    0xc3bb, 0x0bdc, 0x9b12, 0x5375, 0x72e9, 0xba8e, 0x2a40, 0xe227,    0x6978, 0xa11f, 0x31d1, 0xf9b6, 0xd82a, 0x104d, 0x8083, 0x48e4,
    0xadff, 0x6598, 0xf556, 0x3d31, 0x1cad, 0xd4ca, 0x4404, 0x8c63,    0x073c, 0xcf5b, 0x5f95, 0x97f2, 0xb66e, 0x7e09, 0xeec7, 0x26a0,
    0x301e, 0xf879, 0x68b7, 0xa0d0, 0x814c, 0x492b, 0xd9e5, 0x1182,    0x9add, 0x52ba, 0xc274, 0x0a13, 0x2b8f, 0xe3e8, 0x7326, 0xbb41,
    0x7177, 0xb910, 0x29de, 0xe1b9, 0xc025, 0x0842, 0x988c, 0x50eb,    0xdbb4, 0x13d3, 0x831d, 0x4b7a, 0x6ae6, 0xa281, 0x324f, 0xfa28,
    0xec96, 0x24f1, 0xb43f, 0x7c58, 0x5dc4, 0x95a3, 0x056d, 0xcd0a,    0x4655, 0x8e32, 0x1efc, 0xd69b, 0xf707, 0x3f60, 0xafae, 0x67c9,
    0x82d2, 0x4ab5, 0xda7b, 0x121c, 0x3380, 0xfbe7, 0x6b29, 0xa34e,    0x2811, 0xe076, 0x70b8, 0xb8df, 0x9943, 0x5124, 0xc1ea, 0x098d,
    0x1f33, 0xd754, 0x479a, 0x8ffd, 0xae61, 0x6606, 0xf6c8, 0x3eaf,    0xb5f0, 0x7d97, 0xed59, 0x253e, 0x04a2, 0xccc5, 0x5c0b, 0x946c,
};
#endif

#endif /* crc_16_enable */

#if crc_32_enable

#endif /* crc_32_enable */

#if crc_64_enable

#endif /* crc_64_enable */

#endif /* crc_xx_table_calc_enable */

#if crc_xx_table_calc_enable

#if crc_08_enable

/* ########################################################################## */
/* #                           CRC-08 查表计算法                            # */
/* ########################################################################## */

static uint8_t crc_08_table_core(unsigned char *data, int len, int shift, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    uint8_t crc = (uint8_t)(init << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint8_t)(table[(crc ^ data_byte)] << shift);
    }
    crc = ref_out ? reverse_08(crc) : (uint8_t)(crc >> shift);
    return (uint8_t)(crc ^ xor_out);
}

static uint8_t crc_01_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 7, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_01_table_calc(crc_01_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_01_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_02_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 6, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_02_table_calc(crc_02_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_02_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_03_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 5, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_03_table_calc(crc_03_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_03_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_04_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 4, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_04_table_calc(crc_04_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_04_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_05_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 3, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_05_table_calc(crc_05_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_05_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_06_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 2, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_06_table_calc(crc_06_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_06_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_07_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 1, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_07_table_calc(crc_07_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_07_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_08_table_comm(unsigned char *data, int len, uint8_t *table, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_table_core(data, len, 0, table, init, ref_in, ref_out, xor_out);
}

uint8_t crc_08_table_calc(crc_08_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_08_table_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_08_enable */

#if crc_16_enable

/* ########################################################################## */
/* #                           CRC-16 查表计算法                            # */
/* ########################################################################## */

static uint16_t crc_16_table_core(unsigned char *data, int len, int shift, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    uint16_t crc = (uint16_t)(init << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint16_t)((table[((crc >> 8) ^ data_byte) & 0xff] << shift) ^ (crc << 8));
    }
    crc = ref_out ? reverse_16(crc) : (uint16_t)(crc >> shift);
    return (uint16_t)(crc ^ xor_out);
}

static uint16_t crc_09_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 7, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_09_table_calc(crc_09_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_09_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_10_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 6, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_10_table_calc(crc_10_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_10_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_11_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 5, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_11_table_calc(crc_11_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_11_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_12_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 4, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_12_table_calc(crc_12_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_12_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_13_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 3, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_13_table_calc(crc_13_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_13_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_14_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 2, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_14_table_calc(crc_14_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_14_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_15_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 1, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_15_table_calc(crc_15_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_15_table_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_16_table_comm(unsigned char *data, int len, uint16_t *table, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_table_core(data, len, 0, table, init, ref_in, ref_out, xor_out);
}

uint16_t crc_16_table_calc(crc_16_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        #if crc_16_poly_8005_enable
        /**
         * brief: width=16 poly=0x8005 init=0x0000 refin=1 refout=1 xorout=0x0000 check=0xbb3d residue=0x0000
         * class: attested
         * alias: CRC-16, CRC-16/ARC, CRC-16/IBM, CRC-16/LHA
         */
        case CRC_16_8005_0000_1_1_0000:
        case CRC_16_ARC:
        case CRC_16_IBM:
        case CRC_16_LHA:
        {
            poly = crc_16_table_0x8005;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0xfee8 residue=0x0000
         * class: attested
         * alias: CRC-16/UMTS, CRC-16/BUYPASS, CRC-16/VERIFONE
         */
        case CRC_16_8005_0000_0_0_0000:
        case CRC_16_UMTS:
        case CRC_16_BUYPASS:
        case CRC_16_VERIFONE:
        {
            poly = crc_16_table_0x8005;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0x0000 refin=1 refout=1 xorout=0xFFFF check=0x44c2 residue=0xb001
         * class: attested
         * alias: CRC-16/MAXIM, CRC-16/MAXIM-DOW
         */
        case CRC_16_8005_0000_1_1_FFFF:
        case CRC_16_MAXIM:
        {
            poly = crc_16_table_0x8005;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0xFFFF refin=1 refout=1 xorout=0x0000 check=0x4b37 residue=0x0000
         * class: attested
         * alias: CRC-16/MODBUS
         */
        case CRC_16_8005_FFFF_1_1_0000:
        case CRC_16_MODBUS:
        {
            poly = crc_16_table_0x8005;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0x800D refin=0 refout=0 xorout=0x0000 check=0x9ecf residue=0x0000
         * class: attested
         * alias: CRC-16/DDS-110
         */
        case CRC_16_8005_800D_0_0_0000:
        case CRC_16_DDS110:
        {
            poly = crc_16_table_0x8005;
            init = 0x800D;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0xFFFF refin=1 refout=1 xorout=0xFFFF check=0xb4c8 residue=0xb001
         * class: third-party
         * alias: CRC-16/USB
         */
        case CRC_16_8005_FFFF_1_1_FFFF:
        case CRC_16_USB:
        {
            poly = crc_16_table_0x8005;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0xaee7 residue=0x0000
         * class: third-party
         * alias: CRC-16/CMS
         */
        case CRC_16_8005_FFFF_0_0_0000:
        case CRC_16_CMS:
        {
            poly = crc_16_table_0x8005;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        #endif
        #if crc_16_poly_1021_enable
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=0 refout=0 xorout=0xFFFF check=0xd64e residue=0x1d0f
         * class: attested
         * alias: CRC-16/GENIBUS, CRC-16/DARC, CRC-16/EPC, CRC-16/EPC-C1G2, CRC-16/I-CODE
         */
        case CRC_16_1021_FFFF_0_0_FFFF:
        case CRC_16_GENIBUS:
        case CRC_16_DARC:
        case CRC_16_EPC:
        case CRC_16_EPC_C1G2:
        case CRC_16_ICODE:
        {
            poly = crc_16_table_0x1021;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x0000 refin=0 refout=0 xorout=0xFFFF check=0xce3c residue=0x1d0f
         * class: attested
         * alias: CRC-16/GSM
         */
        case CRC_16_1021_0000_0_0_FFFF:
        case CRC_16_GSM:
        {
            poly = crc_16_table_0x1021;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0x29b1 residue=0x0000
         * class: attested
         * alias: CRC-16/CCITT-FALSE, CRC-16/IBM-3740, CRC-16/AUTOSAR
         */
        case CRC_16_1021_FFFF_0_0_0000:
        case CRC_16_CCITT_FALSE:
        case CRC_16_IBM_3740:
        case CRC_16_AUTOSAR:
        {
            poly = crc_16_table_0x1021;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=1 refout=1 xorout=0xFFFF check=0x906e residue=0xf0b8
         * class: attested
         * alias: CRC-16/X-25, CRC-16/IBM-SDLC, CRC-16/ISO-HDLC, CRC-16/ISO-IEC-14443-3-B, CRC-B
         */
        case CRC_16_1021_FFFF_1_1_FFFF:
        case CRC_16_X25:
        case CRC_16_IBM_SDLC:
        case CRC_16_ISO_HDLC:
        case CRC_16_ISO_IEC_14443_3_B:
        {
            poly = crc_16_table_0x1021;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xC6C6 refin=1 refout=1 xorout=0x0000 check=0xbf05 residue=0x0000
         * class: attested
         * alias: CRC-16/ISO-IEC-14443-3-A, CRC-A
         */
        case CRC_16_1021_C6C6_1_1_0000:
        case CRC_16_ISO_IEC_14443_3_A:
        {
            poly = crc_16_table_0x1021;
            init = 0xC6C6;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x0000 refin=1 refout=1 xorout=0x0000 check=0x2189 residue=0x0000
         * class: attested
         * alias: CRC-16/CCITT, CRC-16/CCITT-TRUE, CRC-16/KERMIT, CRC-16/BLUETOOTH, CRC-16/V-41-LSB
         */
        case CRC_16_1021_0000_1_1_0000:
        case CRC_16_CCITT:
        case CRC_16_CCITT_TRUE:
        case CRC_16_KERMIT:
        case CRC_16_BLUETOOTH:
        case CRC_16_V_41_LSB:
        {
            poly = crc_16_table_0x1021;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=1 refout=1 xorout=0x0000 check=0x6f91 residue=0x0000
         * class: attested
         * alias: CRC-16/MCRF4XX
         */
        case CRC_16_1021_FFFF_1_1_0000:
        case CRC_16_MCRF4XX:
        {
            poly = crc_16_table_0x1021;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xB2AA refin=1 refout=1 xorout=0x0000 check=0x63d0 residue=0x0000
         * class: third-party
         * alias: CRC-16/RIELLO
         */
        case CRC_16_1021_B2AA_1_1_0000:
        case CRC_16_RIELLO:
        {
            poly = crc_16_table_0x1021;
            init = 0xB2AA;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x1D0F refin=0 refout=0 xorout=0x0000 check=0xe5cc residue=0x0000
         * class: attested
         * alias: CRC-16/AUG-CCITT, CRC-16/SPI-FUJITSU
         */
        case CRC_16_1021_1D0F_0_0_0000:
        case CRC_16_AUG_CCITT:
        case CRC_16_SPI_FUJITSU:
        {
            poly = crc_16_table_0x1021;
            init = 0x1D0F;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x31c3 residue=0x0000
         * class: attested
         * alias: CRC-16/XMODEM, CRC-16/ACORN, CRC-16/LTE, CRC-16/V-41-MSB, XMODEM, YMODEM, ZMODEM
         */
        case CRC_16_1021_0000_0_0_0000:
        case CRC_16_XMODEM:
        case CRC_16_YMODEM:
        case CRC_16_ZMODEM:
        case CRC_16_ACORN:
        case CRC_16_LTE:
        case CRC_16_V_41_MSB:
        {
            poly = crc_16_table_0x1021;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x89EC refin=1 refout=1 xorout=0x0000 check=0x26b1 residue=0x0000
         * class: attested
         * alias: CRC-16/TMS37157
         */
        case CRC_16_1021_89EC_1_1_0000:
        case CRC_16_TMS37157:
        {
            poly = crc_16_table_0x1021;
            init = 0x89EC;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        #endif
        #if crc_16_poly_xxxx_enable
        /**
         * brief: width=16 poly=0x0589 init=0x0000 refin=0 refout=0 xorout=0x0001 check=0x007e residue=0x0589
         * class: attested
         * alias: CRC-16/DECT-R, R-CRC-16
         */
        case CRC_16_0589_0000_0_0_0001:
        case CRC_16_DECT_R:
        {
            poly = crc_16_table_0x0589;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0001;
            break;
        }
        /**
         * brief: width=16 poly=0x0589 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x007f residue=0x0000
         * class: attested
         * alias: CRC-16/DECT-X, X-CRC-16
         */
        case CRC_16_0589_0000_0_0_0000:
        case CRC_16_DECT_X:
        {
            poly = crc_16_table_0x0589;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8bb7 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0xd0db residue=0x0000
         * class: attested
         * alias: CRC-16/T10-DIF
         */
        case CRC_16_8BB7_0000_0_0_0000:
        case CRC_16_T10_DIF:
        {
            poly = crc_16_table_0x8bb7;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x3D65 init=0x0000 refin=1 refout=1 xorout=0xFFFF check=0xea82 residue=0x66c5
         * class: confirmed
         * alias: CRC-16/DNP
         */
        case CRC_16_3D65_0000_1_1_FFFF:
        case CRC_16_DNP:
        {
            poly = crc_16_table_0x3d65;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x3d65 init=0x0000 refin=0 refout=0 xorout=0xFFFF check=0xc2b7 residue=0xa366
         * class: confirmed
         * alias: CRC-16/EN-13757
         */
        case CRC_16_3D65_0000_0_0_FFFF:
        case CRC_16_EN_13757:
        {
            poly = crc_16_table_0x3d65;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0xa097 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x0fb3 residue=0x0000
         * class: confirmed
         * alias: CRC-16/TELEDISK
         */
        case CRC_16_A097_0000_0_0_0000:
        case CRC_16_TELEDISK:
        {
            poly = crc_16_table_0xa097;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0xc867 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0x4c06 residue=0x0000
         * class: academic
         * alias: CRC-16/CDMA2000
         */
        case CRC_16_C867_FFFF_0_0_0000:
        case CRC_16_CDMA2000:
        {
            poly = crc_16_table_0xc867;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        #endif
        default:
        {
            break;
        }
    }

    return crc_16_table_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_16_enable */

#if crc_32_enable

/* ########################################################################## */
/* #                           CRC-32 查表计算法                            # */
/* ########################################################################## */

static uint32_t crc_32_table_core(unsigned char *data, int len, int shift, uint32_t *table, uint32_t init, bool ref_in, bool ref_out, uint32_t xor_out)
{
    uint32_t crc = (uint32_t)(init << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint32_t)((table[((crc >> 24) ^ data_byte) & 0xff] << shift) ^ (crc << 8));
    }
    crc = ref_out ? reverse_32(crc) : (uint32_t)(crc >> shift);
    return (uint32_t)(crc ^ xor_out);
}

static uint32_t crc_32_table_comm(unsigned char *data, int len, uint32_t *table, uint32_t init, bool ref_in, bool ref_out, uint32_t xor_out)
{
    return crc_32_table_core(data, len, 0, table, init, ref_in, ref_out, xor_out);
}

uint32_t crc_32_table_calc(crc_32_type_t type, unsigned char *data, int len)
{
    uint32_t *poly = 0;
    uint32_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint32_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_32_table_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_32_enable */

#if crc_64_enable

/* ########################################################################## */
/* #                           CRC-64 查表计算法                            # */
/* ########################################################################## */

static uint64_t crc_64_table_core(unsigned char *data, int len, int shift, uint64_t *table, uint64_t init, bool ref_in, bool ref_out, uint64_t xor_out)
{
    uint64_t crc = (uint64_t)(init << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint64_t)((table[((crc >> 56) ^ data_byte) & 0xff] << shift) ^ (crc << 8));
    }
    crc = ref_out ? reverse_64(crc) : (uint64_t)(crc >> shift);
    return (uint64_t)(crc ^ xor_out);
}

static uint64_t crc_64_table_comm(unsigned char *data, int len, uint64_t *table, uint64_t init, bool ref_in, bool ref_out, uint64_t xor_out)
{
    return crc_64_table_core(data, len, 0, table, init, ref_in, ref_out, xor_out);
}

uint64_t crc_64_table_calc(crc_64_type_t type, unsigned char *data, int len)
{
    uint64_t *poly = 0;
    uint64_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint64_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_64_table_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_64_enable */

#endif /* crc_xx_table_calc_enable */

#if crc_xx_logic_calc_enable

#if crc_08_enable

/* ########################################################################## */
/* #                           CRC-08 直接计算法                            # */
/* ########################################################################## */

static uint8_t crc_08_logic_core(unsigned char *data, int len, int shift, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    uint8_t crc = (uint8_t)(init << shift);
    poly = (uint8_t)(poly << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint8_t)(crc ^ data_byte);
        for (int i = 0; i < 8; ++i)
        {
            if ((crc & 0x80) != 0)
            {
                crc = (uint8_t)((crc << 1) ^ poly);
            }
            else
            {
                crc = (uint8_t)(crc << 1);
            }
        }
    }
    crc = ref_out ? reverse_08(crc) : (uint8_t)(crc >> shift);
    return (uint8_t)(crc ^ xor_out);
}

static uint8_t crc_01_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 7, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_01_logic_calc(crc_01_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_01_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_02_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 6, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_02_logic_calc(crc_02_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_02_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_03_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 5, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_03_logic_calc(crc_03_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_03_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_04_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 4, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_04_logic_calc(crc_04_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_04_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_05_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 3, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_05_logic_calc(crc_05_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_05_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_06_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 2, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_06_logic_calc(crc_06_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_06_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_07_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 1, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_07_logic_calc(crc_07_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_07_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint8_t crc_08_logic_comm(unsigned char *data, int len, uint8_t poly, uint8_t init, bool ref_in, bool ref_out, uint8_t xor_out)
{
    return crc_08_logic_core(data, len, 0, poly, init, ref_in, ref_out, xor_out);
}

uint8_t crc_08_logic_calc(crc_08_type_t type, unsigned char *data, int len)
{
    uint8_t *poly = 0;
    uint8_t  init = 0;
    bool     refi = 0;
    bool     refo = 0;
    uint8_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_08_logic_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_08_enable */

#if crc_16_enable

/* ########################################################################## */
/* #                           CRC-16 直接计算法                            # */
/* ########################################################################## */

static uint16_t crc_16_logic_core(unsigned char *data, int len, int shift, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    uint16_t crc = (uint16_t)(init << shift);
    poly = (uint16_t)(poly << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint16_t)(crc ^ (data_byte << 8));
        for (int i = 0; i < 8; ++i)
        {
            if ((crc & 0x8000) != 0)
            {
                crc = (uint16_t)((crc << 1) ^ poly);
            }
            else
            {
                crc = (uint16_t)(crc << 1);
            }
        }
    }
    crc = ref_out ? reverse_16(crc) : (uint16_t)(crc >> shift);
    return (uint16_t)(crc ^ xor_out);
}

static uint16_t crc_09_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 7, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_09_logic_calc(crc_09_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_09_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_10_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 6, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_10_logic_calc(crc_10_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_10_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_11_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 5, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_11_logic_calc(crc_11_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_11_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_12_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 4, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_12_logic_calc(crc_12_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_12_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_13_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 3, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_13_logic_calc(crc_13_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_13_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_14_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 2, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_14_logic_calc(crc_14_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_14_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_15_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 1, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_15_logic_calc(crc_15_type_t type, unsigned char *data, int len)
{
    uint16_t *poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_15_logic_comm(data, len, poly, init, refi, refo, xoro);
}

static uint16_t crc_16_logic_comm(unsigned char *data, int len, uint16_t poly, uint16_t init, bool ref_in, bool ref_out, uint16_t xor_out)
{
    return crc_16_logic_core(data, len, 0, poly, init, ref_in, ref_out, xor_out);
}

uint16_t crc_16_logic_calc(crc_16_type_t type, unsigned char *data, int len)
{
    uint16_t  poly = 0;
    uint16_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint16_t  xoro = 0;

    switch (type)
    {
        #if crc_16_poly_8005_enable
        /**
         * brief: width=16 poly=0x8005 init=0x0000 refin=1 refout=1 xorout=0x0000 check=0xbb3d residue=0x0000
         * class: attested
         * alias: CRC-16, CRC-16/ARC, CRC-16/IBM, CRC-16/LHA
         */
        case CRC_16_8005_0000_1_1_0000:
        case CRC_16_ARC:
        case CRC_16_IBM:
        case CRC_16_LHA:
        {
            poly = 0x8005;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0xfee8 residue=0x0000
         * class: attested
         * alias: CRC-16/UMTS, CRC-16/BUYPASS, CRC-16/VERIFONE
         */
        case CRC_16_8005_0000_0_0_0000:
        case CRC_16_UMTS:
        case CRC_16_BUYPASS:
        case CRC_16_VERIFONE:
        {
            poly = 0x8005;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0x0000 refin=1 refout=1 xorout=0xFFFF check=0x44c2 residue=0xb001
         * class: attested
         * alias: CRC-16/MAXIM, CRC-16/MAXIM-DOW
         */
        case CRC_16_8005_0000_1_1_FFFF:
        case CRC_16_MAXIM:
        {
            poly = 0x8005;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0xFFFF refin=1 refout=1 xorout=0x0000 check=0x4b37 residue=0x0000
         * class: attested
         * alias: CRC-16/MODBUS
         */
        case CRC_16_8005_FFFF_1_1_0000:
        case CRC_16_MODBUS:
        {
            poly = 0x8005;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0x800D refin=0 refout=0 xorout=0x0000 check=0x9ecf residue=0x0000
         * class: attested
         * alias: CRC-16/DDS-110
         */
        case CRC_16_8005_800D_0_0_0000:
        case CRC_16_DDS110:
        {
            poly = 0x8005;
            init = 0x800D;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0xFFFF refin=1 refout=1 xorout=0xFFFF check=0xb4c8 residue=0xb001
         * class: third-party
         * alias: CRC-16/USB
         */
        case CRC_16_8005_FFFF_1_1_FFFF:
        case CRC_16_USB:
        {
            poly = 0x8005;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x8005 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0xaee7 residue=0x0000
         * class: third-party
         * alias: CRC-16/CMS
         */
        case CRC_16_8005_FFFF_0_0_0000:
        case CRC_16_CMS:
        {
            poly = 0x8005;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        #endif
        #if crc_16_poly_1021_enable
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=0 refout=0 xorout=0xFFFF check=0xd64e residue=0x1d0f
         * class: attested
         * alias: CRC-16/GENIBUS, CRC-16/DARC, CRC-16/EPC, CRC-16/EPC-C1G2, CRC-16/I-CODE
         */
        case CRC_16_1021_FFFF_0_0_FFFF:
        case CRC_16_GENIBUS:
        case CRC_16_DARC:
        case CRC_16_EPC:
        case CRC_16_EPC_C1G2:
        case CRC_16_ICODE:
        {
            poly = 0x1021;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x0000 refin=0 refout=0 xorout=0xFFFF check=0xce3c residue=0x1d0f
         * class: attested
         * alias: CRC-16/GSM
         */
        case CRC_16_1021_0000_0_0_FFFF:
        case CRC_16_GSM:
        {
            poly = 0x1021;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0x29b1 residue=0x0000
         * class: attested
         * alias: CRC-16/CCITT-FALSE, CRC-16/IBM-3740, CRC-16/AUTOSAR
         */
        case CRC_16_1021_FFFF_0_0_0000:
        case CRC_16_CCITT_FALSE:
        case CRC_16_IBM_3740:
        case CRC_16_AUTOSAR:
        {
            poly = 0x1021;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=1 refout=1 xorout=0xFFFF check=0x906e residue=0xf0b8
         * class: attested
         * alias: CRC-16/X-25, CRC-16/IBM-SDLC, CRC-16/ISO-HDLC, CRC-16/ISO-IEC-14443-3-B, CRC-B
         */
        case CRC_16_1021_FFFF_1_1_FFFF:
        case CRC_16_X25:
        case CRC_16_IBM_SDLC:
        case CRC_16_ISO_HDLC:
        case CRC_16_ISO_IEC_14443_3_B:
        {
            poly = 0x1021;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xC6C6 refin=1 refout=1 xorout=0x0000 check=0xbf05 residue=0x0000
         * class: attested
         * alias: CRC-16/ISO-IEC-14443-3-A, CRC-A
         */
        case CRC_16_1021_C6C6_1_1_0000:
        case CRC_16_ISO_IEC_14443_3_A:
        {
            poly = 0x1021;
            init = 0xC6C6;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x0000 refin=1 refout=1 xorout=0x0000 check=0x2189 residue=0x0000
         * class: attested
         * alias: CRC-16/CCITT, CRC-16/CCITT-TRUE, CRC-16/KERMIT, CRC-16/BLUETOOTH, CRC-16/V-41-LSB
         */
        case CRC_16_1021_0000_1_1_0000:
        case CRC_16_CCITT:
        case CRC_16_CCITT_TRUE:
        case CRC_16_KERMIT:
        case CRC_16_BLUETOOTH:
        case CRC_16_V_41_LSB:
        {
            poly = 0x1021;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xFFFF refin=1 refout=1 xorout=0x0000 check=0x6f91 residue=0x0000
         * class: attested
         * alias: CRC-16/MCRF4XX
         */
        case CRC_16_1021_FFFF_1_1_0000:
        case CRC_16_MCRF4XX:
        {
            poly = 0x1021;
            init = 0xFFFF;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0xB2AA refin=1 refout=1 xorout=0x0000 check=0x63d0 residue=0x0000
         * class: third-party
         * alias: CRC-16/RIELLO
         */
        case CRC_16_1021_B2AA_1_1_0000:
        case CRC_16_RIELLO:
        {
            poly = 0x1021;
            init = 0xB2AA;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x1D0F refin=0 refout=0 xorout=0x0000 check=0xe5cc residue=0x0000
         * class: attested
         * alias: CRC-16/AUG-CCITT, CRC-16/SPI-FUJITSU
         */
        case CRC_16_1021_1D0F_0_0_0000:
        case CRC_16_AUG_CCITT:
        case CRC_16_SPI_FUJITSU:
        {
            poly = 0x1021;
            init = 0x1D0F;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x31c3 residue=0x0000
         * class: attested
         * alias: CRC-16/XMODEM, CRC-16/ACORN, CRC-16/LTE, CRC-16/V-41-MSB, XMODEM, YMODEM, ZMODEM
         */
        case CRC_16_1021_0000_0_0_0000:
        case CRC_16_XMODEM:
        case CRC_16_YMODEM:
        case CRC_16_ZMODEM:
        case CRC_16_ACORN:
        case CRC_16_LTE:
        case CRC_16_V_41_MSB:
        {
            poly = 0x1021;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x1021 init=0x89EC refin=1 refout=1 xorout=0x0000 check=0x26b1 residue=0x0000
         * class: attested
         * alias: CRC-16/TMS37157
         */
        case CRC_16_1021_89EC_1_1_0000:
        case CRC_16_TMS37157:
        {
            poly = 0x1021;
            init = 0x89EC;
            refi = 1;
            refo = 1;
            xoro = 0x0000;
            break;
        }
        #endif
        #if crc_16_poly_xxxx_enable
        /**
         * brief: width=16 poly=0x0589 init=0x0000 refin=0 refout=0 xorout=0x0001 check=0x007e residue=0x0589
         * class: attested
         * alias: CRC-16/DECT-R, R-CRC-16
         */
        case CRC_16_0589_0000_0_0_0001:
        case CRC_16_DECT_R:
        {
            poly = 0x0589;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0001;
            break;
        }
        /**
         * brief: width=16 poly=0x0589 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x007f residue=0x0000
         * class: attested
         * alias: CRC-16/DECT-X, X-CRC-16
         */
        case CRC_16_0589_0000_0_0_0000:
        case CRC_16_DECT_X:
        {
            poly = 0x0589;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x8bb7 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0xd0db residue=0x0000
         * class: attested
         * alias: CRC-16/T10-DIF
         */
        case CRC_16_8BB7_0000_0_0_0000:
        case CRC_16_T10_DIF:
        {
            poly = 0x8bb7;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0x3D65 init=0x0000 refin=1 refout=1 xorout=0xFFFF check=0xea82 residue=0x66c5
         * class: confirmed
         * alias: CRC-16/DNP
         */
        case CRC_16_3D65_0000_1_1_FFFF:
        case CRC_16_DNP:
        {
            poly = 0x3d65;
            init = 0x0000;
            refi = 1;
            refo = 1;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0x3d65 init=0x0000 refin=0 refout=0 xorout=0xFFFF check=0xc2b7 residue=0xa366
         * class: confirmed
         * alias: CRC-16/EN-13757
         */
        case CRC_16_3D65_0000_0_0_FFFF:
        case CRC_16_EN_13757:
        {
            poly = 0x3d65;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0xFFFF;
            break;
        }
        /**
         * brief: width=16 poly=0xa097 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x0fb3 residue=0x0000
         * class: confirmed
         * alias: CRC-16/TELEDISK
         */
        case CRC_16_A097_0000_0_0_0000:
        case CRC_16_TELEDISK:
        {
            poly = 0xa097;
            init = 0x0000;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        /**
         * brief: width=16 poly=0xc867 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0x4c06 residue=0x0000
         * class: academic
         * alias: CRC-16/CDMA2000
         */
        case CRC_16_C867_FFFF_0_0_0000:
        case CRC_16_CDMA2000:
        {
            poly = 0xc867;
            init = 0xFFFF;
            refi = 0;
            refo = 0;
            xoro = 0x0000;
            break;
        }
        #endif
        default:
        {
            break;
        }
    }

    return crc_16_logic_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_16_enable */

#if crc_32_enable

/* ########################################################################## */
/* #                           CRC-32 直接计算法                            # */
/* ########################################################################## */

static uint32_t crc_32_logic_core(unsigned char *data, int len, int shift, uint32_t poly, uint32_t init, bool ref_in, bool ref_out, uint32_t xor_out)
{
    uint32_t crc = (uint32_t)(init << shift);
    poly = (uint32_t)(poly << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint32_t)(crc ^ (data_byte << 24));
        for (int i = 0; i < 8; ++i)
        {
            if ((crc & 0x80000000) != 0)
            {
                crc = (uint32_t)((crc << 1) ^ poly);
            }
            else
            {
                crc = (uint32_t)(crc << 1);
            }
        }
    }
    crc = ref_out ? reverse_32(crc) : (uint32_t)(crc >> shift);
    return (uint32_t)(crc ^ xor_out);
}

static uint32_t crc_32_logic_comm(unsigned char *data, int len, uint32_t poly, uint32_t init, bool ref_in, bool ref_out, uint32_t xor_out)
{
    return crc_32_logic_core(data, len, 0, poly, init, ref_in, ref_out, xor_out);
}

uint32_t crc_32_logic_calc(crc_32_type_t type, unsigned char *data, int len)
{
    uint32_t *poly = 0;
    uint32_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint32_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_32_logic_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_32_enable */

#if crc_64_enable

/* ########################################################################## */
/* #                           CRC-64 直接计算法                            # */
/* ########################################################################## */

static uint64_t crc_64_logic_core(unsigned char *data, int len, int shift, uint64_t poly, uint64_t init, bool ref_in, bool ref_out, uint64_t xor_out)
{
    uint64_t crc = (uint64_t)(init << shift);
    poly = (uint64_t)(poly << shift);
    unsigned char data_byte;

    for (int i = 0; i < len; ++i)
    {
        data_byte = ref_in ? reverse_08(data[i]) : data[i];
        crc = (uint64_t)(crc ^ (data_byte << 56));
        for (int i = 0; i < 8; ++i)
        {
            if ((crc & 0x8000000000000000) != 0)
            {
                crc = (uint64_t)((crc << 1) ^ poly);
            }
            else
            {
                crc = (uint64_t)(crc << 1);
            }
        }
    }
    crc = ref_out ? reverse_64(crc) : (uint64_t)(crc >> shift);
    return (uint64_t)(crc ^ xor_out);
}

static uint64_t crc_64_logic_comm(unsigned char *data, int len, uint64_t poly, uint64_t init, bool ref_in, bool ref_out, uint64_t xor_out)
{
    return crc_64_logic_core(data, len, 0, poly, init, ref_in, ref_out, xor_out);
}

uint64_t crc_64_logic_calc(crc_64_type_t type, unsigned char *data, int len)
{
    uint64_t *poly = 0;
    uint64_t  init = 0;
    bool      refi = 0;
    bool      refo = 0;
    uint64_t  xoro = 0;

    switch (type)
    {
        default:
        {
            break;
        }
    }

    return crc_64_logic_comm(data, len, poly, init, refi, refo, xoro);
}

#endif /* crc_64_enable */

#endif /* crc_xx_logic_calc_enable */

int crc_test(void)
{
    unsigned char buf[] = "123456789";
    int len = 9;
    int crc = 0;
    int ret = 0;
    (void)buf;
    (void)len;
    (void)crc;

    #if crc_xx_table_calc_enable

    #if crc_08_enable

    #endif /* crc_08_enable */

    #if crc_16_enable
    #if crc_16_poly_8005_enable
    ret |= (crc = crc_16_table_calc(CRC_16_8005_0000_1_1_0000, buf, len)) != 0xbb3d;
    ret |= (crc = crc_16_table_calc(CRC_16_8005_0000_0_0_0000, buf, len)) != 0xfee8;
    ret |= (crc = crc_16_table_calc(CRC_16_8005_0000_1_1_FFFF, buf, len)) != 0x44c2;
    ret |= (crc = crc_16_table_calc(CRC_16_8005_FFFF_1_1_0000, buf, len)) != 0x4b37;
    ret |= (crc = crc_16_table_calc(CRC_16_8005_800D_0_0_0000, buf, len)) != 0x9ecf;
    ret |= (crc = crc_16_table_calc(CRC_16_8005_FFFF_1_1_FFFF, buf, len)) != 0xb4c8;
    ret |= (crc = crc_16_table_calc(CRC_16_8005_FFFF_0_0_0000, buf, len)) != 0xaee7;
    #endif
    #if crc_16_poly_1021_enable
    ret |= (crc = crc_16_table_calc(CRC_16_1021_FFFF_0_0_FFFF, buf, len)) != 0xd64e;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_0000_0_0_FFFF, buf, len)) != 0xce3c;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_FFFF_0_0_0000, buf, len)) != 0x29b1;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_FFFF_1_1_FFFF, buf, len)) != 0x906e;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_C6C6_1_1_0000, buf, len)) != 0xbf05;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_0000_1_1_0000, buf, len)) != 0x2189;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_FFFF_1_1_0000, buf, len)) != 0x6f91;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_B2AA_1_1_0000, buf, len)) != 0x63d0;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_1D0F_0_0_0000, buf, len)) != 0xe5cc;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_0000_0_0_0000, buf, len)) != 0x31c3;
    ret |= (crc = crc_16_table_calc(CRC_16_1021_89EC_1_1_0000, buf, len)) != 0x26b1;
    #endif
    #if crc_16_poly_xxxx_enable
    ret |= (crc = crc_16_table_calc(CRC_16_0589_0000_0_0_0001, buf, len)) != 0x007e;
    ret |= (crc = crc_16_table_calc(CRC_16_0589_0000_0_0_0000, buf, len)) != 0x007f;
    ret |= (crc = crc_16_table_calc(CRC_16_8BB7_0000_0_0_0000, buf, len)) != 0xd0db;
    ret |= (crc = crc_16_table_calc(CRC_16_3D65_0000_1_1_FFFF, buf, len)) != 0xea82;
    ret |= (crc = crc_16_table_calc(CRC_16_3D65_0000_0_0_FFFF, buf, len)) != 0xc2b7;
    ret |= (crc = crc_16_table_calc(CRC_16_A097_0000_0_0_0000, buf, len)) != 0x0fb3;
    ret |= (crc = crc_16_table_calc(CRC_16_C867_FFFF_0_0_0000, buf, len)) != 0x4c06;
    #endif
    #endif /* crc_16_enable */

    #if crc_32_enable

    #endif /* crc_32_enable */

    #if crc_64_enable

    #endif /* crc_64_enable */

    #endif /* crc_xx_table_calc_enable */

    #if crc_xx_logic_calc_enable

    #if crc_08_enable

    #endif /* crc_08_enable */

    #if crc_16_enable
    #if crc_16_poly_8005_enable
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_0000_1_1_0000, buf, len)) != 0xbb3d;
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_0000_0_0_0000, buf, len)) != 0xfee8;
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_0000_1_1_FFFF, buf, len)) != 0x44c2;
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_FFFF_1_1_0000, buf, len)) != 0x4b37;
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_800D_0_0_0000, buf, len)) != 0x9ecf;
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_FFFF_1_1_FFFF, buf, len)) != 0xb4c8;
    ret |= (crc = crc_16_logic_calc(CRC_16_8005_FFFF_0_0_0000, buf, len)) != 0xaee7;
    #endif
    #if crc_16_poly_1021_enable
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_FFFF_0_0_FFFF, buf, len)) != 0xd64e;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_0000_0_0_FFFF, buf, len)) != 0xce3c;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_FFFF_0_0_0000, buf, len)) != 0x29b1;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_FFFF_1_1_FFFF, buf, len)) != 0x906e;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_C6C6_1_1_0000, buf, len)) != 0xbf05;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_0000_1_1_0000, buf, len)) != 0x2189;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_FFFF_1_1_0000, buf, len)) != 0x6f91;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_B2AA_1_1_0000, buf, len)) != 0x63d0;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_1D0F_0_0_0000, buf, len)) != 0xe5cc;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_0000_0_0_0000, buf, len)) != 0x31c3;
    ret |= (crc = crc_16_logic_calc(CRC_16_1021_89EC_1_1_0000, buf, len)) != 0x26b1;
    #endif
    #if crc_16_poly_xxxx_enable
    ret |= (crc = crc_16_logic_calc(CRC_16_0589_0000_0_0_0001, buf, len)) != 0x007e;
    ret |= (crc = crc_16_logic_calc(CRC_16_0589_0000_0_0_0000, buf, len)) != 0x007f;
    ret |= (crc = crc_16_logic_calc(CRC_16_8BB7_0000_0_0_0000, buf, len)) != 0xd0db;
    ret |= (crc = crc_16_logic_calc(CRC_16_3D65_0000_1_1_FFFF, buf, len)) != 0xea82;
    ret |= (crc = crc_16_logic_calc(CRC_16_3D65_0000_0_0_FFFF, buf, len)) != 0xc2b7;
    ret |= (crc = crc_16_logic_calc(CRC_16_A097_0000_0_0_0000, buf, len)) != 0x0fb3;
    ret |= (crc = crc_16_logic_calc(CRC_16_C867_FFFF_0_0_0000, buf, len)) != 0x4c06;
    #endif
    #endif /* crc_16_enable */

    #if crc_32_enable

    #endif /* crc_32_enable */

    #if crc_64_enable

    #endif /* crc_64_enable */

    #endif /* crc_xx_logic_calc_enable */

    return ret;
}
