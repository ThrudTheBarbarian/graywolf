/*
 *   Copyright (C) 1988-1990 Yale University
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
FILE:	    debug2.c                                       
DESCRIPTION:more debug routines
CONTENTS:   
DATE:	    Feb 13, 1988 
REVISIONS:  Jan 29, 1989 - changed msg to msgG and added \n's.
	    Mar 30, 1989 - changed data structure of tiles.
	    Apr 17, 1989 - moved from placer into indep. program.
	    Apr 20, 1989 - now write debug to a file.
	    Sun Nov  4 13:22:21 EST 1990 - added new debug function
		for displaying cell slacks.
----------------------------------------------------------------- */
#ifndef lint
static char SccsId[] = "@(#) debug2.c version 7.1 11/10/90" ;
#endif

#include <compact.h>
#include <yalecad/debug.h>
#include <yalecad/file.h>

VOID dumpxGraph(VOID)
{
    int  i ;
    ECOMPBOXPTR eptr ;
    FILE *fp ;
    int xmin, xmax ;

    /****************** XGRAPH *******************************/

    fp = TWOPEN( "debug", "w", ABORT ) ;
    for( i=0;i<=last_tileG;i++){
	fprintf( fp,"Node:%2d cell:%2d l:%5d r:%5d b:%5d t:%5d\n",
	    (int)(tileNodeG[i]->node), 
	    (int)(tileNodeG[i]->cell), 
	    (int)(tileNodeG[i]->l),
	    (int)(tileNodeG[i]->r), 
	    (int)(tileNodeG[i]->b), 
	    (int)(tileNodeG[i]->t) ) ;
	fprintf( fp," xvMin:%d xvMax:%d yvMin:%d yvMax:%5d pathx:%d pathy:%d\n",
	    (int)(tileNodeG[i]->xvalueMin),
	    (int)(tileNodeG[i]->xvalueMax), 
	    (int)(tileNodeG[i]->yvalueMin),
	    (int)(tileNodeG[i]->yvalueMax), 
	    (int)(tileNodeG[i]->pathx), 
	    (int)(tileNodeG[i]->pathy) ) ;
	/* find window */
	/* xmin is max of all left edges */
	xmin = tileNodeG[i]->xvalueMin ;
	for( eptr = tileNodeG[i]->xadjB ;eptr; eptr=eptr->next){
	    xmin = MAX( xmin, tileNodeG[eptr->node]->xvalueMax ) ;
	}
	xmax = tileNodeG[i]->xvalueMax ;
	for( eptr = tileNodeG[i]->xadjF ;eptr; eptr=eptr->next){
	    xmax = MIN( xmax, tileNodeG[eptr->node]->xvalueMin ) ;
	}
	fprintf( fp,"xmin:%d xmax:%d\n",xmin, xmax ) ;
	fprintf( fp," xancF:%d xancB:%d yancF:%d yancB:%d\n",
	    (int)(tileNodeG[i]->xancestrF),
	    (int)(tileNodeG[i]->xancestrB),
	    (int)(tileNodeG[i]->yancestrF),
	    (int)(tileNodeG[i]->yancestrB) ) ;
	fprintf( fp," Edges for node %d:\n", (int)i );
	for( eptr = tileNodeG[i]->xadjB ;eptr; eptr=eptr->next){
	    fprintf( fp,"     node %2d constraint:%d\n",
			(int)(eptr->node), 
			(int)(eptr->constraint) ) ; 
	}
	fprintf( fp, "\n" ) ;
    }
    TWCLOSE( fp ) ;
}

BOOL dxancestors( numtiles, xGraph ) 
int numtiles ;
COMPACTPTR *xGraph ;
{
    int i, fcount = 0, bcount = 0 ;
    int fanc = 0 , banc = 0 ;
    int fnode = 0 , bnode = 0 ;
    ECOMPBOXPTR edge ;

    for( i=0;i<=numtiles; i++ ){
	fanc += xGraph[i]->xancestrF ;
	fnode = 0 ;
	for( edge=xGraph[i]->xadjF;edge;edge=edge->next ){
	    fcount++ ;
	    fnode++ ;
	}
    }
    for( i=0;i<=numtiles; i++ ){
	banc += xGraph[i]->xancestrB ;
	bnode = 0 ;
	for( edge=xGraph[i]->xadjB;edge;edge=edge->next ){
	    bcount++ ;
	    bnode++ ;
	}
    }
    if( fcount != bcount || fcount != fanc || bcount != banc ){
	printf( "Forward edges:%d Backward edges:%d\n",(int)fcount,(int)bcount ) ;
	printf( "Forward nodes:%d Backward nodes:%d\n",(int)fnode,(int)bnode ) ;
	printf( "Forward ancestrs:%d Backward ancestrs:%d\n",(int)fanc,(int)banc );
	return(FALSE) ;
    }
    return(TRUE) ;

}

