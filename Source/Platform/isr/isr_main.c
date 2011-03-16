/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: isr_main.c
 *  author:   vanyid
 *  create date: 2011.03.08.
 *
 * ******************************************************************************************** */

#include "isr_imp.h"
#include "isr_exp.h"

/* ******************************** *
 *  HIGH PRIORITY INTERRUPT VECTOR  *
 * ******************************** */
void interrupt isr_high()
{

  if (TMR1IF)
  {
    TMR1IF = 0;
    SET_TMR1();
    (void)ct_1s_Run();
  }

}


/* ******************************* *
 *  LOW PRIORITY INTERRUPT VECTOR  *
 * ******************************* */
void interrupt low_priority isr_low()
{
  if (TMR0IF)
  {
    TMR0IF = 0;
    SET_TMR0();
    (void)ct_1ms_Run();
  }

}


