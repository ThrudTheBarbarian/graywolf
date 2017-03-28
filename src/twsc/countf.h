/* ----------------------------------------------------------------- 
FILE:	    countf.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Tue  7 Mar 2017 18:44:21 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_COUNTF_H
#define _TWSC_COUNTF_H

#include <yalecad/base.h>

extern INT countf(P1(VOID));
extern VOID prep_feed_count_1(P1(VOID));
extern VOID prep_feed_count(P1(VOID));
extern VOID insert_row(P1(INT flag));
extern INT feed_situation(P2(INT row , INT net));

#endif /* !_TWSC_COUNTF_H */
