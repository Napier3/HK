/*************************************************************************/
/*File Name:  cli_rpt_dec.c		 */
/*writer:     lijin
/*Describe:   Decode the report data			 */
/*************************************************************************/
#include "glbtypes.h"
#include "sysincs.h"
#include "mvl_acse.h"
#include "mvl_log.h"
#include "mvl_uca.h"	/* only need OPTFLD_* defines	*/
#include "client.h"
#include "RptDeCode.h"
#include "math.h"

ST_UCHAR ReasonCode[MAX_DSMEMBER];

/* My Printf */
// ST_VOID myprintf(char* fmt, ...)
// {
// 	va_list ap; /* points to each unnamed arg in turn */
// 	ST_CHAR *p,*sval;
// 	ST_INT  ival;
// 	ST_DOUBLE dval;
// 	return;
// 	va_start(ap, fmt); /* make ap point to lst unnamed arg */
// 	for( p=fmt; *p; p++ ){
// 		if( *p != '%' ){
// 			putchar(*p);
// 			continue;
// 		}
// 		switch(*++p){
// 		case 'd':
// 			ival = va_arg(ap,int);
// 			log_printf("%d",ival);
// 			break;
// 		case 'f':
// 			dval = va_arg(ap,double);
// 			log_printf("%f",dval);
// 			break;
// 		case 's':
// 			for(sval=va_arg(ap,char*); *sval; sval++)
// 				putchar(*sval);
// 			break;
// 		default:
// 			putchar(*p);
// 			break;
// 		}
// 	}
// 	va_end(ap); /* clean up when done */
// }

/*************************************************************************/
/*Function Name:  IsEvent( ST_CHAR *lpmmsVarName )						 */
/*Function description:	Is SOE/RelaySOE or not							 */
/*Input Parameter:*lpmmsVarName:point to the mmsVarName					 */
/*************************************************************************/
ST_INT IsEvent( ST_CHAR *lpmmsVarName )
{
	if( strstr( lpmmsVarName, "stVal" ) != NULL )
		return 2;
	if( strstr( lpmmsVarName, "general") != NULL )
		return 3;
	else
		return -1;
}

/*************************************************************************************/
/*Function Name:  DifEventFromVar( ST_INT DSIndex, ST_INT nACSI )					 */
/*Function description:	Different Event ( SOE or RelaySOE ) form variable (YC、YX)	 */
/*Input Parameter:DSIndex: the Index of DataSet										 */
/*				  NumDSMember: the number of DataSet Member							 */
/*************************************************************************************/
ST_INT	DifEventFromVar( ST_INT DSIndex, ST_INT NumDSMember )
{
	ST_INT  i,j,EventIdx=0, EnventNo=1;
	ST_INT  IsEventReport=0;

	if( struDSAppLink[DSIndex].MemberNum < NumDSMember )
		return -1;
	if( struDSAppLink[DSIndex].MemberNum == NumDSMember ){
		struDSAppLink[DSIndex].EventNum = 0;
		for( i=0; i<struDSAppLink[DSIndex].MemberNum; i++ )
			struDSAppLink[DSIndex].ApplyType[i] = 1;
		return 0;
	}

	for(i=0; i<struDSAppLink[DSIndex].MemberNum; i++)
		struDSAppLink[DSIndex].ApplyType[i] = -1;

	for(i=0; i<struDSAppLink[DSIndex].MemberNum; i++)
	{
		if( strcmp(struDSAppLink[DSIndex].DataType[i], "STRUCT") != 0 ){
			if( struDSAppLink[DSIndex].ApplyType[i] == -1 )
				struDSAppLink[DSIndex].ApplyType[i] = 1;
			continue;
		}
		EnventNo = 1;
		for( j=0; j<struDSAppLink[DSIndex].MemberNum; j++)
		{
			if( (i!=j) && (struDSAppLink[DSIndex].Level[i][0]==struDSAppLink[DSIndex].Level[j][0]) )
			{
				IsEventReport = IsEvent( struDSAppLink[DSIndex].mmsVARName[j] );
				if( IsEventReport > 0 )
				{
					struDSAppLink[DSIndex].EventIndx[EventIdx][0] = i+1;  /* LIJIN ADD +1 */
					struDSAppLink[DSIndex].ApplyType[i] = IsEventReport;
					struDSAppLink[DSIndex].ApplyType[j] = 0;
					struDSAppLink[DSIndex].EventIndx[EventIdx][EnventNo++] = j+1; /* LIJIN ADD +1 */
					struDSAppLink[DSIndex].EventNum += 1;
				}
				if( (IsEventReport<0) && (EnventNo>1) )
				{
					if( strstr(struDSAppLink[DSIndex].mmsVARName[j],struDSAppLink[DSIndex].mmsVARName[i]) != NULL ){
						struDSAppLink[DSIndex].ApplyType[j] = 0;
						struDSAppLink[DSIndex].EventIndx[EventIdx][EnventNo++] = j+1; /* LIJIN ADD +1 */
					}
				}
			}
		}
		EventIdx += 1;
	}
	return struDSAppLink[DSIndex].EventNum;
}

ST_INT DifEventFromVar_Ex(tagDA *pDA, ST_INT *daindex, ST_INT numVar, ST_INT nDANum)
{
	ST_INT  i;
	ST_INT  IsEventReport=0;
	ST_INT  nEventNum = 0;

	if (daindex == NULL)
		return -1;

	if (nDANum < numVar)
		return -1;

	if (numVar == nDANum)
	{
		for (i=0; i<numVar; i++ )
			pDA[i].ApplyType = 1;
		
		return 0;
	}

	for (i=0; i<nDANum; i++)
	{
		pDA[i].ApplyType = -1;

		if (daindex[i] == 1)
		{
			//if (strstr(pDA[i].DataType, "STRUCT") != 0)
			if (strcmp(pDA[i].DataType, "STRUCT") == 0)
			{
				if (pDA[i].ApplyType == -1)
					pDA[i].ApplyType = 1;

				continue;
			}	

#ifdef _use_mms_string
			IsEventReport = IsEvent(mms_string(&pDA[i].DAValue.mmsName) );
#else
			IsEventReport = IsEvent(pDA[i].DAValue.mmsName);
#endif
			if (IsEventReport > 0)
			{
				pDA[i].ApplyType = IsEventReport;
				nEventNum++;
			}

			if (IsEventReport < 0)
			{
				pDA[i].ApplyType = 0;
			}
		}
	}

	return nEventNum;
}

