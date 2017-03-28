/* ----------------------------------------------------------------- 
FILE:	    uloop.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	   Sat Mar  4 14:05:21 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_ACCEPTT_H
#define _TWSC_ACCEPTT_H

#include <yalecad/base.h>

extern VOID init_uloop(P1(VOID));
extern VOID uloop(P1(VOID));
extern VOID rowcon(P1(VOID));


extern DOUBLE partition(P4(INT C_initial , INT k_initial , 
						   INT p_initial , INT R_initial));
						   
extern DOUBLE expected_value(P4(INT C_initial , INT k_initial , 
								INT p_initial , INT R_initial));

extern DOUBLE expected_svalue(P4(INT C_initial , INT k_initial , 
								 INT p_initial , INT R_initial));
								
extern DOUBLE compute_and_combination(P4(INT C_initial , INT k_initial , 
										 INT p_initial , INT R_initial));

extern DOUBLE combination(P2(INT numerator , INT denominator));

extern INT eval_ratio(P1(DOUBLE *t));


extern VOID init_control(P1(INT first));

extern VOID pick_fence_position(P3(INT *x, INT *y, FENCEBOX *fence));

extern VOID pick_position(P5(INT *x, INT *y, INT ox, INT oy, DOUBLE scale));

extern VOID update_window_size(P1(DOUBLE iternum));

extern VOID save_control(P1(FILE *fp));
extern VOID read_control(P1(FILE *fp));

extern INT tw_frozen(P1(INT cost));

#endif /* !_TWSC_ACCEPTT_H */
