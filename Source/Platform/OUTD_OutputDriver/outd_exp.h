/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename   : outd_exp.h
 *  author     : vanyid
 *  created on : 2011.03.09.
 *
 * ******************************************************************************************** */

#ifndef OUTD_EXP_H_
#define OUTD_EXP_H_

/***********************************************************************************************
 *                                              MACROS
 ***********************************************************************************************/
#define MAX_DIGIT_NUM     4

/***********************************************************************************************
 *                                             TYPEDEFS
 ***********************************************************************************************/
typedef enum
{
  num_0,
  num_1,
  num_2,
  num_3,
  num_4,
  num_5,
  num_6,
  num_7,
  num_8,
  num_9,
  num_a,
  num_b,
  num_c,
  num_d,
  num_e,
  num_f,
  seg_a,
  seg_b,
  seg_c,
  seg_d,
  seg_e,
  seg_f,
  seg_g,
  blank,
  MAX_SEGMENT_NUM
} eDigit;

typedef struct
{
  eDigit  Value;
  tBOOL   Dot;
} tDigit;

/***********************************************************************************************
 *                                          GLOBAL VARIABLE
 ***********************************************************************************************/

extern volatile tDigit Digit[MAX_DIGIT_NUM];

/***********************************************************************************************
 *                                          LOCAL VARIABLE
 ***********************************************************************************************/




/***********************************************************************************************
 *                                            PROTOTYPES
 ***********************************************************************************************/

extern tBOOL OUTD_Init();
extern tBOOL OUTD_Run();

#endif
