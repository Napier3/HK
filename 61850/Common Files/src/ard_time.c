/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	  1986 - 2002, All Rights Reserved.		        */
/*									*/
/*		    PROPRIETARY AND CONFIDENTIAL			*/
/*									*/
/* MODULE NAME : ard_time.c 						*/
/* PRODUCT(S)  : ASN1DE 						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 07/26/02  EJV     05    Added code to skip fraction of a second.	*/
/* 12/20/01  JRB     04    Chg ASN1_CTXT to ASN1_DEC_CTXT.		*/
/* 11/19/01  EJV     03    Made asn1dec_figureDelta func static		*/
/* 09/13/99  MDE     02    Added SD_CONST modifiers			*/
/* 07/26/99  MDE     01    New module, derived from ad_time.c		*/
/************************************************************************/

#include "glbtypes.h"
#include "sysincs.h"
#include "asn1r.h"
#include "asn1log.h"

/************************************************************************/
/* For debug version, use a static pointer to avoid duplication of 	*/
/* __FILE__ strings.							*/

#ifdef DEBUG_SISCO
SD_CONST static ST_CHAR *SD_CONST thisFileName = __FILE__;
#endif

/* Local global's to hold differential between local and GMT time	*/
static time_t gmtLocalAdjustmentTime = 0;
static ST_BOOLEAN adjustmentCalculated = 0;
static time_t asn1dec_figureDelta(struct tm local, struct tm gmt);

/************************************************************************/
/*			asn1dec_figureDelta				*/
/************************************************************************/
static time_t asn1dec_figureDelta(struct tm local, struct tm gmt)
  {
ST_INT deltaDay;
ST_INT deltaHour;
ST_INT deltaMin;
ST_INT deltaSec;
time_t returnDelta;

  deltaDay = gmt.tm_yday - local.tm_yday;
  deltaHour = gmt.tm_hour - local.tm_hour;
  deltaMin = gmt.tm_min - local.tm_min;
  deltaSec = gmt.tm_sec - local.tm_sec;

  /* if this is the time when the year is changing */
  if (local.tm_year != gmt.tm_year)
    if (gmt.tm_yday != local.tm_yday)
      deltaDay = 1;

  /* calculate the return Value */
  returnDelta = (time_t) 0;
  returnDelta += (time_t)(deltaSec);
  returnDelta += (time_t)(deltaMin  * (time_t) 60);
  returnDelta += (time_t)(deltaHour * (time_t) 60 * (time_t) 60);
  returnDelta += (time_t)(deltaDay  * (time_t) 60 * (time_t) 60 * (time_t) 24);

  ALOG_DEC0("Calculate the NON DST GMT - local offset ");

  ALOG_CDEC1("Delta Seconds GMT - Local %d",deltaSec);
  ALOG_CDEC1("Delta Minutes GMT - Local %d",deltaMin);
  ALOG_CDEC1("Delta Hour    GMT - Local %d",deltaHour);
  ALOG_CDEC1("Delta Day     GMT - Local %d",deltaDay);
  ALOG_CDEC1("Difference in seconds from here to GMT %ld",returnDelta);

  return (returnDelta);
  }

/************************************************************************/
/*			      get_time					*/
/*  Function to decode Generalized Time into MS-DOS time (= number of	*/
/*  seconds since 00:00 Jan 1, 1970, GMT).				*/
/************************************************************************/