/*********************************************************************************************/
/*Function Name:  DecodeReasonCode()														 */
/*Input Parameter:*IncluData:point to the Report Inclusion									 */
/*				  DSVarNum:the number of total DS member									 */
/*				  ReasonData:the point to the  ReasonCode data to be decoded				 */
/*********************************************************************************************/
ST_INT DecodeReasonCode(ST_INT *daindex, ST_INT DSVarNum, ST_UCHAR **lpReasonData, ST_INT RptNum)
{
	ST_INT i=0,j=0,sign=0,startidx=0;
	tagasn1r_head	ASN1_head_temp;
	ST_INT asn1r_bitcount=0;
	ST_INT accepted_bits;
	ST_INT Length=0,Unused_bits=0;
	ST_INT Max_Bits=10;
	ST_UCHAR	*offsetBak;

	if( lpReasonData == NULL ){
		//myprintf("RptData attemp to points to NULL!\n");
		return -1;
	}
	if( DSVarNum == 0 ){
		//myprintf("DSVarNum=0 Break !\n");
		return -1;
	}

	/* search the position of each DataSet member */
	offsetBak = *lpReasonData;
// 	for(j=0; j<DSVarNum; j++)
// 	{
// 		if( BSTR_BIT_GET (IncluData, j) )
// 		{
// 			if( dec_asn1_head( lpReasonData, (tagasn1r_head*)&ASN1_head_temp ) <= 0 )
// 			{
// 				//myprintf("dec_asn1_head return value <= 0\n");
// 				return -1;
// 			}
// 			*lpReasonData += ASN1_head_temp.asn1r_elmnt_len;
// 			memset( &ASN1_head_temp, 0, sizeof(tagasn1r_head) );
// 		}
// 		else
// 		{
// 			i = 0;
// 		}
// 	}
	//跳过数据定义
	for(j=0; j<RptNum; j++)
	{
		if( dec_asn1_head( lpReasonData, (tagasn1r_head*)&ASN1_head_temp ) <= 0 )
		{
			//myprintf("dec_asn1_head return value <= 0\n");
			return -1;
		}
		*lpReasonData += ASN1_head_temp.asn1r_elmnt_len;
		memset( &ASN1_head_temp, 0, sizeof(tagasn1r_head) );
	}

	memset( &ASN1_head_temp, 0, sizeof(tagasn1r_head) );
	memset(ReasonCode, 0, MAX_DSMEMBER);

	for(i=0; i<DSVarNum; i++)
	{
		//if( BSTR_BIT_GET (IncluData, i) )
		if (daindex[i] > 0)
		{
			if(sign == 0)
			{
				startidx = i;
				sign += 1;
			}

			memset( &ASN1_head_temp, 0, sizeof(tagasn1r_head) );

			if( dec_asn1_head( lpReasonData, (tagasn1r_head*)&ASN1_head_temp ) > 0 )
			{
				Length = ASN1_head_temp.asn1r_elmnt_len;

				if (Length > 0)
				{
					if( ASN1_head_temp.asn1r_element_id == 0x04 )
					{
						Unused_bits = (**lpReasonData);
						*lpReasonData += 1;
						if (Unused_bits>7 || Unused_bits<0)
							return -1;
						if ( Length == 1 && Unused_bits != 0 )
							return -1;
						else
						{
							asn1r_bitcount = ((Length-1)*8 - Unused_bits);
							if (Max_Bits != 0  &&  asn1r_bitcount > Max_Bits)
								accepted_bits = Max_Bits;
							else
								accepted_bits = asn1r_bitcount;
							bstrcpy (&ReasonCode[i], *lpReasonData, accepted_bits);
							*lpReasonData += (Length - 1);
						}
					}
				}
			
			}
			else
			{
				break;
			}
		}
		else
		{
			j = 0;	
		}
	}

	*lpReasonData = offsetBak;

	return	startidx;
}

