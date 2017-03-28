/* ----------------------------------------------------------------- 
FILE:	    overlap.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 20:00:22 PST 2017 
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_OVERLAP_H
#define _TWSC_OVERLAP_H

#include <yalecad/base.h>
#include "standard.h"

/* from overlap.c */
extern VOID new_old(P1(INT c)); 
extern VOID old_assgnto_new1(P4(INT alobin , INT ahibin , INT anewlobin , INT anewhibin));
extern VOID new_assgnto_old1(P4(INT alobin , INT ahibin , INT anewlobin , INT anewhibin));

extern VOID old_assgnto_new2(P8(INT a1lobin, INT a1hibin, INT a2lobin,    INT a2hibin ,
		 	 					INT b1lobin, INT b1hibin, INT b2lobin,    INT b2hibin ));
extern VOID new_assgnto_old2(P8(INT a1lobin, INT a1hibin, INT a2lobin,    INT a2hibin ,
		 	 					INT b1lobin, INT b1hibin, INT b2lobin,    INT b2hibin ));

extern VOID sub_penal(P5(INT startx , INT endx , INT block , INT LoBin , INT HiBin));
extern VOID add_penal(P5(INT startx , INT endx , INT block , INT LoBin , INT HiBin));
	 	 					
extern VOID term_newpos(P4(PINBOXPTR antrmptr , INT xcenter , INT ycenter , INT newaor));


/* from rmoverlap.c */
extern VOID assgn_channel_to_seg(P1(VOID));
extern VOID free_chan_seg(P1(VOID)); 
extern VOID remove_overlap_segment(P1(INT net)); 
extern VOID rm_segm_overlap(P2(SEGBOXPTR *checkseg, INT m)); 
extern VOID replace_seg(P3(PINBOXPTR netptr, PINBOXPTR oldnode, PINBOXPTR newnode)); 
extern VOID add_adj(P2(SEGBOXPTR segptr, PINBOXPTR node)); 
extern VOID check_overlap_at_pin(P1(PINBOXPTR ptr));
extern INT check_connectivity(P1(INT net));
extern VOID depth_first_check(P2(PINBOXPTR ptr , SEGBOXPTR oldedge));

#endif /* !_TWSC_OVERLAP_H */
