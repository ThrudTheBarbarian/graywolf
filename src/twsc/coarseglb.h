/* ----------------------------------------------------------------- 
FILE:	    coarseglb.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 19:59:51 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_COARSEGLB_H
#define _TWSC_COARSEGLB_H

#include <yalecad/base.h>

extern VOID coarseglb(P1(VOID)); 
extern VOID assign_row_to_pin(P1(VOID)); 
extern VOID set_up_grid(P1(VOID)); 
extern VOID initialize_feed_need(P1(VOID)); 
extern VOID feed_config(P1(VOID)); 
extern INT set_node(P1(INT x)); 
extern VOID compute_feed_diff(P1(INT iteration)); 
extern INT space_for_feed(P1(VOID)); 
extern VOID update_feed_config(P1(INT iteration)); 
extern INT no_of_feedthru_cells(P1(VOID)); 
extern VOID addin_feedcell(P1(VOID)); 
extern VOID final_feed_config(P1(VOID)); 
extern VOID free_cglb_data(P1(VOID)); 


#endif /* !_TWSC_COARSEGLB_H */
