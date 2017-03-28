/* ----------------------------------------------------------------- 
"@(#) findcost.h (Yale) version 4.7 3/23/92"
FILE:	    findcost.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 21:21:04 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_FINDCOST_H
#define TWMC_FINDCOST_H

#include <yalecad/base.h>
#include <custom.h>

extern INT findcost(P1(VOID));

/* from findside.c */
extern INT findside(P4(PSIDEBOX *pSideArray, CELLBOXPTR cellptr, INT x, INT y));
extern VOID loadside(P3(PSIDEBOX *pSideArray, INT side , DOUBLE factor));
extern VOID load_soft_pins(P2(CELLBOXPTR ptr, PSIDEBOX *pSideArray));


#endif /* !TWMC_FINDCOST_H */