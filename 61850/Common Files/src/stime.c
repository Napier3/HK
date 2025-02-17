/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*		1993 - 2003, All Rights Reserved 			*/
/*									*/
/* MODULE NAME : stime.c  						*/
/* PRODUCT(S)  : SLOG							*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 03/11/04  GLB     21    Remove "thisFileName"                    	*/
/* 12/09/03  JRB     20    Add LYNX support.				*/
/* 11/04/03  JRB     19    Add sMsSleep (replaces gs_sleep).		*/
/* 10/13/03  EJV     18    Chg defined(vms) to defined(__VMS)		*/
/* 04/08/03  EJV     17    Use S_LOCK_UTIL_RESOURCES (better for non-MT apps)*/
/* 03/21/03  EJV     16    _WIN32: sGetMsTime, sGetSysMsTime must be	*/
/*			   protected by mutex,prevent incorect wrapCount*/
/* 03/18/03  EJV     15    Corrected __QNX4__ to __QNX__ (per JRB).	*/
/* 03/18/03  EJV     14    sGetMsTime: fixed lastTime casting problem	*/
/*			     (made lastTime ST_UINT on _WIN32).		*/ 
/* 02/17/03  CRM     13    Added "defined(linux)" code.			*/
/* 02/17/03  JRB     12    Add "sysincs.h" & del other includes.	*/
/*			   Del obsolete _WINDOWS, MSOS2 code.		*/
/* 02/17/03  EJV     11    sGetMsTime, sGetSysMsTime: fixed wrap counter*/
/*			   Auto-initialize funs with call to stimeInit()*/
/*			   Chg S_LOCK_UTIL_RESOURCES to gs_get_sem,avoid loop*/
/* 06/05/02 MDE,EJV  10    sGetMsTime: workaround some math problem	*/
/* 11/29/01  EJV     09    Del code for old LATT, XENIX, ultrix, RMX86.	*/
/* 06/19/01  JRB     08    Chg S_LOCK_COMMON.. to S_LOCK_UTIL_RESOURCES so	*/
/*			   glbsem doesn't log (caused infinite loop).	*/
/* 04/19/00  JRB     07    Lint cleanup.				*/
/* 11/18/99  EJV     06    Added code to capture wrapping of ms counter	*/
/*			   for _WIN32 and PHARLAP_ETS.			*/
/* 09/13/99  MDE     05    Added SD_CONST modifiers			*/
/* 11/05/97  DSF     04    Added sGetSysMsTime ()			*/
/* 09/22/97  JRB     03    Fixed some #if's.				*/
/* 09/09/97  JRB     02    Use GetTickCount for PHARLAP_ETS.		*/
/* 09/08/97  EJV     01    Added code for QNX.				*/
/* 04/02/97  DTL   7.00    MMSEASE 7.0 release. See MODL70.DOC for	*/
/*			   history.					*/
/************************************************************************/

#if defined (_WIN32)
#include <windows.h>
#include <mmsystem.h>
#if defined (PHARLAP_ETS)
#define timeGetTime	GetTickCount	/* timeGetTime not supported	*/
#endif		/* PHARLAP_ETS	*/
#endif

#if defined(__OS2__)
#define INCL_DOSMISC
#define INCL_ERRORS
#define INCL_DOSFILEMGR
#include <os2.h>
#include "hrutil.h"
#endif

#include "glbtypes.h"
#include "sysincs.h"
#include "glbsem.h"

#if defined(__VMS)
#include <starlet.h>
#endif

#define MS_PER_TICK	(1000/18.2)

#if defined(MSDOS)
#include <bios.h>
#ifdef USE_PCHRT
#include "stime.h"
#include "pchrt.h"
static ST_INT msTimer;		/* Timer ID number 			*/
/* Total time = cumulative time + current timer count 			*/
static ST_DOUBLE  cumTime;
#endif
#endif

/************************************************************************/

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) \
    || defined(VXWORKS) || defined(__QNX__) || defined(__LYNX) 
