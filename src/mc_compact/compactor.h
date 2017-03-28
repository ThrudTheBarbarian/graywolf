/* ----------------------------------------------------------------- 
FILE:	    cdraw.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:06:11 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_COMPACTOR_H
#define _MC_COMPACT_COMPACTOR_H

#include <yalecad/base.h>
#include <compact.h>

extern VOID remove_violations(P1(VOID));
extern VOID compact(P1(VOID));
extern VOID freeGraph(P1(INT direction));
extern VOID cleanupGraph(P1(INT direction));
extern INT path(P1(INT direction));

extern VOID find_core(P4(INT *l, INT *r, INT *b, INT *t));

#endif /* !_MC_COMPACT_COMPACTOR_H */
