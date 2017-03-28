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
FILE:	    debug2.c                                       
DESCRIPTION:Various debug functions.
CONTENTS:   dbx_fdpen()
	    dbx_adj( net )
		INT net ;
	    dbx_netseg( net1 , net2 )
		INT net1 , net2 ;
	    dbx_seg( segptr )
		SEGBOXPTR segptr ;
	    dbx_feed( row1 , row2 )
		INT row1 , row2 ;
	    dbx_imp( row1 , row2 )
		INT row1 , row2 ;
	    dbx_funcost()
	    mst_graph( net1 , net2 )
		INT net1 , net2 ;
	    pre_dbx_Lseg()
	    dbx_Lseg( check_row )
		INT check_row ;
	    dbx_proj( check_row )
		INT check_row ;
	    dbx_fdasgn( row )
		INT row ;
	    check_funccost()
DATE:	    Mar 27, 1989 
REVISIONS:  Apr  1, 1990 - added check_funccost() ;
		Added ASSERT checks to check_funccost.
	    Sat Dec 15 22:08:21 EST 1990 - modified pinloc values
		so that it will always be positive.
----------------------------------------------------------------- */
#ifndef VMS
#ifndef lint
static char SccsId[] = "@(#) debug2.c (Yale) version 4.7 12/15/90" ;
#endif
#endif

#include <yalecad/base.h>
#include <yalecad/debug.h>
#include <yalecad/message.h>

#include "coarseglb.h"
#include "debug.h"
#include "feeds.h"
#include "groute.h"
#include "standard.h"
#include "pads.h"


/*
extern FEED_SEG_PTR *worker ;
extern FEED_DATA **feedpptr ;
extern SEGBOX  **netsegHead ;
extern IPBOXPTR *impFeeds ;
extern PINBOXPTR *steinerHead ;
extern INT chan_node_no ;
extern INT *min_feed , *FeedInRow ;
*/



VOID dbx_adj( net )
INT net ;
{

FILE *fp ;
PINBOXPTR pin1ptr , pin2ptr , netptr ;
ADJASEGPTR adjptr ;
SEGBOXPTR segptr ;

fp = TWOPEN("adj.dat" , "w", ABORT ) ;
fprintf(fp,"\nnet %5d\n\n" , (int)net ) ;
for( netptr = netarrayG[net]->pins; netptr ;netptr = netptr->next ) {
    fprintf(fp," pin %5d\n", (int)(netptr->terminal) );
    fprintf(fp,"   pin1  pin2  xpos1 xpos2  row1 row2  sw\n" ) ;
    for( adjptr = netptr->adjptr->next ; adjptr ;
			adjptr = adjptr->next ) {
	segptr = adjptr->segptr ;
	pin1ptr = segptr->pin1ptr ;
	pin2ptr = segptr->pin2ptr ;
	fprintf(fp,"  %5d %5d  %5d %5d  %4d %4d  %2d\n",
	    (int)(pin1ptr->terminal) , (int)(pin2ptr->terminal) ,
	    (int)(pin1ptr->xpos) , (int)(pin2ptr->xpos) ,
	    (int)(pin1ptr->row) , (int)(pin2ptr->row) , (int)(segptr->switchvalue) ) ;
    }
}
TWCLOSE(fp) ;
}

VOID dbx_netseg( net1 , net2 )
INT net1 , net2 ;
{

FILE *fp ;
PINBOXPTR pin1ptr , pin2ptr ;
SEGBOXPTR segptr ;
INT net ;

fp = TWOPEN("netseg.dat" , "w", ABORT ) ;
for( net = net1 ; net <= net2 ; net++ ) {
    fprintf(fp,"\nnet %5d\n" , (int)net ) ;
    fprintf(fp,"   pin1  pin2  xpos1 xpos2  row1 row2  sw loc1 loc2\n");
    for( segptr = netsegHeadG[net]->next ;
	segptr ; segptr = segptr->next ) {
	pin1ptr = segptr->pin1ptr ;
	pin2ptr = segptr->pin2ptr ;
	fprintf(fp,"  %5d %5d  %5d %5d  %4d %4d  %2d %4d %4d\n",
	    (int)(pin1ptr->terminal) , (int)(pin2ptr->terminal) ,
	    (int)(pin1ptr->xpos) , (int)(pin2ptr->xpos) ,
	    (int)(pin1ptr->row) , (int)(pin2ptr->row) , (int)(segptr->switchvalue) ,
	    (int)(pin1ptr->pinloc) , (int)(pin2ptr->pinloc) ) ;
    }
}
TWCLOSE(fp) ;
}