static ST_DOUBLE lastTime;	/* Used for differential timing			*/
#elif defined(_WIN32)
static ST_UINT32 lastTime;	/* Used for differential timing			*/
#else
static ST_INT32 lastTime;	/* Used for differential timing			*/
#endif

#if defined (_WIN32)
static ST_UINT32 lastCheckTime;	/* last time checked				*/
static ST_UINT64 wrapCount;	/* wrap count (see timeGetTime or GetTickTime)	*/
#endif

static ST_INT initialized;

/************************************************************************/

ST_INT stimeInit (ST_VOID)
  {
ST_UINT32 msTime;

#if defined (MSDOS) && defined (USE_PCHRT)
ST_INT istat;
#endif

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) || defined(__LYNX)
struct timeval tp;
struct timezone tzp;
#endif

#if defined (__QNX__)
struct timespec tp;
#endif

#if defined(__VMS)
ST_INT32 vmsTime = 0;
#endif

  msTime = 0;

/* Allow multiple calls 						*/
  if (initialized)
    return (SD_SUCCESS);

  S_LOCK_UTIL_RESOURCES ();	/* NOTE: this macro is now using non-logging gs_get_sem() */

#if defined (MSDOS)
#if defined (USE_PCHRT)

/* Initialize the timer system 						*/
  istat = t_start();        	/* returns # bytes allocated if OK 	*/
  if (!istat)
    {
    S_UNLOCK_UTIL_RESOURCES ();
    return (SD_FAILURE);
    }
  msTimer = t_alloc(T_MSEC,"Elapsed time");  /* Allocate the timer 	*/
  if (msTimer == T_FAIL)
    {
    t_stop();
    S_UNLOCK_UTIL_RESOURCES ();
    return (SD_FAILURE);
    }

  t_entry(msTimer);			     /* start it going 		*/
#else /* USE_PCHRT */

  _bios_timeofday (_TIME_GETCLOCK,(ST_INT32*) &msTime);
  lastTime = msTime;

#endif /* USE_PCHRT */
#endif /* MSDOS */

#if defined(__OS2__)

/* Use the HRTIMER.SYS if it is installed.  The penalty is the OS/2	*/
/* Toolkit timer which has a very coarse granularity.			*/

  if (startTiming(0) == SD_SUCCESS)
    {
    timingSave (0,"");
    lastTime = 0;
    }
  else
    {
    if (DosQuerySysInfo (QSV_MS_COUNT,QSV_MS_COUNT,
                (PST_VOID)&msTime,sizeof(msTime)) != SD_SUCCESS)
      {
      lastTime = msTime;
      S_UNLOCK_UTIL_RESOURCES ();
      return(SD_FAILURE);
      }
    else
      {
      lastTime = msTime;
      }
    }

#endif /* __OS2__  */

#if defined (VXWORKS)
  lastTime = (ST_FLOAT) time (NULL);
#endif

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) || defined(__LYNX)
  gettimeofday (&tp, &tzp);
  lastTime = (ST_DOUBLE)tp.tv_sec + ((ST_DOUBLE)tp.tv_usec / 1000000);
#endif

#if defined (__QNX__)
  /* NOTE: The clock_gettime fun is available in the POSIX 1003.4 release. */
  clock_gettime (CLOCK_REALTIME, &tp);
  lastTime = (ST_DOUBLE)tp.tv_sec + ((ST_DOUBLE)tp.tv_nsec / 1000000000);
#endif /* __QNX__ */

#if defined (_WIN32)
  lastTime = timeGetTime ();
  wrapCount = 0;
  lastCheckTime = lastTime;
#endif

#if defined(__VMS)
  sys$gettim (&vmsTime);
/*  lastTime = vmsTime * 10000; */ /* used to be this RKR */
  lastTime = vmsTime / 10000;
#endif

  initialized = SD_TRUE;
  S_UNLOCK_UTIL_RESOURCES ();
  return (SD_SUCCESS);
  }

