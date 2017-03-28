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
FILE:	    outcm.c                                       
DESCRIPTION:input/output to connection machine.
CONTENTS:   outcm()
	    incm(fp)
		FILE *fp ;
DATE:	    Mar 27, 1989 
REVISIONS:  
----------------------------------------------------------------- */
#ifndef VMS
#ifndef lint
static char SccsId[] = "@(#) outcm.c (Yale) version 4.3 9/7/90" ;
#endif
#endif

#include <yalecad/base.h>

#include "standard.h"
#include "main.h"
#include "out.h"

#include "groute.h"

#if SIZEOF_VOID_P == 64
#define INTSCANSTR "%ld"
#else
#define INTSCANSTR "%d"
#endif

VOID outcm(VOID)
{

char filename[64] ;
FILE *fp ;
PINBOXPTR netptr ;
INT net , x , local_pin_count , pin_count ;
INT cell , row , length , xstart ;


sprintf( filename , "%s.cm" , cktNameG ) ;
fp = TWOPEN ( filename , "w", ABORT ) ;

pin_count = 0 ;
for( net = 1 ; net <= numnetsG ; net++ ) {
    local_pin_count = 0 ;
    for( netptr = netarrayG[net]->pins; netptr; netptr = netptr->next){
	if( netptr->cell <= numcellsG ) {
	    local_pin_count++ ;
	}
    }
    if( local_pin_count > 1 ) {
	pin_count += local_pin_count ;
    }
}
fprintf(fp,"%d\n", (int)pin_count ) ;

for( net = 1 ; net <= numnetsG ; net++ ) {
    local_pin_count = 0 ;
    for( netptr = netarrayG[net]->pins; netptr; netptr = netptr->next){
	if( netptr->cell <= numcellsG ) {
	    local_pin_count++ ;
	}
    }
    if( local_pin_count <= 1 ) {
	continue ;
    }
    for( netptr = netarrayG[net]->pins; netptr; netptr = netptr->next){
	if( netptr->cell > numcellsG ) {
	    continue ;
	}
	cell = netptr->cell ;
	row  = carrayG[cell]->cblock ;
	x    = netptr->xpos ;
	length = carrayG[cell]->tileptr->right - 
					carrayG[cell]->tileptr->left ;
	xstart = carrayG[cell]->cxcenter + carrayG[cell]->tileptr->left ;

	fprintf(fp,"%8d %8d %8d %8d %8d %8d\n", (int)row, (int)cell, (int)net,
						 (int)x, (int)length, (int)xstart );
    }
}
TWCLOSE(fp);

return ;
}





VOID incm(fp)
FILE *fp ;
{

CBOXPTR ptr ;
INT net , x , pin_count , pin ;
INT cell , row , length , xstart ;
int w1, w2, w3, w4, w5, w6;

fscanf(fp, "%d", &w1 ) ;
pin_count = w1;

for( pin = 1 ; pin <= pin_count ; pin++ ) {
    fscanf(fp, "%d %d %d %d %d %d",
		&w1, &w2, &w3, &w4, &w5, &w6 );
	row		= w1;
	cell	= w2;
	net		= w3;
	x		= w4;
	length	= w5;
	xstart	= w6;
	
    ptr = carrayG[cell] ;
    ptr->cblock = row ;
    ptr->cxcenter = xstart + length / 2 ;
    ptr->cycenter = barrayG[row]->bycenter ;
}
TWCLOSE(fp);

return ;
}
