/* ----------------------------------------------------------------- 
"@(#) paths.h (Yale) version 4.7 3/23/92"
FILE:	    paths.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 20:39:32 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_PATHS_H
#define TWMC_PATHS_H

#include <yalecad/base.h>
#include <custom.h>

extern VOID print_paths(P1(VOID)); 
extern INT calc_incr_time(P1(INT cell)); 
extern VOID update_time(P1(INT cell));
extern INT calc_incr_time2( P2(INT cella, INT cellb)); 
extern VOID update_time2(P2(INT cella, INT cellb));
extern VOID init_path_set(P1(VOID));
extern VOID add2path_set(P1(INT path)); 
extern PSETPTR enum_path_set(P1(VOID));
extern VOID clear_path_set(P1(VOID));

extern VOID init_net_set(P1(VOID));
extern VOID add2net_set(P1(INT net)); 
extern BOOL member_net_set(P1(INT net));
extern VOID clear_net_set(P1(VOID));

extern INT dcalc_full_penalty(P1(VOID));
extern INT dcalc_min_path_len(P1(INT path_num));
extern INT dcalc_max_path_len(P1(INT path_num));


#endif /* !TWMC_PATHS_H */