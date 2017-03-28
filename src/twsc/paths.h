/* ----------------------------------------------------------------- 
FILE:	    paths.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 21:16:48 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_PATHS_H
#define _TWSC_PATHS_H

#include <yalecad/base.h>
#include "standard.h"

extern VOID print_paths(P1(VOID));

extern INT calc_incr_time(P1(INT cell));
extern VOID update_time(P1(INT cell));

extern INT calc_incr_time2(P2(INT cella, INT cellb));
extern VOID update_time2(P1(VOID));

extern VOID init_path_set(P1(VOID)); 
extern VOID add2path_set(P1(INT path)); 

extern PSETPTR enum_path_set(P1(VOID));
extern VOID clear_path_set(P1(VOID));

extern VOID init_net_set(P1(VOID));
extern VOID add2net_set(P1(INT net));
extern BOOL member_net_set(P1(INT net));
extern VOID clear_net_set(P1(VOID));
 
#ifdef DEBUG
extern INT dcalc_full_penalty(P1(INT newtimepenal));
extern INT dcalc_path_len(P2(INT path_num, INT verify_length));
extern INT dpath_len(P2(INT net_num, BOOL old_not_new));
extern INT dprint_error(P1(VOID));
extern VOID dverify_nets(P1(VOID));
extern VOID dprint_paths(P1(INT cell));
extern VOID dprint_net_set(P1(VOID));
#endif /* DEBUG */

extern DOUBLE calc_time_factor(P1(VOID)); 
extern VOID calc_init_timeFactor(P1(VOID));
 
#endif /* !_TWSC_PATHS_H */
