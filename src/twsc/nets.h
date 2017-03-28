/* ----------------------------------------------------------------- 
FILE:	    nets.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 23:14:58 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_NETS_H
#define _TWSC_NETS_H

#include <yalecad/base.h>
#include "standard.h"

/* from readnets.c */
extern VOID readnets(P1(FILE *fp));
extern PATHPTR get_path_list(P1(VOID));
extern INT get_total_paths(P1(VOID));
extern VOID add_paths_to_cells(P1(VOID));

/* from netgraph.c */
extern VOID netgraph_free_up(P1(VOID));
extern VOID postFeedAssgn(P1(VOID));
extern VOID rebuild_netgraph(P1(INT net));
extern VOID remove_unnecessary_feed(P2(INT net, INT flag));

extern INT find_set_name(P1(INT v));
extern VOID do_set_union(P2(INT i, INT j));

extern VOID switchable_or_not(P1(VOID));
extern VOID free_z_memory(P1(VOID));
extern VOID postFeedAssgn_carl(P1(VOID));

extern VOID rebuild_netgraph_carl(P1(INT net));

#endif /* !_TWSC_NETS_H */
