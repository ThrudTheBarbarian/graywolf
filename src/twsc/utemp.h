/* ----------------------------------------------------------------- 
FILE:	    utemp.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Tue  7 Mar 2017 19:23:02 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_UTEMP_H
#define _TWSC_UTEMP_H

#include <yalecad/base.h>

extern VOID utemp(P1(VOID));
extern INT rm_overlapping_feeds(P1(VOID));
extern VOID route_only_critical_nets(P1(VOID));
extern VOID elim_nets(P1(INT print_flag));
extern INT refine_fixed_placement(P1(VOID));

#endif /* !_TWSC_UTEMP_H */
