/**
  ******************************************************************************
  * Copyright © 2023 刘汲桐. All rights reserved. https://sulfurandcu.github.io/
  ******************************************************************************
  * Note :
  ******************************************************************************
  * 2023-09-09  sulfurandcu@gmail.com   first release (1.0.0)
  ******************************************************************************
  */

#ifndef __crc_cyclic_redundancy_check_h__
#define __crc_cyclic_redundancy_check_h__

#include "crc_conf.h"

#include <stdint.h>
#include <stdbool.h>

#ifndef crc_xx_table_calc_enable
#define crc_xx_table_calc_enable        1                   /* 查表计算法 */
#endif
#ifndef crc_xx_logic_calc_enable
#define crc_xx_logic_calc_enable        0                   /* 直接计算法 */
#endif

#ifndef crc_08_enable
#define crc_08_enable                   0
#endif
#ifndef crc_16_enable
#define crc_16_enable                   1
#endif
#ifndef crc_32_enable
#define crc_32_enable                   0
#endif
#ifndef crc_64_enable
#define crc_64_enable                   0
#endif

#ifndef crc_16_poly_8005_enable
#define crc_16_poly_8005_enable         1
#endif
#ifndef crc_16_poly_1021_enable
#define crc_16_poly_1021_enable         1
#endif
#ifndef crc_16_poly_xxxx_enable
#define crc_16_poly_xxxx_enable         0
#endif

int crc_test(void);

#if crc_08_enable
typedef enum crc_01_type_t
{
    CRC_01,
} crc_01_type_t;

typedef enum crc_02_type_t
{
    CRC_02,
} crc_02_type_t;

typedef enum crc_03_type_t
{
    CRC_03,
} crc_03_type_t;

typedef enum crc_04_type_t
{
    CRC_04,
} crc_04_type_t;

typedef enum crc_05_type_t
{
    CRC_05,
} crc_05_type_t;

typedef enum crc_06_type_t
{
    CRC_06,
} crc_06_type_t;

typedef enum crc_07_type_t
{
    CRC_07,
} crc_07_type_t;

typedef enum crc_08_type_t
{
    CRC_08,
} crc_08_type_t;
#endif /* crc_08_enable */

#if crc_16_enable
typedef enum crc_09_type_t
{
    CRC_09,
} crc_09_type_t;

typedef enum crc_10_type_t
{
    CRC_10,
} crc_10_type_t;

typedef enum crc_11_type_t
{
    CRC_11,
} crc_11_type_t;

typedef enum crc_12_type_t
{
    CRC_12,
} crc_12_type_t;

typedef enum crc_13_type_t
{
    CRC_13,
} crc_13_type_t;

typedef enum crc_14_type_t
{
    CRC_14,
} crc_14_type_t;

typedef enum crc_15_type_t
{
    CRC_15,
} crc_15_type_t;

