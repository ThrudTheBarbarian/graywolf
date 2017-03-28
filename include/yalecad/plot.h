#ifndef __YALE_PLOT_HEADER__
#define __YALE_PLOT_HEADER__

#include "yalecad/base.h"

VOID Yplot_control( P1(BOOL toggle) );
VOID Yplot_init( P2(INT dval, ...) );
VOID Yplot_heading( P2(INT dval, ...) );
VOID Yplot_close(VOID);
VOID Yplot( P2(char * dval, ...) );
VOID Yplot_flush( P1(char * gName));

#endif /* !__YALE_PLOT_HEADER__ */
