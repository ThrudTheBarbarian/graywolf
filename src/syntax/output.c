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
FILE:	    output.c
DESCRIPTION:This file accumulates data for TimberWolf system.
CONTENTS:   
DATE:	    Apr 24, 1989 
REVISIONS:  May 24, 1989 - updated argument to YcurTime.
	    May 15, 1990 - now add up cell area so that standard cell
		macros size will be the average macro size.
	    Aug 3,  1990 - added port counting to output.
	    Thu Apr 18 01:12:20 EDT 1991 - added more error checking.
	    Wed Jun 12 13:40:11 CDT 1991 - added check for pins
		outside cell boundary.
	    Wed Jul 24 21:06:02 CDT 1991 - added a more
		meaningful output error message.
----------------------------------------------------------------- */
#ifndef lint
static char SccsId[] = "@(#) output.c version 1.8 7/24/91" ;
#endif

#include <string.h>

#include <yalecad/base.h>
#include <yalecad/message.h>
#include <yalecad/hash.h>
#include <yalecad/buster.h>
#include <yalecad/ytime.h>

#include <globals.h>

#define EXPECTEDNUMNETS         10009
static INT objectS = 0 ;       /* number of objects read */
static INT celltypeS ;         /* current cell type */
static INT stdcellS = 0 ;      /* number of standard cells */
static INT macroS = 0 ;        /* number of macro cells */
static INT numinstanceS = 0 ;  /* number of macro instances */
static INT padS = 0 ;          /* number of pad cells */
static INT netS = 0 ;          /* number of nets */
static INT equivS = 0 ;        /* number of equivalent pins */
static INT unequivS = 0 ;      /* number of unequivalent pins */
static INT pinS = 0 ;          /* number of pins */
static INT impS = 0 ;          /* number of implicit feeds */
static INT portS = 0 ;         /* number of ports */
static INT minxS, minyS ;      /* bounding box of cell */
static INT maxxS, maxyS ;      /* bounding box of cell */
static char current_cellS[LRECL] ; /* the current cell name */
static char cur_pinnameS[LRECL] ;  /* current pinname */
static BOOL count_portS ;      /* whether a pin is a port */
static YHASHPTR netTableS ;    /* hash table for cross referencing nets */
static DOUBLE cellAreaS = 0 ;  /* area of the macro cells */

/* *************************************************************** */

VOID init(VOID)
{
    /* get ready for parsing */
    /* make hash table for nets */
    netTableS = Yhash_table_create( EXPECTEDNUMNETS ) ;
} /* end init */

VOID addCell( celltype, cellname )
INT celltype ;
char *cellname ;
{

    strcpy( current_cellS, cellname ) ;
    Ysafe_free( cellname ) ;
    /* passify the user */
    if( (++objectS % 50) == 0 ){
	sprintf( YmsgG, "Read %4d objects so far...\n", (int)objectS ) ;
	M( MSG, NULL, YmsgG ) ;
    }

    celltypeS = celltype ;   /* save for determining instances etc. */
    switch( celltype ){
	case HARDCELLTYPE:
	case SOFTCELLTYPE:
	    macroS++ ;
	    numinstanceS++ ;
	    count_portS = TRUE ;    /* count pins as ports */
	    break ;
	case STDCELLTYPE:
	    stdcellS++ ;
	    count_portS = FALSE ;
	    break ;
	case PADCELLTYPE:
	    padS++ ;
	    count_portS = TRUE ;
	    break ;
    }

} /* end addCell */

VOID addNet( signal )
char *signal ;
{
    INT *data ;

    if( strcmp( signal, "TW_PASS_THRU" ) == STRINGEQ ){
	impS++ ;
	return ; /* not a net so return */
    }
    if(!(Yhash_search( netTableS, signal, NULL, FIND ))){
	/* else a new net load data holder */
	data = (INT *) Ysafe_malloc( sizeof(INT) ) ;
	*data = ++netS ;
	if( Yhash_search( netTableS, signal, (char *)data, ENTER )){
	    sprintf( YmsgG, "Trouble adding signal:%s to hash table\n",
		signal ) ;
	    M(ERRMSG,"addNet",YmsgG ) ;
	}
    }
    pinS++ ;
    if( count_portS ){
	portS++ ;
    }

} /* end addNet */

VOID addEquiv(VOID)
{
    equivS++ ;
} /* end addEquiv */

VOID addUnEquiv(VOID)
{
    unequivS++ ;
} /* end addUnEquiv */

VOID add_instance(VOID)
{
    if( celltypeS == HARDCELLTYPE || celltypeS == SOFTCELLTYPE ){
	numinstanceS++ ;
    }
} /* end add_instance */

VOID set_bbox( left, right, bottom, top )
INT left, right, bottom, top ;
{
    minxS = left ;
    minyS = bottom ;
    maxxS = right ;
    maxyS = top ;
} /* end set_bbox */