typedef enum crc_16_type_t
{
    #if crc_16_poly_8005_enable
    /**
     * brief: width=16 poly=0x8005 init=0x0000 refin=1 refout=1 xorout=0x0000 check=0xbb3d residue=0x0000
     * class: attested
     * alias: CRC-16, CRC-16/ARC, CRC-16/IBM, CRC-16/LHA
     */
    CRC_16_8005_0000_1_1_0000, // check=0xbb3d
    CRC_16_ARC,
    CRC_16_IBM,
    CRC_16_LHA,
    /**
     * brief: width=16 poly=0x8005 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0xfee8 residue=0x0000
     * class: attested
     * alias: CRC-16/UMTS, CRC-16/BUYPASS, CRC-16/VERIFONE
     */
    CRC_16_8005_0000_0_0_0000, // check=0xfee8
    CRC_16_UMTS,
    CRC_16_BUYPASS,
    CRC_16_VERIFONE,
    /**
     * brief: width=16 poly=0x8005 init=0x0000 refin=1 refout=1 xorout=0xFFFF check=0x44c2 residue=0xb001
     * class: attested
     * alias: CRC-16/MAXIM, CRC-16/MAXIM-DOW
     */
    CRC_16_8005_0000_1_1_FFFF, // check=0x44c2
    CRC_16_MAXIM,
    /**
     * brief: width=16 poly=0x8005 init=0xFFFF refin=1 refout=1 xorout=0x0000 check=0x4b37 residue=0x0000
     * class: attested
     * alias: CRC-16/MODBUS
     */
    CRC_16_8005_FFFF_1_1_0000, // check=0x4b37
    CRC_16_MODBUS,
    /**
     * brief: width=16 poly=0x8005 init=0x800D refin=0 refout=0 xorout=0x0000 check=0x9ecf residue=0x0000
     * class: attested
     * alias: CRC-16/DDS-110
     */
    CRC_16_8005_800D_0_0_0000, // check=0x9ecf
    CRC_16_DDS110,
    /**
     * brief: width=16 poly=0x8005 init=0xFFFF refin=1 refout=1 xorout=0xFFFF check=0xb4c8 residue=0xb001
     * class: third-party
     * alias: CRC-16/USB
     */
    CRC_16_8005_FFFF_1_1_FFFF, // check=0xb4c8
    CRC_16_USB,
    /**
     * brief: width=16 poly=0x8005 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0xaee7 residue=0x0000
     * class: third-party
     * alias: CRC-16/CMS
     */
    CRC_16_8005_FFFF_0_0_0000, // check=0xaee7
    CRC_16_CMS,
    #endif
    #if crc_16_poly_1021_enable
    /**
     * brief: width=16 poly=0x1021 init=0xFFFF refin=0 refout=0 xorout=0xFFFF check=0xd64e residue=0x1d0f
     * class: attested
     * alias: CRC-16/GENIBUS, CRC-16/DARC, CRC-16/EPC, CRC-16/EPC-C1G2, CRC-16/I-CODE
     */
    CRC_16_1021_FFFF_0_0_FFFF, // check=0xd64e
    CRC_16_GENIBUS,
    CRC_16_DARC,
    CRC_16_EPC,
    CRC_16_EPC_C1G2,
    CRC_16_ICODE,
    /**
     * brief: width=16 poly=0x1021 init=0x0000 refin=0 refout=0 xorout=0xFFFF check=0xce3c residue=0x1d0f
     * class: attested
     * alias: CRC-16/GSM
     */
    CRC_16_1021_0000_0_0_FFFF, // check=0xce3c
    CRC_16_GSM,
    /**
     * brief: width=16 poly=0x1021 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0x29b1 residue=0x0000
     * class: attested
     * alias: CRC-16/CCITT-FALSE, CRC-16/IBM-3740, CRC-16/AUTOSAR
     */
    CRC_16_1021_FFFF_0_0_0000, // check=0x29b1
    CRC_16_CCITT_FALSE,
    CRC_16_IBM_3740,
    CRC_16_AUTOSAR,
    /**
     * brief: width=16 poly=0x1021 init=0xFFFF refin=1 refout=1 xorout=0xFFFF check=0x906e residue=0xf0b8
     * class: attested
     * alias: CRC-16/X-25, CRC-16/IBM-SDLC, CRC-16/ISO-HDLC, CRC-16/ISO-IEC-14443-3-B, CRC-B
     */
    CRC_16_1021_FFFF_1_1_FFFF, // check=0x906e
    CRC_16_X25,
    CRC_16_IBM_SDLC,
    CRC_16_ISO_HDLC,
    CRC_16_ISO_IEC_14443_3_B,
    /**
     * brief: width=16 poly=0x1021 init=0xC6C6 refin=1 refout=1 xorout=0x0000 check=0xbf05 residue=0x0000
     * class: attested
     * alias: CRC-16/ISO-IEC-14443-3-A, CRC-A
     */
    CRC_16_1021_C6C6_1_1_0000, // check=0xbf05
    CRC_16_ISO_IEC_14443_3_A,
    /**
     * brief: width=16 poly=0x1021 init=0x0000 refin=1 refout=1 xorout=0x0000 check=0x2189 residue=0x0000
     * class: attested
     * alias: CRC-16/CCITT, CRC-16/CCITT-TRUE, CRC-16/KERMIT, CRC-16/BLUETOOTH, CRC-16/V-41-LSB
     */
    CRC_16_1021_0000_1_1_0000, // check=0x2189
    CRC_16_CCITT,
    CRC_16_CCITT_TRUE,
    CRC_16_KERMIT,
    CRC_16_BLUETOOTH,
    CRC_16_V_41_LSB,
    /**
     * brief: width=16 poly=0x1021 init=0xFFFF refin=1 refout=1 xorout=0x0000 check=0x6f91 residue=0x0000
     * class: attested
     * alias: CRC-16/MCRF4XX
     */
    CRC_16_1021_FFFF_1_1_0000, // check=0x6f91
    CRC_16_MCRF4XX,
    /**
     * brief: width=16 poly=0x1021 init=0xB2AA refin=1 refout=1 xorout=0x0000 check=0x63d0 residue=0x0000
     * class: third-party
     * alias: CRC-16/RIELLO
     */
    CRC_16_1021_B2AA_1_1_0000, // check=0x63d0
    CRC_16_RIELLO,
    /**
     * brief: width=16 poly=0x1021 init=0x1D0F refin=0 refout=0 xorout=0x0000 check=0xe5cc residue=0x0000
     * class: attested
     * alias: CRC-16/AUG-CCITT, CRC-16/SPI-FUJITSU
     */
    CRC_16_1021_1D0F_0_0_0000, // check=0xe5cc
    CRC_16_AUG_CCITT,
    CRC_16_SPI_FUJITSU,
    /**
     * brief: width=16 poly=0x1021 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x31c3 residue=0x0000
     * class: attested
     * alias: CRC-16/XMODEM, CRC-16/ACORN, CRC-16/LTE, CRC-16/V-41-MSB, XMODEM, YMODEM, ZMODEM
     */
    CRC_16_1021_0000_0_0_0000, // check=0x31c3
    CRC_16_XMODEM,
    CRC_16_YMODEM,
    CRC_16_ZMODEM,
    CRC_16_ACORN,
    CRC_16_LTE,
    CRC_16_V_41_MSB,
    /**
     * brief: width=16 poly=0x1021 init=0x89EC refin=1 refout=1 xorout=0x0000 check=0x26b1 residue=0x0000
     * class: attested
     * alias: CRC-16/TMS37157
     */
    CRC_16_1021_89EC_1_1_0000, // check=0x26b1
    CRC_16_TMS37157,
    #endif
    #if crc_16_poly_xxxx_enable
    /**
     * brief: width=16 poly=0x0589 init=0x0000 refin=0 refout=0 xorout=0x0001 check=0x007e residue=0x0589
     * class: attested
     * alias: CRC-16/DECT-R, R-CRC-16
     */
    CRC_16_0589_0000_0_0_0001, // check=0x007e
    CRC_16_DECT_R,
    /**
     * brief: width=16 poly=0x0589 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x007f residue=0x0000
     * class: attested
     * alias: CRC-16/DECT-X, X-CRC-16
     */
    CRC_16_0589_0000_0_0_0000, // check=0x007f
    CRC_16_DECT_X,
    /**
     * brief: width=16 poly=0x8bb7 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0xd0db residue=0x0000
     * class: attested
     * alias: CRC-16/T10-DIF
     */
    CRC_16_8BB7_0000_0_0_0000, // check=0xd0db
    CRC_16_T10_DIF,
    /**
     * brief: width=16 poly=0x3D65 init=0x0000 refin=1 refout=1 xorout=0xFFFF check=0xea82 residue=0x66c5
     * class: confirmed
     * alias: CRC-16/DNP
     */
    CRC_16_3D65_0000_1_1_FFFF, // check=0xea82
    CRC_16_DNP,
    /**
     * brief: width=16 poly=0x3d65 init=0x0000 refin=0 refout=0 xorout=0xFFFF check=0xc2b7 residue=0xa366
     * class: confirmed
     * alias: CRC-16/EN-13757
     */
    CRC_16_3D65_0000_0_0_FFFF, // check=0xc2b7
    CRC_16_EN_13757,
    /**
     * brief: width=16 poly=0xa097 init=0x0000 refin=0 refout=0 xorout=0x0000 check=0x0fb3 residue=0x0000
     * class: confirmed
     * alias: CRC-16/TELEDISK
     */
    CRC_16_A097_0000_0_0_0000, // check=0x0fb3
    CRC_16_TELEDISK,
    /**
     * brief: width=16 poly=0xc867 init=0xFFFF refin=0 refout=0 xorout=0x0000 check=0x4c06 residue=0x0000
     * class: academic
     * alias: CRC-16/CDMA2000
     */
    CRC_16_C867_FFFF_0_0_0000, // check=0x4c06
    CRC_16_CDMA2000,
    #endif
} crc_16_type_t;
#endif /* crc_16_enable */

