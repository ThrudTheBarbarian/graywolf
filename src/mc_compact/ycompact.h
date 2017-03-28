/* ----------------------------------------------------------------- 
FILE:	    ycompact.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 20:39:44 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_YCOMPACT_H
#define _MC_COMPACT_YCOMPACT_H

#include <yalecad/base.h>
#include <compact.h>

extern ERRORPTR buildYGraph(P1(VOID));
extern VOID formyEdge(P2(INT fromNode, INT toNode));

extern VOID inityPicket(P1(VOID));
extern VOID update_ypicket(P3(INT i, PICKETPTR lowerLimit, PICKETPTR upperLimit));

extern INT projectY(P4(INT tile1_bot, INT tile1_top, INT tile2_bot, INT tile2_top));

extern INT longestyPath(P1(BOOL find_path));

extern VOID dypick(P1(VOID));

#endif /* !_MC_COMPACT_XCOMPACT_H */
