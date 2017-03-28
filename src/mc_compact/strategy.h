/* ----------------------------------------------------------------- 
FILE:	    strategy.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:06:11 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_STRATEGY_H
#define _MC_COMPACT_STRATEGY_H

#include <yalecad/base.h>
#include <compact.h>

/* from movestrat.c */
extern VOID moveStrategy(P1(ERRORPTR violations));

extern VOID update_cell_tiles(P3(INT cell, INT dx, INT dy));

extern VOID dcheck_pos(P1(INT cell));



/* from movestrat2.c */
extern VOID move_compactx(P1(INT length)); 
extern VOID move_compacty(P1(INT length)); 

extern BOOL test_area(P1(VOID));


#endif /* !_MC_COMPACT_STRATEGY_H */
