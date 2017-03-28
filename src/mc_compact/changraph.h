/* ----------------------------------------------------------------- 
FILE:	    changraph.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:37:20 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_CHANGRAPH_H
#define _MC_COMPACT_CHANGRAPH_H

#include <yalecad/base.h>
#include <compact.h>

extern VOID init_graph(P2(INT numnodes, INT numedges));
extern VOID addNode(P3(INT node, INT xc, INT yc));
extern VOID addEdge(P5(INT node1, INT node2, BOOL hNotV, INT cell_lb, INT cell_rt));
extern VOID build_trees(P1(VOID));
extern INFOPTR get_closest_edge(P2(INT x, INT y));
extern VOID stretch_graph(P3(INFOPTR stretch_edge, INT x, INT y));


#endif /* !_MC_COMPACT_CHANGRAPH_H */
