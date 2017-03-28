/* ----------------------------------------------------------------- 
FILE:	    acceptt.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 19:53:16 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_ACCEPTT_H
#define _TWSC_ACCEPTT_H

#include <yalecad/base.h>

extern VOID init_table(P1(VOID));
extern BOOL acceptt(P3(INT d_wire, INT d_time, INT d_penal));
extern BOOL accept_greedy(P3(INT d_wire, INT d_time, INT d_penal));

#endif /* !_TWSC_ACCEPTT_H */
