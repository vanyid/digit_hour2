/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: outd_main.c
 *  author:   vanyid
 *  create date: 2011.03.09.
 *
 * ******************************************************************************************** */

#include "outd_imp.h"
#include "outd_exp.h"

/***********************************************************************************************
 *                                          GLOBAL VARIABLE
 ***********************************************************************************************/

volatile tDigit Digit[MAX_DIGIT_NUM];

tUI8 counter = 0;     // digit counter

/***********************************************************************************************
 *                                          LOCAL VARIABLE
 ***********************************************************************************************/
static const tUI8 SegmentEncode[MAX_SEGMENT_NUM] =
    {
//        pgfedcba
        0b00111111,   // num_0
        0b00000110,   // num_1
        0b01011011,   // num_2
        0b01001111,   // num_3
        0b01100110,   // num_4
        0b01101101,   // num_5
        0b01111101,   // num_6
        0b00000111,   // num_7
        0b01111111,   // num_8
        0b01101111,   // num_9
        0b01110111,   // num_a
        0b01111100,   // num_b
        0b00111001,   // num_c
        0b01011110,   // num_d
        0b01111001,   // num_e
        0b01110001,   // num_f
        0b00000001,   // seg_a
        0b00000010,   // seg_b
        0b00000100,   // seg_c
        0b00001000,   // seg_d
        0b00010000,   // seg_e
        0b00100000,   // seg_f
        0b01000000,   // seg_g
        0b00000000,   // blank
    };

/***********************************************************************************************
 *                                           FUNCTIONS
 ***********************************************************************************************/
static void Update_Digit(tUI8 id)
{
  DIGIT_PIN_0 = (tUI8)(0 == id) & 0x01;
  DIGIT_PIN_1 = (tUI8)(1 == id) & 0x01;
  DIGIT_PIN_2 = (tUI8)(2 == id) & 0x01;
  DIGIT_PIN_3 = (tUI8)(3 == id) & 0x01;
}

static void Update_Segment(eDigit id, tBOOL dot)
{
  if (id >= MAX_SEGMENT_NUM) { id = blank; }
  SEGMENT_PIN_A   = (SegmentEncode[(tUI8)id] >> 0) & 0x01;
  SEGMENT_PIN_B   = (SegmentEncode[(tUI8)id] >> 1) & 0x01;
  SEGMENT_PIN_C   = (SegmentEncode[(tUI8)id] >> 2) & 0x01;
  SEGMENT_PIN_D   = (SegmentEncode[(tUI8)id] >> 3) & 0x01;
  SEGMENT_PIN_E   = (SegmentEncode[(tUI8)id] >> 4) & 0x01;
  SEGMENT_PIN_F   = (SegmentEncode[(tUI8)id] >> 5) & 0x01;
  SEGMENT_PIN_G   = (SegmentEncode[(tUI8)id] >> 6) & 0x01;
  SEGMENT_PIN_DOT = dot;
}

/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL OUTD_Init()
{
  tBOOL ret = TRUE;
  TRISD = 0;
  TRISC2 = 0;
  TRISC3 = 0;
  TRISC4 = 0;
  TRISC5 = 0;

  Update_Digit(MAX_DIGIT_NUM);
  Update_Segment(blank, FALSE);

  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL OUTD_Run()
{
  tBOOL ret = TRUE;

  Update_Digit(MAX_DIGIT_NUM);  // nothing
  Update_Segment(Digit[counter].Value, Digit[counter].Dot);
  Update_Digit(counter);
  if (++counter >= MAX_DIGIT_NUM) { counter = 0; }

  return (ret);
}