#if crc_32_enable
typedef enum crc_32_type_t
{
    CRC_32,
} crc_32_type_t;
#endif /* crc_32_enable */

#if crc_64_enable
typedef enum crc_64_type_t
{
    CRC_64,
} crc_64_type_t;
#endif /* crc_64_enable */


#if crc_xx_table_calc_enable /* 查表计算法 */

#if crc_08_enable
uint8_t crc_01_table_calc(crc_01_type_t type, unsigned char *data, int len);
uint8_t crc_02_table_calc(crc_02_type_t type, unsigned char *data, int len);
uint8_t crc_03_table_calc(crc_03_type_t type, unsigned char *data, int len);
uint8_t crc_04_table_calc(crc_04_type_t type, unsigned char *data, int len);
uint8_t crc_05_table_calc(crc_05_type_t type, unsigned char *data, int len);
uint8_t crc_06_table_calc(crc_06_type_t type, unsigned char *data, int len);
uint8_t crc_07_table_calc(crc_07_type_t type, unsigned char *data, int len);
uint8_t crc_08_table_calc(crc_08_type_t type, unsigned char *data, int len);
#endif /* crc_08_enable */

#if crc_16_enable
uint16_t crc_09_table_calc(crc_09_type_t type, unsigned char *data, int len);
uint16_t crc_10_table_calc(crc_10_type_t type, unsigned char *data, int len);
uint16_t crc_11_table_calc(crc_11_type_t type, unsigned char *data, int len);
uint16_t crc_12_table_calc(crc_12_type_t type, unsigned char *data, int len);
uint16_t crc_13_table_calc(crc_13_type_t type, unsigned char *data, int len);
uint16_t crc_14_table_calc(crc_14_type_t type, unsigned char *data, int len);
uint16_t crc_15_table_calc(crc_15_type_t type, unsigned char *data, int len);
uint16_t crc_16_table_calc(crc_16_type_t type, unsigned char *data, int len);
#endif /* crc_16_enable */

