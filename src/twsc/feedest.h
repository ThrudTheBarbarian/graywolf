/* ----------------------------------------------------------------- 
FILE:	    feedest.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 20:29:29 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_FEEDEST_H
#define _TWSC_FEEDEST_H

#include <yalecad/base.h>

extern VOID feedest(P1(VOID));
extern VOID re_estimate_feed_penalty(P1(VOID));
extern VOID estimate_pass_thru_penalty(P2(INT row1 , INT row2));

extern VOID update_feedest(P1(INT net));
extern VOID free_up_feedest_malloc(P1(VOID));

extern VOID update_segment_data(P1(SEGBOXPTR segptr));
extern PINBOXPTR makeSTpt( P3(INT net , PINBOXPTR ptr1 , PINBOXPTR ptr2 ));
extern SEGBOXPTR makeseg(P2(PINBOXPTR lowptr , PINBOXPTR highptr ));

extern VOID dbg_cost(P1(VOID));
extern VOID dbx_fdpen(P1(VOID));


#endif /* !_TWSC_FEEDEST_H */
