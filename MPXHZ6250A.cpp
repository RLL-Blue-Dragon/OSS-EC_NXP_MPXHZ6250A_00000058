// License       : License.txt
// Specifications: Spec-MPXHZ6250A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXHZ6250A.cpp
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MPXHZ6250A.h"

#if     iMPXHZ6250A_ma == iSMA                          // Simple moving average filter
static float32 MPXHZ6250A_sma_buf[iMPXHZ6250A_SMA_num];
static sma_f32_t MPXHZ6250A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMPXHZ6250A_SMA_num ,                           // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MPXHZ6250A_sma_buf[0]                          // buffer
};

#elif   iMPXHZ6250A_ma == iEMA                          // Exponential moving average filter
static ema_f32_t MPXHZ6250A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMPXHZ6250A_EMA_K                               // Exponential smoothing factor 
};

#elif   iMPXHZ6250A_ma == iWMA                          // Weighted moving average filter
static float32 MPXHZ6250A_wma_buf[iMPXHZ6250A_WMA_num];
static wma_f32_t MPXHZ6250A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMPXHZ6250A_WMA_num ,                           // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMPXHZ6250A_WMA_num * (iMPXHZ6250A_WMA_num + 1)/2 , // kn sum
        &MPXHZ6250A_wma_buf[0]                          // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MPXHZ6250A =
{
        iMPXHZ6250A             ,
        iMPXHZ6250A_pin         ,
        iMPXHZ6250A_xoff        ,
        iMPXHZ6250A_yoff        ,
        iMPXHZ6250A_gain        ,
        iMPXHZ6250A_max         ,
        iMPXHZ6250A_min         ,
        iMPXHZ6250A_ma          ,
        
#if     iMPXHZ6250A_ma == iSMA                          // Simple moving average filter
        &MPXHZ6250A_Phy_SMA     ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMPXHZ6250A_ma == iEMA                          // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MPXHZ6250A_Phy_EMA     ,
        (wma_f32_t*)iDummy_adr
#elif   iMPXHZ6250A_ma == iWMA                          // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MPXHZ6250A_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
