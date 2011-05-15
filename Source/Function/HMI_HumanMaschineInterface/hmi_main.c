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

tCallHMIFunc HMIFuncs[MAX_NUM_HMI_FUNC] = {
                                             SLT_CheckOn, SLT_Run, SLT_PassFocus
                                          };

eHMIFuncName  ActHMIFunc = Standby;

tUI16 DiginActive;

/* *************************** *
 *  Init component             *
 * *************************** */
tBOOL HMI_Init()
{
  tBOOL ret = TRUE;

  ActHMIFunc = Standby;

  return (ret);
}

/* *************************** *
 *  Run component              *
 * *************************** */
tBOOL HMI_Run()
{
  tBOOL ret = TRUE;
  tUI8  ii;

  for (ii = 0; ii < MAX_NUM_HMI_FUNC; ii++)
  {
    if ( (Standby == ActHMIFunc) && (HMIFuncs[ii].CheckOn()) )
    {
      ActHMIFunc = (eHMIFuncName)ii;
    }

    if ( ((eHMIFuncName)ii == ActHMIFunc) && (HMIFuncs[ii].PassFocus()) )
    {
      ActHMIFunc = Standby;
    }
  }

  if ((Standby != ActHMIFunc) && (MAX_NUM_HMI_FUNC > ActHMIFunc))
  {
    (void)HMIFuncs[(tUI8)ActHMIFunc].Run();
  }

  return (ret);
}
