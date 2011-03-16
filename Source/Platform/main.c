/*
 * main.c
 *
 *  Created on: 2011.03.08.
 *      Author: vanyid
 */

#include "datatype.h"
#include "ct_exp.h"
#include "outd_exp.h"




void main()
{

  /* Init Clock Timer module */
  (void)ct_Init();
  (void)OUTD_Init();

  IPEN = 1;             /* enable high and low prio interrupt */
  PEIE = 1; GIE = 1;    /* enable interrupt */

  TRISD = 0;
  PORTD = 0;

  /* Go infinite loop (BackGround Task) */
  while (1)
  {
    if (Run_1ms_task)
    {
      Run_1ms_task = FALSE;
      (void)OUTD_Run();
    }
  }
}
