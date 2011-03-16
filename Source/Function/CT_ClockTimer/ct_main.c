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

tUI8  timer1s = 0;
tUI8  timer1ms = 0;

tBOOL Run_1ms_task;

/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL ct_Init()
{
  tBOOL ret = TRUE;

  /* TIMER1 1s timer */
  T1CON = 0b10001111;
  SET_TMR1();
  TMR1IP = 1;           /* High interrupt prio */
  TMR1IF = 0;
  TMR1IE = 1;

  /* TIMER0 1ms timer */
  T0CS = 0;             // internal source Fosc/4
  PSA  = 0;             // Use the prescaler
  T0PS2 = 1;
  T0PS1 = 0;            // 1:64
  T0PS0 = 1;
  T08BIT = 1;           // 16bit mode
  SET_TMR0();

  TMR0IP = 0;           // low prio interrupt
  TMR0IE = 1;           // interrupt enable
  TMR0ON = 1;           // enable timer0


  timer1s = 0;
  timer1ms = 0;
  Run_1ms_task = FALSE;
  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL ct_1s_Run()
{
  tBOOL ret = TRUE;

  Digit[0].Value++;
  Digit[1].Dot ^= (tBOOL)1;

  return (ret);
}


tBOOL ct_1ms_Run()
{
  tBOOL ret = TRUE;
  Run_1ms_task = TRUE;
  return (ret);
}


