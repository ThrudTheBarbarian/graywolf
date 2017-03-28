/* ----------------------------------------------------------------- 
"@(#) parser.h (Yale) version 4.5 9/7/90"
FILE:	    parser.h                                       
DESCRIPTION:definitions for parsing.
CONTENTS:   
DATE:	    Dec  8, 1989 
REVISIONS:  
----------------------------------------------------------------- */
#ifndef PARSER_H
#define PARSER_H

#include <yalecad/base.h>
#include <yalecad/hash.h>

#ifdef PARSER_VARS
#define EXTERN 
#else
#define EXTERN extern 
#endif

/* cell types */
#define STDCELLTYPE       1
#define EXCEPTTYPE        2
#define PADTYPE           3
#define PORTTYPE          4
#define EXTRATYPE         5
#define PADGROUPTYPE      6
#define HARDCELLTYPE      7
/* pin types */
#define PINTYPE           1
#define PASS_THRU         2
#define SWAP_PASS         3

EXTERN SWAPBOX *swap_group_listG ;
EXTERN BOOL one_pin_feedthruG ;

EXTERN INT case_unequiv_pinG ;
EXTERN INT celllenG ;
EXTERN INT cells_per_clusterG ;
EXTERN INT cluster_widthG ;
EXTERN INT extra_cellsG ;
EXTERN INT *fixLRBTG ;
EXTERN INT last_pin_numberG ;
EXTERN INT num_clustersG ;
EXTERN BOOL swappable_gates_existG ;

EXTERN INT swap_netG ;
EXTERN INT totallenG ;
EXTERN DOUBLE *padspaceG ;

#undef EXTERN  

extern VOID set_error_flag(P1(VOID));
extern VOID initialize_parser(P1(VOID));

extern VOID addCell(P2(char *cellname, INT celltype));
extern VOID add_tile(P4(INT left, INT bottom, INT right, INT top));

extern VOID add_initial_orient(P1(INT orient));

extern VOID add_swap_group(P1(char *swap_name));
extern VOID add_pingroup(P1(VOID));
extern VOID end_pingroup(P1(VOID));

extern VOID add_pin(P5(char *pin_name, char *signal, INT layer, INT xpos, INT ypos));
extern VOID add_equiv(P5(char *equiv_name, INT layer, INT x, INT y, BOOL unequiv_flag));
extern VOID add_port(P5(char *portname, char *signal, INT layer, INT xpos, INT ypos));

extern VOID init_legal_blocks(P1(INT numblocks));
extern VOID add_legal_blocks(P1(INT block_class));

extern VOID set_mirror_flag(P1(VOID));
extern VOID add_orient(P1(INT orient));

extern VOID fix_placement(P4(char *fixed_type, INT from, char *fixed_loc, INT block));
extern VOID add_extra_cells(P1(VOID));
extern VOID cleanup_readcells(P1(VOID));

extern VOID not_supported(P1(char *object));

extern YHASHPTR get_net_table(P1(VOID));

extern VOID add_eco(P1(VOID));

extern VOID init_corners(P1(VOID));
extern VOID add_corner(P2(INT x, INT y));
extern VOID process_corners(P1(VOID));

extern VOID add_padside(P1(char *padside));
extern VOID add_sidespace(P2(DOUBLE lower, DOUBLE upper));
extern VOID setPermutation(P1(INT permuteFlag)); 
extern VOID set_old_format(P1(char *padside));
extern VOID add2padgroup(P2(char * padName, BOOL ordered));
extern VOID end_padgroup(P1(VOID));

#endif /* PARSER_H */
