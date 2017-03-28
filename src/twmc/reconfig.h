/* ----------------------------------------------------------------- 
"@(#) reconfigure.h (Yale) version 4.7 3/23/92"
FILE:	    reconfigure.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 16:40:25 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_RECONFIGURE_H
#define TWMC_RECONFIGURE_H

#include <yalecad/base.h>

extern VOID reconfigure( P3(INT numbinX, INT numbinY, DOUBLE newCoreArea) );
extern VOID reorigin(P1(VOID));

#endif /* !TWMC_RECONFIGURE_H */