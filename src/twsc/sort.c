/*
 *   Copyright (C) 1989-1990 Yale University
 *
 *   This work is distributed in the hope that it will be useful; you can
 *   redistribute it and/or modify it under the terms of the
 *   GNU General Public License as published by the Free Software Foundation;
 *   either version 2 of the License,
 *   or any later version, on the following conditions:
 *
 *   (a) YALE MAKES NO, AND EXPRESSLY DISCLAIMS
 *   ALL, REPRESENTATIONS OR WARRANTIES THAT THE MANUFACTURE, USE, PRACTICE,
 *   SALE OR
 *   OTHER DISPOSAL OF THE SOFTWARE DOES NOT OR WILL NOT INFRINGE UPON ANY
 *   PATENT OR
 *   OTHER RIGHTS NOT VESTED IN YALE.
 *
 *   (b) YALE MAKES NO, AND EXPRESSLY DISCLAIMS ALL, REPRESENTATIONS AND
 *   WARRANTIES
 *   WHATSOEVER WITH RESPECT TO THE SOFTWARE, EITHER EXPRESS OR IMPLIED,
 *   INCLUDING,
 *   BUT NOT LIMITED TO, WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *   PARTICULAR
 *   PURPOSE.
 *
 *   (c) LICENSEE SHALL MAKE NO STATEMENTS, REPRESENTATION OR WARRANTIES
 *   WHATSOEVER TO
 *   ANY THIRD PARTIES THAT ARE INCONSISTENT WITH THE DISCLAIMERS BY YALE IN
 *   ARTICLE
 *   (a) AND (b) above.
 *
 *   (d) IN NO EVENT SHALL YALE, OR ITS TRUSTEES, DIRECTORS, OFFICERS,
 *   EMPLOYEES AND
 *   AFFILIATES BE LIABLE FOR DAMAGES OF ANY KIND, INCLUDING ECONOMIC DAMAGE OR
 *   INJURY TO PROPERTY AND LOST PROFITS, REGARDLESS OF WHETHER YALE SHALL BE
 *   ADVISED, SHALL HAVE OTHER REASON TO KNOW, OR IN FACT SHALL KNOW OF THE
 *   POSSIBILITY OF THE FOREGOING.
 *
 */

/* ----------------------------------------------------------------- 
FILE:	    sort.c                                       
DESCRIPTION:various sort functions for quicksort.
CONTENTS:   compare_cost( a , b )
		EDGE_COST *a , *b ;
	    comparegdx( a , b )
		CHANGRDPTR *a , *b ;
	    comparetxpos( a , b )
		IPBOXPTR *a , *b ;
	    comparenptr( a , b )
		FEED_SEG_PTR *a , *b ;
	    comparepinx( a , b )
		PINBOXPTR *a , *b ;
	    comparex( a , b )
		INT *a , *b ;
	    cmpr_sx( aptr, bptr )
		PINBOXPTR *aptr, *bptr ;
	    cmpr_lx( aptr, bptr )
		PINBOXPTR *aptr, *bptr ;
	    cmpr_sy( aptr, bptr )
		PINBOXPTR *aptr, *bptr ;
	    cmpr_ly( aptr, bptr )
		PINBOXPTR *aptr, *bptr ;
DATE:	    Mar 27, 1989 
REVISIONS:  
----------------------------------------------------------------- */
#ifndef VMS
#ifndef lint
static char SccsId[] = "@(#) sort.c (Yale) version 4.3 9/7/90" ;
#endif
#endif

#include <yalecad/base.h>

#include "standard.h"

#include "groute.h"
#include "feeds.h"

INT compare_cost( a , b )
void *a , *b ;
{
	EDGE_COST *ec1 = (EDGE_COST *)a;
	EDGE_COST *ec2 = (EDGE_COST *)b;
	
return( (*ec1)->cost - (*ec2)->cost ) ;
}


INT comparegdx( a , b )
void *a , *b ;
{
	CHANGRDPTR *c1 = (CHANGRDPTR *)a;
	CHANGRDPTR *c2 = (CHANGRDPTR *)b;
	
return( (*c1)->netptr->xpos - (*c2)->netptr->xpos ) ;
}

INT comparetxpos( a , b )
void *a , *b ;
{
	IPBOXPTR *i1	= (IPBOXPTR *)a;
	IPBOXPTR *i2	= (IPBOXPTR *)b;
	
return( (*i1)->txpos - (*i2)->txpos ) ;
}

INT comparenptr( a , b )
void *a , *b ;
{
	FEED_SEG_PTR *f1 = (FEED_SEG_PTR *)a;
	FEED_SEG_PTR *f2 = (FEED_SEG_PTR *)b;
	
return( (*f1)->netptr->xpos - (*f2)->netptr->xpos ) ;
}

INT comparepinx( a , b )
void *a , *b ;
{
	PINBOXPTR *p1 = (PINBOXPTR *)a;
	PINBOXPTR *p2 = (PINBOXPTR *)b;
	
return( (*p1)->xpos - (*p2)->xpos ) ;
}

INT comparex( a , b )
void *a , *b ;

{
	INT *i1 = (INT *)a;
	INT *i2 = (INT *)b;
	
    return( carrayG[ *i1 ]->cxcenter - carrayG[ *i2 ]->cxcenter ) ;
}


INT cmpr_sx( aptr, bptr )
void *aptr, *bptr ;
{
	PINBOXPTR *a = (PINBOXPTR *)aptr;
	PINBOXPTR *b = (PINBOXPTR *)bptr;
	
if( (*a)->xpos > (*b)->xpos ) {
    return(1) ;
} else if( (*a)->xpos < (*b)->xpos ) {
    return(-1) ;
} else {
    return(0) ;
}
}


INT cmpr_lx( aptr, bptr )
void *aptr, *bptr ;
{
	PINBOXPTR *a = (PINBOXPTR *)aptr;
	PINBOXPTR *b = (PINBOXPTR *)bptr;
	
if( (*a)->xpos > (*b)->xpos ) {
    return(-1) ;
} else if( (*a)->xpos < (*b)->xpos ) {
    return(1) ;
} else {
    return(0) ;
}
}


INT cmpr_sy( aptr, bptr )
void *aptr, *bptr ;
{
	PINBOXPTR *a = (PINBOXPTR *)aptr;
	PINBOXPTR *b = (PINBOXPTR *)bptr;

if( (*a)->newy > (*b)->newy ) {
    return(1) ;
} else if( (*a)->newy < (*b)->newy ) {
    return(-1) ;
} else {
    return(0) ;
}
}


INT cmpr_ly( aptr, bptr )
void *aptr, *bptr ;
{
	PINBOXPTR *a = (PINBOXPTR *)aptr;
	PINBOXPTR *b = (PINBOXPTR *)bptr;

if( (*a)->newy > (*b)->newy ) {
    return(-1) ;
} else if( (*a)->newy < (*b)->newy ) {
    return(1) ;
} else {
    return(0) ;
}
}
