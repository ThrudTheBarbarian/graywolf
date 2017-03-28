/* ----------------------------------------------------------------- 
"@(#) partition.h (Yale) version 3.3 9/5/90"
FILE:	    partition.h                                       
DESCRIPTION:insert file to support standard cell partitioner.
CONTENTS:   
DATE:	    May 17, 1989 
REVISIONS:  
----------------------------------------------------------------- */
#ifndef PARTITION_H
#define PARTITION_H

#include <yalecad/base.h>

#define         INITROWSEP      1.0 
#define		EVEN_ODD( x )	( (x) & 01 )
#define		EVEN	0

typedef	struct d_field {
    INT			x_lb	;
    INT			x_ub	;
    INT                 cell    ;
    struct d_field	*prev	;
    struct d_field	*next	;
} DFLD, *DFLDPTR ;

typedef	struct b_record {
    SHORT		state	;
    SHORT		number	;
    INT			length	;
    INT			x_lb	;
    INT			x_ub	;
    INT			y_lb	;
    INT			y_ub	;
    struct d_field	*macro	;
} BLOCK, *BLOCKPTR ;

extern VOID config_rows(P1(VOID));
extern VOID read_stat_file(P1(VOID));
extern DOUBLE read_par_file(P1(VOID));
extern VOID output_partition(P1(VOID));
extern VOID build_mver_file( P4(INT left, INT right, INT bottom, INT top ));
extern VOID read_gen_file(P1(VOID));

#endif /* PARTITION_H */
