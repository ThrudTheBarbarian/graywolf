/* ----------------------------------------------------------------- 
FILE:	    findrcost.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 19:48:20 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_FINDRCOST_H
#define _TWSC_FINDRCOST_H

#include <yalecad/base.h>
#include "standard.h"

extern VOID findrcost(P1(VOID));
extern VOID initial_tracks(P1(SEGBOXPTR segptr));
extern VOID set_cedgebin(P1(VOID));
extern VOID reset_track(P1(VOID));
extern INT facing_cellheight(P4(INT pin , INT row , INT pinloc , INT status));
extern INT fcellheight(P3(INT  pin , INT *fcell , INT status));

#endif /* !_TWSC_FINDRCOST_H */
