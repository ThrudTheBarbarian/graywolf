/* ----------------------------------------------------------------- 
"@(#) config.h (Yale) version 4.7 3/23/92"
FILE:	    config.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 17:04:48 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_CONFIG_H
#define TWMC_CONFIG_H

#include <yalecad/base.h>

extern VOID config1( P1(VOID) );
extern VOID config2( P3(INT numbinX, INT numbinY, DOUBLE wire_red_ratio) );


#endif /* !TWMC_CONFIG_H */