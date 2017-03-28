#ifdef linux
# include <stdio.h>
#else
# include "stdio.h"
#endif
# define U(x) ((x)&0377)
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
#if defined (linux) || defined (__APPLE__)
FILE *yyin = (FILE *)NULL, *yyout = (FILE *)NULL;
#else
FILE *yyin ={stdin}, *yyout ={stdout};
#endif
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;
/* ----------------------------------------------------------------- 
FILE:	    readcell.l                               
DESCRIPTION:rules for lexical analyzer for syntax checker. This lexical
	    analyzer uses a binary search to reduce the size of 
	    the f.a.  generated by lex.  Thanks to Gary Richey who 
	    showed me the trick.  See chapter 3 of "Introduction
	    to Compiler Construction with UNIX" by Schreiner &
	    Friedman for more details.
CONTENTS:   lex rules -
	    screen()
DATE:	    Aug 03, 1990 - 
	    "@(#) readcell.l (Yale) version 4.7 3/22/91" ;
REVISIONS:  Dec  7, 1990 - add | for National.
	    Sun Jan 20 21:51:45 PST 1991 - added * for VALID.
	    Mon Jan 21 21:38:48 PST 1991 - added ASCII char set for alphanum.
	    Fri Mar 22 16:21:58 CST 1991 - made letter more
		general.
----------------------------------------------------------------- */
#undef   YYLMAX 
#define  YYLMAX 2000       /* comments may be at most 2000 characters */

#define token(x)      x    /* makes it look like regular lex */
#define END(v) (v-1 + sizeof(v) / sizeof( v[0] ) ) /* for table lookup */

static INT screen(P1(VOID)) ;
static INT check_line_count(P1(char *s)) ;
static INT line_countS = 0 ;

