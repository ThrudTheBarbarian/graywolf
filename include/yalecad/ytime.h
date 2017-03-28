#ifndef __YALE_TIME_HEADER__
#define __YALE_TIME_HEADER__

#include "yalecad/base.h"

/* ----------------------------------------------------------------- 
FILE:	    from: time.c                                       
DESCRIPTION:This file contains a time utility routine which returns
	    an ASCII string with time and date.
CONTENTS:   
	    char *YcurTime( time_in_sec ) 
		INT *time_in_sec ;

DATE:	    Oct 23, 1988
REVISIONS:  Apr 27, 1989 - changed to Y prefix and added time in seconds.
----------------------------------------------------------------- */
extern char *YcurTime( P1( INT * time_in_sec) );



/* From: timer.c: initialize the timer */
extern VOID Ytimer_start(P1(VOID));
extern VOID Ytimer_elapsed(P1(INT * time_elapsed) );

/* From: date.c - return the compilation date for YLib */
char *getCompileDate(P1(VOID));

#endif /* !__YALE_TIME_HEADER__ */
