/* ----------------------------------------------------------------- 
FILE:	    upair.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 11:43:50 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_UPAIR_H
#define _TWSC_UPAIR_H

#include <yalecad/base.h>

extern VOID upair(P1(VOID));
extern INT eval_range(P6(CBOXPTR acellptr , CBOXPTR bcellptr, 
						 INT axc, INT anxc, INT bxc, INT bnxc));

#endif /* !_TWSC_UPAIR_H */
