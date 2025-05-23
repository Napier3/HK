/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*	1997-2003, All Rights Reserved					*/
/*									*/
/* MODULE NAME : glbsem_w32.c						*/
/* PRODUCT(S)  :							*/
/*									*/
/* MODULE DESCRIPTION :  Multi-thread support for Windows ONLY.		*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 07/21/04  DWL     13    Added ifdef so non debug configs would build.*/
/* 07/02/04  DSF     12    Always link in winmm.lib			*/
/* 05/21/04  DSF     11    Timeout log is now FLOW instead of NERR	*/
/* 04/19/04  DSF     10    gs_wait_thread () now returns SD_TIMEOUT on	*/
/*			   timeouts					*/
/* 12/29/03  ASK     09    enable logLastError, pass gle to logLastError*/
/* 12/03/03  EJV     08    gs_is_win_ver(): chg return ST_RET to ST_INT;*/
/*			     Add SD_WIN_VER_2003_AND_LATER, replaced	*/
/*			     SD_WIN_VER_NET with SD_WIN_VER_2003;	*/
/* 12/01/03  EJV     07    gs_is_win_ver: chk for corr ret 1, 0, -1.	*/
/*			   Named mutex, event: for 2000S w/terminal serv*/
/*			     chg from XP to SD_WIN_VER_2K_AND_LATER.	*/
/* 11/24/03  DSF     06    Spelling					*/
/* 11/04/03  JRB     05    Del gs_sleep (use sMsSleep).			*/
/* 06/20/03  EJV     04    Renamed gs_mutex_get to gs_mutex_get_tm.	*/
/* 06/12/03  EJV     03    Redesigned mutex sems implementation.	*/
/* 06/10/03  EJV     02    Added gs_named_mutex_xxx functions.		*/
/* 06/06/03  JRB     01    NEW. Code taken out of glbsem.c		*/
/************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "mem_chk.h"
#include "slog.h"
#include "glbsem.h"

#include <process.h>	/* for _beginthreadex proto	*/

#pragma comment(linker, "/defaultlib:winmm.lib")

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/


#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

static ST_VOID logLastError (DWORD errCode);

	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/
	/*							*/
	/*	MUTEX SEMAPHORE FUNCTIONS for _WIN32		*/
	/*							*/
	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/

/************************************************************************/
/*                         gs_mutex_create				*/
/*----------------------------------------------------------------------*/
/* Initialize the mutex semaphore ms.					*/
/* CRITICAL_SECTION is used for mutex semaphore for faster operation.	*/
/* Parameters:								*/
/*	ms		pointer to mutex object				*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/************************************************************************/

ST_RET gs_mutex_create (ST_MUTEX_SEM *ms)
  {
  ms->mutexType = GS_MUTEX_UNNAMED;
  InitializeCriticalSection (&ms->u.cs);

  return (SD_SUCCESS);
  }

/************************************************************************/
/*                       gs_named_mutex_create				*/
/*----------------------------------------------------------------------*/
/* Create/Open NAMED mutex.						*/
/* On Windows XP this function prepends 'Global\\' to the mutex name	*/
/* and sets the security descriptor in the way that the mutex can	*/
/* be accessed by processes in different user spaces (in Windows XP Fast*/
/* User Switching).							*/
/* For each call to this function the gs_named_mutex_destroy must be	*/
/* called.								*/
/* Parameters:								*/
/*	ms		pointer where to return handle to named	mutex	*/
/*	name	       	pointer to mutex name.				*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/************************************************************************/

