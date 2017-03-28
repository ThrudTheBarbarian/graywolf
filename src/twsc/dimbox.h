/* ----------------------------------------------------------------- 
FILE:	    dimbox.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	    Mon Mar  6 21:29:37 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _TWSC_DIMBOX_H
#define _TWSC_DIMBOX_H

#include <yalecad/base.h>
#include "standard.h"

extern VOID init_dimbox(P1(VOID));

extern VOID new_dbox(P2(PINBOXPTR antrmptr, INT *costptr));
extern VOID new_dbox2(P3(PINBOXPTR antrmptr, PINBOXPTR bntrmptr, INT *costptr));
 
extern VOID wire_boundary1(P1(DBOXPTR dimptr));
extern VOID check_validbound(P3(DBOXPTR dimptr, PINBOXPTR termptr, PINBOXPTR nextptr));
extern VOID wire_boundary2(P2(INT c, DBOXPTR dimptr));

extern VOID dbox_pos(P1(PINBOXPTR antrmptr));
extern VOID dbox_pos_swap(P1(PINBOXPTR antrmptr));
extern VOID init_dbox_pos_swap(P1(PINBOXPTR antrmptr));

#endif /* !_TWSC_DIMBOX_H */
