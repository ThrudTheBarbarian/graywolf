/* ----------------------------------------------------------------- 
"@(#) wire.h (Yale) version 4.7 3/23/92"
FILE:	    wire.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 16:58:34 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_WIRE_H
#define TWMC_WIRE_H

#include <yalecad/base.h>
#include <yalecad/buster.h>
#include <custom.h>

extern BOOL read_wire_est( P1(FILE *fp) );
extern VOID resize_wire_params(P1(VOID));
extern VOID save_wireest( P1(FILE *fp) );
extern INT read_wireest( P1(FILE *fp) );

/* from wireratio.c */
extern VOID adapt_wire_estimator(P1(VOID));

/* from wirecosts.c */
extern VOID wirecosts(P1(VOID));

/* from wireest.c */
extern VOID wireestxy(P3(MOVEBOXPTR pos, INT xc, INT yc));
extern VOID wireestxy2(P3(MOVEBOXPTR pos, INT xc, INT yc));
extern BOOL read_wire_est(P1(FILE *fp));
extern VOID resize_wire_params(P1(VOID));
extern VOID save_wireest(P1(FILE *fp));
extern INT read_wireest(P1(FILE *fp));

/* from watesides.c */
extern VOID watesides(P2(CELLBOXPTR ptr, PSIDEBOX *pSideArray));

/* from perimeter.c */
extern INT perimeter(P2(YBUSTBOXPTR A, INT numcorners));

/* from penalties.c */
extern DOUBLE calc_lap_factor(P1(DOUBLE percentDone )); 
extern DOUBLE calc_time_factor(P1(DOUBLE percentDone )); 
extern DOUBLE calc_core_factor(P1(DOUBLE percentDone )); 
extern DOUBLE calc_init_lapFactor(P2(DOUBLE totFunc, DOUBLE totPen )); 
extern DOUBLE calc_init_timeFactor(P2(DOUBLE totFunc, DOUBLE totPen )); 
extern DOUBLE calc_init_coreFactor(P1(VOID )); 

#endif /* !TWMC_WIRE_H */