/* ----------------------------------------------------------------- 
FILE:	    findcostf.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 19:37:08 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_FINDCOSTF_H
#define _TWSC_FINDCOSTF_H

#include <yalecad/base.h>

extern INT findcostf(P1(VOID));
extern VOID install_clusters(P1(VOID));
extern VOID place_clusters(P1(VOID));
extern INT recompute_wirecost(P1(VOID));
extern INT recompute_timecost(P1(VOID));

#endif /* !_TWSC_FINDCOST_H */
