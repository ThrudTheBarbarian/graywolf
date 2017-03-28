/* ----------------------------------------------------------------- 
FILE:	    globe.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 20:08:33 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_GLOBE_H
#define _TWSC_GLOBE_H

#include <yalecad/base.h>

extern INT globe(P1(VOID));
extern VOID globe_free_up(P1(VOID));
extern VOID preFeedAssgn(P1(VOID));
extern VOID free_static_in_globe(P1(VOID));

extern VOID FeedAssgn(P1(INT row));
extern VOID row_seg_intersect(P3(PINBOXPTR ptr1 , PINBOXPTR ptr2 , SEGBOXPTR segptr ));
extern VOID copy_workerS_field(P2(FEED_SEG_PTR aptr, FEED_SEG_PTR bptr));
extern VOID assgn_impin(P3(IPBOXPTR imptr , FEED_SEG_PTR fsptr , INT row ));
extern VOID local_Assgn(P2(INT row , INT node));

extern VOID unequiv_pin_pre_processing(P1(VOID));
extern VOID relax_padPins_pinloc(P1(VOID));
extern VOID relax_unequiv_pinloc(P1(VOID));
extern INT check_unequiv_connectivity(P1(VOID));

extern INT improve_place_sequential(P2(INT row , INT index));
extern INT cell_rotate(P2(INT row , INT index));
extern VOID elim_unused_feedsSC(P1(VOID));
extern VOID rebuild_nextpin(P1(VOID));
extern VOID rebuild_cell_paths(P1(VOID));

#endif /* !_TWSC_GLOBE_H */