VOID dumpyGraph(VOID)
{
    int  i ;
    ECOMPBOXPTR eptr ;
    FILE *fp ;

    fp = TWOPEN( "debug", "w", ABORT ) ;
    /****************** YGRAPH *******************************/
    /* SOURCE */
    fprintf(fp,"Node:%2d cell:%2d l:%5d r:%5d b:%5d t:%5d\n",
		(int)(tileNodeG[numtilesG+2]->node), 
		(int)(tileNodeG[numtilesG+2]->cell),
		(int)(tileNodeG[numtilesG+2]->l),
		(int)(tileNodeG[numtilesG+2]->r), 
		(int)(tileNodeG[numtilesG+2]->b),
		(int)(tileNodeG[numtilesG+2]->t) ) ;
    fprintf(fp," xvMin:%d xvMax:%d yvMin:%d yvMax:%5d pathx:%d pathy:%d\n",
		(int)(tileNodeG[numtilesG+2]->xvalueMin), 
		(int)(tileNodeG[numtilesG+2]->xvalueMax),
		(int)(tileNodeG[numtilesG+2]->yvalueMin),
		(int)(tileNodeG[numtilesG+2]->yvalueMax),
		(int)(tileNodeG[numtilesG+2]->pathx), 
		(int)(tileNodeG[numtilesG+2]->pathy) ) ;
    fprintf(fp," Edges for node %d:\n", (int)(numtilesG+2) );
    for( eptr = tileNodeG[numtilesG+2]->yadjB ;eptr; eptr=eptr->next){
	fprintf(fp,"     node %2d constraint:%d\n",
	    (int)(eptr->node), (int)(eptr->constraint) ) ; 
    }

    for( i=1;i<=numtilesG;i++){
	fprintf(fp,"Node:%2d cell:%2d l:%5d r:%5d b:%5d t:%5d\n",
	    (int)(tileNodeG[i]->node), 
	    (int)(tileNodeG[i]->cell), 
	    (int)(tileNodeG[i]->l),
	    (int)(tileNodeG[i]->r), 
	    (int)(tileNodeG[i]->b), 
	    (int)(tileNodeG[i]->t) ) ;
	fprintf(fp," xvMin:%d xvMax:%d yvMin:%d yvMax:%5d pathx:%d pathy:%d\n",
	    (int)(tileNodeG[i]->xvalueMin), 
	    (int)(tileNodeG[i]->xvalueMax),
	    (int)(tileNodeG[i]->yvalueMin),
	    (int)(tileNodeG[i]->yvalueMax), 
	    (int)(tileNodeG[i]->pathx),
	    (int)(tileNodeG[i]->pathy) ) ;
	fprintf(fp," Edges for node %d:\n", i );
	for( eptr = tileNodeG[i]->yadjB ;eptr; eptr=eptr->next){
	    fprintf(fp,"     node %2d constraint:%d\n",
		(int)(eptr->node), 
		(int)(eptr->constraint) ) ; 
	}
    }

    /* SINK */
    fprintf(fp,"Node:%2d cell:%2d l:%5d r:%5d b:%5d t:%5d\n",
		(int)(tileNodeG[numtilesG+3]->node), 
		(int)(tileNodeG[numtilesG+3]->cell),
		(int)(tileNodeG[numtilesG+3]->l),
		(int)(tileNodeG[numtilesG+3]->r), 
		(int)(tileNodeG[numtilesG+3]->b),
		(int)(tileNodeG[numtilesG+3]->t) ) ;
    fprintf(fp," xvMin:%d xvMax:%d yvMin:%d yvMax:%5d pathx:%d pathy:%d\n",
		(int)(tileNodeG[numtilesG+3]->xvalueMin),
		(int)(tileNodeG[numtilesG+3]->xvalueMax),
		(int)(tileNodeG[numtilesG+3]->yvalueMin),
		(int)(tileNodeG[numtilesG+3]->yvalueMax),
		(int)(tileNodeG[numtilesG+3]->pathx), 
		(int)(tileNodeG[numtilesG+3]->pathy) ) ;
    fprintf(fp," Edges for node %d:\n", i );
    for( eptr = tileNodeG[numtilesG+3]->yadjB ;eptr; eptr=eptr->next){
	fprintf(fp,"     node %2d constraint:%d\n",
	    (int)(eptr->node), (int)(eptr->constraint) ) ; 
    }
    fprintf( fp, "\n" ) ;
    TWCLOSE( fp ) ;

}


