/* ----------------------------------------------------------------- 
"@(#) makesite.h (Yale) version 4.7 3/23/92"
FILE:	    makesite.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    4 Mar 2017 
REVISIONS: Sat  4 Mar 2017 17:26:54 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_MAKESITE_H
#define TWMC_MAKESITE_H

#include <yalecad/base.h>
#include <custom.h>

extern INT Vside(P6(KBOXPTR kArray, CELLBOXPTR cellptr ,INT x ,INT yy1 ,INT yy2 ,INT flag));
extern INT Hside(P6(KBOXPTR kArray, CELLBOXPTR cellptr ,INT xx1 ,INT xx2 ,INT y ,INT flag));

#endif /* !TWMC_MAKESITE_H */