ST_RET asn1r_get_time (ASN1_DEC_CTXT *ac, time_t *decTimeTValue)
  {
struct tm *tmStructPtr;
struct tm localTime;
struct tm gmtTime;
struct tm breakDown;
struct tm gStruTime;
ST_UCHAR *last_pos;
ST_CHAR time_comp[6];
ST_BOOLEAN adjustmetPos;
ST_INT  adjust;
time_t resultantTimeT;

  /* check to see if the pointer for returning is valid */
  if (!decTimeTValue)
    {
    ALOG_ERR0 ("Required pointer passed to function is NULL, expecting non NULL time_t pointer");
    return(SD_FAILURE);
    }

  ALOG_DEC0("Decode ASN1 generalized time string ");
  last_pos = ac->asn1r_field_ptr + ac->asn1r_elmnt_len;	/* 1 + last pos'n in data el't  */

  /* Determine the Adjustment Factor for Local to GMT */
  if (adjustmentCalculated == 0)
    {
    adjustmentCalculated = 1;

    /* Ok now set the time to the 1984 EPOCHE, it work's for all time's */
    /* it does not have DST so it returns a non DST differential */
    gmtLocalAdjustmentTime = 441763200;

    tmStructPtr = gmtime(&gmtLocalAdjustmentTime);
    memcpy(&gmtTime,tmStructPtr,sizeof (struct tm));

    tmStructPtr = localtime(&gmtLocalAdjustmentTime);
    memcpy(&localTime,tmStructPtr,sizeof (struct tm));

    gmtLocalAdjustmentTime = asn1dec_figureDelta(localTime,gmtTime);
    }

  /* Determine the Year in this generalized time string */
  time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[2] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[3] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[4] = 0;
  /* Convert the year to a integer string */
  breakDown.tm_year = (ST_INT16) atoi(time_comp);
  breakDown.tm_year = breakDown.tm_year - 1900;

  /* Determine the month in this generalized time string */
  time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[2] = 0;
  /* Convert the month to a integer string */
  breakDown.tm_mon = (ST_INT16) atoi(time_comp);
  breakDown.tm_mon = breakDown.tm_mon - 1;

  /* Determine the day of the month in this generalized time string */
  time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[2] = 0;
  /* Convert the day of the month to a integer string */
  breakDown.tm_mday = (ST_INT16) atoi(time_comp);

  /* Determine the hour in this generalized time string */
  time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[2] = 0;
  /* Convert the hour to a integer string */
  breakDown.tm_hour = (ST_INT16) atoi(time_comp);

  /* Determine the min in this generalized time string */
  time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[2] = 0;
  /* Convert the min to a integer string */
  breakDown.tm_min = (ST_INT16) atoi(time_comp);

  /* Determine the sec in this generalized time string */
  time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
  time_comp[2] = 0;
  /* Convert the sec to a integer string */
  breakDown.tm_sec = (ST_INT16) atoi(time_comp);

  /* Check to see if we have overrun */
  if (ac->asn1r_field_ptr > last_pos)
    return(SD_FAILURE);

  /* Broken Down Time component's */

  ALOG_CDEC0(" Broken Down Component's so far");
  ALOG_CDEC1(" tm_sec      %d",breakDown.tm_sec);
  ALOG_CDEC1(" tm_min      %d",breakDown.tm_min);
  ALOG_CDEC1(" tm_hour     %d",breakDown.tm_hour);
  ALOG_CDEC1(" tm_mon      %d",breakDown.tm_mon);
  ALOG_CDEC1(" tm_year     %d",breakDown.tm_year);
  ALOG_CDEC1(" tm_mday     %d",breakDown.tm_mday);

  /* There maybe be a fraction of a second in the generalized time.	*/
  /* Ignore the fraction value since we can not pass it currently up.	*/
  if (*ac->asn1r_field_ptr == '.')
    {
    ac->asn1r_field_ptr++;
    /* skip all digits after the period */
    while (isdigit((ST_INT)(*ac->asn1r_field_ptr)) && ac->asn1r_field_ptr <= last_pos)
      ac->asn1r_field_ptr++;
    }

  /* Actually break down the date and time as a local time*/
  if (ac->asn1r_field_ptr == last_pos)
    {
    /* Place the known data into the fields */
    gStruTime.tm_sec  = breakDown.tm_sec;
    gStruTime.tm_min  = breakDown.tm_min;
    gStruTime.tm_hour = breakDown.tm_hour;
    gStruTime.tm_mon  = breakDown.tm_mon;
    gStruTime.tm_year = breakDown.tm_year;
    gStruTime.tm_mday = breakDown.tm_mday;

    gStruTime.tm_yday = 0;
    gStruTime.tm_wday = 0;
    gStruTime.tm_isdst = 0;

    /* Ask for a make time */
    resultantTimeT = mktime(&gStruTime);

    if (resultantTimeT == (time_t)-1)
      {
      ALOG_ERR0 ("mktime function returned -1 for time");
      return(SD_FAILURE);
      }

    ALOG_CDEC1("Local time Decode : First Pass %ld ",resultantTimeT);

    /* if the DST flag came up set, re run it with the DST flag */
    if (gStruTime.tm_isdst == 1)
      {
      gStruTime.tm_sec  = breakDown.tm_sec;
      gStruTime.tm_min  = breakDown.tm_min;
      gStruTime.tm_hour = breakDown.tm_hour;
      gStruTime.tm_mon  = breakDown.tm_mon;
      gStruTime.tm_year = breakDown.tm_year;
      gStruTime.tm_mday = breakDown.tm_mday;

      gStruTime.tm_yday = 0;
      gStruTime.tm_wday = 0;
      gStruTime.tm_isdst = 1;

      resultantTimeT = mktime(&gStruTime);

      if (resultantTimeT == (time_t)-1)
        {
        ALOG_ERR0 ("mktime function returned -1 for time");
        return(SD_FAILURE);
        }

      ALOG_CDEC1("Local time Decode : Second Pass %ld ",resultantTimeT);
      }

    ALOG_CDEC1("Local time Decode : Result %ld ",resultantTimeT);

    /* Now factor the Difference between GMT and local */
    *decTimeTValue = resultantTimeT;

    return (SD_SUCCESS);
    }

  /* Actually break down the date and time as a GMT based time with possible offset */
  if ((*ac->asn1r_field_ptr == 'Z')||(*ac->asn1r_field_ptr == '+')||(*ac->asn1r_field_ptr == '-'))       
    {
    /* Place the known data into the fields */
    gStruTime.tm_sec  = breakDown.tm_sec;
    gStruTime.tm_min  = breakDown.tm_min;
    gStruTime.tm_hour = breakDown.tm_hour;
    gStruTime.tm_mon  = breakDown.tm_mon;
    gStruTime.tm_year = breakDown.tm_year;
    gStruTime.tm_mday = breakDown.tm_mday;

    gStruTime.tm_yday = 0;
    gStruTime.tm_wday = 0;
    gStruTime.tm_isdst = 0;

    /* Ask for a make time */
    resultantTimeT = mktime(&gStruTime);

    if (resultantTimeT == (time_t)-1)
      {
      ALOG_ERR0 ("mktime function returned -1 for time");
      return(SD_FAILURE);
      }

    ALOG_CDEC1("GMT time Decode : First Pass %ld ",resultantTimeT);

    /* if the DST flag came up set, re run it with the DST flag */
    if (gStruTime.tm_isdst == 1)
      {
      gStruTime.tm_sec  = breakDown.tm_sec;
      gStruTime.tm_min  = breakDown.tm_min;
      gStruTime.tm_hour = breakDown.tm_hour;
      gStruTime.tm_mon  = breakDown.tm_mon;
      gStruTime.tm_year = breakDown.tm_year;
      gStruTime.tm_mday = breakDown.tm_mday;

      gStruTime.tm_yday = 0;
      gStruTime.tm_wday = 0;
      gStruTime.tm_isdst = 1;

      resultantTimeT = mktime(&gStruTime);

      if (resultantTimeT == (time_t)-1)
        {
        ALOG_ERR0 ("mktime function returned -1 for time");
        return(SD_FAILURE);
        }

      ALOG_CDEC1("GMT time Decode : Second Pass %ld ",resultantTimeT);
      }

    ALOG_CDEC1("GMT time Decode : Adjustment value to be Subtracted (- %ld) ",gmtLocalAdjustmentTime);

    /* now if DST is in effect for the decoded time, then reduce in magnitude the  */
    /* DST offset								   */
    if ((gStruTime.tm_isdst == 1))
      {
      if (gmtLocalAdjustmentTime > 0)
        {
        ALOG_CDEC0("Decrease GMT adjust in magnitude 1 hr (+1) ");
        resultantTimeT = resultantTimeT - gmtLocalAdjustmentTime + (60 * 60);
        }
      else
        {
        ALOG_CDEC0("Increase GMT adjust in magnitude 1 hr (-1) ");
        resultantTimeT = resultantTimeT - gmtLocalAdjustmentTime - (60 * 60);
        }
      }
    else
      {
      resultantTimeT = resultantTimeT - gmtLocalAdjustmentTime;
      }  

    ALOG_CDEC1("GMT time Decode : Result %ld ",resultantTimeT);

    /* Now factor the Difference between GMT and local */
    *decTimeTValue = resultantTimeT;

    /* now if there are adjustment's to GMT */
    if ((*ac->asn1r_field_ptr == '+')||(*ac->asn1r_field_ptr == '-'))
      {
      if (*ac->asn1r_field_ptr == '+')
        {
        ALOG_CDEC0("Doing a GMT based adjustment of (+) ");
        adjustmetPos = SD_TRUE;
	}
      else
        {
        ALOG_CDEC0("Doing a GMT based adjustment of (-) ");
        adjustmetPos = SD_FALSE;
	}
        
      ac->asn1r_field_ptr++;
      time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
      time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
      time_comp[2] = 0;
      adjust = atoi(time_comp);

      ALOG_CDEC1("Adjust by Hours %d ",adjust);

      if (adjustmetPos == SD_TRUE)
        *decTimeTValue += (time_t) (adjust*(60 * 60));  /* adjust hrs */
      else
        *decTimeTValue -= (time_t) (adjust*(60 * 60));  /* adjust hrs */

      time_comp[0] = (ST_CHAR)*ac->asn1r_field_ptr++;
      time_comp[1] = (ST_CHAR)*ac->asn1r_field_ptr++;
      time_comp[2] = 0;
      adjust = atoi(time_comp);

      ALOG_CDEC1("Adjust by Minutes %d ",adjust);

      if (adjustmetPos == SD_TRUE)
        *decTimeTValue += (time_t) (adjust*(60));  /* adjust min */
      else
        *decTimeTValue -= (time_t) (adjust*(60));  /* adjust min */

      ALOG_CDEC1("GMT time Decode with offset : Result %ld ",*decTimeTValue);
	
      return (SD_SUCCESS);
      }
    else
      {
      ac->asn1r_field_ptr++;		/* Skip the 'Z' */
      return (SD_SUCCESS);
      }
    }  /* end of GMT based Time */
    
  /* if the string to decode does not end in nothing, "Z", "+", "-" */
  /* then return failure and dump the string */
    
  ALOG_ERR0 ("Time string cannot be decoded by this ASN1 function");
  return(SD_FAILURE);
  }


