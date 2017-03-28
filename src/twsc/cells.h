/* ----------------------------------------------------------------- 
FILE:	    cells.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 20:17:54 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_ACCEPTT_H
#define _TWSC_ACCEPTT_H

#include <yalecad/base.h>

/* from readcell.h */
extern VOID readcell(P1(FILE *fp));

/* from cell_width.c */
extern VOID calc_cells_width(P1(VOID));

/* from crossbus.h */
extern VOID handle_crossbuses(P1(VOID));
extern VOID check_violations(P1(VOID));
extern INT reduce_violations(P1(VOID));

#endif /* !_TWSC_ACCEPTT_H */
