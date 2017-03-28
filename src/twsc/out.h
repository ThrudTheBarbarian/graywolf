/* ----------------------------------------------------------------- 
FILE:	    out.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Mon Mar  6 22:31:52 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_OUT_H
#define _TWSC_OUT_H

#include <yalecad/base.h>
#include "standard.h"

/* from outcm.h */
extern VOID outcm(P1(VOID));
extern VOID incm(P1(FILE *fp));

/* from outpins.c */
extern VOID outpins(P1(VOID));
extern char *find_layer(P2(char *pinname, INT *layer));
extern VOID set_pin_format(P1(BOOL flag));

/* from output.c */
extern VOID output(P1(VOID));
extern VOID final_free_up(P1(VOID));
extern VOID density(P1(VOID));

/* from outpins1.c */
extern VOID old_outpins(P1(VOID));

#endif /* !_TWSC_OUT_H */
