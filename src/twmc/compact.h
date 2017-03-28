/* ----------------------------------------------------------------- 
"@(#) compact.h (Yale) version 4.7 3/23/92"
FILE:	    compact.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 16:21:46 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_COMPACT_H
#define TWMC_COMPACT_H

#include <yalecad/base.h>

extern VOID compact( P1(BOOL compactFlag) );
extern VOID get_cell_centers(P3(INT cell, INT *xc, INT *yc) );


#endif /* !TWMC_COMPACT_H */