/***********************************************************************************/
/*Function Name:		dec_asn1_head( ST_CHAR *RptData, tagasn1r_head* asn1_head )
/*Function Description:	decode data head
/*Input Parameters:		RptData: Point to the report data to be decoded
/***********************************************************************************/
ST_INT dec_asn1_head( ST_CHAR **lpRptData_temp, tagasn1r_head* asn1_head_point )
{
	ST_UCHAR c;
	ST_UINT  offset=0;
	ST_UINT16 ui16;
	ST_INT i, i2, i3;
	tagasn1r_head	*ASN1_head_temp;

	ASN1_head_temp = (tagasn1r_head*)asn1_head_point;
	if( ( *lpRptData_temp == NULL ) || ( lpRptData_temp == NULL ) )
	{
		//myprintf("dec_asn1_head: lpRptData points to NULL!\n");
		return -1;
	}
	c = **lpRptData_temp;	/* read the first byte of the element	*/
	*lpRptData_temp += 1;
	offset += 1;
	/* pointer points to next byte，but must not be the Length, may be TagValue remain */
	ASN1_head_temp->asn1r_constr_element = (ST_UCHAR) (c & CONSTR);	/* isolate the constr bit */
	/* CONSTR = 0x20, so ( c&CONSTR ) get Primitive or Constructed flag */
	ASN1_head_temp->asn1r_element_class = (ST_UCHAR) (c & 0xC0);		/* get the class bits */
	/* (c&0xC0) get Type of Tag */
	if ((c &= 0x1F) == 0x1F)			/* if ID extender - ,c &= 0x1F get Tag Value */
	{
		if ( (c = ( **lpRptData_temp ) ) & 0x80 )	/* if next byte is not last -	*/
		/*(c = *(ac->asn1r_field_ptr++)) & 0x80 determine whether this byte belongs to TagValue or not */
		{
			*lpRptData_temp += 1;
			if (**lpRptData_temp & 0x80)	/* if more than two extention	*/
			{				/* ID octets, reject		*/
				offset = -1;
				//myprintf ("ASN.1 decode: element id too long\n");
				return offset;
			}
			offset += 1;
			ui16 = (ST_UINT16) (c & 0x7F) << 7;		/* support 2 extention bytes */
			ui16 |= (**lpRptData_temp) & 0x7F;		/* merge the 14 ID bits (only*/
			*lpRptData_temp += 1;
			ASN1_head_temp->asn1r_element_id = ui16;		/* 13 usable in this impl'n).*/
		}
		else	/* one octet extended */
		{
			*lpRptData_temp += 1;
			offset += 1;
			ASN1_head_temp->asn1r_element_id = (ST_UINT16) c;	/* write masked ID code 	*/
		}
	}
	else		/* not extended ID code	*/
		ASN1_head_temp->asn1r_element_id = (ST_UINT16) c;	/* write masked ID code 	*/

	/* RptData points to contents length field start.			*/
	/* Support all length forms : short, long, and indefinite.		*/
	if ( ( c = ( **lpRptData_temp) ) & 0x80  )	/* check for long,indef forms	*/
	{
		*lpRptData_temp += 1;
		offset += 1;
		if (c &= 0x7F)			/* if long form  */
		{
			switch (c)			/* switch on # bytes in length	*/
			{
				case 1 :			/* one byte length	*/
					ASN1_head_temp->asn1r_elmnt_len = ( **lpRptData_temp ) & 0xFF;
					*lpRptData_temp += 1;
					offset += 1;
					break;
				case 2 :			/* two byte length	*/
					i =  (ST_INT) ((ST_UINT)(**lpRptData_temp) << 8);
					*lpRptData_temp += 1;
					ASN1_head_temp->asn1r_elmnt_len = (ST_INT)(((ST_UINT)(**lpRptData_temp) & 0xFF) | i);
					*lpRptData_temp += 1;
					offset += 2;
					break;
				case 3 :	 		/* three byte length */
					i =  (ST_INT) ((ST_UINT) (**lpRptData_temp) << 16);
					*lpRptData_temp += 1;
					#if (INT_MAX <= 0x7FFF)
						if (i != 0)
						{
							//myprintf ("ASN.1 decode: element length too long\n");
						}
					#endif
					i2 =  (ST_INT) (((ST_UINT) (**lpRptData_temp) << 8) | i);
					*lpRptData_temp += 1;
					ASN1_head_temp->asn1r_elmnt_len = (ST_INT)(((ST_UINT)(**lpRptData_temp)
																		  & 0xFF) | i2);
					*lpRptData_temp += 1;
					offset += 3;
					break;
				case 4 :	 		/* four byte length	*/
					i =  (ST_INT) ((ST_UINT)(**lpRptData_temp) << 24);
					*lpRptData_temp += 1;
					i2 =  (ST_INT) (((ST_UINT)(**lpRptData_temp) << 16) | i);
					*lpRptData_temp += 1;
					#if (INT_MAX <= 0x7FFF)
						if (i != 0 || i2 != 0)
						{
							//myprintf ("ASN.1 decode: element length too long\n");
						}
					#endif
					i3 =  (ST_INT) (((ST_UINT)(**lpRptData_temp) << 8) | i2);
					*lpRptData_temp += 1;
					ASN1_head_temp->asn1r_elmnt_len = (ST_INT)(((ST_UINT)(**lpRptData_temp) & 0xFF) | i3);
					*lpRptData_temp += 1;
					offset += 4;
					break;
				default :
					ASN1_head_temp->asn1r_elmnt_len = 0;
					offset = -1;
					//myprintf ("dec_asn1_head: ASN.1 decode: length > 4\n");
					break;
			}
		}
		else	/* indefinite length */
		{
			if (ASN1_head_temp->asn1r_constr_element) 		/* valid only for constructors	*/
				ASN1_head_temp->asn1r_indef_flag = SD_TRUE;	/* set 'indefinite len' flag    */
			else
			{
				//myprintf ("ASN.1 decode: indefinite length primitive\n");
			}
		}
	}
	else		/* short form length */
	{
		offset += 1;
		*lpRptData_temp += 1;
		ASN1_head_temp->asn1r_elmnt_len = c;	/* write length  */
	}
	return offset;
}			/* data element decode complete */

/*****************************************************************************/
/*Function Name: 		asn1r_dec_bool( )									 */
/*Function Description:	Decode a asn.1 decoded Boolean						 */
/*****************************************************************************/
// ST_INT asn1r_dec_bool (ST_CHAR **lpRptData_temp, ST_INT Length,
// 					   tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx)
// {
// 	ST_INT ACSI_DAIdx=-1;
// 	if (Length != 1)
// 	{
// 		myprintf ("ASN.1 decode: Boolean length is not equal to 1\n");
// 		return (SD_FAILURE);
// 	}
// 	ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
// 	pACSINode[ACSIIdx].DA[ACSI_DAIdx].Value.u= (ST_BOOLEAN)(**lpRptData_temp);
// 	*lpRptData_temp += 1;
// 	return (ACSI_DAIdx);
// }

ST_VOID asn1r_dec_bool_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA)
{
	if (Length != 1)
	{
		//myprintf ("ASN.1 decode: Boolean length is not equal to 1\n");
		return;
	}

	if (pDA == NULL)
		return;

	pDA->DAValue.Value.u= (ST_BOOLEAN)(**lpRptData_temp);

	if (pDA->DAValue.Value.u != 0)
	{
		pDA->DAValue.Value.u  = 1;
	}

	*lpRptData_temp += 1;
}

