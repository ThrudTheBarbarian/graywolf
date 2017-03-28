/* ----------------------------------------------------------------- 
FILE:	    merge.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 10:47:19 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _GENROW_MERGE_H
#define _GENROW_MERGE_H

#include <yalecad/base.h>

extern VOID merge_tiles(P1(VOID));
extern VOID merge_upward(P1(TILE_BOX *begin_tile));
extern VOID merge_downward(P1(TILE_BOX *begin_tile));
extern VOID merge_right(P1(TILE_BOX *begin_tile));
extern VOID merge_left(P1(TILE_BOX *begin_tile));
extern VOID renumber_tiles(P1(VOID));
extern VOID dtiles(P1(VOID));

#endif /* !_GENROW_MERGE_H */