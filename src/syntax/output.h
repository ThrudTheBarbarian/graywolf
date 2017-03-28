/* ----------------------------------------------------------------- 
FILE:	    output.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 18:33:44 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _SYNTAX_OUTPUT_H
#define _SYNTAX_OUTPUT_H

#include <yalecad/base.h>
#include <globals.h>

extern VOID init(P1(VOID));

extern VOID addCell(P2(INT celltype, char *cellname));
extern VOID addNet(P1(char *signal));

extern VOID addEquiv(P1(VOID));
extern VOID addUnEquiv(P1(VOID));
extern VOID add_instance(P1(VOID));

extern VOID set_bbox(P4(INT left, INT right, INT bottom, INT top));
extern VOID start_pt(P2(INT x, INT y));
extern VOID add_pt(P2(INT x, INT y));
extern VOID processCorners(P1(VOID));

extern VOID check_xloc(P1(char *value));
extern VOID check_yloc(P1(char *value));
extern VOID check_sideplace(P1(char *side));

extern VOID set_pinname(P1(char *pinname));

extern VOID check_pos(P2(INT x, INT y));

extern VOID output(P1(VOID));

#endif /* !_SYNTAX_OUTPUT_H */