/********************************************************************************/
/*Function Name: 		asn1r_dec_integer( )									*/
/*Function Description:	Decode a asn.1 decoded Integer							*/
/********************************************************************************/
// ST_INT asn1r_dec_integer (ST_CHAR **lpRptData_temp, ST_INT Length,
// 						  tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx)
// {
// 	ST_INT ACSI_DAIdx=-1;
// 	ST_INT32 nvalue;
// 	ST_INT32 oVal;
// 	ST_INT32 negMask;
// 	ST_BOOLEAN positive;
// 	ST_INT i;
// 
// 	/* Check to see if the ASN.1 data value is positive or negative	*/
// 	if (**lpRptData_temp & 0x80)
// 		positive = SD_FALSE;
// 	else
// 		positive = SD_TRUE;
// 
// 	/* Large unsigned value's may be 5 bytes, with a leading 0. If so,	*/
// 	/* we will strip it here.						*/
// 	i = Length;
// 	if (i >= 5)			/* Large positive number, skip leading 0 */
// 	{
// 		if (**lpRptData_temp != 0 || positive == SD_FALSE)
// 		{
// 			myprintf ("ASN.1 decode: invalid 5 byte (or larger) integer");
// 			return (SD_FAILURE);
// 		}
// 		*lpRptData_temp += 1;
// 		--i;
// 	}
// 
// 	/* Go ahead and read the value into A 4 byte integer, shifting as we go	*/
// 	nvalue = 0;
// 	while (SD_TRUE)
// 	{
// 		oVal = (ST_INT32)(**lpRptData_temp);
// 		*lpRptData_temp += 1;
// 		oVal &= 0xFF;
// 		nvalue |= oVal;
// 		if (--i == 0)		break;
// 		/* More bytes of data, need to make room for next one */
// 		nvalue = (nvalue << 8) & 0xffffff00;
// 	}
// 
// 	/* We may need to sign extend if negative */
// 	if (!positive && Length < 4)
// 	{
// 		negMask = 0xff000000L;
// 		i = 4 - Length;
// 		while (i-- > 0)
// 		{
// 			nvalue |= negMask;
// 			negMask = negMask >> 8;
// 		}
// 	}
// 	ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
// 	pACSINode[ACSIIdx].DA[ACSI_DAIdx].Value.i= nvalue;
// 
// 	return (ACSI_DAIdx);
// }

ST_VOID asn1r_dec_integer_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA)
{
	ST_INT32 nvalue;
	ST_INT32 oVal;
	ST_INT32 negMask;
	ST_BOOLEAN positive;
	ST_INT i;

	if (pDA == NULL)
		return;

	/* Check to see if the ASN.1 data value is positive or negative	*/
	if (**lpRptData_temp & 0x80)
		positive = SD_FALSE;
	else
		positive = SD_TRUE;

	/* Large unsigned value's may be 5 bytes, with a leading 0. If so,	*/
	/* we will strip it here.						*/
	i = Length;
	if (i >= 5)			/* Large positive number, skip leading 0 */
	{
		if (**lpRptData_temp != 0 || positive == SD_FALSE)
		{
			//myprintf ("ASN.1 decode: invalid 5 byte (or larger) integer");
			return;
		}
		*lpRptData_temp += 1;
		--i;
	}

	/* Go ahead and read the value into A 4 byte integer, shifting as we go	*/
	nvalue = 0;
	while (SD_TRUE)
	{
		oVal = (ST_INT32)(**lpRptData_temp);
		*lpRptData_temp += 1;
		oVal &= 0xFF;
		nvalue |= oVal;
		if (--i == 0)		
			break;
		/* More bytes of data, need to make room for next one */
		nvalue = (nvalue << 8) & 0xffffff00;
	}

	/* We may need to sign extend if negative */
	if (!positive && Length < 4)
	{
		negMask = 0xff000000L;
		i = 4 - Length;
		while (i-- > 0)
		{
			nvalue |= negMask;
			negMask = negMask >> 8;
		}
	}
	 
	pDA->DAValue.Value.i= nvalue;
}

/*****************************************************************************/
/*Function Name: 		asn1r_dec_UINT( )									 */
/*Function Description:	Decode a asn.1 decoded Unsigned Integer				 */
/*****************************************************************************/
//ST_INT asn1r_dec_UINT (ST_CHAR **lpRptData_temp, ST_INT Length,
//					   tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx)
//{
//	ST_INT ACSI_DAIdx=-1;
//	ST_INT32 ivalue;
//	ST_INT32 oVal;
//	ST_INT i;
//
//	/* Large unsigned value's may be 5 bytes, with a leading 0. If so,	*/
//	/* we will strip it here.						*/
//	i = Length;
//	if (i >= 5)			/* Large positive number, skip leading 0 */
//	{
//		if (**lpRptData_temp != 0)
//		{
//			myprintf ("ASN.1 decode: invalid 5 byte (or larger) integer");
//			return (SD_FAILURE);
//		}
//		*lpRptData_temp += 1;
//		--i;
//	}
//
//	/* Go ahead and read the value into A 4 byte integer, shifting as we go	*/
//	ivalue = 0;
//	while (SD_TRUE)
//	{
//		oVal = (ST_INT32)(**lpRptData_temp);
//		*lpRptData_temp += 1;
//		oVal &= 0xFF;
//		ivalue |= oVal;
//		if (--i == 0)		break;
//		/* More bytes of data, need to make room for next one */
//		ivalue = (ivalue << 8) & 0xffffff00;
//	}
//
//	ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
//	pACSINode[ACSIIdx].DA[ACSI_DAIdx].Value.i= ivalue;
//	return (ACSI_DAIdx);
//}

ST_VOID asn1r_dec_UINT_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA)
{
	ST_INT32 ivalue;
	ST_INT32 oVal;
	ST_INT i;

	if (pDA == NULL)
		return;

	/* Large unsigned value's may be 5 bytes, with a leading 0. If so,	*/
	/* we will strip it here.						*/
	i = Length;
	if (i >= 5)			/* Large positive number, skip leading 0 */
	{
		if (**lpRptData_temp != 0)
		{
			//myprintf ("ASN.1 decode: invalid 5 byte (or larger) integer");
			return;
		}
		*lpRptData_temp += 1;
		--i;
	}

	/* Go ahead and read the value into A 4 byte integer, shifting as we go	*/
	ivalue = 0;
	while (SD_TRUE)
	{
		oVal = (ST_INT32)(**lpRptData_temp);
		*lpRptData_temp += 1;
		oVal &= 0xFF;
		ivalue |= oVal;
		if (--i == 0)	
			break;
		/* More bytes of data, need to make room for next one */
		ivalue = (ivalue << 8) & 0xffffff00;
	}
 
	pDA->DAValue.Value.i= ivalue;
}

