/* ----------------------------------------------------------------- 
FILE:	    findcost.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 22:25:00 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_FINDCOST_H
#define _TWSC_FINDCOST_H

#include <yalecad/base.h>
#include "standard.h"

extern INT findcost(P1(VOID));
extern VOID create_cell(P1(VOID));
extern VOID find_net_sizes(P1(VOID));

extern INT get_max_pin(P1(VOID));
extern VOID set_print_pin(P1(INT pins));

#endif /* !_TWSC_FINDCOST_H */