ECOMPBOXPTR find_edge( node1, node2, direction )
INT node1, node2 ;
INT direction ;
{
    ECOMPBOXPTR eptr ;
    switch( direction ){
	case XFORWARD:
	    eptr = tileNodeG[node1]->xadjF;
	    break ;
	case XBACKWARD:
	    eptr = tileNodeG[node1]->xadjB;
	    break ;
	case YFORWARD:
	    eptr = tileNodeG[node1]->yadjF;
	    break ;
	case YBACKWARD:
	    eptr = tileNodeG[node1]->yadjB;
	    break ;
    }
    for( ; eptr; eptr = eptr->next ){
	if( eptr->node == node2 ){
	    return( eptr ) ;
	}
    }
    return( NULL ) ;
}

VOID dycons(VOID)
{
    int  i, bcons ;
    ECOMPBOXPTR eptr, eptr2 ;

    /****************** YGRAPH *******************************/
    /* SOURCE */
    printf(" Edges for node %d:\n", (int)(numtilesG+2) );
    for( eptr = tileNodeG[numtilesG+2]->yadjF ;eptr; eptr=eptr->next){
	
	/* Use ((...)) to avoid assignment as a condition warning */
	if(( eptr2 = find_edge( eptr->node, numtilesG+2, YBACKWARD ) )){
	    bcons = eptr2->constraint ;
	} else {
	    bcons = -1 ;
	}
	printf("     node %2d fconstraint:%d bconstraint:%d\n",
	    (int)(eptr->node), (int)(eptr->constraint), (int)bcons ) ; 
    }

    for( i=1;i<=numtilesG;i++){
	printf(" Edges for node %d:\n", (int)i );
	for( eptr = tileNodeG[i]->yadjF ;eptr; eptr=eptr->next){
	    /* Use ((...)) to avoid assignment as a condition warning */
	    if(( eptr2 = find_edge( eptr->node, i, YBACKWARD ) )){
		bcons = eptr2->constraint ;
	    } else {
		bcons = -1 ;
	    }
	    printf("     node %2d fconstraint:%d bconstraint:%d\n",
		(int)(eptr->node), (int)(eptr->constraint), (int)bcons ) ; 
	}
    }

    /* SINK */
    printf(" Edges for node %d:\n", (int)i );
    for( eptr = tileNodeG[numtilesG+3]->yadjF ;eptr; eptr=eptr->next){
	/* Use ((...)) to avoid assignment as a condition warning */
	if(( eptr2 = find_edge( eptr->node, numtilesG+3, YBACKWARD ) )){
	    bcons = eptr2->constraint ;
	} else {
	    bcons = -1 ;
	}
	printf("     node %2d fconstraint:%d bconstraint:%d\n",
	    (int)(eptr->node), (int)(eptr->constraint), (int)bcons ) ; 
    }

}



VOID dsort( numtiles, XNotY )
int numtiles ;
BOOL XNotY ;
{
    int i ;
    COMPACTPTR *ptr ;

    fprintf(stderr,"Dumping tileNodeG - node:cell...\n") ;

    ptr = tileNodeG ;
    for( i=1;i<=numtiles;i++ ){
	fprintf(stderr, "%d:%d  ", (int)(ptr[i]->node),(int)(ptr[i]->cell) ) ; 
	if( ( i % 10 ) == 0 ){
	    fprintf( stderr, "\n") ;
	}
    }
    fprintf(stderr,"\n") ;

    if( XNotY ){
	fprintf(stderr,"\nDumping xGraph...\n") ;
	ptr = xGraphG ;
    } else {
	fprintf(stderr,"\nDumping yGraph...\n") ;
	ptr = yGraphG ;
    }

    for( i=0;i<=last_tileG;i++ ){
	fprintf(stderr, "%d:%d  ", (int)(ptr[i]->node),(int)(ptr[i]->cell) ) ; 
	if( i != 0 && ( i % 10 ) == 0 ){
	    fprintf( stderr, "\n") ;
	}
    }
    fprintf(stderr,"\n") ;

}  /* end numtiles */