VOID dbx_seg( segptr )
SEGBOXPTR segptr ;
{

FILE *fp ;
PINBOXPTR pin1ptr , pin2ptr ;

fp = TWOPEN("seg.dat" , "a", ABORT ) ;
pin1ptr = segptr->pin1ptr ;
pin2ptr = segptr->pin2ptr ;
fprintf(fp,"\nnet %5d\n" , (int)(pin1ptr->net) ) ;
fprintf(fp,"   pin1  pin2  xpos1 xpos2  row1 row2  sw loc1 loc2\n");
fprintf(fp,"  %5d %5d  %5d %5d  %4d %4d  %2d %4d %4d\n",
    (int)(pin1ptr->terminal) , (int)(pin2ptr->terminal) , (int)(pin1ptr->xpos) ,
    (int)(pin2ptr->xpos) , (int)(pin1ptr->row) , (int)(pin2ptr->row) ,
    (int)(segptr->switchvalue) , (int)(pin1ptr->pinloc) , (int)(pin2ptr->pinloc) ) ;
TWCLOSE(fp) ;
}


VOID dbx_feed( row1 , row2 )
INT row1 , row2 ;
{

FILE *fp ;
FEED_DATA *feedptr ;
INT i , q , r , t , j , node , row ;
INT actual , needed , total_actual , total_needed ;

total_actual = 0 ;
total_needed = 0 ;
fp = TWOPEN("feed.dat" , "w", ABORT ) ;
for( row = row1 ; row <= row2 ; row++ ) {
    actual = 0 ;
    needed = 0 ;
    feedptr = feedpptrG[row] ;
    fprintf(fp,"\nrow %2d" , (int)row ) ;
    q = chan_node_noG / 10 ;
    r = chan_node_noG % 10 ;
    for( i = 0 ; i <= q-1 ; i++ ) {
	t = 10 * i ;
	fprintf(fp,"\n\n       %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d"
	, (int)(t+1) , (int)(t+2) , (int)(t+3) , (int)(t+4) , (int)(t+5) , 
	  (int)(t+6) , (int)(t+7) , (int)(t+8) , (int)(t+9) , (int)(t+10)) ;
	fprintf(fp,"\nactual" ) ;
	for( j = 1 ; j <= 10 ; j++ ) {
	    node = t + j ;
	    fprintf(fp," %4d", (int)(feedptr[node]->actual) ) ;
	}
	fprintf(fp,"\nneeded" ) ;
	for( j = 1 ; j <= 10 ; j++ ) {
	    node = t + j ;
	    fprintf(fp," %4d", (int)(feedptr[node]->needed) ) ;
	}
	fprintf(fp,"\n diff " ) ;
	for( j = 1 ; j <= 10 ; j++ ) {
	    node = t + j ;
	    actual += feedptr[node]->actual ;
	    needed += feedptr[node]->needed ;
	    fprintf(fp," %4d",
			(int)(feedptr[node]->actual - feedptr[node]->needed) ) ;
	}
    }
    t = 10 * q ;
    fprintf(fp,"\n\n       %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d"
    , (int)(t+1) , (int)(t+2) , (int)(t+3) , (int)(t+4) , (int)(t+5) , 
      (int)(t+6) , (int)(t+7) , (int)(t+8) , (int)(t+9) , (int)(t+10)) ;
    fprintf(fp,"\nactual" ) ;
    for( j = 1 ; j <= r ; j++ ) {
	node = t + j ;
	fprintf(fp," %4d", (int)(feedptr[node]->actual) ) ;
    }
    fprintf(fp,"\nneeded" ) ;
    for( j = 1 ; j <= r ; j++ ) {
	node = t + j ;
	fprintf(fp," %4d", (int)(feedptr[node]->needed) ) ;
    }
    fprintf(fp,"\n diff " ) ;
    for( j = 1 ; j <= r ; j++ ) {
	node = t + j ;
	actual += feedptr[node]->actual ;
	needed += feedptr[node]->needed ;
	fprintf(fp," %4d",
	    (int)(feedptr[node]->actual - feedptr[node]->needed) ) ;
    }
    fprintf(fp,"\n actual feedthru pin in row %d is %d\n", (int)row, (int)actual);
    fprintf(fp,"\n needed feedthru pin in row %d is %d\n", (int)row, (int)needed);
    fprintf(fp,"\n total difference in row %d is %d\n",
				    (int)row ,(int)(actual - needed) );
    total_actual += actual ;
    total_needed += needed ;
}
fprintf(fp,"\n total actual feedthru pins = %d\n" , (int)total_actual ) ;
fprintf(fp,"\n total needed feedthru pins = %d\n" , (int)total_needed ) ;
TWCLOSE(fp) ;
}


