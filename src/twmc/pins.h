/* ----------------------------------------------------------------- 
"@(#) pins.h (Yale) version 4.7 3/23/92"
FILE:	    pins.h                                       
DESCRIPTION:prototypes so we can call the API from other modules
CONTENTS:   
DATE:	    3 Mar 2017 
REVISIONS: Fri  3 Mar 2017 19:45:02 PST - Initial revision
----------------------------------------------------------------- */
#ifndef TWMC_PINS_H
#define TWMC_PINS_H

#include <yalecad/base.h>
#include <custom.h>

extern VOID placepin( P2(INT cell, BOOL newVertFlag) );
extern VOID set_up_pinplace(P1(VOID));
extern VOID update_pins( P1(BOOL initialFlag) );  
extern VOID set_pin_verbosity( P1(BOOL flag) ); 
extern INT *find_pin_sides( P1(INT cell) );
extern INT find_tile_side( P3(INT center, INT loc, INT direction) );
extern VOID init_wire_est(P1(VOID));

/* from setpwates.c */
extern VOID setpwates(P1(VOID));

/* from sortpin.c */
extern VOID sortpins(P1(VOID));

/* from upin.c */
extern VOID upin_test(P2(PINBOXPTR termptr, MOVEBOXPTR pos) );
extern VOID upin_accept(P1(PINBOXPTR termptr ));

/* from upinswap.c */
extern BOOL upinswap(P1(INT a ));
extern VOID check_pin(P1(INT a ));

/* from selectpin.c */
extern BOOL selectpin( P1(CELLBOXPTR acellptr) );

#endif /* !TWMC_PINS_H */