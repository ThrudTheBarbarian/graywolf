/* ----------------------------------------------------------------- 
"@(#) config.h (Yale) version 4.4 2/17/91"
FILE:	    config.h                                       
DESCRIPTION:TimberwolfSC insert file for configuration parameters.
CONTENTS:   
DATE:	    Mar 27, 1989 
REVISIONS:  Sun Feb 17 21:11:18 EST 1991 - moved numMacroG to pad.h
----------------------------------------------------------------- */
#ifndef CONFIG_H
#define CONFIG_H

#include <yalecad/base.h>

#ifdef CONFIG_VARS
#define EXTERN 
#else
#define EXTERN extern 
#endif

typedef struct macrobox {
    INT mx ;
    INT my ;
} MACROBOX ;

typedef struct rowbox {
    INT startx  ;
    INT endx    ;
    INT endx1   ;
    INT startx2 ;
    INT ypos    ;
    INT desiredL ;
} ROWBOX ;

EXTERN MACROBOX *macroArrayG ;
EXTERN ROWBOX *rowArrayG ;

EXTERN INT max_blklengthG ;
EXTERN INT route2actG;   /* added for placement adjusted for routing */
EXTERN INT gridCellG;    /* used only if global routing is performed */
EXTERN INT desiredLG ;
EXTERN DOUBLE *macspaceG ;

EXTERN INT *padArrayG ;
EXTERN INT extraSpaceG ;
EXTERN INT coreHeightG ;
EXTERN INT coreWidthG ;
EXTERN INT separationG ;
EXTERN INT spaceG ;
EXTERN INT maxHeight ;
EXTERN INT lastG ;

#undef EXTERN  

/* from configure.c */
extern VOID configure(P1(VOID));
extern VOID random_placement(P1(VOID));

/* from reconfig.c */
extern INT reconfig(P1(VOID));
extern VOID read_feeds(P1(FILE *fp));
extern VOID save_feeds(P1(FILE *fp));
extern BOOL read_feed_data(P1(VOID)); 



#endif /* CONFIG_H */
