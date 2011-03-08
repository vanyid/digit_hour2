/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename   : ct_exp.h
 *  author     : vanyid
 *  created on : 2011.03.08.
 *
 * ******************************************************************************************** */

#ifndef CT_EXP_H_
#define CT_EXP_H_

/***********************************************************************************************
 *                                              MACROS
 ***********************************************************************************************/
#define SET_TMR1() \
  TMR1H = 0x80; \
  TMR1L = 0x00;

/***********************************************************************************************
 *                                          GLOBAL VARIABLE
 ***********************************************************************************************/



/***********************************************************************************************
 *                                          LOCAL VARIABLE
 ***********************************************************************************************/




/***********************************************************************************************
 *                                            PROTOTYPES
 ***********************************************************************************************/

extern tBOOL ct_Init();
extern tBOOL ct_Run();

#endif
