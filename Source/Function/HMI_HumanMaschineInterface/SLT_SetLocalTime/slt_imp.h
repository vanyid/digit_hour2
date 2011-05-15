/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename   : slt_imp.h
 *  author     : vanyid
 *  created on : 2011.05.15.
 *
 * ******************************************************************************************** */

#ifndef HMI_IMP_H_
#define HMI_IMP_H_

#include "datatype.h"
#include "ct_exp.h"
#include "hmi_exp.h"

#define incLOCAL_THOUR      IncTimeHour(&LOCALTIME)
#define incLOCAL_TMINUTE    IncTimeMinute(&LOCALTIME)
#define incLOCAL_TDAY       IncTimeDay(&LOCALTIME)

#define ACTIVE_SLT          (tBOOL)(2 == DiginActive)

#endif
