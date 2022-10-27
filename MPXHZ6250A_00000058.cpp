// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXHZ6250A_00000058.cpp
// BSL              : 00000058
// Model number     : NXP MPXHZ6250A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "MPXHZ6250A.h"

AnalogIn MPXHZ6250A_adc( iMPXHZ6250A_pin , iVref );     // AnalogIn object

// Main Function
pp2ap_adc_t MPXHZ6250A_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( MPXHZ6250A_adc , tbl_MPXHZ6250A );
        return( res );
}
