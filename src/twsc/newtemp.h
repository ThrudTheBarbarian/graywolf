/* ----------------------------------------------------------------- 
FILE:	    newtemp.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 21:00:40 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_NEWTEMP_H
#define _TWSC_NEWTEMP_H

#include <yalecad/base.h>

extern VOID init_acceptance_rate(P1(VOID));
extern DOUBLE calc_acceptance_ratio(P1(DOUBLE iternum));

#endif /* !_TWSC_NEWTEMP_H */
