/* ----------------------------------------------------------------- 
"@(#) ucxxglb.h (Yale) version 4.4 9/19/91"
FILE:	    ucxxglb.h                                       
DESCRIPTION:insert file for cell moves.
CONTENTS:   macros and global defs for cell moves.
DATE:	    Mar 27, 1989 
REVISIONS:  Thu Sep 19 14:15:51 EDT 1991 - added equal width cell
		capability.
----------------------------------------------------------------- */
#ifndef UCXXGLB_H
#define UCXXGLB_H

#include "standard.h"

#define MASK 0x3ff 
#define remv_cell( cellptr , post ) (\
( *cellptr != post ) ? (cellptr[ post ] = cellptr[ *cellptr ],\
(*cellptr)-- ) : (*cellptr)-- )
/*
#define add_cell( cellptr , c ) ( cellptr[ ++(*cellptr) ] = c )
*/

/* global variables defined for main */
#ifdef UCXXGLB_VARS
#define EXTERN 
#else
#define EXTERN extern 
#endif

EXTERN INT ablockG , bblockG ;
EXTERN INT aG , bG ;
EXTERN INT ApostG , BpostG ;
EXTERN INT *cellaptrG , *cellbptrG ;
EXTERN INT earlyRejG , Rej_errorG ;
EXTERN INT axcenterG , aycenterG , bxcenterG , bycenterG ;
EXTERN INT aleftG , arightG , bleftG , brightG ;
EXTERN INT attemptsG ;
EXTERN INT potential_errorsG , error_countG , P_limitG ;
EXTERN DOUBLE total_wire_chgG ;
EXTERN DOUBLE sigma_wire_chgG ;
EXTERN DOUBLE mean_wire_chgG ;
EXTERN INT wire_chgsG ;
EXTERN DOUBLE fraction_doneG ;

#undef EXTERN  

/* from uc0.c */
extern VOID uc0(P2(INT a , INT newaor));

/* from ucxx1.c */
extern INT ucxx1(P2(INT bxcenter, INT bycenter));

/* from ucxx2.c */
extern INT ucxx2(P1(VOID));
extern VOID find_new_pos(P1(VOID));
extern VOID add_cell(P2(INT **cellptr, INT c));

/* from ucxxo1.c */
extern INT ucxxo1(P3(INT bxcenter , INT bycenter , INT newaor ));

/* from ucxxo2.c */
extern INT ucxxo2(P2(INT newaor , INT newbor));

/* from ucxxp.c */
extern INT ucxxp(P4(INT a , INT b , INT anxcenter , INT bnxcenter));



#endif /* UCXXGLB_H */