VOID start_pt( x, y )
INT x, y ;
{
    Ybuster_init() ;
    Ybuster_addpt( x, y ) ;
    minxS = x ;
    minyS = y ;
    maxxS = x ;
    maxyS = y ;
} /* end start_pt */

VOID add_pt( x, y )
INT x, y ;
{
    Ybuster_addpt( x, y ) ;
    minxS = MIN( x, minxS ) ;
    minyS = MIN( y, minyS ) ;
    maxxS = MAX( x, maxxS ) ;
    maxyS = MAX( y, maxyS ) ;
} /* end add_pt */

VOID processCorners(VOID)
{
    YBUSTBOXPTR bustptr ;        /* get a tile from Ybuster */
    DOUBLE this_cell ;           /* area of the current tile */
    DOUBLE l, r, b, t ;          /* the coordinates of the current tile*/

    if( celltypeS == HARDCELLTYPE || celltypeS == SOFTCELLTYPE ){
	if( !(Ybuster_verify( current_cellS ))){
	    M(ERRMSG,"processCorners",YmsgG ) ;
	    return ;
	}
	/* Use ((...)) to avoid assignment as a condition warning */
	while(( bustptr = Ybuster() )){
	    l = (DOUBLE) bustptr[1].x ;
	    r = (DOUBLE) bustptr[3].x ;
	    b = (DOUBLE) bustptr[1].y ;
	    t = (DOUBLE) bustptr[3].y ;
	    this_cell = (r - l) * (t - b) ;
	    cellAreaS += this_cell ;
	}
    }
} /* end processCorners */

VOID check_xloc( value )
char *value ;
{
    if( (strcmp( value, "L" ) != STRINGEQ ) && strcmp( value, "R" ) != STRINGEQ ){
	sprintf( YmsgG, "x location should be L or R:%s\n", current_cellS ) ;
	M( ERRMSG,"check_xloc", YmsgG ) ;
    }
    Ysafe_free( value ) ;
} /* end check_xloc */

VOID check_yloc( value )
char *value ;
{
    if( (strcmp( value, "B" ) != STRINGEQ ) && strcmp( value, "T" ) != STRINGEQ ){
	sprintf( YmsgG, "y location should be B or T:%s\n", current_cellS ) ;
	M( ERRMSG,"check_yloc", YmsgG ) ;
    }
    Ysafe_free( value ) ;
} /* end check_xloc */

VOID check_sideplace( side )
char *side ;
{
    INT numsides ;
    INT i ;

    numsides = strlen( side ) ;
    for( i = 0 ; i < numsides; i++ ){
	switch( side[i] ){
	    case 'B' :
	    case 'L' :
	    case 'R' :
	    case 'T' :
		break ;
	    default:
		sprintf( YmsgG,
		    "side restriction not specified properly for cell:%s\n",
		    current_cellS );
	    M(ERRMSG,"check_sideplace",YmsgG ) ;
	} /* end switch */
    } 
    Ysafe_free( side ) ;
} /* end check_sideplace */

VOID set_pinname( pinname )
char *pinname ;
{
    strcpy( cur_pinnameS, pinname ) ;
} /* end set_pinname */

VOID check_pos( xpos, ypos ) 
INT xpos, ypos ;
{

    if( xpos < minxS || xpos > maxxS || ypos < minyS || ypos > maxyS ){
	sprintf( YmsgG, "Pin:%s cell:%s @(%d,%d) is outside cell boundary\n",
	    cur_pinnameS, current_cellS, (int)xpos, (int)ypos ) ;
	M( ERRMSG, "check_pos", YmsgG ) ;
    }
} /* end check_pos */

/* ***************************************************************** 
    OUTPUT routine - output the results.
   **************************************************************** */
VOID output(VOID)
{
    char *yctime = (char *)YcurTime(NULL);
    fprintf( fpoG, "TIMESTAMP:%s\n", yctime ) ;
    // fprintf( fpoG, "TIMESTAMP:%s\n", YcurTime(NULL) ) ;
    fprintf( fpoG, "Statistics for %s:\n", cktNameG ) ;
    fprintf( fpoG, "num_stdcells:%d\n", (int)stdcellS ) ;
    fprintf( fpoG, "num_macros:%d\n", (int)macroS ) ;
    fprintf( fpoG, "num_instances:%d\n", (int)numinstanceS ) ;
    fprintf( fpoG, "num_pads:%d\n", (int)padS ) ;
    fprintf( fpoG, "num_nets:%d\n", (int)netS ) ;
    fprintf( fpoG, "num_pins:%d\n", (int)pinS ) ;
    fprintf( fpoG, "num_implicit_feeds:%d\n", (int)impS ) ;
    fprintf( fpoG, "num_equivs:%d\n", (int)equivS ) ;
    fprintf( fpoG, "num_unequivs:%d\n", (int)unequivS ) ;
    fprintf( fpoG, "num_ports:%d\n", (int)portS ) ;
    fprintf( fpoG, "macro_area:%4.3le\n", cellAreaS ) ;

} /* end output */
