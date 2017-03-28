/* ----------------------------------------------------------------- 
FILE:	    readcells.h                                       
DESCRIPTION:Export API for other modules.
CONTENTS:   
DATE:	     Tue Mar  7 18:46:37 PST 2017
REVISIONS:  
----------------------------------------------------------------- */

#ifndef _SYNTAX_READCELLS_H
#define _SYNTAX_READCELLS_H

#include <yalecad/base.h>
#include <globals.h>

/* Declare prototypes if required */
extern int yyback(P2(int *, int));
extern int yyinput(P1(void));
extern int yylook(P1(void));
extern void yyoutput(P1(int));
extern int yyracc(P1(int));
extern int yyreject(P1(void));
extern void yyunput(P1(int));
extern int yylex(P1(void));
extern int yyless(P1(int));
extern int yywrap(P1(void));
extern int yyparse(P1(void));
extern int yyerror(P1(char * s));

extern VOID readcells(P1(FILE *fp));

#endif /* !_SYNTAX_READCELLS_H */