ST_RET gs_named_mutex_create (ST_MUTEX_SEM *ms, ST_CHAR *name)
  {
ST_RET   ret = SD_SUCCESS;
HANDLE   hMutex = NULL;
ST_CHAR	 glbMutexName[MAX_PATH+1];
ST_CHAR	*mutexName;		/* ptr to mutex name to create	*/

  if (ms == NULL || name == NULL)
    {
#if defined(DEBUG_SISCO) 	
    GLBSEM_LOG_ERR0 ("GLBSEM error: gs_named_mutex_create() failed ms=NULL or name=NULL");
#endif
    return (SD_FAILURE);
    }

  /* set the mutex type */
  ms->mutexType = GS_MUTEX_NAMED;

  mutexName = name;			/* point to name for now	*/

  if (gs_is_win_ver (SD_WIN_VER_2K_AND_LATER) == 1)
    {
    /* Check if the mutex name need to be prefixed with "Global\\" string */
    if (memcmp (name, "Global\\", strlen ("Global\\")) != 0)
      {
      /* prepend "Global\\" to the name */
      sprintf (glbMutexName, "Global\\%s", name);
      mutexName = glbMutexName;
      }
    }

  if (gs_is_win_ver (SD_WIN_VER_2K_AND_LATER) == 1)
    {
    PSECURITY_DESCRIPTOR psd;
    SECURITY_ATTRIBUTES sa;

    /* This code allows the mutex to be accessed from different			*/
    /* applications in different users (Windows XP Fast User Switching).	*/
    psd = (PSECURITY_DESCRIPTOR) LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);
    if (psd == NULL)
      return (SD_FAILURE);
    if (!InitializeSecurityDescriptor(psd, SECURITY_DESCRIPTOR_REVISION))
      {
      LocalFree (psd);
      return (SD_FAILURE);
      }
    if (!SetSecurityDescriptorDacl(psd, TRUE, (PACL) NULL, FALSE))
      {
      LocalFree (psd);
      return (SD_FAILURE);
      }
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = psd;
    sa.bInheritHandle = TRUE;

    hMutex = CreateMutex (&sa,		/* security attributes		*/
      			  SD_FALSE,	/* FALSE is initially not owned	*/
                          mutexName);    /* object name			*/
    if (hMutex == NULL)
      {
#if defined(DEBUG_SISCO) 	
      DWORD gle = GetLastError ();
      GLBSEM_LOG_ERR2 ("GLBSEM error: CreateMutex failed GLE=%d for %s", 
                       (unsigned int) gle, mutexName);
#endif
      ret = SD_FAILURE;
      }
    LocalFree (psd);
    }
  else
    {
    /* this is Win 98, NT or 2000 */
    hMutex = CreateMutex (NULL,		/* no security attributes	*/
      			  SD_FALSE,	/* FALSE is initially not owned	*/
                          mutexName);    /* object name			*/
    if (hMutex == NULL)
      {
#if defined(DEBUG_SISCO) 	
      DWORD gle = GetLastError ();
      GLBSEM_LOG_ERR2 ("GLBSEM error: CreateMutex failed GLE=%d for %s", 
                       (unsigned int) gle, mutexName);
#endif
      ret = SD_FAILURE;
      }
    }

  ms->u.hMutex = hMutex;		/* return the handle to user		*/

  return (ret);
  }

/************************************************************************/
/*			gs_mutex_get_tm	        			*/
/*----------------------------------------------------------------------*/
/* Lock the mutex semaphore ms.						*/
/* This function uses the gs_wait_event_sem to wait for ownership of	*/
/* the named mutex. The named mutex object can be also passed to the	*/
/* gs_wait_mult_event_sem function when waiting for multiple objects is	*/
/* required.								*/
/*									*/
/* Parameters:								*/
/*	ms		pointer to mutex object				*/
/*	timeout		Interval in milliseconds to wait for the named	*/
/*			mutex to be owned, if -1L then the function will*/
/*			be blocked indefinitely until the named mutex	*/
/*			is owned.					*/
/*			The timeout parameter is ignored for unnamed	*/
/*			mutex. The function will wait indefinetely until*/
/*			the mutex is owned.				*/
/* Return values:							*/
/*	none								*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/*      SD_TIMEOUT      timeout						*/
/*									*/
/* CRITICAL: gs_mutex_get_tm must NOT call any slog, stime, or mem_chk	*/
/*	functions. These functions call gs_mutex_get_tm causing		*/
/*	an infinite loop. Logging in the named mutex code is OK.	*/
/************************************************************************/

ST_RET gs_mutex_get_tm (ST_MUTEX_SEM *ms, ST_LONG timeout)
  {
ST_RET ret = SD_SUCCESS;

  if (!gs_already_inited)	/* Make sure gs is initialized.		*/
    gs_init ();

  if (ms->mutexType == GS_MUTEX_UNNAMED)
    /* ! do not put logging here to avoid infinite loop */
    EnterCriticalSection (&ms->u.cs);
  else
    /* named mutex */
    ret = gs_wait_event_sem ((ST_EVENT_SEM) ms->u.hMutex, timeout);

  return (ret);
  }

