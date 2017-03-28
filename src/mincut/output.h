/* ----------------------------------------------------------------- 
FILE:	    output.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 10:47:19 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _MINCUT_OUTPUT_H
#define _MINCUT_OUTPUT_H

#include <yalecad/base.h>

extern VOID init(P1(VOID));
extern VOID addCell(P2(INT celltype, char *cellname));
extern VOID addNet(P1(char *signal ));
extern VOID set_bbox(P4(INT left, INT right, INT bottom, INT top ));
extern VOID output(P1(FILE *fp));
extern VOID read_par(VOID);
extern VOID update_stats(P1(FILE *fp));

#endif /* !_MINCUT_OUTPUT_H */