#if crc_32_enable
uint32_t crc_32_table_calc(crc_32_type_t type, unsigned char *data, int len);
#endif /* crc_32_enable */

#if crc_64_enable
uint64_t crc_64_table_calc(crc_64_type_t type, unsigned char *data, int len);
#endif /* crc_64_enable */

#endif /* crc_xx_table_calc_enable */

#if crc_xx_logic_calc_enable /* 直接计算法 */

#if crc_08_enable
uint8_t crc_01_logic_calc(crc_01_type_t type, unsigned char *data, int len);
uint8_t crc_02_logic_calc(crc_02_type_t type, unsigned char *data, int len);
uint8_t crc_03_logic_calc(crc_03_type_t type, unsigned char *data, int len);
uint8_t crc_04_logic_calc(crc_04_type_t type, unsigned char *data, int len);
uint8_t crc_05_logic_calc(crc_05_type_t type, unsigned char *data, int len);
uint8_t crc_06_logic_calc(crc_06_type_t type, unsigned char *data, int len);
uint8_t crc_07_logic_calc(crc_07_type_t type, unsigned char *data, int len);
uint8_t crc_08_logic_calc(crc_08_type_t type, unsigned char *data, int len);
#endif /* crc_08_enable */

#if crc_16_enable
uint16_t crc_09_logic_calc(crc_09_type_t type, unsigned char *data, int len);
uint16_t crc_10_logic_calc(crc_10_type_t type, unsigned char *data, int len);
uint16_t crc_11_logic_calc(crc_11_type_t type, unsigned char *data, int len);
uint16_t crc_12_logic_calc(crc_12_type_t type, unsigned char *data, int len);
uint16_t crc_13_logic_calc(crc_13_type_t type, unsigned char *data, int len);
uint16_t crc_14_logic_calc(crc_14_type_t type, unsigned char *data, int len);
uint16_t crc_15_logic_calc(crc_15_type_t type, unsigned char *data, int len);
uint16_t crc_16_logic_calc(crc_16_type_t type, unsigned char *data, int len);
#endif /* crc_16_enable */

#if crc_32_enable
uint32_t crc_32_logic_calc(crc_32_type_t type, unsigned char *data, int len);
#endif /* crc_32_enable */

#if crc_64_enable
uint64_t crc_64_logic_calc(crc_64_type_t type, unsigned char *data, int len);
#endif /* crc_64_enable */

#endif /* crc_xx_logic_calc_enable */

#endif /* __crc_cyclic_redundancy_check_h__ */