/************************************************************************/
/*			gs_mutex_free		        		*/
/*----------------------------------------------------------------------*/
/* Unlock the mutex semaphore ms.					*/
/* Parameters:								*/
/*	ms		pointer to mutex object				*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/* CRITICAL: gs_mutex_free must NOT call any slog, stime, or mem_chk	*/
/*	functions. These functions call ge_mutex_free which would cause	*/
/*	an infinite loop. Logging in the named mutex code is OK.	*/
/************************************************************************/

ST_RET gs_mutex_free (ST_MUTEX_SEM *ms)
  {
ST_RET ret = SD_SUCCESS;

  if (ms->mutexType == GS_MUTEX_UNNAMED)
    /* ! do not put logging here to avoid infinite loop */
    LeaveCriticalSection (&ms->u.cs);
  else
    {
    /* named mutex */
    if (ReleaseMutex (ms->u.hMutex) == SD_FALSE)
      {
#if defined(DEBUG_SISCO) 	
      DWORD gle = GetLastError ();
      GLBSEM_LOG_ERR2 ("GLBSEM error: ReleaseMutex failed for hMutex=%d (GLE=%d)", 
                       ms->u.hMutex, (unsigned int) gle);
#endif
      ret = SD_FAILURE;
      }
    }

  return (ret);
  }

/************************************************************************/
/*                         gs_mutex_destroy				*/
/*----------------------------------------------------------------------*/
/* Free all resources allocated for the MUTEX semaphore ms.		*/
/* Parameters:								*/
/*	ms		pointer to mutex object				*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/************************************************************************/

ST_RET gs_mutex_destroy (ST_MUTEX_SEM *ms)
  {
ST_RET ret = SD_SUCCESS;

  if (ms->mutexType == GS_MUTEX_UNNAMED)
    DeleteCriticalSection (&ms->u.cs);
  else
    {
    /* named mutex */
    if (CloseHandle (ms->u.hMutex) == SD_FALSE)
      {
#if defined(DEBUG_SISCO) 	
      DWORD gle = GetLastError ();
      GLBSEM_LOG_ERR2 ("GLBSEM error: CloseHandle failed for hMutex=%d (GLE=%d)", 
                       ms->u.hMutex, (unsigned int) gle);
#endif
      ret = SD_FAILURE;
      }
    }

  return (ret);
  }

	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/
	/*							*/
	/*	USER's EVENT SEMAPHORE FUNCTIONS for _WIN32	*/
	/*							*/
	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/

/************************************************************************/
/*                       gs_get_event_sem				*/
/*----------------------------------------------------------------------*/
/* Create a "manual-reset" or "auto-reset" event semaphore.		*/
/* Parameters:								*/
/*	manualReset		SD_TRUE or SD_FALSE			*/
/* Return values:							*/
/*	ST_EVENT_SEM		handle to event semaphore object	*/
/************************************************************************/

ST_EVENT_SEM gs_get_event_sem (ST_BOOLEAN manualReset)
  {
ST_EVENT_SEM retEventSem; 

  retEventSem = CreateEvent(NULL,         // no security attributes
      			    manualReset,  // manual-reset event
      			    FALSE,        // initial state is signaled
      			    NULL	  // object name
			    ); 
  if (retEventSem == NULL)
    GLBSEM_LOG_ERR1 ("GLBSEM error: CreateEvent failed for event semaphore, rc = %d", GetLastError ());

  return (retEventSem);
  }

/************************************************************************/
/*                       gs_get_named_event_sem				*/
/*----------------------------------------------------------------------*/
/* Create a "manual-reset" or "auto-reset" NAMED event semaphore.	*/
/* On Windows XP this function prepends 'Global\\' to the semaphore name*/
/* and sets the security descriptor in the way that the semaphore can	*/
/* be accessed by processes in different user spaces (in Windows XP Fast*/
/* User Switching).							*/
/* Parameters:								*/
/*	name			pointer to semaphore name.		*/
/*	manualReset		SD_TRUE or SD_FALSE			*/
/* Return values:							*/
/*	ST_EVENT_SEM		handle to named event semaphore object	*/
/************************************************************************/

