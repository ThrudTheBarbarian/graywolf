/* ----------------------------------------------------------------- 
FILE:	    stdmacro.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 20:39:44 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _MC_COMPACT_STDMACRO_H
#define _MC_COMPACT_STDMACRO_H

#include <yalecad/base.h>
#include <compact.h>

extern VOID partition_compact(P1(VOID));
extern BOOL depth_first_search(P1(VOID));
extern BOOL remove_problem(P2(INT source, INT sink));

#endif /* !_MC_COMPACT_STDMACRO_H */
