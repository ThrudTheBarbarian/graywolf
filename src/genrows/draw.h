/* ----------------------------------------------------------------- 
FILE:	    draw.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sat  4 Mar 2017  
REVISIONS:  Sat  4 Mar 2017 23:00:30 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _GENROW_DRAW_H
#define _GENROW_DRAW_H

#include <yalecad/base.h>

extern VOID initgraphics(P3(INT argc, char **argv, INT windowId ));
extern INT draw_the_data(P1(VOID));
extern VOID process_graphics(P1(VOID));
extern VOID edit_row( P1(ROW_BOX *rowptr ));


#endif /* !_GENROW_DRAW_H */