VOID dbx_imp( row1 , row2 )
INT row1 , row2 ;
{

INT row , k ;
char *s ;
IPBOXPTR imptr ;
FILE *fp ;

fp = TWOPEN("imp.dat" , "w", ABORT ) ;
for( row = row1 ; row <= row2 ; row++ ) {
    fprintf(fp,"\nrow %d\n" , (int)row ) ;
    fprintf(fp," node terminal   xpos  NETBOX position\n" ) ;
    for( imptr = impFeedsG[row]->next ; imptr ; imptr = imptr->next ) {
	k = set_node( imptr->xpos ) ;
	if( feedpptrG[row][k]->firstimp == imptr ) {
	    s = "firstimp" ;
	} else if( feedpptrG[row][k]->lastimp == imptr ) {
	    s = "lastimp" ;
	} else {
	    s = " " ;
	}
	fprintf(fp," %4d %8d %6d  %6s %8s\n", (int)k ,
	    (int)(imptr->terminal) , (int)(imptr->xpos) ,
	    tearrayG[imptr->terminal]->pinname , s ) ;
    }
}
TWCLOSE(fp) ;
}

VOID dbx_funcost(VOID)
{

INT net , cost , minx , miny , maxx , maxy ;
DBOXPTR dimptr ;
PINBOXPTR netptr ;

cost = 0 ;
for( net = 1 ; net <= numnetsG ; net++ ) {
    dimptr = netarrayG[net] ;
    if( dimptr->numpins <= 1 ) {
	continue ;
    }
    netptr = dimptr->pins ;
    maxx = minx = netptr->xpos ;
    maxy = miny = netptr->ypos ;
    for( netptr = netptr->next ; netptr ; netptr = netptr->next ) {
	if( netptr->xpos > maxx ) {
	    maxx = netptr->xpos ;
	}
	if( netptr->xpos < minx ) {
	    minx = netptr->xpos ;
	}
	if( netptr->ypos > maxy ) {
	    maxy = netptr->ypos ;
	}
	if( netptr->ypos < miny ) {
	    miny = netptr->ypos ;
	}
    }
    cost += ( maxx - minx ) + ( maxy - miny ) ;
}
if( cost != funccostG ) {
    printf("cost = %d funccost = %d\n" , (int)cost , (int)funccostG ) ;
}
}

