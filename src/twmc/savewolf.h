/* ----------------------------------------------------------------- 
"@(#) savewolf.h (Yale) version 4.7 3/23/92"
FILE:	    savewolf.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 19:52:52 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_SAVEWOLF_H
#define TWMC_SAVEWOLF_H

#include <yalecad/base.h>
#include <custom.h>

extern VOID savewolf( P1(BOOL forceSave) );
extern BOOL TW_oldinput(P1(FILE *fp));
extern VOID HPO(P2(FILE *fp, DOUBLE d));  
extern VOID HPI(P2(FILE *fp, DOUBLE *d));  

/* from outgeo.c */
extern VOID outgeo(P1(VOID));

/* from outpin.c */
extern VOID outpin(P1(VOID));
extern VOID setPadMacroNum(P2(INT side, INT cellnum));
extern PINBOXPTR findTerminal(P2(char *pinName, INT cell));
extern INT get_circuit_type(P1(VOID));



#endif /* !TWMC_SAVEWOLF_H */