/************************************************************************/
/*		                sGetMsTime				*/
/* The most frequently used Stime function				*/
/************************************************************************/

ST_DOUBLE 	sGetMsTime (ST_VOID)
  {
ST_UINT32 msTime;
ST_DOUBLE ret;

#if defined(sun) || defined(linux)
struct timeval tp;
struct timezone tzp;
#endif

  msTime = 0;
  ret = 0;

  if (!initialized)
    if (stimeInit () != SD_SUCCESS)
      return ((ST_DOUBLE)0.0);

  S_LOCK_UTIL_RESOURCES ();

#if defined (VXWORKS)
    ret = (ST_DOUBLE) time (NULL);
#endif

#if defined(sun) ||	defined(linux) 
    gettimeofday (&tp, &tzp);
    ret = ((ST_DOUBLE) (((ST_DOUBLE) tp.tv_sec + ((ST_DOUBLE) tp.tv_usec / 1000000)) 
   				                     	- lastTime)) * 1000;
#endif

#if defined (_WIN32)
  /* NOTE: The timeGetTime and GetTickCount (used for PHARLAP_ETS)	*/
  /*       return DWORD value that wraps to 0 every 49 days.		*/
  /*       We need to detect the wrap up moment and save it.		*/
  msTime = timeGetTime ();
  if ( msTime < lastCheckTime )
    /* the ms counter wrapped to 0 */
    wrapCount += ( (ST_UINT64) 1 << 32 );	/* increment the high part of ST_UINT64	*/
    ret = (ST_DOUBLE) ((wrapCount + (ST_UINT64) msTime) - (ST_UINT64) lastTime);
		/* Note: lastTime is now ST_UINT32.				*/
		/*       When lastTime was ST_INT32 the compiler casted it	*/
		/*       first to ST_INT64 and next to ST_UINT64. If the 	*/
		/*       computer run for many days without rebooting we have	*/
		/*       experienced negative ret. The first cast generated	*/
		/*       very big negative 64-bit number and the second cast	*/
		/*       to unsigned 64-bit generated very big positive number	*/
		/*       resulting in negative ret.				*/
  lastCheckTime = msTime;			/* save for next check	*/
#endif

  S_UNLOCK_UTIL_RESOURCES ();

  return (ret);
  }

/************************************************************************/
/*		                sGetSysMsTime				*/
/* Returns system time in milliseconds					*/
/************************************************************************/

ST_DOUBLE 	sGetSysMsTime (ST_VOID)
  {
ST_UINT32 msTime;
ST_DOUBLE ret;

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) || defined(__LYNX)
struct timeval tp;
struct timezone tzp;
#endif

#if defined (__QNX__)
struct timespec tp;
#endif

#if defined(__VMS)
ST_INT32 vmsTime = 0;
#endif

  msTime = 0;
  ret = 0;

  if (!initialized)
    if (stimeInit () != SD_SUCCESS)
      return ((ST_DOUBLE)0.0);

  S_LOCK_UTIL_RESOURCES ();

#if defined(MSDOS)
#if defined(USE_PCHRT)

/* get current elapsed time on this timer 				*/
  msTime = t_check_timer (msTimer,T_TOTAL);    

/* Calculate the total elapsed time 					*/
  ret = (ST_DOUBLE) msTime + cumTime;

/* Since this timer is good for no more than 74 minutes, we do a  	*/
/* reset every 10 minutes and save the count in cumulative counter 	*/

  if (msTime > 0x927C0)		/* 10 minutes since last save & reset 	*/
    {
    cumTime += (ST_DOUBLE) msTime;
    t_exit(msTimer);     	/* stop the timer 			*/
    t_reset (msTimer);   	/* reset the count		 	*/
    t_entry(msTimer);	   	/* start it going 			*/
    }

#else /* USE_PCHRT */

    _bios_timeofday (_TIME_GETCLOCK,(ST_INT32*) &msTime);
    ret = ((ST_DOUBLE) (msTime - lastTime)) * MS_PER_TICK;

#endif /* USE_PCHRT */
#endif /* MSDOS */

