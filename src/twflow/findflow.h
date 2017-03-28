/* ----------------------------------------------------------------- 
FILE:	    findflow.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 16:17:49 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _TWFLOW_FINDFLOW_H
#define _TWFLOW_FINDFLOW_H

#include <yalecad/base.h>
#include <globals.h>

extern FILE *find_flow_file(P3(BOOL general_mode, BOOL debug, char *filename));
extern INT find_design_type(P1(VOID));


#endif /* !_TWFLOW_FINDFLOW_H */