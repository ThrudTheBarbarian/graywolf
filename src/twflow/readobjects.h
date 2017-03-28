/* ----------------------------------------------------------------- 
FILE:	    main.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 16:37:19 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _TWFLOW_READOBJECTS_H
#define _TWFLOW_READOBJECTS_H

#include <yalecad/base.h>
#include <globals.h>

extern VOID readobjects(P2(FILE *fp, char *filename));

#endif /* !_TWFLOW_READOBJECTS_H */