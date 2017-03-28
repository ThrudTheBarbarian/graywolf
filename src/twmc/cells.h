/* ----------------------------------------------------------------- 
"@(#) fixcell.h (Yale) version 4.7 3/23/92"
FILE:	    fixcell.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 16:49:06 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_FIXCELL_H
#define TWMC_FIXCELL_H

#include <yalecad/base.h>
#include <compact.h>
#include <custom.h>

/* from fixcell.c */
extern VOID updateFixedCells( P1(BOOL initializeFlag) );
extern VOID init_fixcell(P4(INT left, INT bottom, INT right, INT top));
extern VOID build_active_array(P1(VOID));
extern VOID build_soft_array(P1(VOID));
extern VOID determine_origin(P4(INT *x, INT *y, char *left_not_right, char *bottom_not_top));
extern VOID delete_fix_constraint(P1(INT cell));

/* from readcells.c */
extern VOID readcells(P1(FILE *fp));

/* from uaspect.c */
extern BOOL uaspect(P2(INT a , double newAspect ));
extern VOID initialize_aspect_ratios(P1(VOID));

/* from mergecells.c */
extern VOID mergeCells(P2(CELLBOXPTR cptr, CELLBOXPTR pptr ));

/* from uinst.c */
extern BOOL uinst(P1(VOID));

#endif /* !TWMC_FIXCELL_H */