VOID mst_graph( net1 , net2 )
INT net1 , net2 ;
{

FILE *fp ;
PINBOXPTR pin1ptr , pin2ptr , netptr ;
CBOXPTR cellptr1 , cellptr2 , cellptr ;
SEGBOXPTR segptr ;
INT net , x1 , x2 , y1 , y2 , row , cell ;

fp = TWOPEN("net.file" , "w", ABORT ) ;
for( net = net1 ; net <= net2 ; net++ ) {
    for( segptr = netsegHeadG[net]->next ;
	segptr ; segptr = segptr->next ) {
	pin1ptr = segptr->pin1ptr ;
	pin2ptr = segptr->pin2ptr ;
	if( pin1ptr->pinloc > NEITHER ) {
	    cellptr1 = carrayG[pin1ptr->cell] ;
	    if( !cellptr1->padptr || cellptr1->padptr->padside == 0 ) {
		y1 = cellptr1->cycenter + cellptr1->tileptr->top ;
	    } else {
		y1 = pin1ptr->ypos ;
	    }
	} else if( pin1ptr->pinloc < NEITHER ) {
	    cellptr1 = carrayG[pin1ptr->cell] ;
	    if( !cellptr1->padptr || cellptr1->padptr->padside == 0 ) {
		y1 = cellptr1->cycenter + cellptr1->tileptr->bottom ;
	    } else {
		y1 = pin1ptr->ypos ;
	    }
	} else {
	    y1 = pin1ptr->ypos ;
	}
	if( pin2ptr->pinloc > NEITHER ) {
	    cellptr2 = carrayG[pin2ptr->cell] ;
	    if( !cellptr2->padptr || cellptr2->padptr->padside == 0 ) {
		y2 = cellptr2->cycenter + cellptr2->tileptr->top ;
	    } else {
		y2 = pin2ptr->ypos ;
	    }
	} else if( pin2ptr->pinloc < NEITHER ) {
	    cellptr2 = carrayG[pin2ptr->cell] ;
	    if( !cellptr2->padptr || cellptr2->padptr->padside == 0 ) {
		y2 = cellptr2->cycenter + cellptr2->tileptr->bottom ;
	    } else {
		y2 = pin2ptr->ypos ;
	    }
	} else {
	    y2 = pin2ptr->ypos ;
	}
	fprintf(fp,"%d, %d, %d, %d, %d, color: black\n",
	    (int)net, (int)(pin1ptr->xpos) , 
	    (int)y1 , (int)(pin2ptr->xpos) , 
	    (int)y2 ) ;
    }
    for( netptr = netarrayG[net]->pins ; netptr ; netptr = netptr->next ) {
	if( netptr->pinloc == NEITHER ) {
	    cellptr = carrayG[netptr->cell] ;
	    if( !cellptr->padptr || cellptr->padptr->padside == 0 ) {
		y1 = cellptr->cycenter + cellptr->tileptr->bottom ;
		y2 = cellptr->cycenter + cellptr->tileptr->top ;
		fprintf(fp,"%d, %d, %d, %d, %d, color: black\n",
		    (int)net, (int)(netptr->xpos), 
		    (int)y1 , (int)(netptr->xpos) , 
		    (int)y2 ) ;
	    }
	}
    }
}
for( row = 1 ; row <= numRowsG ; row++ ) {
    cellptr1 = carrayG[ pairArrayG[row][1] ] ;
    cellptr2 = carrayG[ pairArrayG[row][ pairArrayG[row][0] ] ] ;
    x1 = cellptr1->cxcenter + cellptr1->tileptr->left ;
    x2 = cellptr2->cxcenter + cellptr2->tileptr->right ;
    y1 = cellptr1->cycenter + cellptr1->tileptr->bottom ;
    y2 = cellptr2->cycenter + cellptr2->tileptr->top ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x1, (int)y1, (int)x1, (int)y2 ) ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x1, (int)y2, (int)x2, (int)y2 ) ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x1, (int)y1, (int)x2, (int)y1 ) ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x2, (int)y1, (int)x2, (int)y2 ) ;
}
for( cell = numcellsG + 1 ; cell <= numcellsG + numtermsG ; cell++ ) {
    cellptr = carrayG[cell] ;
    x1 = cellptr->cxcenter + cellptr->tileptr->left ;
    x2 = cellptr->cxcenter + cellptr->tileptr->right ;
    y1 = cellptr->cycenter + cellptr->tileptr->bottom ;
    y2 = cellptr->cycenter + cellptr->tileptr->top ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x1, (int)y1, (int)x1, (int)y2 ) ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x1, (int)y2, (int)x2, (int)y2 ) ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x1, (int)y1, (int)x2, (int)y1 ) ;
    fprintf(fp,"0, %d, %d, %d, %d, color: black\n", 
    	(int)x2, (int)y1, (int)x2, (int)y2 ) ;
}
TWCLOSE(fp) ;
}