#if defined(__OS2__)
   
    if (timingSave (0,"") == SD_SUCCESS)
      {
      ret = (ST_DOUBLE) ulMsecs;
      }
    else
      {
      DosQuerySysInfo (QSV_MS_COUNT,QSV_MS_COUNT,
                (PST_VOID)&msTime,sizeof(msTime));

      ret = (ST_DOUBLE) msTime;
      }

#endif /* __OS2__ */

#if defined (VXWORKS)
    ret = (ST_DOUBLE) time (NULL);
#endif

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) || defined(__LYNX)
    gettimeofday (&tp, &tzp);
    ret = ((ST_DOUBLE) (((ST_DOUBLE) tp.tv_sec + ((ST_DOUBLE) tp.tv_usec / 1000000)))) * 1000;
#endif

#if defined (__QNX__)
  /* NOTE: The clock_gettime fun is available in the POSIX 1003.4 release. */
  clock_gettime (CLOCK_REALTIME, &tp);
  ret = ((ST_DOUBLE) (((ST_DOUBLE) tp.tv_sec + ((ST_DOUBLE) tp.tv_nsec / 1000000000)))) * 1000;
#endif /* __QNX__ */

#if defined (_WIN32)
  /* NOTE: The timeGetTime and GetTickCount (used for PHARLAP_ETS)	*/
  /*       return DWORD value that wraps to 0 every 49 days.		*/
  /*       We need to detect the wrap up moment and save it.		*/
  msTime = timeGetTime ();
  if ( msTime < lastCheckTime )
    /* the ms counter wrapped to 0 */
    wrapCount += ( (ST_UINT64) 1 << 32 );	/* increment the high part of ST_UINT64	*/
  ret = (ST_DOUBLE) (wrapCount + (ST_UINT64) msTime);
  lastCheckTime = msTime;			/* save for next check	*/
#endif

#if defined(__VMS)
  sys$gettim (&vmsTime);
  ret = (ST_DOUBLE) (vmsTime / 10000);
#endif

  S_UNLOCK_UTIL_RESOURCES ();

  return (ret);
  }

/************************************************************************/
/*		               sResetMsTime				*/
/************************************************************************/

ST_VOID sResetMsTime (ST_VOID)
  {	
#if (defined (MSDOS) && !defined (USE_PCHRT)) || defined(__OS2__)
ST_UINT32 msTime;
#endif

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) || defined(__LYNX)
struct timeval tp;
struct timezone tzp;
#endif

#if defined (__QNX__)
struct timespec tp;
#endif

#if defined(__VMS)
ST_INT32 vmsTime = 0;
#endif

  if (!initialized)
    if (stimeInit () != SD_SUCCESS)
      return;

  S_LOCK_UTIL_RESOURCES ();

#if defined (MSDOS)
#if defined (USE_PCHRT)

  t_exit(msTimer);     		/* stop the timer 			*/
  t_reset (msTimer);   		/* reset the count		 	*/
  t_entry(msTimer);	   	/* start it going 			*/
  cumTime = 0;			/* reset cumulative count 		*/

#else /* USE_PCHRT */

    _bios_timeofday (_TIME_GETCLOCK,(ST_INT32*) &msTime);
    lastTime = msTime;

#endif /* USE_PCHRT */
#endif /* MSDOS */

#if defined(__OS2__)

    if (timingSave (0,"") == SD_SUCCESS)
      {
      lastTime = ulMsecs ;
      }
    else
      {
      DosQuerySysInfo(QSV_MS_COUNT, 
                       QSV_MS_COUNT,
                       (PST_VOID)&msTime,
		       sizeof(msTime));
  
      lastTime = msTime;
      }

#endif /* __OS2__ */

#if defined (VXWORKS)
  lastTime = (ST_FLOAT) time (NULL);
#endif

