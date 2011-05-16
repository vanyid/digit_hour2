/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename: slt_main.c
 *  author:   vanyid
 *  create date: 2011.05.15.
 *
 * ******************************************************************************************** */

#include "slt_imp.h"
#include "slt_exp.h"

tUI8 cnt;
tBOOL active = FALSE;
eSLTMode  SLTMode;

tUI8  DelayTimer;
tUI8  ShortLongCnt;
const tUI8  shortcnt = 10;
const tUI8  longcnt  = 30;


void SLT_Init()
{
  cnt = 10;
  ShortLongCnt = 5;
  DelayTimer = longcnt;
  SLTMode = SLT_Nothing;
}


tBOOL SLT_CheckOn()
{
  tBOOL ret = FALSE;

  if (   ( (SLT_DIN_HOUR_ACTIVE) || (SLT_DIN_MINUTE_ACTIVE))
      && (!active)
     )
  {
    ret = TRUE;
    active = TRUE;
    SLT_Init();

    if (SLT_DIN_HOUR_ACTIVE)
    {
      SLTMode = SetHour;
    }
    else
      if (SLT_DIN_MINUTE_ACTIVE)
      {
        SLTMode = SetMinute;
      }
  }
  return (ret);
}

tBOOL getDelayTimerReady()
{
  tBOOL ret = FALSE;
  if (0 == DelayTimer)
  {
    if (0 != ShortLongCnt)
    {
      ShortLongCnt--;
    }
    DelayTimer = (0 == ShortLongCnt ? shortcnt : longcnt);
    ret = TRUE;
  }
  else
  {
    DelayTimer--;
  }
  return (ret);
}


tBOOL SLT_Run()
{
  tBOOL ret = FALSE;

  if (getDelayTimerReady())
  {
    switch (SLTMode)
    {
      case SetHour:
        incLOCAL_THOUR;
        break;

      case SetMinute:
        incLOCAL_TMINUTE;
        break;

      case SetDay:
        incLOCAL_TDAY;
        break;
    }
    cnt--;
  }

  return (ret);
}


tBOOL SLT_PassFocus()
{
  tBOOL ret = FALSE;

  if (0 == cnt)
  {
    ret = TRUE;
    active = FALSE;
//    DiginActive = 0;
  }

  return (ret);
}