VOID dbx_fdasgn( row )
INT row ;
{

PINBOXPTR netptr , ptr1 , ptr2 ;
SEGBOXPTR segptr , nextptr ;
FEED_DATA *feedptr ;
INT i, k , net ;

feedptr = feedpptrG[row] ;
for( i =1 ; i <= chan_node_noG ; i++ ) {
    feedptr[i]->needed = 0 ;
}
for( net = 1 ; net <= numnetsG ; net++ ) {
    for( netptr = steinerHeadG[net]->next ;
	netptr ; netptr = netptr->next ) {
	if( netptr->flag && netptr->row == row ) {
	    k = set_node(netptr->xpos) ;
	    feedptr[k]->needed++ ;
	}
    }
    for( segptr = netsegHeadG[net]->next ; segptr ; segptr = nextptr ) {
	nextptr = segptr->next ;
	ptr1 = segptr->pin1ptr ;
	ptr2 = segptr->pin2ptr ;
	if( ptr1->row < row && ptr2->row > row ) {
	    if( segptr->switchvalue == swL_down ) {
		k = set_node(ptr2->xpos) ;
	    } else {
		k = set_node(ptr1->xpos) ;
	    }
	    feedptr[k]->needed++ ;
	} else if( ptr1->row == row && ptr2->row == row ) {
	    if( segptr->switchvalue == swL_down ) {
		k = set_node(ptr2->xpos) ;
		feedptr[k]->needed++ ;
	    } else if( segptr->switchvalue == swL_up ) {
		k = set_node(ptr1->xpos) ;
		feedptr[k]->needed++ ;
	    }
	} else if( ptr1->row == row ) {
	    if( segptr->switchvalue == swL_down && !segptr->flag ) {
		k = set_node(ptr2->xpos) ;
		feedptr[k]->needed++ ;
	    } else if( (int) ptr1->pinloc == BOTCELL ) {
		if( segptr->switchvalue == swL_down ) {
		    k = set_node(ptr2->xpos) ;
		    feedptr[k]->needed++ ;
		} else {
		    k = set_node(ptr1->xpos) ;
		    feedptr[k]->needed++ ;
		}
	    }
	} else if( ptr2->row == row ) {
	    if( segptr->switchvalue == swL_up && !segptr->flag ) {
		k = set_node(ptr1->xpos) ;
		feedptr[k]->needed++ ;
	    } else if( ptr2->pinloc == TOPCELL ) {
		if( segptr->switchvalue == swL_down ) {
		    k = set_node(ptr2->xpos) ;
		    feedptr[k]->needed++ ;
		} else {
		    k = set_node(ptr1->xpos) ;
		    feedptr[k]->needed++ ;
		}
	    }
	}
    }
}
}