ST_EVENT_SEM gs_get_named_event_sem (ST_CHAR *name, ST_BOOLEAN manualReset)
  {
ST_EVENT_SEM retEventSem = NULL;
ST_CHAR	     glbSemName[MAX_PATH+1];
ST_CHAR	    *semName;		/* pointer to semaphore name to create	*/

  /* NOTE: do not put any logging to this function. It is used in DLLs.	*/

  semName = name;		/* point to name for now	*/

  if (gs_is_win_ver (SD_WIN_VER_2K_AND_LATER) == 1)
    {
    /* Check if the semaphore name need to be prefixed with "Global\\" string */
    if (memcmp (name, "Global\\", strlen ("Global\\")) != 0)
      {
      /* prepend "Global\\" to the name */
      sprintf (glbSemName, "Global\\%s", name);
      semName = glbSemName;
      }
    }

  if (gs_is_win_ver (SD_WIN_VER_2K_AND_LATER) == 1)
    {
    PSECURITY_DESCRIPTOR psd;
    SECURITY_ATTRIBUTES sa;

    /* This code allows the event semaphore to be accessed from	different	*/
    /* applications in different users (Windows XP Fast User Switching).	*/
    psd = (PSECURITY_DESCRIPTOR) LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);
    if (psd == NULL)
      return (NULL);
    if (!InitializeSecurityDescriptor(psd, SECURITY_DESCRIPTOR_REVISION))
      {
      LocalFree (psd);
      return (NULL);
      }
    if (!SetSecurityDescriptorDacl(psd, TRUE, (PACL) NULL, FALSE))
      {
      LocalFree (psd);
      return (NULL);
      }
    sa.nLength = sizeof(sa);
    sa.lpSecurityDescriptor = psd;
    sa.bInheritHandle = TRUE;

    retEventSem = CreateEvent(&sa,		/* security attributes	*/
        		      manualReset,	/* manual-reset event	*/
      			      SD_FALSE,		/* initial state is non-signaled */
      			      semName);         /* object name		*/
    LocalFree (psd);
    }
  else
    {
    /* this is Win 98, NT or 2000 */
    retEventSem = CreateEvent (NULL, manualReset, SD_FALSE, semName);
    }

  return (retEventSem);
  }

/************************************************************************/
/*                       gs_wait_event_sem				*/
/*----------------------------------------------------------------------*/
/* Wait for event semaphore es until it becomes signaled or timeout	*/
/* occurrs.								*/
/* If compiled with DEBUG_SISCO the gs_track variable need to be set to	*/
/* value >0 to enable the timing code. This way logging can be used	*/
/* by an application without degradation of the EVENT sem performance.	*/
/* Parameters:								*/
/*	es		event semaphore object				*/
/*	timeout		interval in milliseconds to wait for the es to	*/
/*			be signaled, if -1L then the function will be	*/
/*			blocked indefinitely until the event semaphore	*/
/*			is signaled.					*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/*      SD_TIMEOUT      timeout						*/
/************************************************************************/

ST_RET gs_wait_event_sem (ST_EVENT_SEM es, ST_LONG timeout)
  {
ST_RET ret;
DWORD rc;
#if defined(DEBUG_SISCO)
DWORD gle;
ST_DOUBLE startTime;
ST_DOUBLE endTime;
ST_DOUBLE elapsedTime;
#endif
ST_THREAD_ID thisThreadId;

  /* Let's see just who we are						*/
  thisThreadId = GET_THREAD_ID();

#if defined(DEBUG_SISCO)
  if (gs_track)
    startTime = sGetMsTime ();
#endif

  rc = WaitForSingleObject (es, timeout);

#if defined(DEBUG_SISCO)
  if (gs_track)
    {
    endTime = sGetMsTime ();
    elapsedTime = endTime - startTime;
    if (elapsedTime > gs_hwEventTime)
      gs_hwEventTime = elapsedTime;
    }
#endif

  if (rc == WAIT_FAILED)
    {
#if defined(DEBUG_SISCO) 	
    gle = GetLastError ();
    GLBSEM_LOG_ERR3 ("GLBSEM error: WaitEvent rc=0x%04x, GLE=0x%04x, Thread %08lx", 
                     (unsigned int) rc, (unsigned int)gle, thisThreadId);
    logLastError (gle);
#endif
    ret = SD_FAILURE;
    }
  else if (rc == WAIT_TIMEOUT)
    ret = SD_TIMEOUT;
  else
    ret = SD_SUCCESS;

  return (ret);
  }

