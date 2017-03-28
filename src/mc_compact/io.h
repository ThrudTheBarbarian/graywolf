/* ----------------------------------------------------------------- 
FILE:	    io.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 19:13:42 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_IO_H
#define _MC_COMPACT_IO_H

#include <yalecad/base.h>
#include <compact.h>


extern VOID init(P2(INT numtiles, INT numcells));

extern VOID final_tiles(P1(VOID));
extern VOID setErrorFlag(P1(VOID));

extern VOID initCell(P6(INT celltype, INT cellnum, INT x, INT y, INT xoff, INT yoff));
extern VOID init_extra_tile(P2(INT cell, INT type));

extern INT addtile(P4(INT l, INT r, INT b, INT t));

extern VOID endCell(P1(VOID));
extern VOID process_tiles(P1(VOID));
extern VOID addSourceNSink(P1(VOID));

extern VOID output(P1(VOID));


#endif /* !_MC_COMPACT_IO_H */
