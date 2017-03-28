/* ----------------------------------------------------------------- 
FILE:	    initialize.h
DESCRIPTION:Header file for initialize.c
CONTENTS:   
DATE:	    March 15, 1990 
REVISIONS:  Wed Dec 19 19:38:46 EST 1990 - added analog pin type.
----------------------------------------------------------------- */
/* *****************************************************************
   static char SccsId[] = "@(#) initialize.h version 3.4 12/19/90" ;
***************************************************************** */
#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <yalecad/base.h>
#include <yalecad/hash.h>
#include <custom.h>

#define PINGROUPTYPE     1
#define HARDPINTYPE      2
#define SOFTPINTYPE      3
#define SOFTEQUIVTYPE    4
#define HARDEQUIVTYPE    5
#define ADDEQUIVTYPE     6
#define ANALOGPINTYPE    7

extern VOID setErrorFlag(P1(VOID));
extern YHASHPTR getNetTable(P1(VOID));
extern VOID initCellInfo(P1(VOID));
extern VOID cleanupReadCells(P1(VOID));
extern VOID endCell(P1(VOID));

extern VOID addCell(P2(char *cellName, CELLTYPE cellType));
extern VOID fixCell(P9(INT fixedType, INT xloc, char * lorR, 
									  INT yloc, char * borT, 
									  INT xloc2, char *lorR2, 
									  INT yloc2, char *borT2));
extern VOID processCorners(P1(INT numCorners));
extern VOID addCorner(P2(INT xpos, INT ypos));
extern VOID initializeCorner(P1(INT cell));
extern VOID addClass(P1(INT class));
extern VOID initOrient(P1(INT orient));
extern VOID addOrient(P1(INT orient));
extern VOID set_cur_orient(P1(INT orient));
extern VOID addAspectBounds(P2(DOUBLE lowerBound, DOUBLE upperBound));
extern PINBOXPTR addPinAndNet(P2(char *pinName, char *signal));
extern VOID addPin(P4(char *pinName, char *signal, INT layer, INT pinType));
extern VOID set_pin_pos(P2(INT xpos, INT ypos));
extern VOID addEquivPin(P5(char *pinName, INT layer, INT xpos, INT ypos, INT pinType));
extern VOID set_restrict_type(P1(INT object));
extern VOID addSideRestriction(P1(INT side));
extern VOID add_pinspace(P2(DOUBLE lower, DOUBLE upper));
extern VOID add_soft_array(P1(VOID));

extern VOID start_pin_group(P2(char *pingroup, BOOL permute));
extern VOID add2pingroup(P2(char *pinName, BOOL ordered)); 
extern VOID addSideSpace(P2(DOUBLE lower, DOUBLE upper));
extern VOID addPadSide(P1(char *side));
extern VOID setPermutation(P1(INT permuteFlag)); 
extern VOID add2padgroup(P2(char *padName, BOOL ordered));
extern VOID add_cell_to_group(P1(char *cellName));
extern VOID add_instance(P1(char *instName));
extern INT get_tile_count(P1(VOID));
extern VOID add_analog(P1(INT numcorners));
extern VOID add_pin_contour(P2(INT x, INT y));
extern VOID add_current(P1(DOUBLE current));
extern VOID add_power(P1(DOUBLE power));
extern VOID no_layer_change(P1(VOID));
extern VOID process_pin(P1(VOID));

/* from initnets.c */
extern VOID init_nets(P1(VOID));
extern VOID cleanup_nets(P1(VOID));
extern VOID set_net_error(P1(VOID));
extern VOID add_path(P2(BOOL pathFlag, char *net));
extern VOID end_path(P3(INT lower_bound, INT upper_bound, INT priority));
extern VOID build_path_array(P1(VOID));
extern PATHPTR get_path_list(P1(VOID));
extern INT get_total_paths(P1(VOID));
extern VOID add_paths_to_cells(P1(VOID));
extern VOID init_analog(P1(char *net));
extern VOID set_cap_upper_bound(P1(DOUBLE cap));
extern VOID set_res_upper_bound(P1(DOUBLE cap));
extern VOID set_net_type(P1(INT net_type));
extern VOID set_max_voltage_drop(P1(DOUBLE cap));
extern VOID add_common_pt(P1(VOID));
extern VOID add2common(P2(char *cell, char *pin));
extern VOID common_cap(P2(char *cell, char *pin));
extern VOID common_res(P2(char *cell, char *pin));
extern VOID start_net_capmatch(P1(char *netname));
extern VOID add_net_capmatch(P1(char *netname));
extern VOID start_net_resmatch(P1(char *netname));
extern VOID add_net_resmatch(P1(char *netname));











#endif /* INITIALIZE_H */