/************************************************************************************/
/*Function Name: 		asn1r_dec_Bitstring( )										*/
/*Function Description:	Decode a asn.1 decoded Unsigned bitstring					*/
/*Return Value:			The bit count of the bitstring								*/
/************************************************************************************/
//ST_INT asn1r_dec_Bitstring ( ST_CHAR **lpRptData_temp, ST_INT Length, ST_INT Max_Bits,
//							 tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx )
//{
//	ST_INT ACSI_DAIdx=-1;
//	ST_INT i;
//	ST_INT asn1r_bitcount=0;
//	ST_INT accepted_bits;	/* # of bits accepted (may be truncated)	*/
//
//	if (Length < 1)   /* For element length of 0, return error code.	*/
//		return 0;
//
//	i = (**lpRptData_temp);
//	*lpRptData_temp += 1;
//	if (i>7 || i<0)
//		return (0);     /* Return error code for bad unused-bits value.	*/
//
//	/* When there is only the unused-bits octet,
//  		it must = 0, and there are no data bits.	*/
//	if ( Length == 1 && i != 0 )
//		return (0);
//	else		       /* Treat normal case where there are data bits.	*/
//	{
//		asn1r_bitcount = ((Length-1)*8 - i); /* Compute # data bits.	*/
//
//		/* If caller imposed a limit, truncate. */
//		if (Max_Bits != 0  &&  asn1r_bitcount > Max_Bits)
//			accepted_bits = Max_Bits;	/* truncated	*/
//		else
//			accepted_bits = asn1r_bitcount;
//
//		ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
//		/* Copy Bitstring to user buffer */
//		bstrcpy ( (ST_UCHAR*)&pACSINode[ACSIIdx].DA[ACSI_DAIdx].Value.i,
//										*lpRptData_temp, accepted_bits);
//		*lpRptData_temp += (Length - 1);	/* point to next*/
//	}
//	return (ACSI_DAIdx);
//}

static void CharToBinary(unsigned char ch, char *szBinary)
{
	int i;
	unsigned char byte[2];
	byte[0] = ch/16;
	byte[1] = ch%16;

	for(i=0; i<2; i++)
	{
		if (byte[i]/8 == 1)
		{
			byte[i] = byte[i]%8;
			szBinary[i*4+0] = '1';
		} 
		else
			szBinary[i*4+0] = '0';

		if (byte[i]/4 == 1)
		{
			byte[i] = byte[i]%4;
			szBinary[i*4+1] = '1';
		} 
		else
			szBinary[i*4+1] = '0';

		if (byte[i]/2 == 1)
		{
			byte[i] = byte[i]%2;
			szBinary[i*4+2] = '1';
		} 
		else
			szBinary[i*4+2] = '0';

		if (byte[i] == 1)
			szBinary[i*4+3] = '1';
		else
			szBinary[i*4+3] = '0';
	}

	szBinary[8] = 0;
}

ST_VOID CharStrToBinaryStr( char *pucCharStr, int iSize,  char *pszHexStr)
{
	int i;
	char szBinary[9];
	pszHexStr[0] = 0;
	for(i=0; i<iSize; i++)
	{
		CharToBinary(pucCharStr[i], szBinary);
		strcat(pszHexStr, szBinary);
	}
}

ST_VOID asn1r_dec_Bitstring_Ex ( ST_CHAR **lpRptData_temp, ST_INT Length, ST_INT Max_Bits, tagDA*pDA)
{
	ST_INT i;
	ST_INT asn1r_bitcount=0;
	ST_INT accepted_bits;	/* # of bits accepted (may be truncated)	*/
	BYTE *bitstr;
	BYTE byteVal;
	char *mmsString;

	if (pDA == NULL)
		return;

	if (Length < 1)   /* For element length of 0, return error code.	*/
		return;

	i = (**lpRptData_temp);
	*lpRptData_temp += 1;
	if (i>7 || i<0)
		return;     /* Return error code for bad unused-bits value.	*/

	/* When there is only the unused-bits octet,
  		it must = 0, and there are no data bits.	*/
	if ( Length == 1 && i != 0 )
		return;
	else		       /* Treat normal case where there are data bits.	*/
	{
		asn1r_bitcount = ((Length-1)*8 - i); /* Compute # data bits.	*/

		/* If caller imposed a limit, truncate. */
		if (Max_Bits != 0  &&  asn1r_bitcount > Max_Bits)
			accepted_bits = Max_Bits;	/* truncated	*/
		else
			accepted_bits = asn1r_bitcount;

		/* Copy Bitstring to user buffer */
#ifdef _use_mms_string
		if (pDA->nDataType == DA_DATATYE_BIT_STR)//zhouhj 20180524 修改品质位按实际2进制显示
		{
			bitstr = (BYTE*)malloc(Length);
			ZeroMemory(bitstr, Length);
			bstrcpy ( (ST_UCHAR*)bitstr, *lpRptData_temp, accepted_bits);

			mms_str_init2(&pDA->DAValue.Value.string, Length * 8 + 4);
			mms_str_set_size(&pDA->DAValue.Value.string, accepted_bits);
			mmsString = mms_string(&pDA->DAValue.Value.string);

			CharStrToBinaryStr(bitstr,Length,mmsString);
			mmsString[accepted_bits] = 0;

			free(bitstr);
		}
		else
		{
			mvl_log_err("asn1r_dec_Bitstring_Ex:装置设备数据模型与加载的模型文件不一致");
		}

#else
		bstrcpy ( (ST_UCHAR*)&pDA->DAValue.Value.i, *lpRptData_temp, accepted_bits);
#endif

		*lpRptData_temp += (Length - 1);	/* point to next*/
	}
}