# define YYNEWLINE 10
int yylex(void){
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:

		      {
			/* C-style comments over multiple lines */
          		check_line_count(yytext) ;
	              }
break;
case 2:
      { 
		         /* convert to an integer */
		         yylval.ival = atoi( yytext ) ;
	  	         return (INTEGER); 
	              }
break;
case 3:
 {
		         /* convert to an float */
		         yylval.fval = atof( yytext ) ;
	  	         return (FLOAT); 
		      }
break;
case 4:
 {
		         /* convert to an float */
		         yylval.fval = atof( yytext ) ;
	  	         return (FLOAT); 
		      }
break;
case 5:
  {  return( (int)screen() ) ; }
break;
case 6:
           {  line_countS++;}
break;
case 7:
             ;
break;
case 8:
              {  return( token(yytext[0]) ) ;}
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */

/* reserved word screener */
/* ----------------------------------------------------------------- 
    The following is table of the reserved words - Table must be in
    alphabetical order for binary search to work properly.
----------------------------------------------------------------- */
static struct rw_table {  /* reserved word table */
    char *rw_name ;      /* pattern */
    int rw_yylex  ;      /* lex token number */
} rwtable[] = {
    "ECO_added_cell",      token(ECO_ADDED_CELL),
    "approximately_fixed", token(APPROXIMATELY_FIXED),
    "asplb",               token(ASPLB),
    "aspub",               token(ASPUB),
    "at",                  token(AT),
    "block",               token(BLOCK),
    "bottom",              token(BOTTOM),
    "cell",                token(CELL),
    "cell_offset",         token(CELLOFFSET),
    "cellgroup",           token(CELLGROUP),
    "class",               token(CLASS),
    "corners",             token(CORNERS),
    "end_pin_group",       token(ENDPINGROUP),
    "equiv",               token(EQUIV),
    "fixed",               token(FIXED),
    "from",                token(FROM),
    "group",               token(GROUP),
    "hardcell",            token(HARDCELL),
    "initially",           token(INITIALLY),
    "instance",            token(INSTANCE),
    "layer",               token(LAYER),
    "left",                token(LEFT),
    "legal_block_classes", token(LEGALBLKCLASS),
    "name",                token(NAME),
    "neighborhood",        token(NEIGHBORHOOD),
    "nomirror",            token(NOMIRROR),
    "nonfixed",            token(NONFIXED),
    "nopermute",           token(NOPERMUTE),
    "of",                  token(OF),
    "orient",              token(ORIENT),
    "orientations",        token(ORIENTATIONS),
    "pad",                 token(PAD),
    "padgroup",            token(PADGROUP),
    "padside",             token(PADSIDE),
    "permute",             token(PERMUTE),
    "pin",                 token(PIN),
    "pin_group",           token(PINGROUP),
    "port",                token(PORT),
    "restrict",            token(RESTRICT),
    "right",               token(RIGHT),
    "rigidly_fixed",       token(RIGIDFIXED),
    "sequence",            token(SEQUENCE),
    "side",                token(SIDE),
    "side.restriction",    token(SIDERESTRICTION),
    "sidespace",           token(SIDESPACE),
    "signal",              token(SIGNAL),
    "softcell",            token(SOFTCELL),
    "stdcell",             token(STDCELL),
    "supergroup",          token(SUPERGROUP),
    "swap_group",          token(SWAPGROUP),
    "top",                 token(TOP),
    "unequiv",             token(UNEQUIV)
} ;

static INT screen(VOID) 
{
    int c ;
    struct rw_table  *low = rwtable,        /* ptr to beginning */
		     *mid ,  
		     *high = END(rwtable) ;   /* ptr to end */

    /* binary search to look thru table to find pattern match */
    while( low <= high){
	mid = low + (high-low) / 2 ;
	if( (c = strcmp(mid->rw_name, yytext) ) == STRINGEQ){
	    return( mid->rw_yylex ) ; /* return token number */
	} else if( c < 0 ){
	    low = mid + 1 ;
	} else {
	    high = mid - 1 ;
	}
    }
    /* at this point we haven't found a match so we have a string */
    /* save the string by making copy */
    yylval.string = Ystrclone( yytext ) ;
    return (STRING); 
		
} /* end screen function */

static INT check_line_count( s ) 
char *s ;
{
    if( s ){
	if( strlen(s) >= YYLMAX ){
	    sprintf(YmsgG,"comment beginning at line %d ",(int)(line_countS+1) );
	    M( ERRMSG, "lex", YmsgG ) ;
	    sprintf(YmsgG,"exceeds maximum allowed length:%d chars.\n", 
		(int)YYLMAX );
	    M( MSG, NULL, YmsgG ) ;
	}
	for( ;*s;s++ ){
	    if( *s == '\n'){
		line_countS++;
	    }
	}
    }
    return 0;
} /* end check_line_count */
int yyvstop[] ={
0,

7,
0,

7,
0,

8,
0,

7,
8,
0,

6,
0,

5,
8,
0,

5,
8,
0,

3,
5,
8,
0,

5,
8,
0,

2,
8,
0,

7,
0,

5,
0,

3,
5,
0,

2,
5,
0,

5,
0,

3,
5,
0,

2,
0,

5,
0,

5,
0,

5,
0,

5,
0,

5,
0,

5,
0,

1,
5,
0,

5,
0,

4,
5,
0,

1,
0,

5,
0,

1,
5,
0,

1,
0,
0};
# define YYTYPE unsigned char
struct yywork { YYTYPE verify, advance; } yycrank[] ={
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
4,11,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,6,	4,11,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	1,6,	
1,7,	9,15,	0,0,	1,8,	
1,9,	1,10,	7,13,	19,19,	
7,14,	7,14,	7,14,	7,14,	
7,14,	7,14,	7,14,	7,14,	
7,14,	7,14,	25,33,	26,34,	
32,24,	33,25,	34,25,	0,0,	
0,0,	0,0,	1,6,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	6,12,	6,12,	6,12,	
6,12,	8,13,	8,13,	8,13,	
8,13,	8,13,	8,13,	8,13,	
8,13,	8,13,	8,13,	10,16,	
0,0,	10,17,	10,17,	10,17,	
10,17,	10,17,	10,17,	10,17,	
10,17,	10,17,	10,17,	13,13,	
13,13,	13,13,	13,13,	13,13,	
13,13,	13,13,	13,13,	13,13,	
13,13,	14,16,	0,0,	14,14,	
14,14,	14,14,	14,14,	14,14,	
14,14,	14,14,	14,14,	14,14,	
14,14,	15,18,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	15,18,	15,18,	16,16,	
16,16,	16,16,	16,16,	16,16,	
16,16,	16,16,	16,16,	16,16,	
16,16,	0,0,	0,0,	0,0,	
0,0,	18,18,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
16,22,	15,19,	18,23,	18,18,	
20,24,	0,0,	18,18,	18,18,	
18,18,	0,0,	15,20,	15,19,	
20,24,	20,24,	15,19,	15,21,	
15,19,	17,16,	0,0,	17,17,	
17,17,	17,17,	17,17,	17,17,	
17,17,	17,17,	17,17,	17,17,	
17,17,	18,18,	0,0,	0,0,	
16,22,	0,0,	0,0,	0,0,	
20,25,	15,19,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	20,26,	20,25,	0,0,	
0,0,	20,25,	20,27,	20,25,	
22,28,	0,0,	22,28,	0,0,	
0,0,	22,29,	22,29,	22,29,	
22,29,	22,29,	22,29,	22,29,	
22,29,	22,29,	22,29,	23,24,	
0,0,	0,0,	0,0,	0,0,	
20,25,	0,0,	24,18,	0,0,	
23,30,	23,24,	0,0,	0,0,	
23,24,	23,31,	23,24,	24,23,	
24,18,	0,0,	0,0,	24,18,	
24,32,	24,18,	28,29,	28,29,	
28,29,	28,29,	28,29,	28,29,	
28,29,	28,29,	28,29,	28,29,	
0,0,	0,0,	0,0,	23,24,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	24,18,	29,29,	
29,29,	29,29,	29,29,	29,29,	
29,29,	29,29,	29,29,	29,29,	
29,29,	30,18,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	30,23,	30,18,	
0,0,	0,0,	30,18,	30,35,	
30,18,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	30,18,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] ={
0,	0,	0,
yycrank+-1,	0,		yyvstop+1,
yycrank+0,	yysvec+1,	yyvstop+3,
yycrank+0,	0,		yyvstop+5,
yycrank+3,	0,		yyvstop+7,
yycrank+0,	0,		yyvstop+10,
yycrank+38,	0,		yyvstop+12,
yycrank+4,	yysvec+6,	yyvstop+15,
yycrank+117,	yysvec+6,	yyvstop+18,
yycrank+3,	yysvec+6,	yyvstop+22,
yycrank+129,	yysvec+6,	yyvstop+25,
yycrank+0,	yysvec+4,	yyvstop+28,
yycrank+0,	yysvec+6,	yyvstop+30,
yycrank+139,	yysvec+6,	yyvstop+32,
yycrank+151,	yysvec+6,	yyvstop+35,
yycrank+-208,	0,		yyvstop+38,
yycrank+171,	yysvec+6,	yyvstop+40,
yycrank+211,	yysvec+6,	yyvstop+43,
yycrank+-200,	yysvec+15,	0,	
yycrank+-4,	yysvec+15,	yyvstop+45,
yycrank+-243,	0,		yyvstop+47,
yycrank+0,	yysvec+15,	yyvstop+49,
yycrank+249,	yysvec+6,	yyvstop+51,
yycrank+-274,	yysvec+20,	0,	
yycrank+-281,	yysvec+15,	0,	
yycrank+-15,	yysvec+15,	yyvstop+53,
yycrank+-16,	yysvec+15,	yyvstop+55,
yycrank+0,	yysvec+6,	yyvstop+57,
yycrank+282,	yysvec+6,	yyvstop+60,
yycrank+303,	yysvec+6,	yyvstop+62,
yycrank+-328,	yysvec+15,	0,	
yycrank+0,	0,		yyvstop+65,
yycrank+17,	0,		0,	
yycrank+18,	yysvec+6,	yyvstop+67,
yycrank+19,	yysvec+6,	yyvstop+69,
yycrank+0,	yysvec+32,	yyvstop+72,
0,	0,	0};
struct yywork *yytop = yycrank+397;
struct yysvf *yybgin = yysvec+1;
char yymatch[] ={
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'*' ,'+' ,'!' ,'+' ,'.' ,'/' ,
'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,
'0' ,'0' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'E' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'E' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,
'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,'!' ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
0};
char yyextra[] ={
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
/*	ncform	4.1	83/08/11	*/

int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
int yylook(P1(VOID)){
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;

#if defined (linux) || defined (__APPLE__)
	if (yyin == (FILE *)NULL) yyin = stdin;
	if (yyout == (FILE *)NULL) yyout = stdout;
#endif
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank){		/* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"unsigned char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (INT)yyt > (INT)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((INT)yyt < (INT)yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = (int)(yylastch-yytext+1);
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
int yyback(p, m)
	int *p;
	int m;
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
int yyinput(void){
#if defined (linux) || defined (__APPLE__)
	if (yyin == NULL) yyin = stdin;
#endif
	return(input());
	}
void yyoutput(c)
  int c; {
#if defined (linux) || defined (__APPLE__)
	if (yyout == NULL) yyout = stdout;
#endif
	output(c);
	}
void yyunput(c)
   int c; {
	unput(c);
	}