/************************************************************************/
/*                       gs_wait_mult_event_sem				*/
/*----------------------------------------------------------------------*/
/* Wait for event semaphores in table esTable until one of them becomes	*/
/* signaled or timeout	occurrs.					*/
/* If compiled with DEBUG_SISCO the gs_track variable need to be set to	*/
/* value >0 to enable the timing code. This way logging can be used	*/
/* by an application without degradation of the EVENT sem performance.	*/
/* Parameters:								*/
/*	numEvents	number of event semaphores to wait for		*/
/*	esTable		pointer to table of event semaphore objects	*/
/*	activity	pointer to table where this function will mark	*/
/*			proper index entry with SD_TRUE for the event	*/
/*			semaphore that have been signaled		*/
/*	timeout		interval in milliseconds to wait for the es to	*/
/*			be signaled, if -1L then the function will be	*/
/*			blocked indefinitely until the event semaphore	*/
/*			is signaled.					*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/*      SD_TIMEOUT      timeout						*/
/************************************************************************/

ST_RET gs_wait_mult_event_sem (ST_INT numEvents, ST_EVENT_SEM *esTable, 
		ST_BOOLEAN *activity, ST_LONG timeout)
  {
ST_RET ret;
DWORD rc;
ST_INT i;
#if defined(DEBUG_SISCO)
DWORD gle;
ST_DOUBLE startTime;
ST_DOUBLE endTime;
ST_DOUBLE elapsedTime;
#endif
ST_THREAD_ID thisThreadId;

  /* Let's see just who we are						*/
  thisThreadId = GET_THREAD_ID();

#if defined(DEBUG_SISCO)
  if (gs_track)
    startTime = sGetMsTime ();
#endif

  rc = WaitForMultipleObjects (numEvents, esTable, FALSE, timeout);

#if defined(DEBUG_SISCO)
  if (gs_track)
    {
    endTime = sGetMsTime ();
    elapsedTime = endTime - startTime;
    if (elapsedTime > gs_hwEventTime)
      gs_hwEventTime = elapsedTime;
    }
#endif
 
 /* make sure activity array is zero'd out */
  memset (activity, '\x0', sizeof (ST_BOOLEAN) * numEvents);
  
  i = rc - WAIT_OBJECT_0;
  if ((i >= 0) && (i < numEvents))
    {
    activity[i] = SD_TRUE;
    ret = SD_SUCCESS;
    }
  else if (rc == WAIT_FAILED)
    {
#if defined(DEBUG_SISCO) 	
    gle = GetLastError ();
    GLBSEM_LOG_ERR3 ("GLBSEM error: WaitEvent rc=0x%04x, GLE=0x%04x, Thread %08lx", 
                     (unsigned int) rc, (unsigned int)gle, thisThreadId);
    logLastError (gle);
#endif
    ret = SD_FAILURE;
    }
  else if (rc == WAIT_TIMEOUT)
    ret = SD_TIMEOUT;
  else
    ret = SD_SUCCESS;

  return (ret);
  }

/************************************************************************/
/*                       gs_signal_event_sem				*/
/*----------------------------------------------------------------------*/
/* Signal event semaphore es.						*/
/* Manual-Reset: all waiting threads are released, es remains signaled	*/
/*               until reset explicitly by call to ResetEvent.		*/
/* Auto-Reset:   first waiting thread is released and es will be reset	*/
/*               to non-signaled state. If no thread is waiting the es	*/
/*               remains in signaled state unless ResetEvent is called.	*/
/* Parameters:								*/
/*	es		event semaphore object				*/
/* Return values:							*/
/*	none								*/
/************************************************************************/

ST_VOID gs_signal_event_sem (ST_EVENT_SEM es)
  {
BOOL rc;
#if defined(DEBUG_SISCO) 	
DWORD gle;
#endif

  rc = SetEvent(es);
#if defined(DEBUG_SISCO) 	
  if (rc == FALSE)
    {
    gle = GetLastError ();
    GLBSEM_LOG_ERR1 ("GLBSEM error: SetEvent GLE=0x%04x", (unsigned int) gle);
    logLastError (gle);
    }
#endif
  }

/************************************************************************/
/*                       gs_pulse_event_sem				*/
/*----------------------------------------------------------------------*/
/* Uses PulseEvent to signal the event semaphore es.			*/
/* Manual-Reset: all waiting threads are released, es state changes to	*/
/*               non-signaled.						*/
/* Auto-Reset:   first waiting thread is released and es will be reset	*/
/*               to non-signaled state even if no thread is waiting.	*/
/* Parameters:								*/
/*	es		event semaphore object				*/
/* Return values:							*/
/*	none								*/
/************************************************************************/

