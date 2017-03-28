/* ----------------------------------------------------------------- 
"@(#) finalout.h (Yale) version 4.7 3/23/92"
FILE:	    finalout.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 17:54:51 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_FINALOUT_H
#define TWMC_FINALOUT_H

#include <yalecad/base.h>
#include <custom.h>

extern VOID finalout(P1(VOID));
extern VOID prnt_cost(P1(char *out_string));

/* From output.c */
extern VOID output( P1(FILE *fp) );
extern VOID output_pads( P1(FILE *fp) );
extern VOID set_determine_side( P1(BOOL flag) );
extern VOID output_vertices( P2(FILE *fp, CELLBOXPTR cellptr ));
extern VOID create_sc_output(P1(VOID));

/* from finalpin.c */
#ifdef LATER
extern VOID finalpin(P1(VOID));
extern VOID final_pin_place(P1(VOID));
extern VOID update_sites(P1(CELLBOXPTR cellptr));
extern find_closest_site(P6(CELLBOXPTR cellptr, CONTENTPTR *sitePtr, 
			PINBOXPTR *curSidePins, INT numsoftpins, 
    		INT firstSite, INT lastSite));
#endif

#endif /* !TWMC_FINALOUT_H */