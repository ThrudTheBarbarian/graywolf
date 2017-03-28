/* ----------------------------------------------------------------- 
FILE:	    rowevener.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 20:53:00 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_ROWEVENER_H
#define _TWSC_ROWEVENER_H

#include <yalecad/base.h>

extern VOID rowevener(P1(VOID)); 
extern VOID decide_right_most_in_class(P1(VOID)); 

extern VOID dump_rowlength(P1(INT flag)); 

#endif /* !_TWSC_ROWEVENER_H */