/*************************************************************************/
/*Function Name: 		asn1r_dec_UTC( )								 */
/*Function Description:	Decode a asn.1 decoded UTC time					 */
/*************************************************************************/
//ST_INT asn1r_dec_UTC (ST_CHAR **lpRptData_temp, tagDSAppLink *pDSAppLK,
//					  ST_INT DSMemIdx, ST_INT ACSIIdx)
//{
//	ST_INT	 ACSI_DAIdx=-1;
//	MMS_UTC_TIME  *dest;
//	//ST_UINT32  Lvalue=0;
//	ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
//	dest = (MMS_UTC_TIME*)&(pACSINode[ACSIIdx].DA[ACSI_DAIdx].Value.utctime);
//	//dest = &Lvalue;
//
//	/* Read the number of seconds since January 1, 1970 (4 bytes)	*/
//	dest->secs  =  (((ST_UINT32)(**lpRptData_temp)) << 24) & 0xFF000000L;
//	*lpRptData_temp += 1;
//	dest->secs |= (((ST_UINT32)(**lpRptData_temp)) << 16) & 0x00FF0000L;
//	*lpRptData_temp += 1;
//	dest->secs |= (((ST_UINT32)(**lpRptData_temp)) << 8)  & 0x0000FF00L;
//	*lpRptData_temp += 1;
//	dest->secs |=  ((ST_UINT32)(**lpRptData_temp))        & 0x000000FFL;
//	*lpRptData_temp += 1;
//
//	/* read fraction of a second (3 bytes) */
//	dest->fraction =  (((ST_UINT32)(**lpRptData_temp)) << 16) & 0x00FF0000L;
//	*lpRptData_temp += 1;
//	dest->fraction |= (((ST_UINT32)(**lpRptData_temp)) << 8)  & 0x0000FF00L;
//	*lpRptData_temp += 1;
//	dest->fraction |=  ((ST_UINT32)(**lpRptData_temp))        & 0x000000FFL;
//	*lpRptData_temp += 1;
//
//	/* read the quality flags (1 byte) */
//	dest->qflags =  ((ST_UINT32)(**lpRptData_temp));
//	*lpRptData_temp += 1;
//
//	return (ACSI_DAIdx);
//}

ST_VOID asn1r_dec_UTC_Ex (ST_CHAR **lpRptData_temp, tagDA*pDA)
{
	MMS_UTC_TIME  *dest;

	if (pDA == NULL)
		return;

	//ST_UINT32  Lvalue=0;
 	dest = (MMS_UTC_TIME*)&(pDA->DAValue.Value.utctime);
	//dest = &Lvalue;

	/* Read the number of seconds since January 1, 1970 (4 bytes)	*/
	dest->secs  =  (((ST_UINT32)(**lpRptData_temp)) << 24) & 0xFF000000L;
	*lpRptData_temp += 1;
	dest->secs |= (((ST_UINT32)(**lpRptData_temp)) << 16) & 0x00FF0000L;
	*lpRptData_temp += 1;
	dest->secs |= (((ST_UINT32)(**lpRptData_temp)) << 8)  & 0x0000FF00L;
	*lpRptData_temp += 1;
	dest->secs |=  ((ST_UINT32)(**lpRptData_temp))        & 0x000000FFL;
	*lpRptData_temp += 1;

	/* read fraction of a second (3 bytes) */
	dest->fraction =  (((ST_UINT32)(**lpRptData_temp)) << 16) & 0x00FF0000L;
	*lpRptData_temp += 1;
	dest->fraction |= (((ST_UINT32)(**lpRptData_temp)) << 8)  & 0x0000FF00L;
	*lpRptData_temp += 1;
	dest->fraction |=  ((ST_UINT32)(**lpRptData_temp))        & 0x000000FFL;
	*lpRptData_temp += 1;

	/* read the quality flags (1 byte) */
	dest->qflags =  ((ST_UINT32)(**lpRptData_temp));
	*lpRptData_temp += 1;
}


/*************************************************************************/
/*Function Name: 		asn1r_dec_float( )								 */
/*Function Description:	Decode a asn.1 decoded float 					 */
/*************************************************************************/
//ST_INT asn1r_dec_float(ST_CHAR **lpRptData_temp, ST_INT Length,
//					   tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx )
//{
//	ST_UCHAR n;			/* length of the exponent part		*/
//	ST_UCHAR *ptr;		/* char ptr to output float variable out*/
//	ST_UCHAR *next;		/* points to next data element		*/
//	ST_UCHAR *original_asn1_field_ptr;
//	ST_BOOLEAN float_is_zero;
//	ST_INT   ACSI_DAIdx=-1;
//	//ST_FLOAT fvalue=0;
//
//	#ifdef ASN1_ARB_FLOAT
//		ST_UINT16 exp;			/* local variable to hold exponent part */
//		ST_INT i;				/* utility variable			*/
//		ST_INT16 sign;			/* sign of the floating point quantity	*/
//		ST_INT32 signexp;		/* contains sign and exp parts of out	*/
//		ST_INT16 m;				/* # of fract bits in 1st 2 exp octets	*/
//		ST_UINT32 *fract;		/* contains fraction part of out	*/
//	#endif
//
//	next = *lpRptData_temp + Length;
//	n = (ST_UCHAR)(**lpRptData_temp);			/* read exponent width	*/
//	*lpRptData_temp += 1;
//
//	ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
//	//ptr = (ST_UCHAR*)&fvalue;
//	ptr = (ST_UCHAR*)&pACSINode[ACSIIdx].DA[ACSI_DAIdx].DAValue.Value.f;
//	/* check to see if all the octets are 0	 */
//
//	original_asn1_field_ptr = *lpRptData_temp;
//	float_is_zero = SD_TRUE;					/* assume the float = 0	*/
//	while(*lpRptData_temp < next)
//	{
//		if( (**lpRptData_temp) != 0 )
//		{
//			float_is_zero = SD_FALSE;
//			break;
//		}
//		*lpRptData_temp += 1;
//	}
//	if (float_is_zero)
//	{
//		*lpRptData_temp = next;
//		pACSINode[ACSIIdx].DA[ACSI_DAIdx].DAValue.Value.f = (ST_FLOAT)0;	/* this float = 0	*/
//		return ACSI_DAIdx;				/* return success	*/
//	}
//	else
//		*lpRptData_temp = original_asn1_field_ptr;
//
//	/* Treat case where MMS floating point format coincides with IEEE 754.	*/
//	if ( Length == 5 && n == 8)
//	{
//		#if SD_BYTE_ORDER==SD_BIG_ENDIAN	/* big-endian (like Motorola)	*/
//			*ptr = (ST_UCHAR)(**lpRptData_temp);
//			*lpRptData_temp += 1;		ptr += 1;
//			*ptr = (ST_UCHAR)(**lpRptData_temp);
//			*lpRptData_temp += 1;		ptr += 1;
//			*ptr = (ST_UCHAR)(**lpRptData_temp);
//			*lpRptData_temp += 1;		ptr += 1;
//		#else
//			*lpRptData_temp += 3;
//			*ptr = (ST_UCHAR)(**lpRptData_temp);
//			*lpRptData_temp -= 1;		ptr += 1;
//			*ptr = (ST_UCHAR)(**lpRptData_temp);
//			*lpRptData_temp -= 1;		ptr += 1;
//			*ptr = (ST_UCHAR)(**lpRptData_temp);
//			*lpRptData_temp -= 1;		ptr += 1;
//		#endif
//		*ptr = (ST_UCHAR) **lpRptData_temp;
//		*lpRptData_temp = next;
//	}
//	return ACSI_DAIdx;
//}

