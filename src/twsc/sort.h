/* ----------------------------------------------------------------- 
FILE:	    sort.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 21:03:24 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_SORT_H
#define _TWSC_SORT_H

#include <yalecad/base.h>
#include "standard.h"

/* from sortpin.c */
extern VOID sortpin(P1(VOID));
extern VOID sortpin1(P1(INT cell));
extern VOID sortpin2(P2(INT cella, INT cellb));
extern VOID shellsort(P2(PINBOXPTR term[], INT n));
extern VOID shellsortx(P2(PINBOXPTR term[], INT n));
extern VOID shellsorty(P2(PINBOXPTR term[], INT n));
extern VOID shellsort_referx(P3(FEED_SEG_PTR worker[], INT head, INT n));

/* from sort.c */
extern INT compare_cost(P2(void *a , void *b));
extern INT comparegdx(P2(void *a , void *b));
extern INT comparetxpos(P2(void *a , void *b));
extern INT comparenptr(P2(void *a , void *b));
extern INT comparepinx(P2(void *a , void *b));
extern INT comparex(P2(void *a , void *b));
extern INT cmpr_sx(P2(void *a , void *b));
extern INT cmpr_lx(P2(void *a , void *b));
extern INT cmpr_sy(P2(void *a , void *b));
extern INT cmpr_ly(P2(void *a , void *b));


#endif /* !_TWSC_SORT_H */
