/* ******************************************************************************************** *
 *
 *  Project: Ora
 * -------------------------
 *  filename   : tsched_exp.h
 *  author     : vanyid
 *  created on : 2011.04.23.
 *
 * ******************************************************************************************** */

#ifndef TSCHED_EXP_H_
#define TSCHED_EXP_H_


#define MAX_TASK_NUM    3
/***********************************************************************************************
 *                                          GLOBAL VARIABLE
 ***********************************************************************************************/
typedef enum
{
  ACTIVED,
  RUNING,
  STANDBY
} eTaskState;

typedef struct
{
  void        (*task)();               /* Function pointer */
  tUI16       activeInterval;     /* Periodic time */
  tUI16       counter;
  eTaskState  State;
} tTask;


extern tTask  Tasks[MAX_TASK_NUM];

/***********************************************************************************************
 *                                          LOCAL VARIABLE
 ***********************************************************************************************/




/***********************************************************************************************
 *                                            PROTOTYPES
 ***********************************************************************************************/

#define isTaskActived(i)          (tBOOL)(ACTIVED == Tasks[i].State)
#define isTaskInStandby(i)        (tBOOL)(STANDBY == Tasks[i].State)
#define execTask(i)               (Tasks[i].task)()

extern tBOOL TSCHED_Init();
extern tBOOL TSCHED_Run(tUI8 tasktime);
extern tBOOL TSCHED_RunMain();

#endif
