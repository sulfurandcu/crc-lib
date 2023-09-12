/**
  ******************************************************************************
  * Copyright © 2023 刘汲桐. All rights reserved. https://sulfurandcu.github.io/
  ******************************************************************************
  * Note :
  ******************************************************************************
  * 2023-09-09  sulfurandcu@gmail.com   first release (1.0.0)
  ******************************************************************************
  */

#ifndef __crc_conf_h__
#define __crc_conf_h__

#define crc_xx_table_calc_enable        1                   /* 查表计算法 */
#define crc_xx_logic_calc_enable        0                   /* 直接计算法 */

#define crc_08_enable                   0
#define crc_16_enable                   1
#define crc_32_enable                   0
#define crc_64_enable                   0

#define crc_16_poly_8005_enable         1
#define crc_16_poly_1021_enable         1
#define crc_16_poly_xxxx_enable         0

#endif /* __crc_conf_h__ */