ST_VOID gs_pulse_event_sem (ST_EVENT_SEM es)
  {
BOOL rc;
#if defined(DEBUG_SISCO) 	
DWORD gle;
#endif

  rc = PulseEvent(es);
#if defined(DEBUG_SISCO) 	
  if (rc == FALSE)
    {
    gle = GetLastError ();
    GLBSEM_LOG_ERR1 ("GLBSEM error: PulseEvent GLE=0x%04x", (unsigned int) gle);
    logLastError (gle);
    }
#endif
  }

/************************************************************************/
/*                       gs_reset_event_sem				*/
/*----------------------------------------------------------------------*/
/* Reset event semaphore es.						*/
/* This function should be called after function gs_wait_event_sem or	*/
/* gs_wait_mult_event_sem return SD_SUCCESS and the signaled event	*/
/* semaphore is	a "manual-reset" semaphore.				*/
/* Parameters:								*/
/*	es		event semaphore object				*/
/* Return values:							*/
/*	none								*/
/************************************************************************/

ST_VOID gs_reset_event_sem (ST_EVENT_SEM es)
  {
BOOL rc;
#if defined(DEBUG_SISCO) 	
DWORD gle;
#endif

  rc = ResetEvent (es);
#if defined(DEBUG_SISCO) 	
  if (rc == FALSE)
    {
    gle = GetLastError ();
    GLBSEM_LOG_ERR1 ("GLBSEM error: ResetEvent gle=0x%04x", (unsigned int)gle);
    logLastError (gle);
    }
#endif
  }

/************************************************************************/
/*                       gs_free_event_sem				*/
/*----------------------------------------------------------------------*/
/* Release resources taken be event semaphore es.			*/
/* Parameters:								*/
/*	es		event semaphore object				*/
/* Return values:							*/
/*	none								*/
/************************************************************************/

ST_VOID gs_free_event_sem (ST_EVENT_SEM es)
  {
BOOL rc;
#if defined(DEBUG_SISCO) 	
DWORD gle;
#endif

  rc = CloseHandle (es);
#if defined(DEBUG_SISCO) 	
  if (rc == FALSE)
    {
    gle = GetLastError ();
    GLBSEM_LOG_ERR1 ("GLBSEM error: CloseHandle GLE=0x%04x", (unsigned int)gle);
    logLastError (gle);
    }
#endif
  }

	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/
	/*							*/
	/*	USER's THREAD FUNCTIONS for _WIN32		*/
	/*							*/
	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/

/************************************************************************/
/*                       gs_start_thread				*/
/*----------------------------------------------------------------------*/
/* Start a new thread. The thread handle should be closed after the	*/
/* thread terminates by calling the gs_close_thread(). The function	*/
/* gs_wait_thread can be used to wait until a thread terminates.	*/
/* Parameters:								*/
/*	threadFunc		pointer to thread function to run	*/
/*	threadArg		thread function argument list		*/
/*	threadHandleOut		pointer where to return thread handle	*/
/*	threadIdOut		pointer where to return thread ID	*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/************************************************************************/

ST_RET gs_start_thread (ST_THREAD_RET (ST_THREAD_CALL_CONV *threadFunc) (ST_THREAD_ARG),
			ST_THREAD_ARG threadArg, 
			ST_THREAD_HANDLE *threadHandleOut,
			ST_THREAD_ID *threadIdOut)
  {
ST_RET ret;
ST_THREAD_HANDLE threadHandle;
ST_THREAD_ID threadId;

  threadHandle = _beginthreadex (NULL,		/* No security 		*/
			       0,   		/* Use def stack size 	*/
			       threadFunc, 
			       threadArg,	/* Argument for thread 	*/
			       0, 		/* Creation flags, 0 for running initial state	*/
			       &threadId);	/* Thread identifier	*/

  if (threadHandle == 0)
    {
    GLBSEM_LOG_ERR1 ("GLBSEM error: gs_start_thread _beginthreadex failed errno=%d",
                     errno);
    ret = SD_FAILURE;
    }
  else
    {
    ret = SD_SUCCESS;

    if (threadHandleOut != NULL)
      *threadHandleOut = threadHandle;

    if (threadIdOut != NULL)
      *threadIdOut = threadId;

    GLBSEM_LOG_FLOW2 ("GLBSEM: gs_start_thread created thread threadHandle=0x%08lx "
                      "threadId=0x%08lx", threadHandle, threadId);
    }

  return (ret);
  }


