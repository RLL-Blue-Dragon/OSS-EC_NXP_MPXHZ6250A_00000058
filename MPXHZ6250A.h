// License       : License.txt
// Specifications: Spec-MPXHZ6250A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXHZ6250A.h
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MPXHZ6250A_H__
#define __MPXHZ6250A_H__

#include "user_define.h"

// Components number
#define iMPXHZ6250A             120U                    // NXP MPXHZ6250A

// MPX5999D System Parts definitions
#define iMPXHZ6250A_xoff        ( -0.040F*iADC_vdd )    // X offset [V]
#define iMPXHZ6250A_yoff        0.0F                    // Y offset [kPa]
#define iMPXHZ6250A_gain        ( 0.0040F*iADC_vdd )    // Gain [V/kPa]
#define iMPXHZ6250A_max         250.0F                  // Pressure Max [kPa]
#define iMPXHZ6250A_min         20.0F                   // Pressure Min [kPa]

extern const tbl_adc_t tbl_MPXHZ6250A;

#endif /*__MPXHZ6250A_H__*/
