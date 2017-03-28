/* *****************************************************************
   static char SccsId[] = "@(#) pads.h version 3.6 2/23/91" ;
***************************************************************** */
#ifndef PADS_H
#define PADS_H 

#include <yalecad/base.h>
#include "custom.h"

/* control for pad spacing */
#define UNIFORM_PADS  0
#define VARIABLE_PADS 1
#define ABUT_PADS     2
#define EXACT_PADS    3

/* pad sides */
#define ALL     0
#define L       1
#define T       2
#define R       3
#define B       4

#define MINI  0
#define MAXI  1

#define X     0
#define Y     1

#define HOWMANY 0
#define LARGE 100000
#define PINFINITY INT_MAX / 8
#define PICK_INT(l,u) (((l)<(u)) ? ((RAND % ((u)-(l)+1))+(l)) : (l))

/* pad hierarchy */
#define NONE      0
#define LEAF      1
#define SUBROOT   2
#define ROOT      3

extern VOID placepads( P1(VOID) );
extern VOID call_place_pads(P1(VOID));

extern INT find_numnets(P1(VOID));

extern VOID align_pads( P1(VOID) );
extern VOID calc_constraints( P7(PADBOXPTR pad, INT side, DOUBLE *lb, DOUBLE *ub, 
							     BOOL *spacing_restricted, INT *lowpos, INT *uppos ));
							     
extern VOID dimension_pads(P1(VOID));
extern VOID orient_pads(P1(VOID));
extern VOID setVirtualCore( P1(BOOL flag) );
extern VOID find_core_boundary(P4(INT *left, INT *right, INT *bottom, INT *top));
extern VOID get_global_pos(P5(INT cell, INT *l, INT *b, INT *r, INT *t));
extern VOID get_routing_boundary(P5(INT cell, INT *l, INT *b, INT *r, INT *t));

extern VOID output_nets(P2(FILE *fp, INT numnets));

/* from sortpad.c */
extern VOID sort_pads(P1(VOID));

#endif /* PADS_H */
