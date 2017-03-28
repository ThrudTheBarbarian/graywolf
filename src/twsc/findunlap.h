/* ----------------------------------------------------------------- 
FILE:	    findunlap.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 20:47:36 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_FINDUNLAP_H
#define _TWSC_FINDUNLAP_H

#include <yalecad/base.h>

extern VOID findunlap(P1(INT flag));
extern VOID even_the_rows(P2(INT flag, BOOL even_the_rows_max));

extern VOID findunlap(P1(INT flag));
extern VOID gate_arrayG_even_the_rows(P1(INT flag));

extern INT row_cost(P3(INT long_row , INT short_row , INT width));
extern VOID find_last_6_moveable_cells(P7(INT row, INT *cell1, INT *cell2, INT *cell3, 
												   INT *cell4, INT *cell5, INT *cell6));
extern INT find_longest_row(P1(VOID));
extern INT find_shortest_row(P1(INT long_row));
extern VOID determine_unequal_rows(P2(INT *short_row, INT *long_row));

extern VOID even_the_rows_2(P1(INT iteration));
extern INT check_row_length(P1(VOID));

extern VOID findunlap2(P1(VOID));

#endif /* !_TWSC_FINDUNLAP_H */
