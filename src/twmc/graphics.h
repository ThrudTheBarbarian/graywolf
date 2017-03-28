/* ----------------------------------------------------------------- 
"@(#) graphics.h (Yale) version 4.7 3/23/92"
FILE:	    graphics.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 17:56:51 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_GRAPHICS_H
#define TWMC_GRAPHICS_H

#include <yalecad/base.h>
#include <yalecad/draw.h>
#include <custom.h>

extern VOID initMCGraphics( P3(INT argc, char **argv, INT windowId) );
extern VOID setGraphicWindow(P1(VOID)); 
extern VOID set_graphic_context( P1(INT context) );
extern VOID process_graphics(P1(VOID));
extern INT pick_cell(P1(VOID));
extern INT draw_the_data(P1(VOID));
extern VOID dsetDump( P1(BOOL flag) );
extern BOOL dgetDump(P1(VOID));
extern VOID graphics_dump(P1(VOID)); 
extern VOID set_graphics_wait_menu(TWMENUBOX menus[] );

/* From prboard.c */
extern VOID grid_cells(P1(VOID));

/* from window.c */
extern VOID init_control(P1(BOOL first));
extern VOID pick_position(P4(INT *x, INT *y, INT ox, INT oy));
extern VOID pick_neighborhood(P5(INT *x, INT *y, INT ox, INT oy, FIXEDBOXPTR fixptr));
extern VOID update_window_size(P1(DOUBLE iteration));
extern VOID fix_window(P1(VOID));
extern VOID save_window(P1(FILE *fp));
extern INT read_window(P1(FILE *fp));


#endif /* !TWMC_GRAPHICS_H */