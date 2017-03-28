/* ----------------------------------------------------------------- 
"@(#) uloop.h (Yale) version 4.7 3/23/92"
FILE:	    uloop.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 22:45:31 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_ULOOP_H
#define TWMC_ULOOP_H

#include <yalecad/base.h>

extern VOID uloop(P1(INT limit));
extern VOID initStatCollection(P1(VOID));
extern VOID getStatistics(P4(DOUBLE *totalWire, DOUBLE *totalPenalty, 
							 DOUBLE *avg_time,  DOUBLE *avg_func));
extern VOID make_movebox(P1(VOID)); 
extern VOID save_uloop(P1(FILE *fp));
extern INT read_uloop(P1(FILE *fp));
extern VOID set_dump_ratio(P1(INT count));

/* from utemp.c */
VOID utemp( P2(INT attempts, BOOL multi_cell_moves ));


#endif /* !TWMC_ULOOP_H */