VOID check_cost(VOID)
{

    CBOXPTR ptr ;
    DBOXPTR dimptr ;
    PINBOXPTR netptr , termptr ;
    INT corient ;
    INT cell , net , block ;
    INT x , y , cost ;
    INT tmp ;
    INT xmin = 0, ymin = 0, xmax = 0, ymax = 0 ;
    INT Ln = 0, Bn = 0, Rn = 0, Tn = 0 ;
    extern INT extra_cellsG ;
    INT penal, rpenal ;
    INT bin ;

    for( cell = 1 ; cell <= numcellsG + numtermsG ; cell++ ) {
	ptr = carrayG[ cell ] ;
	corient = ptr->corient ;
	block   = ptr->cblock  ;
	if( cell <= numcellsG - extra_cellsG ) {
	    ptr->cycenter = barrayG[block]->bycenter ;
	    for( termptr = ptr->pins ;termptr;termptr=termptr->nextpin ) {
		tmp = termptr->txpos[corient/2] + ptr->cxcenter;
		ASSERT( tmp == termptr->xpos, NULL, "trouble\n" ) ;
		termptr->xpos = tmp ;
		tmp = termptr->typos[corient%2] + ptr->cycenter;
		ASSERT( tmp == termptr->ypos, NULL, "trouble\n" ) ;
		termptr->ypos = tmp ;
	    }
	} else if( cell > numcellsG ) {
	    for( termptr = ptr->pins;termptr; termptr=termptr->nextpin ) {
		termptr->xpos = termptr->txpos[1] + ptr->cxcenter;
		termptr->ypos = termptr->typos[1] + ptr->cycenter;
	    }
	}
    }

    cost = 0 ;
    for( net = 1 ; net <= numnetsG ; net++ ) {
	dimptr =  netarrayG[ net ] ;
	if( dimptr->ignore == 1 ){
	    continue ;
	}
	/* use ((...)) to avoid assignment as condition warning */
	if(( netptr = dimptr->pins )) {

	    xmin = dimptr->xmin ;
	    xmax = dimptr->xmax ;
	    ymin = dimptr->ymin ;
	    ymax = dimptr->ymax ;
	    Ln = dimptr->Lnum ;
	    Rn = dimptr->Rnum ;
	    Bn = dimptr->Bnum ;
	    Tn = dimptr->Tnum ;
	    dimptr->xmin = dimptr->xmax = netptr->xpos ;
	    dimptr->ymin = dimptr->ymax = netptr->ypos ;
	    dimptr->Lnum = dimptr->Rnum = 1 ;
	    dimptr->Bnum = dimptr->Tnum = 1 ;
	    netptr = netptr->next ;
	}
	for( ; netptr ; netptr = netptr->next ) {
	    x = netptr->xpos ;
	    y = netptr->ypos ;
	    if( x < dimptr->xmin ) {
		dimptr->xmin = x ;
		dimptr->Lnum = 1 ;
	    } else if( x == dimptr->xmin ) {
		dimptr->Lnum++ ;
		if( x == dimptr->xmax ) {
		    dimptr->Rnum++ ;
		}
	    } else if( x > dimptr->xmax ) {
		dimptr->xmax = x ;
		dimptr->Rnum = 1 ;
	    } else if( x == dimptr->xmax ) {
		dimptr->Rnum++ ;
	    }
	    if( y < dimptr->ymin ) {
		dimptr->ymin = y ;
		dimptr->Bnum = 1  ;
	    } else if( y == dimptr->ymin ) { 
		dimptr->Bnum++ ;
		if( y == dimptr->ymax ) {
		    dimptr->Tnum++ ;
		}
	    } else if( y > dimptr->ymax ) {
		dimptr->ymax = y ;
		dimptr->Tnum = 1  ;
	    } else if( y == dimptr->ymax ) {
		dimptr->Tnum++ ;
	    }
	}
	cost += dimptr->halfPx = dimptr->newhalfPx = 
					     dimptr->xmax - dimptr->xmin ;
	dimptr->halfPy = dimptr->newhalfPy = dimptr->ymax - dimptr->ymin ;
	cost += (INT)( vertical_wire_weightG * (DOUBLE) dimptr->halfPy ) ;

	ASSERT( xmin == dimptr->xmin, NULL,"trouble\n" ) ;
	ASSERT( xmax == dimptr->xmax, NULL,"trouble\n" ) ;
	ASSERT( ymin == dimptr->ymin, NULL,"trouble\n" ) ;
	ASSERT( ymax == dimptr->ymax, NULL,"trouble\n" ) ;
	if( dimptr->numpins > 5 ){
	    ASSERT( Ln == dimptr->Lnum, NULL,"trouble\n" ) ;
	    ASSERT( Rn == dimptr->Rnum, NULL,"trouble\n" ) ;
	    ASSERT( Bn == dimptr->Bnum, NULL,"trouble\n" ) ;
	    ASSERT( Tn == dimptr->Tnum, NULL,"trouble\n" ) ;
	}
    }

    if( cost != funccostG ){
	fprintf( stderr, "funcost:%d cost:%d\n", (int)funccostG, (int)cost ) ;
	funccostG = cost ;
    }

    penal = 0 ;
    for( block = 1 ; block <= numRowsG ; block++ ) {
	for( bin = 0 ; bin <= numBinsG ; bin++ ) {
	    penal += ABS( binptrG[block][bin]->penalty ) ;
	}
    }
    sprintf( YmsgG, "binpenalG:%d penal:%d\n", (int)binpenalG, (int)penal ) ;
    ASSERT( binpenalG == penal, NULL, YmsgG ) ;

    rpenal = 0 ;
    for( block = 1 ; block <= numRowsG ; block++ ) {
	rpenal += ABS(barrayG[block]->oldsize - barrayG[block]->desire) ;
    }
    sprintf( YmsgG, "rowpenalG:%d rpenal:%d\n", (int)rowpenalG, (int)rpenal ) ;
    ASSERT( rowpenalG == rpenal, NULL, YmsgG ) ;

} /* end check_funcost */
