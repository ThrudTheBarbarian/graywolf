/* ----------------------------------------------------------------- 
FILE:	    autoflow.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 15:54:20 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _TWFLOW_AUTOFLOW_H
#define _TWFLOW_AUTOFLOW_H

#include <yalecad/base.h>
#include <globals.h>

extern VOID auto_flow(P1(VOID));
extern VOID exec_single_prog(P1(VOID));
extern VOID report_problem(P1(ADJPTR adjptr));
extern BOOL check_dependencies(P1(ADJPTR adjptr));
extern VOID autoflow_set_object(P1(INT object));

#endif /* !_TWFLOW_AUTOFLOW_H */