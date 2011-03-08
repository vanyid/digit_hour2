/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: ct_main.c
 *  author:   vanyid
 *  create date: 2011.03.08.
 *
 * ******************************************************************************************** */

#include "ct_imp.h"
#include "ct_exp.h"


/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL ct_Init()
{
  tBOOL ret = TRUE;

  T1CON = 0b00001111;
  TMR1H = 0x80;
  TMR1L = 0x00;
  TMR1IP = 1;           /* High interrupt prio */
  TMR1IF = 0;
  TMR1IE = 1;

  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL ct_Run()
{
  tBOOL ret = TRUE;
  PORTD ^= 0b00000001;
  return (ret);
}
