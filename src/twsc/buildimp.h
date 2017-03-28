/* ----------------------------------------------------------------- 
FILE:	    buildimp.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 20:25:07 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_BUILDIMP_H
#define _TWSC_BUILDIMP_H

#include <yalecad/base.h>

extern VOID buildimp(P1(VOID));
extern VOID link_imptr(P1(VOID));
extern VOID decide_boundary(P1(VOID));
extern VOID fixwolf(P1(VOID));
extern VOID addfeed(P3(INT row , INT pos , INT feednum));
 
#endif /* !_TWSC_BUILDIMP_H */
