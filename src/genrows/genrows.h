/* ----------------------------------------------------------------- 
FILE:	    genrows.h                                       
DESCRIPTION:Exported API for the other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017  
REVISIONS:  Sun  5 Mar 2017 10:18:00 PST - Initial creation.
----------------------------------------------------------------- */

#ifndef _GENROW_GENROW_H
#define _GENROW_GENROW_H

#include <yalecad/base.h>
#include <globals.h>

extern VOID init_data_structures(P1(VOID)); 
extern VOID set_feed_length( P1(DOUBLE percent) );
extern VOID process_tiles(P1(VOID));
extern VOID check_tiles(P1(VOID));
extern VOID print_blk_file(P1(VOID));
extern VOID print_tiles(P1(VOID)); 
extern VOID print_vertices(P1(VOID));
extern BOOL find_tile(P4( INT *llx , INT *lly , INT *urx , INT *ury) );
extern BOOL read_vertices(P2(FILE *fp, BOOL initial));
extern BOOL restore_state(P1(FILE *fp) ); 
extern VOID save_state(P1(FILE *fp) ); 
extern VOID process_vertices(P1(VOID));
extern VOID build_macros(P1(VOID));
extern VOID makerows(P1(VOID));
extern BOOL convert_tile_to_rows( P2(TILE_BOX *tileptr, INT add_no_more_than ));
extern VOID divide_tile( P2(TILE_BOX *tile, INT horiz_line ));
extern VOID divide_tilelr( P2(TILE_BOX *tileptr, INT vert_line ));
extern VOID get_core(P5( INT *left, INT *bottom, INT *right, INT *top, BOOL tileFlag ));
extern ROW_BOX  *get_rowptr(P1(VOID));
extern VOID grid_rows(P1(VOID));
extern VOID set_minimum_length( P1(INT length) );
extern VOID set_row_separation(P2(DOUBLE channel_sep_relative, INT channel_sep_absolute));
extern VOID set_spacing(P1(VOID));
extern BOOL force_tiles(P1(VOID));
extern VOID check_user_data(P1(VOID));
extern VOID remakerows(P1(VOID));
extern VOID init_vertex_list(P4(INT left, INT bottom, INT right, INT top ));
extern VOID free_structures( P1(BOOL allpts) );
extern VOID update_tile_memory( P1(BOOL free_flag) );
extern VOID recalculate( P1(BOOL free_flag) );
extern VOID find_core(P1(VOID));
extern BOOL snap_core(P4( INT *l, INT *r, INT *b, INT *t) );
extern VOID set_core(P4( INT left, INT right, INT bottom, INT top ));
extern VOID check_overlap(P1(VOID));
extern INT projectX(P4(INT t1_left, INT t1_right, INT t2_left, INT t2_right ));
extern INT projectY(P4(INT tile1_bot, INT tile1_top, INT tile2_bot, INT tile2_top ));
extern VOID calculate_numrows(P1(VOID));

#endif /* !_GENROW_GENROW_H */