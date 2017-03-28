/* ----------------------------------------------------------------- 
"@(#) acceptt.h (Yale) version 4.7 3/23/92"
FILE:	    acceptt.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Sat  4 Mar 2017 11:14:45 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_ACCEPTT_H
#define TWMC_ACCEPTT_H

#include <yalecad/base.h>

extern VOID init_table(P1(VOID));
extern INT acceptt(P1(INT delta_cost));

#endif /* !TWMC_ACCEPTT_H */