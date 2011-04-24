/*
 * -------------------------------------------
 *  typedef header
 *
 * -------------------------------------------
 */

#ifndef _DATATPYE_H_
#define _DATATPYE_H_

#include <htc.h>


typedef unsigned int           tUI16;
typedef signed int             tSI16;
typedef unsigned char          tUI8;
typedef signed char            tSI8;
typedef unsigned long          tUI32;
typedef signed long            tSI32;
typedef unsigned               tBITF;
typedef char                   tBOOL;

#define TRUE    1U
#define FALSE   0x00

#define getbit(value, id)     (tBOOL)((value >> id) & 0x1)

#endif