/************************************************************************/
/*			gs_wait_thread					*/
/*----------------------------------------------------------------------*/
/* Wait until thread with threadHandle terminates or timeout occurrs.	*/
/* Parameters:								*/
/*	threadHandle	thread handle returned from gs_start_thread	*/
/*	threadId	thread ID returned from gs_start_thread		*/
/*	timeout		max time in milliseconds to wait for thread to	*/
/*			terminate.					*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/************************************************************************/

ST_RET gs_wait_thread (ST_THREAD_HANDLE threadHandle, 
		       ST_THREAD_ID threadId, ST_LONG timeout)
  {
ST_RET ret;
DWORD rc;
#if defined(DEBUG_SISCO) 	
DWORD gle;
#endif

  rc = WaitForSingleObject ((HANDLE)threadHandle, timeout);

  if (rc != WAIT_OBJECT_0)
    {
#if defined(DEBUG_SISCO) 	
    gle = GetLastError ();
#endif
    if (rc == WAIT_TIMEOUT)
      {
      ret = SD_TIMEOUT;
    /* WAIT_FAILED or WAIT_TIMEOUT */
#if defined(DEBUG_SISCO) 	
      GLBSEM_LOG_FLOW3 ("GLBSEM: Timeout=%d ms in Wait Thread threadHandle=0x%08lx, "
                        "threadId=0x%08lx", timeout, threadHandle, threadId);
#endif
      }
    else
      {
#if defined(DEBUG_SISCO) 	
      GLBSEM_LOG_ERR3 ("GLBSEM error: Wait Thread threadHandle=0x%08lx, rc=0x%04x, GLE=0x%04x", 
                       threadHandle, (unsigned int)rc, (unsigned int)gle);
      logLastError (gle);
#endif
      ret = SD_FAILURE;
      }
    }
  else
    ret = SD_SUCCESS;

  return (ret);
  }


/************************************************************************/
/*                       gs_close_thread				*/
/*----------------------------------------------------------------------*/
/* Cleanup after thread terminated.					*/
/* Parameters:								*/
/*	threadHandle		thread handle ret from gs_start_thread()*/
/* Return values:							*/
/*	SD_SUCCESS	function successful				*/
/*	SD_FAILURE	error occurred					*/
/************************************************************************/

ST_RET gs_close_thread (ST_THREAD_HANDLE threadHandle)
  {
ST_RET ret = SD_SUCCESS;
#if defined(DEBUG_SISCO) 	
DWORD gle;
#endif

  if (threadHandle)
    {
    if (CloseHandle ((HANDLE)threadHandle) == 0)
      {
#if defined(DEBUG_SISCO) 	
      gle = GetLastError ();
      GLBSEM_LOG_ERR1 ("GLBSEM error: Close Thread GLE=0x%04x", (unsigned int)gle);
#endif
      ret = SD_FAILURE;
      }
    }
  else
    {
    GLBSEM_LOG_ERR1 ("GLBSEM error: Close Thread invalid handle=0x%04x", (unsigned int)threadHandle);
    ret = SD_FAILURE;
    }
  return (ret);
  }


/************************************************************************/
/*                       gs_set_thread_name				*/
/*----------------------------------------------------------------------*/
/* Start a new thread.							*/
/* Parameters:								*/
/*	threadId		ID of Thread whose name is to be set	*/
/*				-1 if name is to be set for calling	*/
/*				thread					*/
/*	pThreadName		Name to set				*/
/************************************************************************/

#define THREADNAME_EXCEPT_ID	0x406D1388
#define THREADNAME_INFO_TYPE	0x1000

typedef struct tagTHREADNAME_INFO
  {
  ST_LONG		type;
  ST_CHAR		*pName;
  ST_THREAD_ID		threadId;
  LONG			flags;
  } THREADNAME_INFO;
  
ST_VOID gs_set_thread_name (ST_THREAD_ID threadId, ST_CHAR *pThreadName)
  {
THREADNAME_INFO info;

  info.type = THREADNAME_INFO_TYPE;
  info.pName = pThreadName;
  info.threadId = threadId;
  info.flags = 0;
  
  __try
    {
#if (_MSC_VER >= 1300)
      RaiseException (THREADNAME_EXCEPT_ID, 0, 
                      sizeof (info) / sizeof (ST_LONG), (ULONG_PTR *) &info);
#else
      RaiseException (THREADNAME_EXCEPT_ID, 0, 
                      sizeof (info) / sizeof (ST_LONG), (DWORD *) &info);
#endif
    }
  __except (EXCEPTION_CONTINUE_EXECUTION)
    {
    }
  }
  
  
	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/
	/*							*/
	/*		Misc. FUNCTIONS	for _WIN32		*/
	/*							*/
	/*---*---*---*---*---*---*---*---*---*---*---*---*---*--*/

