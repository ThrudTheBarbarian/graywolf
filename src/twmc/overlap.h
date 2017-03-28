/* ----------------------------------------------------------------- 
"@(#) overlap.h (Yale) version 4.7 3/23/92"
FILE:	    overlap.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 19:37:23 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_OVERLAP_H
#define TWMC_OVERLAP_H

#include <yalecad/base.h>
#include "custom.h"

extern INT overlap( P1(VOID));
extern INT overlap2(P1(VOID));
extern VOID update_overlap(P1(VOID));
extern VOID update_overlap2(P1(VOID));
extern VOID sub_penal(P1(MOVEBOXPTR *cellpos));
extern VOID add_penal(P1(MOVEBOXPTR *cellpos));
extern VOID calc_wBins(P1(MOVEBOXPTR *cellpos));
extern VOID calc_nBins(P1(MOVEBOXPTR *cellpos));
extern VOID turn_wireest_on( P1(BOOL turn_on) );
extern VOID setup_Bins( P4(CELLBOXPTR s_cellptr, INT s_xc, INT s_yc, INT s_orient ));
extern VOID add2bin(P1(MOVEBOXPTR *cellpos));

#endif /* !TWMC_OVERLAP_H */