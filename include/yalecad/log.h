#ifndef __YALE_LOG_HEADER__
#define __YALE_LOG_HEADER__

#include <yalecad/base.h>

/* put a message in the log file */
extern VOID Ylog_msg( P1(char *message) );
extern VOID Ylog_start( P2(char *design, char *message) );

#endif /* !__YALE_LOG_HEADER__ */