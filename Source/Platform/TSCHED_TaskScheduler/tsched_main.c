/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: tsched_main.c
 *  author:   vanyid
 *  create date: 2011.04.23.
 *
 * ******************************************************************************************** */

#include "tsched_imp.h"
#include "tsched_exp.h"


tTask  Tasks[] =
    {
        { Task_1ms,      5, 0, STANDBY },
        { Task_10ms,    20, 0, STANDBY },
        { Task_100ms,  200, 0, STANDBY },
        { Task_1s,    2000, 0, STANDBY },
    };

const tUI8 MAX_TASK_NUM = sizeof(Tasks) / sizeof(Tasks[0]);


/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL TSCHED_Init()
{
  tBOOL ret = TRUE;

  return (ret);
}


void setTask2Run(tUI8 id)
{
  Tasks[id].State = RUNING;
}

void setTask2Actived(tUI8 id)
{
  Tasks[id].State = ACTIVED;
}

void setTask2Standby(tUI8 id)
{
  Tasks[id].State = STANDBY;
  Tasks[id].counter = 0;
}
/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL TSCHED_Run(tUI8 tasktime)
{
  tBOOL ret = TRUE;

  tUI8 ii;
  for (ii = 0; ii < MAX_TASK_NUM; ii++)
  {
    if (isTaskInStandby(ii))
    {
      Tasks[ii].counter += tasktime;
      if (Tasks[ii].counter >= Tasks[ii].activeInterval)
      {
        setTask2Actived(ii);
      }
    }
  }
  return (ret);
}

tBOOL TSCHED_RunMain()
{
  tUI8 ii;
  for (ii = 0; ii < MAX_TASK_NUM; ++ii)
  {
    if (isTaskActived(ii))
    {
      setTask2Run(ii);
      execTask(ii);
      setTask2Standby(ii);
    }
  }
  return TRUE;
}






