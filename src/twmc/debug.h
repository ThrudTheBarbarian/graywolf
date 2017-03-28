/* ----------------------------------------------------------------- 
"@(#) debug.h (Yale) version 4.7 3/23/92"
FILE:	    debug.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 17:30:21 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_DEBUG_H
#define TWMC_DEBUG_H

#include <yalecad/base.h>

extern VOID dcellList( P1(INT cell ) );
extern BOOL checkbinList( P1(VOID) );
extern VOID dbinList( P1(INT flag) );
extern VOID dbins( P1(INT flag) );
extern VOID dmove( P1(VOID) );
extern VOID dtile(P1(INT cell) );
extern VOID dloadbins( P1(flag) );
extern VOID dcellareas(P1(VOID));
extern VOID dsoftpins(P1(INT cell));

#endif /* !TWMC_DEBUG_H */