ST_VOID asn1r_dec_float_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA)
{
	ST_UCHAR n;			/* length of the exponent part		*/
	ST_UCHAR *ptr;		/* char ptr to output float variable out*/
	ST_UCHAR *next;		/* points to next data element		*/
	ST_UCHAR *original_asn1_field_ptr;
	ST_BOOLEAN float_is_zero;
	//ST_FLOAT fvalue=0;

#ifdef ASN1_ARB_FLOAT
	ST_UINT16 exp;			/* local variable to hold exponent part */
	ST_INT i;				/* utility variable			*/
	ST_INT16 sign;			/* sign of the floating point quantity	*/
	ST_INT32 signexp;		/* contains sign and exp parts of out	*/
	ST_INT16 m;				/* # of fract bits in 1st 2 exp octets	*/
	ST_UINT32 *fract;		/* contains fraction part of out	*/
#endif

	if (pDA == NULL)
		return;

	next = *lpRptData_temp + Length;
	n = (ST_UCHAR)(**lpRptData_temp);			/* read exponent width	*/
	*lpRptData_temp += 1;

 	//ptr = (ST_UCHAR*)&fvalue;
	ptr = (ST_UCHAR*)&pDA->DAValue.Value.f;
	/* check to see if all the octets are 0	 */

	original_asn1_field_ptr = *lpRptData_temp;
	float_is_zero = SD_TRUE;					/* assume the float = 0	*/
	while(*lpRptData_temp < next)
	{
		if( (**lpRptData_temp) != 0 )
		{
			float_is_zero = SD_FALSE;
			break;
		}
		*lpRptData_temp += 1;
	}
	if (float_is_zero)
	{
		*lpRptData_temp = next;
		pDA->DAValue.Value.f = (ST_FLOAT)0;	/* this float = 0	*/
		return;				/* return success	*/
	}
	else
		*lpRptData_temp = original_asn1_field_ptr;

	/* Treat case where MMS floating point format coincides with IEEE 754.	*/
	if ( Length == 5 && n == 8)
	{
#if SD_BYTE_ORDER==SD_BIG_ENDIAN	/* big-endian (like Motorola)	*/
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
#else
		*lpRptData_temp += 3;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
#endif
		*ptr = (ST_UCHAR) **lpRptData_temp;
		*lpRptData_temp = next;
	}
}

/******************************************************************************/
/*Function Name: 		asn1r_dec_double( )									  */
/*Function Description:	Decode a asn.1 decoded double						  */
/******************************************************************************/
ST_INT asn1r_dec_double(ST_CHAR **lpRptData_temp, ST_INT Length,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx)
{
	ST_UCHAR n;			/* length of the exponent part		*/
	ST_UCHAR *ptr;		/* char ptr to the out variable 	*/
	ST_UCHAR *next;		/* points to next data element		*/
	ST_DOUBLE df;
	ST_UCHAR *original_asn1_field_ptr;
	ST_BOOLEAN float_is_zero;
	ST_INT   ACSI_DAIdx=-1;

	ACSI_DAIdx = pDSAppLK->SN_DA[DSMemIdx];
	ptr = (ST_UCHAR*)&df;

	next = *lpRptData_temp + Length;
	n = (ST_UCHAR) *(*lpRptData_temp++);			/* read exponent width	*/

	/* check to see if all the octets are 0					*/
	original_asn1_field_ptr = *lpRptData_temp;
	float_is_zero = SD_TRUE;				/* assume the float = 0	*/
	while(*lpRptData_temp < next)
	{
		if( (**lpRptData_temp) != 0 )
		{
			*lpRptData_temp += 1;
			float_is_zero = SD_FALSE;
			break;
		}
		*lpRptData_temp += 1;
	}
	if (float_is_zero)
	{
		*lpRptData_temp = next;
		pACSINode[ACSIIdx].DA[ACSI_DAIdx].DAValue.Value.f = (ST_FLOAT)0;	/* this float = 0	*/
		return(SD_SUCCESS);				/* return success	*/
	}
	else
		*lpRptData_temp = original_asn1_field_ptr;

	/* Treat case where MMS floating point format coincides with IEEE 754	*/
	/* double precision floating point format.	*/
	if (Length == 9 && n == 11)
	{
		#if SD_BYTE_ORDER==SD_BIG_ENDIAN	/* big-endian (like Motorola)	*/
			*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp += 1;		ptr += 1;
		#else
    		*lpRptData_temp += 7;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
    		*ptr = (ST_UCHAR)(**lpRptData_temp);
			*lpRptData_temp -= 1;		ptr += 1;
		#endif
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp = next;
	}
	memcpy(&pACSINode[ACSIIdx].DA[ACSI_DAIdx].DAValue.Value.f, &df, sizeof(ST_FLOAT));
	return ( ACSI_DAIdx );
}

