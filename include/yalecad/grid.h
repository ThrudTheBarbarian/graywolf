#ifndef __YALE_GRID_HEADER__
#define __YALE_GRID_HEADER__

#include "yalecad/base.h"

/* force coordinate to closest xy grid position */
VOID YforceGrid( P2(INT *x , INT *y) );

/* force coordinate to closest x grid position */
VOID Ygridx( P1(INT *x) );

/* force coordinate to closest x grid position */
VOID Ygridy( P1(INT *y) );

/* force coordinate to smallest x grid position */
VOID Ygridx_down( P1(INT *x) );

/* force coordinate to smallest y grid position */
VOID Ygridy_down( P1(INT *y) );

/* round coordinate to larger x grid position */
VOID Ygridx_up( P1(INT *x) );

/* round coordinate to larger y grid position */
VOID Ygridy_up( P1(INT *y) );

VOID Ygrid_setx( P2(INT x, INT offset) );
VOID Ygrid_sety( P2(INT y, INT offset) );

VOID Ygrid_getx( P2(INT *x, INT *offset) );
VOID Ygrid_gety( P2(INT *y, INT *offset) );

#endif /* !__YALE_GRID_HEADER__ */
