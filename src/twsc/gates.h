/* ----------------------------------------------------------------- 
FILE:	    gates.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Fri  3 Mar 2017 19:20:34 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_GATES_H
#define _TWSC_GATES_H

#include <yalecad/base.h>
#include "standard.h"

/* from gateswap.c */
extern INT gate_swap(P3(INT between_two_cells, INT sgidxa, INT sgidxb));
extern VOID adjust_paths_on_cell(P1(INT cell));

/* from xpickint.c */
INT XPICK_INT(P3(INT l , INT u , INT c ));

#endif /* !_TWSC_GATES_H */
