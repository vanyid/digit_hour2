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

tTime Times[MAX_NUM_TIME_ZONES];

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

  for (ii=0; ii < MAX_NUM_TIME_ZONES; ii++)
  {
    Times[ii].day = eHetfo;
    Times[ii].hour = 00;
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

  IncTime(&LOCALTIME);

  return (ret);
}

void IncTime(tTime *time /**<[in] Pointer to timer to increase */
                          )
{
  if (++time->sec == 60)
  {
    time->sec = 0;
    if (IncTimeMinute(time))
    {
      if (IncTimeHour(time))
      {
        (void)IncTimeDay(time);
      }
    }
  }
}


tBOOL IncTimeHour(tTime *time)
{
  tBOOL ret = FALSE;
  if (++time->hour == 24)
  {
    time->hour = 0;
    ret = TRUE;
  }
  return (ret);
}

tBOOL IncTimeMinute(tTime *time)
{
  tBOOL ret = FALSE;
  if (++time->minute == 60)
  {
    time->minute = 0;
    ret = TRUE;
  }
  return (ret);
}

tBOOL IncTimeDay(tTime *time)
{
  tBOOL ret = FALSE;
  if (++time->day == (eVasarnap + 1))
  {
    time->day = eHetfo;
    ret = TRUE;
  }
  return (ret);
}

