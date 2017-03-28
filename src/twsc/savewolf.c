/*
 *   Copyright (C) 1989-1991 Yale University
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
FILE:	    savewolf.c                                       
DESCRIPTION:checkpoINT file routines.
CONTENTS:   savewolf(flag)
		INT flag ;
	    TW_oldin( fp )
		FILE *fp ;
DATE:	    Mar 27, 1989 
REVISIONS:  Wed Mar 13 13:48:30 CST 1991 - make sure the .blk
		and the .res file are consistent.
	    Thu Sep 19 16:36:02 EDT 1991 - added more error checking.
----------------------------------------------------------------- */
#ifndef VMS
#ifndef lint
static char SccsId[] = "@(#) savewolf.c (Yale) version 4.6 9/19/91" ;
#endif
#endif

#include "string.h"

#include <yalecad/base.h>
#include <yalecad/message.h>
#include <yalecad/program.h>

#include "standard.h"
#include "main.h"

#include "config.h"
#include "feeds.h"
#include "graphics.h"
#include "groute.h"
#include "parser.h"
#include "readpar.h"
#include "savewolf.h"
#include "uloop.h"

#if SIZEOF_VOID_P == 64
#define INTSCANSTR "%ld"
#else
#define INTSCANSTR "%d"
#endif

VOID savewolf(flag)
INT flag ;
{
FILE *fp ;
INT xcenter , ycenter ;
INT cell , block , orient ;
char filename[64] ;
char file1[1024], file2[1024];
CBOXPTR cellptr ;
DOUBLE Ycpu_time();
DOUBLE current_time;
static DOUBLE last_time = 0.0;

if( !flag ) {
#ifndef VMS
    /* make sure another checkpoINT is worthwhile !! */
    current_time = Ycpu_time();
    if ((current_time - last_time) < 900.0 ) {
        return;
    }
    last_time = current_time;
#else
    if( iterationG % 10 != 0 ) {
        return ;
    }
#endif
}

#ifdef VMS
sprintf( filename , "%s.sav" , cktNameG ) ;
fp = TWOPEN( filename , "w", ABORT ) ;
sprintf( filename , "%s.sav;-2" , cktNameG ) ;
delete( filename ) ;
#else
sprintf( filename , "%s.tmp" , cktNameG ) ;
fp = TWOPEN( filename , "w", ABORT ) ;
#endif

fprintf( fp, "%f\n", TG ) ;
fprintf( fp, "%d\n", (int)iterationG ) ;
fprintf( fp, "%d\n", (int)ffeedsG ) ;
fprintf( fp, "1\n" ) ;

fprintf( fp, "%f\n", binpenConG ) ;
fprintf( fp, "%f\n", roLenConG ) ;
/* was cost_scale_factor added for backward compatibility */
fprintf( fp, "%f\n", 1.0 ) ;
fprintf( fp, "%d\n",(int) estimate_feedsG ) ;
save_feeds( fp ) ;
save_control( fp ) ;


for( cell = 1 ; cell <= lastpadG ; cell++ ) {
    cellptr = carrayG[ cell ] ;
    orient  = cellptr->corient   ;
    block   = cellptr->cblock    ;
    xcenter = cellptr->cxcenter  ;
    ycenter = cellptr->cycenter  ;
    fprintf( fp , "%d %d %d %d %d\n", (int)cell , (int)block , 
			       (int)orient , (int)xcenter , (int)ycenter ) ;
}
TWCLOSE( fp ) ;
#ifndef VMS
sprintf(file1, "%s.tmp", cktNameG);
sprintf(file2, "%s.sav", cktNameG);
rename(file1, file2);
#endif
return ;
}

VOID TW_oldin( fp )
FILE *fp ;
{

INT cell , orient , numfds ;
INT block , xcenter , ycenter , dummy ;
INT last_cell ;
INT number_of_core_cells ;
DOUBLE cost_scale_factor ;
CBOXPTR ptr ;
PINBOXPTR pinptr ;
int w1, w2, w3, w4, w5;


fscanf( fp , "%lf" , &TG ) ;
fscanf( fp , "%d" , &w1 ) ;
iterationG = w1;

fscanf( fp , "%d" , &w1 ) ;
numfds = w1;

fscanf( fp , "%d" , &w1 ) ;
dummy = w1;

fscanf( fp , "%lf" , &binpenConG ) ;
fscanf( fp , "%lf" , &roLenConG ) ;
/* no longer use cost_scale_factor but save for backwards compatibility */
fscanf( fp , "%lf" , &cost_scale_factor ) ;
fscanf( fp , "%d" , &w1 ) ;
estimate_feedsG = w1;

read_feeds( fp ) ;

read_control( fp ) ;

/* add error checking to catch problems with different number of cells */
last_cell = 0 ;
number_of_core_cells = numcellsG - extra_cellsG ;
/* ignore the spacer cells */
while( fscanf( fp , " %d %d %d %d %d ", &w1 , &w2 , &w3 , &w4 , &w5 ) == 5 ) {
	cell	= w1;
	block	= w2;
	orient	= w3;
	xcenter	= w4;
	ycenter	= w5;
	
    ptr = carrayG[ cell ] ;
    if( cell <= number_of_core_cells ) {
	/* check to make sure block is valid */
	if( block < 1 || block > numRowsG ){
	    sprintf( YmsgG, "block out of bounds for cell:%s\n",
	    ptr->cname ) ;
	    M( ERRMSG, "TW_oldin", YmsgG ) ;
	    M( ERRMSG, NULL,"Restart file does not match block file\n");
	    M( ERRMSG, NULL, "Must exit\n\n" ) ;
	    TWCLOSE( fpoG ) ;
	    closegraphics() ;
	    YexitPgm(PGMFAIL) ;
	}
	ptr->cblock   = block   ;
	ptr->corient  = orient  ;
	ptr->cxcenter = xcenter ;
	ptr->cycenter = ycenter ;
	for( pinptr = ptr->pins; pinptr ; pinptr = pinptr->nextpin ) {
	    pinptr->xpos = pinptr->txpos[ orient/2 ] + xcenter ;
	    pinptr->ypos = pinptr->typos[ orient%2 ] + ycenter ;
	}
	last_cell = cell ;
    }
    if( strcmp( ptr->cname, "GATE_ARRAY_SPACER" ) == STRINGEQ ){
	/* no need to process spacer cells or pads */
	break ;
    }
}

/* now check to make sure we have the same number of cells */
if( last_cell != number_of_core_cells ){
    sprintf( YmsgG, "Wrong number of cells in restart file:%d vs %d in cell file.\n",
    (int)last_cell, (int)number_of_core_cells ) ;
    M( ERRMSG, "TW_oldin", YmsgG ) ;
    M( ERRMSG, NULL, "Fatal Error. Must exit\n\n" ) ;
    TWCLOSE( fpoG ) ;
    closegraphics() ;
    YexitPgm(PGMFAIL) ;
}
return ;
} /* end TW_oldin */