#if defined(_AIX) || defined(sun) || defined(__hpux) ||	defined(linux) \
    || (defined(__alpha) && !defined(__VMS)) || defined(__LYNX)
  gettimeofday (&tp, &tzp);
  lastTime = (ST_DOUBLE)tp.tv_sec + ((ST_DOUBLE)tp.tv_usec / 1000000);
#endif

#if defined (__QNX__)
  /* NOTE: The clock_gettime fun is available in the POSIX 1003.4 release. */
  clock_gettime (CLOCK_REALTIME, &tp);
  lastTime = (ST_DOUBLE)tp.tv_sec + ((ST_DOUBLE)tp.tv_nsec / 1000000000);
#endif /* __QNX__ */

#if defined (_WIN32)
  lastTime = timeGetTime ();
  wrapCount = 0;
  lastCheckTime = lastTime;
#endif

#if defined(__VMS)
  sys$gettim (&vmsTime);
/*  lastTime = vmsTime * 10000; */
  lastTime = vmsTime / 10000;
#endif
  S_UNLOCK_UTIL_RESOURCES ();
  }

/************************************************************************/
/*                               stimeExit                 		*/
/* terminate timer use 							*/
/************************************************************************/

ST_VOID	stimeExit (ST_VOID)
  {
  if (!initialized)
      return;

  S_LOCK_UTIL_RESOURCES ();
#if defined (MSDOS)
#if defined (USE_PCHRT)

  t_stop();

#endif /* (MSDOS) */
#endif /* (USE_PCHRT) */

  initialized = SD_FALSE;
  S_UNLOCK_UTIL_RESOURCES ();
  }

/************************************************************************/
/*		                sGetMsStartTime				*/
/* Function accessing start time				        */
/* Currently this func is working only with HR Timer                    */
/************************************************************************/

ST_INT 	sGetMsStartTime (unsigned long *pulMs,
                                  unsigned long *pulNs)
  {
ST_INT ret;

  ret = SD_FAILURE;
  *pulMs = 0;
  *pulNs = 0;

  if (!initialized)
    if (stimeInit () != SD_SUCCESS)
      return (ret);

  S_LOCK_UTIL_RESOURCES ();

#if defined(__OS2__)
   
  ret = getStartTime(0, pulMs, pulNs);

#endif /* __OS2__ */

  S_UNLOCK_UTIL_RESOURCES ();
  return (ret);
  }

/************************************************************************/
/*		                sSetMsStartTime				*/
/* Function setting start time to sync timing logs between processes    */
/* Currently this func is working only with HR Timer                    */
/************************************************************************/

ST_INT 	sSetMsStartTime (unsigned long ulMs,
                                  unsigned long ulNs)
  {
ST_INT ret;

  ret = SD_FAILURE;

  if (!initialized)
    if (stimeInit () != SD_SUCCESS)
      return (ret);

  S_LOCK_UTIL_RESOURCES ();
   
#if defined(__OS2__)
   
  ret = setStartTime(0, (ST_UINT32)ulMs, (ST_UINT32)ulNs);

#endif /* __OS2__ */

  S_UNLOCK_UTIL_RESOURCES ();
  return (ret);
  }

/************************************************************************/
/*			sMsSleep					*/
/*----------------------------------------------------------------------*/
/* Calls system function to suspend current task or thread for		*/
/* specified amount of time.						*/
/* Parameters:								*/
/*	ST_LONG		ms	Number of milliseconds to sleep		*/
/* Return values:							*/
/*	none								*/
/************************************************************************/

#if defined(_WIN32)

ST_VOID sMsSleep (ST_LONG ms)
  {
  Sleep (ms);
  }

#else	/* all other systems	*/

/* This version of the function uses the POSIX nanosleep function.	*/
ST_VOID sMsSleep (ST_LONG ms)
  {
struct timespec rqtp;

  rqtp.tv_sec = ms / 1000;
  rqtp.tv_nsec =  (ms % 1000) * 1000000;    /* 1000 ms/us, 1000 us/ns ... 	*/
  nanosleep (&rqtp, NULL);	/* should be available on AIX v5.x	*/
  }

#endif	/* all other systems	*/
