/* ----------------------------------------------------------------- 
FILE:	    cdraw.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:06:11 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_CDRAW_H
#define _MC_COMPACT_CDRAW_H

#include <yalecad/base.h>
#include <compact.h>


extern VOID init_graphics(P3(INT argc, char **argv, INT windowId));

extern VOID set_draw_critical(P1(BOOL flag));

extern INT draw_the_data(P1(VOID));

extern VOID process_graphics(P1(VOID));

extern VOID draw_changraph(P1(VOID));


#endif /* !_MC_COMPACT_CDRAW_H */