ST_VOID asn1r_dec_double_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA)
{
	ST_UCHAR n;			/* length of the exponent part		*/
	ST_UCHAR *ptr;		/* char ptr to the out variable 	*/
	ST_UCHAR *next;		/* points to next data element		*/
	ST_DOUBLE df;
	ST_UCHAR *original_asn1_field_ptr;
	ST_BOOLEAN float_is_zero;
 
	if (pDA == NULL)
		return;

	ptr = (ST_UCHAR*)&df;

	next = *lpRptData_temp + Length;
	n = (ST_UCHAR) *(*lpRptData_temp++);			/* read exponent width	*/

	/* check to see if all the octets are 0					*/
	original_asn1_field_ptr = *lpRptData_temp;
	float_is_zero = SD_TRUE;				/* assume the float = 0	*/
	while(*lpRptData_temp < next)
	{
		if( (**lpRptData_temp) != 0 )
		{
			*lpRptData_temp += 1;
			float_is_zero = SD_FALSE;
			break;
		}
		*lpRptData_temp += 1;
	}
	if (float_is_zero)
	{
		*lpRptData_temp = next;
		pDA->DAValue.Value.f = (ST_FLOAT)0;	/* this float = 0	*/
		return ;				/* return success	*/
	}
	else
		*lpRptData_temp = original_asn1_field_ptr;

	/* Treat case where MMS floating point format coincides with IEEE 754	*/
	/* double precision floating point format.	*/
	if (Length == 9 && n == 11)
	{
#if SD_BYTE_ORDER==SD_BIG_ENDIAN	/* big-endian (like Motorola)	*/
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp += 1;		ptr += 1;
#else
		*lpRptData_temp += 7;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp -= 1;		ptr += 1;
#endif
		*ptr = (ST_UCHAR)(**lpRptData_temp);
		*lpRptData_temp = next;
	}
	memcpy(&pDA->DAValue.Value.f, &df, sizeof(ST_FLOAT));
}

/******************************************************************************/
/*Function Name: 		Convert_UTC_To_BCD( )								  */
/*Function Description:	Convert UTC time to BCD time						  */
/******************************************************************************/
ST_VOID Convert_UTC_To_BCD(tagEVENTTIME* lpTimeBCD, MMS_UTC_TIME UTCTime)
{
    ST_INT32  EvenYearSec=0, LeapYearSec=0, YearSec=0;
	ST_INT32  BigMonthSec=0, SmallMonthSec=0, FebruarySec=0;
	ST_INT	  wYear=0, wMinute=0, wSecond=0;
    ST_UCHAR  wMonth=0,wDay=0,wHour=0;
    ST_INT8   byLeapYear=0, YearLoop=0, byDaysMonth=0, i=0;
	ST_INT32  MonthSec[12];
	ST_INT32  IntergerSecond=0;
	ST_DOUBLE msBase=1,val=0;
	
	IntergerSecond = UTCTime.secs;

	/*Regard of the time-zone*/
	IntergerSecond += 8 * 60 * 60;
		
	/* Calculate the Year */
	EvenYearSec = 365 * 24 * 60 * 60;
	LeapYearSec = 366 * 24 * 60 * 60;
	
	YearLoop = (ST_INT8)( IntergerSecond / ( 3 * EvenYearSec + LeapYearSec ) );
	IntergerSecond %= ( 3 * EvenYearSec + LeapYearSec );
	wYear = 1970 + 4 * YearLoop;

	if( ( 3 * EvenYearSec + LeapYearSec ) > IntergerSecond )
	{
		if( ( 2 * EvenYearSec + LeapYearSec ) <= IntergerSecond )
		{
			wYear += 3; 
			IntergerSecond -= ( 2 * EvenYearSec + LeapYearSec );
		}
		if( ( 2 * EvenYearSec ) <= IntergerSecond )
		{
			wYear += 2;
			byLeapYear = 1;
			IntergerSecond -= ( 2 * EvenYearSec );
		}
		if( EvenYearSec <= IntergerSecond )
		{
			wYear += 1;
			IntergerSecond -= EvenYearSec;
		}
	}
	lpTimeBCD->year = wYear;

	/* Calculate the Month */
	BigMonthSec = 31 * 24 * 60 * 60;
	SmallMonthSec = 30 * 24 * 60 * 60;
	if( byLeapYear ){
		FebruarySec = 29 * 24 * 60 * 60;
		YearSec = LeapYearSec;
	}
	else{
		FebruarySec = 28 * 24 * 60 * 60;
		YearSec = EvenYearSec;
	}
	for(i=1; i<=12; i++)
	{
		if( i==2 )
		{
			MonthSec[i-1] = FebruarySec;
			continue;
		}
		else if( i==4 || i==6 || i==9 || i==11 )
		{
			MonthSec[i-1] = SmallMonthSec;
			continue;
		}
		else
		{
			MonthSec[i-1] = BigMonthSec;
			continue;
		}
	}
	for(i=0; i<12; i++)
	{
		IntergerSecond -= MonthSec[i]; 
		if( IntergerSecond < 0 )
		{
			IntergerSecond += MonthSec[i];
			wMonth = i + 1;
			break;
		}
	}
	lpTimeBCD->month = wMonth;

	/* Calculate the Day */
	for(i=1; i<=31; i++)
	{
		IntergerSecond -= 24 * 60 * 60;
		if( IntergerSecond < 0 )
		{
			IntergerSecond += 24 * 60 * 60;
			wDay = i;
			break;
		}
	}
	lpTimeBCD->day = wDay;

	/* Calculate the Hour */
	for(i=0; i<=24; i++)
	{
		IntergerSecond -= 60 * 60;
		if( IntergerSecond < 0 )
		{
			IntergerSecond += 60 * 60;
			wHour = i;
			break;
		}
	}
	lpTimeBCD->hour = wHour;

	/* Calculate the Minute */
	for(i=0; i<=60; i++)
	{
		IntergerSecond -= 60;
		if( IntergerSecond < 0 )
		{
			IntergerSecond += 60;
			wMinute = i;
			break;
		}
	}
	lpTimeBCD->minute = wMinute;

	/* Evaluate the Second */
	lpTimeBCD->second = IntergerSecond;

	/* Calculate the ms  ns -> ms */
	for( i=0; i<24; i++ )
	{
		msBase = msBase / 2;
	}
	val = UTCTime.fraction * msBase * 1000 ;
	lpTimeBCD->ms = (ST_INT)val;
	if( val > lpTimeBCD->ms + 0.5 )
		lpTimeBCD->ms += 1;
}