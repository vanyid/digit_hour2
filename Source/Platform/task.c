/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: task.c
 *  author:   vanyid
 *  create date: 2011.04.23.
 *
 * ******************************************************************************************** */

#include "datatype.h"
#include "outd_exp.h"
#include "hmi_exp.h"


void Task_1ms()
{
  (void)OUTD_Run();
}

void Task_10ms()
{
  (void)HMI_Run();
}

void Task_100ms()
{

}

void Task_1s()
{
  DiginActive = 3;
}

