/* ----------------------------------------------------------------- 
"@(#) nets.h (Yale) version 4.7 3/23/92"
FILE:	    nets.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    4 Mar 2017 
REVISIONS: Sat  4 Mar 2017 14:01:03 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_NETS_H
#define TWMC_NETS_H

#include <yalecad/base.h>
#include <custom.h>

/* from readnets.c */
extern VOID readnets(P1(FILE *fp));

/* from unet.c */
extern VOID init_unet(P1(VOID));
extern INT unet(P1(PINBOXPTR antrmptr ));
extern INT unet2(P2(PINBOXPTR antrmptr , PINBOXPTR bntrmptr ));

/* from scrapnet.c */
extern VOID scrapnet(P1(VOID));

#endif /* !TWMC_NETS_H */