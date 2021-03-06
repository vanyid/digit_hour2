/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: upd_main.c
 *  author:   vanyid
 *  create date: 2011.03.17.
 *
 * ******************************************************************************************** */

#include "upd_imp.h"
#include "upd_exp.h"


/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL UPD_Init()
{
  tBOOL ret = TRUE;

  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL UPD_Run()
{
  tBOOL ret = TRUE;
  /* Calculate the numeric digit of the time */

  Digit[0].Value = (eDigit)(LocalTime.hour / 10);
  Digit[1].Value = (eDigit)(LocalTime.hour % 10);
  Digit[2].Value = (eDigit)(LocalTime.minute / 10);
  Digit[3].Value = (eDigit)(LocalTime.minute % 10);
  Digit[1].Dot   = (tBOOL)(LocalTime.sec & 0x01);

  return (ret);
}
