/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: inph_main.c
 *  author:   vanyid
 *  create date: 2011.04.24.
 *
 * ******************************************************************************************** */

#include "hmi_imp.h"
#include "hmi_exp.h"


eSettingState SettingState = Standby;

tUI16 DiginActive = 0;
static tUI8 cntLongButtonHour = 0;
static tUI8 cntButtonHour = 0;
static tUI8 delayIncHour = 2;

static tUI8 cntLongButtonMin = 0;
static tUI8 cntButtonMin = 0;
static tUI8 delayIncMin = 2;

static tUI8 cntLongButtonDay = 0;
static tUI8 cntButtonDay = 0;
static tUI8 delayIncDay = 2;

void runSetAlarm()
{

}

void runSetTime()
{

    /* Hour button */
  if (getbit(DiginActive, 0) && !getbit(DiginActive, 1))
  {
    if (!cntButtonHour)
    {
      if (++Times[0].hour == 24)
      {
        Times[0].hour = 0;
      }
    }

    if (++cntButtonHour >= delayIncHour) { cntButtonHour = 0; }

    if (cntLongButtonHour >= 10)
    {
      delayIncHour = 1;
    }
    else
    {
      ++cntLongButtonHour;
    }
  }
  else
    if (!getbit(DiginActive, 0) && getbit(DiginActive, 1))
  {
    if (!cntButtonMin)
    {
      if (++Times[0].minute == 60)
      {
        Times[0].minute = 0;
      }
    }

    if (++cntButtonMin >= delayIncMin) { cntButtonMin = 0; }

    if (cntLongButtonMin >= 10)
    {
      delayIncMin = 1;
    }
    else
    {
      ++cntLongButtonMin;
    }
  }
  else
    if (getbit(DiginActive, 0) && getbit(DiginActive, 1))
  {
      if (!cntButtonDay)
      {
        if (++Times[0].day == (eVasarnap+1))
        {
          Times[0].day = (eHetfo);
        }
      }

      if (++cntButtonDay >= delayIncDay) { cntButtonDay = 0; }

      if (cntLongButtonDay >= 10)
      {
        delayIncDay = 1;
      }
      else
      {
        ++cntLongButtonDay;
      }
  }
    else
    {
      SettingState = Standby;
    }
}


/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL HMI_Init()
{
  tBOOL ret = TRUE;

  SettingState = Standby;

  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL HMI_Run()
{
  tBOOL ret = TRUE;

  if (Standby == SettingState)
  {
    if (getbit(DiginActive, 0) || getbit(DiginActive, 1))
    {
      cntLongButtonHour = 0;
      cntButtonHour = 0;
      delayIncHour = 2;

      cntLongButtonMin = 0;
      cntButtonMin = 0;
      delayIncMin = 2;

      cntLongButtonDay = 0;
      cntButtonDay = 0;
      delayIncDay = 2;

      SettingState = SetTime;
    }
  }
  else
  {
    switch (SettingState)
    {
      case SetTime:
          runSetTime();
        break;

      case SetAlarm:
          runSetAlarm();
        break;

      case OnOffAlarm:

        break;

      default:
        break;
    }
  }

  return (ret);
}
