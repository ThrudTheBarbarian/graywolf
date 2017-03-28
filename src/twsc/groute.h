/* ----------------------------------------------------------------- 
"@(#) groute.h (Yale) version 4.7 3/23/92"
FILE:	    globe.h                                       
DESCRIPTION:global routing definitions and typedefs.
CONTENTS:   
DATE:	    Mar 27, 1989 
REVISIONS:  Fri Jan 25 23:47:24 PST 1991 - removed redundant variables.
	    Fri Mar 22 15:16:41 CST 1991 - changed SHORT to
		INT since it wasn't saving space and could
		be a problem for large designs.
----------------------------------------------------------------- */
#ifndef GLOBE_H
#define GLOBE_H

#include <yalecad/base.h>

#ifdef GLOBE_VARS
#define EXTERN 
#else
#define EXTERN extern 
#endif

#ifdef INFINITY
#undef INFINITY
#endif
#define INFINITY 0x7fffffff
#define LEFT  -1
#define RIGHT 1
#define OLD 0
#define NEW 1
#define swLINE 1
#define nswLINE 2
#define swL_up 3
#define swL_down 4
#define VERTICAL 6
#define HORIZONTAL 7
#define swUP 8
#define swDOWN 9

#define GRDNULL ( ( CHANGRDPTR ) NULL ) 
#define DENSENULL ( ( DENSITYPTR ) NULL ) 

EXTERN CHANGRDPTR *BeginG ;
EXTERN CHANGRDPTR *EndG ;
EXTERN DENSITYPTR **DenseboxG ;
EXTERN DENSITYPTR **DboxHeadG ;
EXTERN TGRIDPTR *TgridG ;
EXTERN SEGBOXPTR *netsegHeadG ;
EXTERN SEGBOXPTR *netsegTailG ;
EXTERN DOUBLE mean_widthG ;
EXTERN INT **pairArrayG ;
EXTERN INT numSegsG ;
EXTERN INT numSwSegsG ;
EXTERN INT tracksG ;
EXTERN INT *maxTrackG ;
EXTERN INT *nmaxTrackG ;
EXTERN INT max_tdensityG ;
EXTERN INT gxstartG ;
EXTERN INT gxstopG ;
EXTERN INT blkleftG , blkriteG ;
EXTERN INT gtopChanG , gbotChanG ;
EXTERN INT uneven_cell_heightG ;
EXTERN INT track_pitchG ;

EXTERN INT chan_node_noG ;
EXTERN INT *FeedInRowG ;
EXTERN INT blk_most_leftG ;
EXTERN INT blk_most_riteG ;
EXTERN INT *row_rite_classG ;
EXTERN INT *right_most_in_classG ;
EXTERN INT hznode_sepG ;
EXTERN INT add_Lcorner_feedG ;
EXTERN INT average_feed_sepG ;
EXTERN INT average_pin_sepG ;
EXTERN PINBOXPTR *steinerHeadG ;
EXTERN FEED_DATA **feedpptrG ;
EXTERN IPBOXPTR *impFeedsG ;

#undef EXTERN  

extern VOID globroute(P1(VOID));
extern VOID process_cross(P2(SEGBOXPTR segptr, INT status));

#endif /* GLOBE_H */
