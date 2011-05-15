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

void SLT_Init()
{
  cnt = 10;
}


tBOOL SLT_CheckOn()
{
  tBOOL ret = FALSE;

  if ((ACTIVE_SLT) && (!active))
  {
    ret = TRUE;
    active = TRUE;
    SLT_Init();
  }

  return (ret);
}



tBOOL SLT_Run()
{
  tBOOL ret = FALSE;

  cnt--;
  incLOCAL_THOUR;

  return (ret);
}


tBOOL SLT_PassFocus()
{
  tBOOL ret = FALSE;

  if (!cnt)
  {
    ret = TRUE;
//    active = FALSE;
  }

  return (ret);
}