VOID dxancerr(VOID)
{
    int i ;

    for( i=0;i<=last_tileG; i++ ){
	if( xGraphG[i]->xancestrF != 0 ){
	    fprintf( stderr, "Tile:%d has %d forward ancestors\n",
		(int)(xGraphG[i]->node), (int)(xGraphG[i]->xancestrF) ) ;
	}
    }
    for( i=0;i<=last_tileG; i++ ){
	if( xGraphG[i]->xancestrB != 0 ){
	    fprintf( stderr, "Tile:%d has %d backward ancestors\n",
		(int)(xGraphG[i]->node), (int)(xGraphG[i]->xancestrB) ) ;
	}
    }
}

VOID dump_anc(VOID)
{
    INT i ;
    INT last ;

    last = YSINK ;
    fprintf( stderr, "The ancestors for the tiles:\n" ) ;
    for( i = 0; i <= last; i++ ){
	fprintf( stderr, "\ttile:%3d ancestors:%d\n", (int)i, (int)(ancestorG[i]) ) ;
    }
} /* dump_anc */

VOID dslack( XNotY, center, length )
BOOL XNotY ;
BOOL center ;
INT length ;
{
    INT i ;
    INT count ;
    INT value ;
    NODEPTR nptr ;
    CELLBOXPTR cptr ;
    COMPACTPTR tptr ;

    if( XNotY ){
	fprintf(stderr,"\nDumping xGraph slacks node:minslack-maxslack...\n") ;
	for( i=1;i<=numcellsG;i++ ){
	    cptr = slackG[i] ;
	    fprintf(stderr, "%d:", (int)(tileNodeG[cptr->tiles->node]->cell) ) ;
	    fprintf(stderr, "%d-%d\n", (int)(cptr->xmin), (int)(cptr->xmax) ) ;
	    count = 0 ;
	    for( nptr = cptr->tiles; nptr; nptr = nptr->next ){
		tptr = tileNodeG[nptr->node] ;
		value = tptr->xvalueMin ;
		if( center ){
		    value -= tptr->l_rel ;
		}
		fprintf(stderr, "\t%d:%d-", (int)(tptr->node), (int)value ) ;

		value = tptr->xvalueMax ;
		if( center ){
		    value -= tptr->l_rel ;
		}
		if( length ){
		    value = length - value ;
		}
		fprintf(stderr, "%d  ", (int)value ) ;

		if( (++count % 4) == 0 ){
		    fprintf( stderr, "\n") ;
		}
	    }
	    fprintf( stderr, "\n") ;
	}
	fprintf(stderr,"\n\n") ;
    } else {
	fprintf(stderr,"\nDumping yGraph slacks node:minslack-maxslack...\n") ;
	for( i=1;i<=numcellsG;i++ ){
	    cptr = slackG[i] ;
	    fprintf(stderr, "%d:", (int)(tileNodeG[cptr->tiles->node]->cell) ) ;
	    fprintf(stderr, "%d-%d\n", (int)(cptr->ymin), (int)(cptr->ymax) ) ;
	    count = 0 ;
	    for( nptr = cptr->tiles; nptr; nptr = nptr->next ){
		tptr = tileNodeG[nptr->node] ;
		value = tptr->yvalueMin ;
		if( center ){
		    value -= tptr->b_rel ;
		}
		fprintf(stderr, "\t%d:%d-", (int)(tptr->node), (int)value ) ;

		value = tptr->yvalueMax ;
		if( center ){
		    value -= tptr->b_rel ;
		}
		if( length ){
		    value = length - value ;
		}
		fprintf(stderr, "%d  ", (int)value ) ;
		if( (++count % 4) == 0 ){
		    fprintf( stderr, "\n") ;
		}
	    }
	    fprintf( stderr, "\n") ;
	}
	fprintf(stderr,"\n\n") ;
    }
} /* end dslack */

