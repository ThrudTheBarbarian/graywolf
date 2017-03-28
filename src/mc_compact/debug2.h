/* ----------------------------------------------------------------- 
FILE:	    debug2.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:57:19 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_XCOMPACT_H
#define _MC_COMPACT_XCOMPACT_H

#include <yalecad/base.h>
#include <compact.h>

extern VOID dumpxGraph(P1(VOID));
extern VOID dumpyGraph(P1(VOID));
extern VOID dycons(P1(VOID));

extern VOID dxancerr(P1(VOID));
extern VOID dyancerr(P1(VOID));
extern VOID dump_anc(P1(VOID));
extern VOID check_xancestors(P1(VOID));
extern VOID check_yancestors(P1(VOID));

extern VOID dxancestors(P2(INT numtiles, COMPACTPTR *xGraph));

extern ECOMPBOXPTR find_edge(P3(INT node1, INT node2, INT direction));

extern VOID dsort(P2(INT numtiles, BOOL xNotY));

extern VOID dslack(P3(BOOL xNotY, BOOL center, INT length));

extern VOID dedges(P3(INT cell, BOOL xNotY, BOOL forwardNotBack));

#endif /* !_MC_COMPACT_XCOMPACT_H */
