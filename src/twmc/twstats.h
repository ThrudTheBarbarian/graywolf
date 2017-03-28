/* ----------------------------------------------------------------- 
"@(#) twstats.h (Yale) version 4.7 3/23/92"
FILE:	    twstats.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 23:05:47 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_STATS_H
#define TWMC_STATS_H

#include <yalecad/base.h>

extern VOID twstats(P1(VOID));
extern VOID set_print_pin(P1(INT pin));
extern VOID prnt_netinfo(P1(VOID));
extern INT get_max_pin(P1(VOID));

#endif /* !TWMC_STATS_H */