VOID dedges( cell, XnotY, forwardNotBack )
INT cell ;
BOOL XnotY ;
BOOL forwardNotBack ;
{
    NODEPTR nptr ;
    CELLBOXPTR cptr ;
    COMPACTPTR tptr ;
    ECOMPBOXPTR eptr ;

    if( XnotY ){
	if( forwardNotBack ){
	    fprintf( stderr, "X forward " ) ;
	} else {
	    fprintf( stderr, "X backward " ) ;
	}
    } else {
	if( forwardNotBack ){
	    fprintf( stderr, "Y forward " ) ;
	} else {
	    fprintf( stderr, "Y backward " ) ;
	}
    }
    fprintf( stderr, "edges for cell:%d :\n", (int)cell ) ;
    for( nptr = cellarrayG[cell]->tiles; nptr ; nptr = nptr->next ){
	tptr = tileNodeG[nptr->node] ;
	if( XnotY ){
	    if( forwardNotBack ){
		eptr = tptr->xadjF;
	    } else {
		eptr = tptr->xadjB;
	    }
	} else {
	    if( forwardNotBack ){
		eptr = tptr->yadjF;
	    } else {
		eptr = tptr->yadjB;
	    }
	}
	for( ; eptr; eptr = eptr->next ){
	    fprintf( stderr, "\t %d --> %d \n", (int)(nptr->node), (int)(eptr->node) ) ;
	}
    }
    fprintf( stderr, "\n\n" ) ;
}

VOID dyancerr(VOID)
{
    int i ;

    for( i=0;i<=last_tileG; i++ ){
	if( yGraphG[i]->yancestrF != 0 ){
	    fprintf( stderr, "Tile:%d has %d forward ancestors\n",
		(int)(yGraphG[i]->node), (int)(yGraphG[i]->yancestrF) ) ;
	}
    }
    for( i=0;i<=last_tileG; i++ ){
	if( yGraphG[i]->yancestrB != 0 ){
	    fprintf( stderr, "Tile:%d has %d backward ancestors\n",
		(int)(yGraphG[i]->node), (int)(yGraphG[i]->yancestrB) ) ;
	}
    }
}


VOID check_xancestors(VOID)
{
    INT i ;
    INT count ;
    COMPACTPTR tptr ;
    ECOMPBOXPTR eptr ;

    for( i=0;i<=last_tileG; i++ ){
	count = 0 ;
	tptr = xGraphG[i] ;
	/* first check forward ancestors */
	for( eptr = tptr->xadjB ;eptr; eptr=eptr->next){
	    count++ ;
	}
	if( tptr->xancestrF != count ){
	    fprintf( stderr, 
	    "ERROR:Mismatch in forward x ancestor count for node:%d\n",
	    (int)(tptr->node) ) ;
	    fprintf( stderr, "\tdata:%d found:%d\n\n", (int)(tptr->xancestrF),
		(int)count ) ;
	}
	/* next check backward ancestors */
	count = 0 ;
	for( eptr = tptr->xadjF ;eptr; eptr=eptr->next){
	    count++ ;
	}
	if( tptr->xancestrB != count ){
	    fprintf( stderr, 
	    "ERROR:Mismatch in backward x ancestor count for node:%d\n",
	    (int)(tptr->node) ) ;
	    fprintf( stderr, "\tdata:%d found:%d\n\n", (int)(tptr->xancestrB),
		(int)count ) ;
	}

    }
} /* end check_xancestors */

VOID check_yancestors(VOID)
{
    INT i ;
    INT count ;
    COMPACTPTR tptr ;
    ECOMPBOXPTR eptr ;

    for( i=0;i<=last_tileG; i++ ){
	count = 0 ;
	tptr = yGraphG[i] ;
	/* first check forward ancestors */
	for( eptr = tptr->yadjB ;eptr; eptr=eptr->next){
	    count++ ;
	}
	if( tptr->yancestrF != count ){
	    fprintf( stderr, 
	    "ERROR:Mismatch in forward y ancestor count for node:%d\n",
	    (int)(tptr->node) ) ;
	    fprintf( stderr, "\tdata:%d found:%d\n\n", (int)(tptr->yancestrF),
		(int)count ) ;
	}
	/* next check backward ancestors */
	count = 0 ;
	for( eptr = tptr->yadjF ;eptr; eptr=eptr->next){
	    count++ ;
	}
	if( tptr->yancestrB != count ){
	    fprintf( stderr, 
	    "ERROR:Mismatch in backward y ancestor count for node:%d\n",
	    (int)(tptr->node) ) ;
	    fprintf( stderr, "\tdata:%d found:%d\n\n", (int)(tptr->yancestrB),
		(int)count ) ;
	}

    }
} /* end check_yancestors */
