/* ----------------------------------------------------------------- 
FILE:	    xcompact.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:45:32 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_XCOMPACT_H
#define _MC_COMPACT_XCOMPACT_H

#include <yalecad/base.h>
#include <compact.h>

extern VOID buildXGraph(P1(VOID));
extern VOID formxEdge(P2(INT fromNode, INT toNode));

extern VOID initxPicket(P1(VOID));
extern VOID update_xpicket(P3(INT i, PICKETPTR lowerLimit, PICKETPTR upperLimit));

extern INT projectX(P4(INT tile1_left, INT tile1_right, INT tile2_left, INT tile2_right));

extern VOID load_ancestors(P1(INT direction));
extern INT longestxPath(P1(BOOL find_path));

extern VOID dxpick(P1(VOID));
extern BOOL dcheckPicks(P1(VOID));


#endif /* !_MC_COMPACT_XCOMPACT_H */
