/* ----------------------------------------------------------------- 
"@(#) genorient.h (Yale) version 4.7 3/23/92"
FILE:	    genorient.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 22:25:49 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_GENORIENT_H
#define TWMC_GENORIENT_H

#include <yalecad/base.h>
#include <custom.h>

extern VOID genorient(P2(INT lowerBound, INT upperBound));
extern VOID regenorient(P2(INT lowerBound, INT upperBound));
extern VOID trans_bbox(P1(CELLBOXPTR ptr)); 
extern VOID loadTermArray(P1(VOID));
extern VOID translate_numpins(P1(CELLBOXPTR ptr)); 

/* from neworient.c */
extern INT newOrient(P2(CELLBOXPTR cellptr , INT range));
extern INT check_valid_orient(P1(CELLBOXPTR cptr));


#endif /* !TWMC_GENORIENT_H */