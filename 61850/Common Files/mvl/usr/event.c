/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*	(c) Copyright Systems Integration Specialists Company, Inc.,		*/
/*	1998 All Rights Reserved											*/
/*																		*/
/* MODULE NAME : event.c												*/
/* PRODUCT(S)  : MMSEASE-LITE											*/
/*																		*/
/* MODULE DESCRIPTION :													*/
/*	Event handling functions.											*/
/*																		*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :							*/
/*	wait_any_event ()													*/
/*																		*/
/* MODIFICATION LOG :													*/
/*  Date     Who   Rev     Comments										*/
/* --------  ---  ------   -------------------------------------------  */
/* 07/07/04  JRB    07     Del #ifdef MOSI. May need a_get_event_handles*/
/*			   added to stack lib if non-MOSI stack used.				*/
/* 10/23/03  JRB    06     Call a_get_event_handles_unix for default system.*/
/* 05/17/02  JRB    05     Put back old code for PHARLAP_ETS, PharLap	*/
/* 			   doesn't have "Wait..Ex".									*/
/* 04/10/00  JRB    04     Del "select.h". See "sysincs.h".				*/
/* 04/06/00  JRB    03     Use WaitForMultipleObjectsEx for WIN32:		*/
/*			   CRITICAL for ethernet driver interface.					*/
/* 08/05/99  JRB    02     Use a_get_ev.., gs_wait.. for WIN32.			*/
/*			   Use hTcpEvent for OS2.									*/
/* 11/10/98  JRB    01     Created										*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "mmsdefs.h"

#include <assert.h>

#if defined (_WIN32)
/************************************************************************/
/*                          wait_any_event								*/
/************************************************************************/

ST_VOID wait_any_event (ST_LONG max_ms_delay)
{
	WaitForSingleObjectEx(hTcpEvent,
				 max_ms_delay,
				 TRUE);
	/* Something woke us up. Don't care if it was event or timeout.	*/
	/* Just return to main loop to attempt processing. */
	return;
}

#else	/* All other systems */

/************************************************************************/
/*                          wait_any_event								*/
/************************************************************************/
ST_VOID wait_any_event (ST_LONG max_ms_delay)
{
	struct timeval stTimeVal;
	fd_set readfds;
	fd_set writefds;
	fd_set exceptfds;
	int    nfds=0;   
	int *fd_array;	/* ptr to array of handles on which to wait	*/
	int num_entries;	/* num of entries in fd_array.			*/
	int j;		/* loop index */

	FD_ZERO (&readfds);
	FD_ZERO (&writefds);
	FD_ZERO (&exceptfds);
	FD_SET (0, &readfds);		/* select on "stdin"	*/

	/* Ask ACSE for array of handles on which to wait.	*/
	fd_array = a_get_event_handles_unix (&num_entries);

	for (j = 0; j < num_entries; j++)
	{
		FD_SET (fd_array[j], &readfds);
		nfds = max (nfds,fd_array[j]);
	}
	nfds++;	/* must be 1 greater than max handle. */

	/* If you want to wait for other events too, add more FD_SET calls,	*/
	/* and recompute "nfds" (or just set it to FD_SETSIZE).	 */

	max_ms_delay *= 1000; /*** Convert to micro seconds ***/
	stTimeVal.tv_sec  = max_ms_delay / 1000000;
	stTimeVal.tv_usec = max_ms_delay % 1000000;

	nfds = select (nfds, &readfds, &writefds, &exceptfds, &stTimeVal);
}

#endif		/* All other systems */