/************************************************************************/
/* 			gs_is_win_ver					*/
/*----------------------------------------------------------------------*/
/* Accesses the OS version of the running system and checks if the	*/
/* version is ver.							*/
/* This function is compatible with Windows 95 and above.		*/
/* Parameters:								*/
/*	ST_UINT	     ver	see SD_WIN_* choices in glbsem.h	*/
/* Return:								*/
/*	1	If OS version is ver					*/
/*	0	If OS version is not ver				*/
/*	-1	If could not access OS version info or ver invalid	*/
/************************************************************************/
ST_INT	gs_is_win_ver (ST_UINT ver)
{
ST_INT        ret = 0;
OSVERSIONINFO OsVerInfo;		/* supported on Win 95 and up	*/

  /* NOTE: do not put any logging to this function. It is used in DLLs.	*/

  OsVerInfo.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
  if (GetVersionEx (&OsVerInfo) == 0)
    return (-1);

  switch (ver)
    {
    case SD_WIN_VER_95_98_Me:		/* 95, 98, Me	*/
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
        ret = 1;
    break;

    case SD_WIN_VER_NT_AND_LATER:	/* NT 3.51, NT 4.0 and above */
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT)
        ret = 1;
    break;

    case SD_WIN_VER_2K_AND_LATER:	/* 2000 and above */
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion >= 5 && OsVerInfo.dwMinorVersion >= 0)
        ret = 1;
    break;

    case SD_WIN_VER_XP_AND_LATER:	/* XP and above */
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion >= 5 && OsVerInfo.dwMinorVersion >= 1)
        ret = 1;
    break;

    case SD_WIN_VER_2003_AND_LATER:	/* 2003 and above */
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion >= 5 && OsVerInfo.dwMinorVersion >= 2)
        ret = 1;
    break;

    case SD_WIN_VER_95:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS &&
	  OsVerInfo.dwMajorVersion == 4 && OsVerInfo.dwMinorVersion == 0)
        ret = 1;
    break;

    case SD_WIN_VER_98:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS &&
	  OsVerInfo.dwMajorVersion == 4 && OsVerInfo.dwMinorVersion == 10)
        ret = 1;
    break;

    case SD_WIN_VER_Me:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS &&
	  OsVerInfo.dwMajorVersion == 4 && OsVerInfo.dwMinorVersion == 90)
        ret = 1;
    break;

    case SD_WIN_VER_NT_351:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion == 3 && OsVerInfo.dwMinorVersion == 51)
        ret = 1;
    break;

    case SD_WIN_VER_NT_40:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion == 4 && OsVerInfo.dwMinorVersion == 0)
        ret = 1;
    break;

    case SD_WIN_VER_2000:	
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion == 5 && OsVerInfo.dwMinorVersion == 0)
        ret = 1;
    break;

    case SD_WIN_VER_XP:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion == 5 && OsVerInfo.dwMinorVersion == 1)
        ret = 1;
    break;

    case SD_WIN_VER_2003:
      if (OsVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
	  OsVerInfo.dwMajorVersion == 5 && OsVerInfo.dwMinorVersion == 2)
        ret = 1;
    break;

    default:
      ret = -1;		/* invalid ver */
    }

  return (ret);	
}

/************************************************************************/
/*			logLastError					*/
/*----------------------------------------------------------------------*/
/* Parameters:								*/
/* Return values:							*/
/************************************************************************/

static ST_VOID logLastError (DWORD errCode) 
  {
LPVOID lpMsgBuf;
DWORD len;
   
  len = FormatMessage( 
          FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
          NULL,
          errCode,
          MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
          (LPTSTR) &lpMsgBuf,
          0,
          NULL);

  if(len == 0) /* FormatMessage failed... */
    return;
  
  GLBSEM_LOG_CERR1 ("  -> %s", lpMsgBuf);

  // Free the buffer.
  LocalFree( lpMsgBuf );
  } 
