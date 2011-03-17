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

/***********************************************************************************************
 *                                              MACROS
 ***********************************************************************************************/

/***********************************************************************************************
 *                                          GLOBAL VARIABLE
 ***********************************************************************************************/
tBOOL Run_1ms_task;

tTime Times[1];

/***********************************************************************************************
 *                                          LOCAL VARIABLE
 ***********************************************************************************************/

/***********************************************************************************************
 *                                            PROTOTYPES
 ***********************************************************************************************/


/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL ct_Init()
{
  tBOOL ret = TRUE;
  tUI8  ii;

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

  Run_1ms_task = FALSE;

  for (ii=0; ii<1; ii++)
  {
    Times[ii].day = eHetfo;
    Times[ii].hour = 22;
    Times[ii].minute = 00;
    Times[ii].sec = 00;
  }
  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL ct_1s_Run()
{
  tBOOL ret = TRUE;

  IncTime(&Times[0]);

  return (ret);
}


tBOOL ct_1ms_Run()
{
  tBOOL ret = TRUE;
  Run_1ms_task = TRUE;
  return (ret);
}


void IncTime(tTime *time)
{
  if (++time->sec == 60)
  {
    time->sec = 0;
    if (++time->minute == 60)
    {
      time->minute = 0;
      if (++time->hour == 24)
      {
        time->hour = 0;
        if (++time->day == (eVasarnap+1))
        {
          time->day = eHetfo;
        }
      }
    }
  }
}

