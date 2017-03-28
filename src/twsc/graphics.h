/* ----------------------------------------------------------------- 
FILE:	    graphics.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 20:59:55 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_GRAPHICS_H
#define _TWSC_GRAPHICS_H

#include <yalecad/base.h>

extern VOID initGraphics(P3(INT argc, char **argv, INT windowId));

extern VOID init_heat_index(P1(VOID));
extern VOID expand_heat_index(P1(VOID));
extern VOID setGraphicWindow(P1(VOID));
extern VOID process_graphics(P1(VOID));

extern INT draw_the_data(P1(VOID));
extern VOID draw_a_cell(P1(INT cell));
extern VOID erase_a_cell(P3(INT cell, INT x, INT y));

extern VOID graphics_dump(P1(VOID));
extern VOID check_graphics(P1(BOOL drawFlag));
extern VOID graphics_cell_update(P1(INT cell));
extern VOID graphics_cell_attempt(P1(INT cell));

extern VOID reset_heat_index(P1(VOID));

extern VOID set_update(P1(BOOL flag));

extern VOID closegraphics(P1(VOID));

#endif /* !_TWSC_GRAPHICS_H */
