#ifndef __YALE_MST_HEADER__
#define __YALE_MST_HEADER__

#include <yalecad/base.h>

VOID Ymst_init( P1(INT numpins) );
VOID Ymst_free( P1(VOID) );
VOID Ymst_clear( P1(VOID) );
VOID Ymst_addpt( P2(INT x, INT y) );
VOID Ymst_draw( P1(VOID) );
VOID Ymst_enumerate( P5(INT *x1, INT *y1, INT *x2, INT *y2, BOOL startFlag) );
VOID Ymst_color( P1(INT color) );



#endif /* !__YALE_MST_HEADER__ */