/* ----------------------------------------------------------------- 
FILE:	    io.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 15:54:20 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _TWFLOW_IO_H
#define _TWFLOW_IO_H

#include <yalecad/base.h>
#include <globals.h>

extern VOID setErrorFlag(P1(VOID));
extern VOID init(P1(INT numobj));

extern VOID add_object(P2(char *pname, INT node));
extern VOID add_pdependency(P1(INT fromNode ));
extern VOID add_path(P1(char *pathname));
extern VOID set_file_type(P1(BOOL type));
extern VOID add_fdependency(P1(char *file)); 
extern VOID add_args(P1(char *argument));
extern VOID add_box(P4(INT l, INT b, INT r, INT t));
extern VOID start_edge(P1(INT fromNode));
extern VOID add_line(P4(INT x1, INT y1, INT x2, INT y2 ));
extern ADJPTR findEdge(P3(INT from, INT to, BOOL direction ));
extern VOID process_arcs(P1(VOID));
extern VOID unmark_edges(P1(VOID));

#ifndef NOGRAPHICS
extern VOID set_window(P1(VOID));
#endif /* !NOGRAPHICS */

#endif /* !_TWFLOW_IO_H */