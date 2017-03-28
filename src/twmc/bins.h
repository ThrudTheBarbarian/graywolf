/* ----------------------------------------------------------------- 
"@(#) bins.h (Yale) version 4.7 3/23/92"
FILE:	    bins.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 16:40:25 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_BINS_H
#define TWMC_BINS_H

#include <yalecad/base.h>

extern VOID makebins( P1(INT numbins) );
extern VOID loadbins( P1(BOOL wireAreaKnown) );
extern INT get_bin_area( P1(VOID) );
extern INT calc_cellareas( P1(BOOL routingFlag) );
 


#endif /* !TWMC_BINS_H */