/* ----------------------------------------------------------------- 
FILE:	    readnets.h
DESCRIPTION:This file redefines global variable of yacc and lex so
	    that we can have more than one parser in TimberWolfMC.
CONTENTS:   macro redefinitions for parser in readnets.
DATE:	    Oct 19, 1988 
REVISIONS:  Mar 27, 1989 - added to TimberWolfSC also added PSETBOX def.
	    Thu Mar  7 02:43:49 EST 1991 - added more definitions
		for byacc.
----------------------------------------------------------------- */
/* *****************************************************************
"@(#) readnets.h (Yale) version 4.4 3/7/91"
***************************************************************** */

#define yyact		NET_yyact
#define yyback		NET_yyback
#define yybgin		NET_yybgin
#define yychar		NET_yychar
#define yychk		NET_yychk
#define yycrank		NET_yycrank
#define yydebug		NET_yydebug
#define yydef		NET_yydef
#define yyerrflag	NET_yyerrflag
#define yyerror	        NET_yyerror
#define yyestate	NET_yyestate
#define yyexca		NET_yyexca
#define yyextra		NET_yyextra
#define yyfnd		NET_yyfnd
#define yyin		NET_yyin
#define yyinput		NET_yyinput
#define yyleng		NET_yyleng
#define yylex		NET_yylex
#define yylineno	NET_yylineno
#define yylook		NET_yylook
#define yylsp		NET_yylsp
#define yylstate	NET_yylstate
#define yylval		NET_yylval
#define yymatch		NET_yymatch
#define yymorfg		NET_yymorfg
#define yynerrs		NET_yynerrs
#define yyolsp		NET_yyolsp
#define yyout		NET_yyout
#define yyoutput	NET_yyoutput
#define yypact		NET_yypact
#define yyparse		NET_yyparse
#define yypgo		NET_yypgo
#define yyprevious	NET_yyprevious
#define yyr1		NET_yyr1
#define yyr2		NET_yyr2
#define yysbuf		NET_yysbuf
#define yysptr		NET_yysptr
#define yysvec		NET_yysvec
#define yytchar		NET_yytchar
#define yytext		NET_yytext
#define yytop		NET_yytop
#define yyunput		NET_yyunput
#define yyv		NET_yyv
#define yyval		NET_yyval
#define yyvstop		NET_yyvstop
#define yywrap		NET_yywrap

/* for byacc */
#define yyrule          NET_yyrule
#define yyname          NET_yyname
#define yytable         NET_yytable
#define yycheck         NET_yycheck
#define yydgoto         NET_yydgoto
#define yydefred        NET_yydefred
#define yygindex        NET_yygindex
#define yyrindex        NET_yyrindex
#define yysindex        NET_yysindex
#define yylen           NET_yylen
#define yylhs           NET_yylhs


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