/* ----------------------------------------------------------------- 
FILE:	    debug.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 21:11:10 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_DEBUG_H
#define _TWSC_DEBUG_H

#include <yalecad/base.h>
#include "standard.h"

/* from debug.c */
extern VOID dbx_adj(P1(INT net));


/* from debug2.c */

extern VOID cellbox_data(P2(INT first_cell , INT last_cell));
extern VOID cellterm_data(P2(INT first_cell , INT last_cell));

extern VOID dbx_terminal(P2(INT first_net , INT last_net));

extern VOID dbx_grd(P2(CHANGRDPTR ptr1 , CHANGRDPTR ptr2 ));

extern VOID pairCheck(P2(INT first_row , INT last_row));

extern VOID dbx_track(P2(INT start_chan , INT end_chan ));

extern VOID check_cost(P1(VOID));

#endif /* !_TWSC_DEBUG_H */
