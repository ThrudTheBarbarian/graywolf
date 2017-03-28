/* ----------------------------------------------------------------- 
FILE:	    mergeseg.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sat Mar  4 14:20:54 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_MERGE_H
#define _TWSC_MERGE_H

#include <yalecad/base.h>
#include "standard.h"

extern VOID mergeseg(P1(PINBOXPTR netptr)); 
extern VOID mergedge(P2(PINBOXPTR netptr, INT direction));
extern VOID rplacseg(P3(PINBOXPTR netptr, PINBOXPTR oldnode, PINBOXPTR newnode));
extern VOID set_steiner_flag(P4(PINBOXPTR ptr1, PINBOXPTR ptr2, PINBOXPTR ptr3, PINBOXPTR stptr));
extern VOID recheck_steiner_flag(P1(PINBOXPTR stptr)); 

extern PINBOXPTR xmedianfun(P3(PINBOXPTR aptr, PINBOXPTR bptr, PINBOXPTR cptr));
extern PINBOXPTR ymedianfun(P3(PINBOXPTR aptr, PINBOXPTR bptr, PINBOXPTR cptr));

#endif /* !_TWSC_STEINER_H */
