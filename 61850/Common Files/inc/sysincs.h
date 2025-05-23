/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	  1986 - 2004, All Rights Reserved.		        */
/*									*/
/*		    PROPRIETARY AND CONFIDENTIAL			*/
/*									*/
/* MODULE NAME : sysincs.h						*/
/* PRODUCT(S)  : MMSEASE						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*	The purpose of this include file is to bring in include files	*/
/*	that come with one of the various C compilers.			*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 07/08/04  DSF     29    Fixed SASSERT macro				*/
/* 01/26/04  JRB     28    Fix LYNX includes.				*/
/* 01/22/04  DSF     27    Added/modified ASSERT macros			*/
/* 01/19/04  EJV     26    __hpux 10.20 does not have sys/select.h.	*/
/* 12/09/03  JRB     25    Add LYNX support. Add () to max,min macros.	*/
/* 10/23/03  JRB     24    Move socket includes to here.		*/
/*			   For _WIN32, add windows.h, process.h		*/
/*			   Del unused CDECL define.			*/
/* 04/28/03  DSF     23    Make sure expression inside VERIFY is always	*/
/*			   executed					*/
/* 04/15/03  DSF     22    Don't define/undef NDEBUG 			*/
/* 03/18/03  JRB     21    Fix QNX #ifdef.				*/
/* 02/20/03  JRB     20    Del PSOS code.				*/
/* 02/17/03  CRM     19    Added "defined(linux)" code.			*/
/* 02/17/03  JRB     18	   Stop using SYSTEM_SEL define.		*/
/*			   Add conio.h for WIN32.			*/
/*			   Add sys/time.h, sys/select.h for UNIX.	*/
/*			   Add termio.h for UNIX & QNX.			*/
/* 02/27/02  EJV     17    Added limits.h to most of systems.		*/
/*			   Check if LONG_MAX and INT_MAX defined.	*/
/* 07/27/01  DSF     16    crtdbg.h should only be included if _DEBUG	*/
/*			   is defined					*/
/* 03/16/01  DSF     15    Make sure VERIFY is not defined before	*/
/*			   defining it					*/
/* 02/02/01  DSF     14    Added asserts				*/
/* 01/19/01  EJV     13    Added <ctype.h>  for      SYSTEM_SEL_SYS_5.	*/
/* 01/03/01  EJV     12    Added <fcntl.h>  for      SYSTEM_SEL_SYS_5.	*/
/* 10/13/00  EJV     11    Added <unistd.h> for some SYSTEM_SEL_SYS_5.	*/
/* 05/05/00  JRB     10    Added "select.h" for some systems.		*/
/* 04/20/00  EJV     09    Added stdarg.h for SYSTEM_SEL_SYS_5.		*/
/* 02/04/99  JRB     08    Added types.h & stat.h for most systems.	*/
/* 07/01/98  JRB     07    Added stdarg.h & ctype.h for some systems.	*/
/* 12/29/97  JRB     06    Cleaned up OS2 (include os2.h). More PSOS.	*/
/* 12/11/97  JRB     05    Cleaned up PSOS includes. Use SYS_PSOS.	*/
/* 12/11/97  JRB     04    Deleted EMBEDDED_6800 includes.		*/
/* 10/29/97  EJV     03    Corrected max maro definition		*/
/* 10/28/97  EJV     02    Added *.h files specific for SYS_5		*/
/* 08/15/97  EJV     01    Added *.h files specific for SYS_QNX4	*/
/* 04/02/97  DTL   7.00    MMSEASE 7.0 release. See MODL70.DOC for	*/
/*			   history.					*/
/************************************************************************/

#ifndef SYSINCS_INCLUDED
#define SYSINCS_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#if defined (_WIN32)
#include <windows.h>
#include <process.h>		/* for _beginthread, _endthread	*/
#endif

#if defined(_WIN32) || defined(MSDOS) || defined(__MSDOS__)
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <conio.h>
#endif

#if defined(VXWORKS)
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <selectLib.h>
#include <limits.h>
#include <signal.h>		/* for "kill", etc.		*/
/* Sockets related includes	*/
#include <sys/socket.h>
#include <ioLib.h>
#include <sockLib.h>
#include <pipeDrv.h>
#include <sysLib.h>
#include <usrLib.h>
#include <netinet/in.h>		/* IPPROTO_*, etc.			*/
#include <arpa/inet.h>		/* inet_addr, etc.			*/
#include <netinet/tcp.h>	/* TCP_NODELAY, etc.			*/
#endif

/* UNIX or "UNIX-like" systems	*/
#if defined(sun) || defined(linux)
#include <unistd.h>	/* SHOULD be before any other include files 	*/
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#define	max(a,b)	(((a) > (b)) ? (a) : (b))
#define	min(a,b)	(((a) < (b)) ? (a) : (b))
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <fcntl.h>		/* open, O_RDONLY, O_WRONLY, etc.	*/
#include <ctype.h>
#include <limits.h>
#include <termio.h>
#include <sys/select.h>
#include <signal.h>		/* for "kill", etc.		*/
#include <sys/ioctl.h>

/* Sockets related includes	*/
#include <sys/socket.h>
#include <netdb.h>		/* gethostbyname, etc.			*/
#include <netinet/in.h>		/* IPPROTO_*, etc.			*/
/* Forward references are supplied to eliminate xlC_r compiler warnings	*/
struct ether_addr;		/* forward reference			*/
struct sockaddr_dl;		/* forward reference			*/
#include <arpa/inet.h>		/* inet_addr, etc.			*/
#include <netinet/tcp.h>	/* TCP_NODELAY, etc.			*/
#endif

#if (!defined(INT_MAX)) || (!defined(LONG_MAX))
#error INT_MAX and LONG_MAX must be defined. Usually defined in limits.h
#endif


/************************************************************************/
/************************************************************************/
/*		Assert stuff						*/
/************************************************************************/
/************************************************************************/

#include <assert.h>

#if defined (_WIN32) && defined (_DEBUG)
#include <crtdbg.h>
#endif

#if !defined (_ASSERT)
#define _ASSERT		assert
#endif

#if !defined (_ASSERTE)
#define _ASSERTE(e)	assert(e)
#endif

#if !defined (ASSERT)
#define ASSERT		_ASSERT
#endif

#if !defined (ASSERTE)
#define ASSERTE		_ASSERTE
#endif


#if !defined (_SASSERT)
#define _SASSERT	assert
#endif

#if !defined (_SASSERTE)
#define _SASSERTE(e)	assert(e)
#endif

#if !defined (SASSERT)
#define SASSERT		_SASSERT
#endif

#if !defined (SASSERTE)
#define SASSERTE	_SASSERTE
#endif

#if !defined (VERIFY)
#if !defined (NDEBUG)
#define VERIFY(e)	_SASSERTE(e)
#else
#define VERIFY(e)	((void) (e))
#endif
#endif

#if !defined (C_ASSERT)
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
#endif

#ifdef __cplusplus
}
#endif

#endif


