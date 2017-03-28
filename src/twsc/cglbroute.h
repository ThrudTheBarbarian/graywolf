/* ----------------------------------------------------------------- 
FILE:	    cglbroute.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Sun  5 Mar 2017 20:46:27 PST 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_CGLBROUTE_H
#define _TWSC_CGLBROUTE_H

#include <yalecad/base.h>

extern VOID cglb_initial(P1(VOID)); 
extern VOID proj_tree_to_grid(P1(VOID)); 
extern VOID set_cbucket(P1(VOID)); 
extern VOID cglbroute(P1(VOID)); 
extern VOID free_cglb_initial(P1(VOID)); 
extern VOID reinitial_Hdensity(P1(VOID)); 
extern VOID update_switchvalue(P1(VOID)); 
extern VOID rebuild_cbucket(P1(VOID)); 

extern VOID check_cbucket(P1(VOID)); 
extern VOID print_bucket(P1(INT row)); 

#endif /* !_TWSC_CGLBROUTE_H */
