/* ----------------------------------------------------------------- 
"@(#) unbust.h (Yale) version 4.7 3/23/92"
FILE:	    unbust.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    4 Mar 2017 
REVISIONS: Sat  4 Mar 2017 21:24:14 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_UNBUST_H
#define TWMC_UNBUST_H

#include <yalecad/base.h>
#include <yalecad/buster.h>

typedef struct {
    INT tile ;    /* tile that point is attached */
    INT x ;       /* x position of point */
    INT y ;       /* y position of point */
    INT Vnum ;    /* position in VPts array */
    INT Hnum ;    /* position in HPts array */
    INT order ;   /* order that points should be output - negative means invalid */
    BOOL marked ; /* point has been used */
} POINTBOX, *POINTPTR ;


extern YBUSTBOXPTR unbust(P1(VOID));
extern VOID addPt( P3(INT tile, INT x, INT y) );
extern VOID addPts( P5(INT cell, INT l, INT r, INT b, INT t) ); 
extern VOID initPts( P1(BOOL addpoint_flag ) );
extern VOID dump_pts( P1(POINTPTR *pt) );

#endif /* !TWMC_UNBUST_H */