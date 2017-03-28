/* ----------------------------------------------------------------- 
FILE:	    graphics.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 16:05:27 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _TWFLOW_GRAPHICS_H
#define _TWFLOW_GRAPHICS_H

#include <yalecad/base.h>
#include <globals.h>

extern VOID init_graphics(P3(INT argc, char **argv, INT windowId));
extern INT draw_the_data(P1(VOID));
extern VOID process_graphics(P1(VOID));
extern ADJPTR get_edge_from_user(P2( OBJECTPTR obj, BOOL direction ));
extern VOID graphics_set_object(P1(INT object ));
extern INT find_obj(P1(VOID));
extern ADJPTR make_decision(P2(OBJECTPTR obj, BOOL direction));

#endif /* !_TWFLOW_GRAPHICS_H */