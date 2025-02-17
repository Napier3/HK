/*************************************************************************/
/*File Name:  Client_SCADA.c											 */
/*writer:     lijin
/*Describe:   Interface for IEC61850 Client and SCADA					 */
/*************************************************************************/
#include "glbtypes.h"
#include "RptDeCode.h"
#include "sysincs.h"
#include "mvl_acse.h"
#include "mvl_uca.h"	/* only need OPTFLD_* defines	*/
#include "client.h"
#include "glbsem.h"
#include "memOBJTree.h"

tagDSAppLink struDSAppLink[MAX_DS_VMD];

/***********************************************************************************/
/*Function Name: DecodeBasicTypeData()											   */
/*Function Description:	decode one member of the DataSet						   */
/*Input Parameters: pRptData_tmp: Point to the report data to be decoded		   */
/*					lpDSApplk:the point to tagDSAppLink							   */
/*					DSMemIndex:   the No of DS member							   */
/*					nACSIIdx:	  the SN of pACSINode							   */
/***********************************************************************************/
//ST_INT DecodeBasicTypeData( ST_CHAR **pRptData_tmp, tagDSAppLink *lpDSApplk,
//													ST_INT DSMemIndex, ST_INT ACSIIdx )
//{
//  ST_UINT	tmp=0;
//  ST_INT	SN=0;
//  tagasn1r_head asn1_head_tmp;
//
//  if( dec_asn1_head( pRptData_tmp, (tagasn1r_head*)&asn1_head_tmp ) < 0 ){
//	  myprintf("DS Member offset calculate error!\n");
//	  SN = -1;
//	  return SN;
//  }
//  switch( asn1_head_tmp.asn1r_element_id )
//  {
//	case 0x03:
//		SN = asn1r_dec_bool( pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, lpDSApplk,
//																DSMemIndex, ACSIIdx );
//		myprintf("The Boolean is %d\n", pACSINode[ACSIIdx].DA[SN].Value.i);
//  		break;
//	case 0x05:
//		SN = asn1r_dec_integer( pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, lpDSApplk,
//																DSMemIndex,ACSIIdx );
//		myprintf("The integer is %d\n",pACSINode[ACSIIdx].DA[SN].Value.i);
//  		break;
//	case 0x06:
//		SN = asn1r_dec_UINT( pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, lpDSApplk,
//																DSMemIndex, ACSIIdx );
//		myprintf("The integer is %d\n",pACSINode[ACSIIdx].DA[SN].Value.i);
//  		break;
//	case 0x07:
//		if( **pRptData_tmp == 8 ){
//			SN = asn1r_dec_float ( pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, lpDSApplk,
//																DSMemIndex, ACSIIdx );
//			myprintf("The float is %f\n",pACSINode[ACSIIdx].DA[SN].Value.f);
//		}
//		else if( **pRptData_tmp == 11 ){
//			SN = asn1r_dec_double( pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, lpDSApplk,
//																	DSMemIndex, ACSIIdx );
//			myprintf("The double is %f\n",pACSINode[ACSIIdx].DA[SN].Value.f);
//		}
//		else{
//			*pRptData_tmp += asn1_head_tmp.asn1r_elmnt_len;
//			myprintf("This is a arbitrary real data\n");
//		}
//  		break;
//	case 0x04:
//		SN = asn1r_dec_Bitstring ( pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, 380,
//														lpDSApplk, DSMemIndex, ACSIIdx );
//		myprintf("The Bitstring value= %d\n",pACSINode[ACSIIdx].DA[SN].Value.i);
//  		break;
//	case 0x11:
//		SN = asn1r_dec_UTC ( pRptData_tmp, lpDSApplk, DSMemIndex, ACSIIdx );
//		myprintf("The timestamp is %d\n", pACSINode[ACSIIdx].DA[SN].Value.l);
//  		break;
//	default:
//		*pRptData_tmp += asn1_head_tmp.asn1r_elmnt_len;
//		myprintf("The data type is not included in DataBase, disposal it\n");
//  }
//  return SN;
//}

ST_RET DecodeBasicTypeData_Ex( ST_CHAR **pRptData_tmp, tagDA *pDA)
{
	ST_UINT	tmp=0;
	ST_INT	SN=0;
	tagasn1r_head asn1_head_tmp;

	if (pDA == NULL)
		return SD_FAILURE;

	if (dec_asn1_head( pRptData_tmp, (tagasn1r_head*)&asn1_head_tmp ) < 0)
 		return SD_FAILURE;

	if (asn1_head_tmp.asn1r_element_id != pDA->nDataType)
	{
		sprintf(buff_mms_err_text, "DecodeBasicTypeData_Ex:装置设备数据模型与加载的模型文件不一致%d != %d"
			, asn1_head_tmp.asn1r_element_id, pDA->nDataType);
		func_mms_log_error_infor();
		return SD_FAILURE;
	}

	switch( asn1_head_tmp.asn1r_element_id )
	{
	case 0x03:
		asn1r_dec_bool_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, pDA);
		break;
	case 0x05:
		asn1r_dec_integer_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, pDA);
		break;
	case 0x06:
		asn1r_dec_UINT_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, pDA);
		break;
	case 0x07:
		if ( **pRptData_tmp == 8 )
		{
			asn1r_dec_float_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, pDA);
		}
		else if ( **pRptData_tmp == 11 )
		{
			asn1r_dec_double_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, pDA);
		}
		else
		{
			*pRptData_tmp += asn1_head_tmp.asn1r_elmnt_len;
		}
		break;
	case 0x04:
		asn1r_dec_Bitstring_Ex(pRptData_tmp, asn1_head_tmp.asn1r_elmnt_len, 380, pDA);
		break;
	case 0x11:
		asn1r_dec_UTC_Ex(pRptData_tmp, pDA);
		break;
	default:
		*pRptData_tmp += asn1_head_tmp.asn1r_elmnt_len;
	}

	return  SD_SUCCESS;
}

/*********************************************************************************/
/*Function Name:  DecodeOneApplyMember()													 */
/*Input Parameter:*RCBTable:point to the tagRCBTable struct						 */
/*				  MemNum:	the SN of tagYCAssoc or tagYXAssoc					 */
/*				  YC_YXRptData:	the point to the data to be decoded				 */
/*				  MemType:	distinguish YX and YC								 */
/*********************************************************************************/
//ST_INT	DecodeOneApplyMember( tagDSAppLink *pDSApplink, ST_UCHAR **RptData,
//														ST_INT DSMemIdx, ST_INT nACSIIdx )
//{
//	ST_INT		k=0;
//	ST_INT		SN=0;
//	ST_INT		Level[LEVELSIZE];
//	ST_INT		DecodeLevel=1;
//	ST_UINT8	StartSign=0;
//	ST_INT		headlength=0;
//	tagasn1r_head asn1_head;
//
//	myprintf("MMS Var Name: %s  ",pDSApplink->mmsVARName[DSMemIdx]);
//	memset( Level, 0, LEVELSIZE*sizeof(ST_INT) );
//	memcpy( Level, pDSApplink->Level[DSMemIdx], LEVELSIZE );
//	headlength = dec_asn1_head(RptData, (tagasn1r_head*)&asn1_head);
//	if( headlength <= 0 )		return SD_FAILURE;
//	if( ( headlength >0 ) && ( asn1_head.asn1r_element_id != 0x02 )	)
//		*RptData -= headlength;
//
//	if( Level[1] == 0 ) /*注意此处Level已经转换为了INT类型，即Level[0]表示数据集位置*/
//	{
//		if( asn1_head.asn1r_element_id != 0x02 )
//		{
//			SN = DecodeBasicTypeData( RptData, pDSApplink, DSMemIdx, nACSIIdx );
//			return SN;
//		}
//		else{
//			SN = pDSApplink->SN_DA[DSMemIdx];
//			return SN;
//		}
//	}
//	memset( &asn1_head, 0, sizeof(tagasn1r_head) );
//	for( k=1; k<LEVELSIZE; k++ )
//	{
//		if( Level[k+1] == 0 )
//		{
//			while( DecodeLevel < Level[k] )
//			{
//				dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head );
//				*RptData += asn1_head.asn1r_elmnt_len;
//				memset( &asn1_head, 0, sizeof(tagasn1r_head) );
//				DecodeLevel += 1;
//			}
//			DecodeLevel = 1;
//			headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head );
//			if( asn1_head.asn1r_element_id != 0x02 )
//			{
//				*RptData -= headlength;
//				SN = DecodeBasicTypeData( RptData, pDSApplink, DSMemIdx, nACSIIdx );
//			}
//			memset(&asn1_head,0,sizeof(tagasn1r_head));
//			break;
//		}
//		while( DecodeLevel < Level[k] )
//		{
//			dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head );
//			*RptData += asn1_head.asn1r_elmnt_len;
//			memset( &asn1_head,0,sizeof(tagasn1r_head) );
//			DecodeLevel += 1;
//		}
//		DecodeLevel = 1;
//		headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head );
//		if( asn1_head.asn1r_element_id != 0x02 )
//			RptData -= headlength;
//		memset( &asn1_head, 0, sizeof(tagasn1r_head) );
//	}
//	return SN;
//}


ST_RET	DecodeOneApplyMember_Ex(ST_UCHAR **RptData, tagDA*pDA)
{
	ST_INT ret = SD_SUCCESS;
	ST_INT		k=0;
	ST_INT		arr=0;
	ST_INT		DecodeLevel=1;
	ST_UINT8	StartSign=0;
	ST_INT		headlength=0;
	tagasn1r_head asn1_head;
	tagDA *pDA_arr = NULL;

	if (pDA == NULL)
		return SD_FAILURE;

// 	if (pDA->pSubDA == NULL)
// 		return SD_FAILURE;

	memset(&asn1_head, 0, sizeof(tagasn1r_head));
	headlength = dec_asn1_head(RptData, (tagasn1r_head*)&asn1_head);
	if (headlength <= 0)		
		return SD_FAILURE;

	if ((headlength >0) && (asn1_head.asn1r_element_id != 0x02))
		*RptData -= headlength;

	//if (strcmp(pDA->DataType,"STRUCT") == 0)
	if (pDA->nDataType == DA_DATATYE_STRUCT)
	{
		k = 0;
		//for (k=0; k<pDA->nSubDANum; k++)
		while (TRUE)
		{		
			memset( &asn1_head, 0, sizeof(tagasn1r_head) );
			headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);

			if ((headlength >0) && asn1_head.asn1r_element_id != 0x02)
			{
				*RptData -= headlength;

				//if (strcmp(pDA->pSubDA[k].DataType,"STRUCT") == 0)
				if (pDA->pSubDA[k].nDataType == DA_DATATYE_STRUCT)
				{
					ret = DecodeOneApplyMember_Ex(RptData, &pDA->pSubDA[k]);
				}
				//else if (strcmp(pDA->pSubDA[k].DataType,"ARRAY") == 0)
				else if (pDA->pSubDA[k].nDataType == DA_DATATYE_ARRAY)
				{
					*RptData += headlength;
					headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);
//
// 					while (asn1_head.asn1r_element_id == 0x02)
// 					{
// 						*RptData += headlength;
// 						headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);
// 					}
//
// 					*RptData -= headlength;
					pDA_arr = &pDA->pSubDA[k];

					for (arr=0; arr < pDA_arr->nSubDANum; arr++)
					{
						headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);

						while (asn1_head.asn1r_element_id == 0x02)
						{
							headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);
						}

						*RptData -= headlength;

						//if (strcmp(pDA_arr->pSubDA[arr].DataType, "STRUCT") == 0)
						if (pDA_arr->pSubDA[arr].nDataType == DA_DATATYE_STRUCT)
						{
							ret = DecodeOneApplyMember_Ex(RptData, &pDA_arr->pSubDA[arr]);
						}
						else if (pDA_arr->pSubDA[arr].DataType[0] == 0 && pDA_arr->pSubDA[arr].nSubDANum > 0)
						{
							ret = DecodeOneApplyMember_Ex(RptData, &pDA_arr->pSubDA[arr]);
						}
						else
						{
							ret = DecodeBasicTypeData_Ex(RptData, &pDA_arr->pSubDA[arr]);
						}
// 						if (pDA_arr->pSubDA[arr].nSubDANum == 0)
// 						{
// 							DecodeBasicTypeData_Ex(RptData, &pDA_arr->pSubDA[arr]);
// 						}
// 						else
// 						{
// 							DecodeOneApplyMember_Ex(RptData, &pDA_arr->pSubDA[arr]);
// 						}
					}
				}
				else
				{
					ret = DecodeBasicTypeData_Ex(RptData, &pDA->pSubDA[k]);
				}

				k++;
			}

			if (k >= pDA->nSubDANum)
			{
				break;
			}
		}
	}
	else
	{
		while (TRUE)
		{
			memset( &asn1_head, 0, sizeof(tagasn1r_head) );
			headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);

			if ((headlength >0) && asn1_head.asn1r_element_id != 0x02)
			{
				*RptData -= headlength;
				ret = DecodeBasicTypeData_Ex(RptData, pDA);
				break;
			}
			else
			{
				*RptData += headlength;
			}
		}
	}

	return ret;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//修改备份
// ST_RET	DecodeOneApplyMember_Ex(ST_UCHAR **RptData, tagDA*pDA)
// {
// 	ST_INT		k=0;
// 	ST_INT		DecodeLevel=1;
// 	ST_UINT8	StartSign=0;
// 	ST_INT		headlength=0;
// 	tagasn1r_head asn1_head;
// 
// 	if (pDA == NULL)
// 		return SD_FAILURE;
// 
// 	if (pDA->pSubDA == NULL)
// 		return SD_FAILURE;
// 
// 	memset(&asn1_head, 0, sizeof(tagasn1r_head));
// 	headlength = dec_asn1_head(RptData, (tagasn1r_head*)&asn1_head);
// 	if (headlength <= 0)		
// 		return SD_FAILURE;
// 
// 	if ((headlength >0) && (asn1_head.asn1r_element_id != 0x02))
// 		*RptData -= headlength;
// 
// 	if (strstr(pDA->DataType,"STRUCT"))
// 	{
// 		for (k=0; k<pDA->nSubDANum; k++)
// 		{		
// 			memset( &asn1_head, 0, sizeof(tagasn1r_head) );
// 			headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);
// 
// 			if ((headlength >0) && asn1_head.asn1r_element_id != 0x02)
// 			{
// 				*RptData -= headlength;
// 				DecodeBasicTypeData_Ex(RptData, &pDA->pSubDA[k]);
// 				//DecodeOneApplyMember_Ex(RptData, &pDA->pSubDA[k]);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		memset( &asn1_head, 0, sizeof(tagasn1r_head) );
// 		headlength = dec_asn1_head( RptData, (tagasn1r_head*)&asn1_head);
// 
// 		if ((headlength >0) && asn1_head.asn1r_element_id != 0x02)
// 		{
// 			*RptData -= headlength;
// 			DecodeBasicTypeData_Ex(RptData, pDA);
// 		}
// 	}
// 	
// 	return SD_SUCCESS;
// }
//修改备份
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/************************************************************************************************/
/*Function Name:  DecodeYC_YX()																	*/
/*Input Parameter:pDSApplink: the point to tagDSAppLink											*/
/*				  RptData:	  the point to the data to be decoded								*/
/*				  DSMemIdx:   the No of DS member												*/
/*				  ACSIIdx:    the SN of pACSINode												*/
/************************************************************************************************/
//ST_INT DecodeYC_YX(tagDSAppLink *pDSApplink, ST_UCHAR **lpRptData, ST_INT DSMemIdx, ST_INT ACSIIdx)
//{
//	ST_INT SN=0;
//	SN = DecodeOneApplyMember( pDSApplink, lpRptData, DSMemIdx, ACSIIdx );
//	myprintf("YC_YX: SN=%d\n");
//	return SD_SUCCESS;
//}

ST_INT DecodeYC_YX_Ex(ST_UCHAR **lpRptData, tagDA *pDA)
{
	return DecodeOneApplyMember_Ex(lpRptData, pDA);
}

/***********************************************************************************************/
/*Function Name:  DecodeSOE()																   */
/*Input Parameter:pDSApplink: the point to tagDSAppLink										   */
/*				  RptData:	  the point to the data to be decoded							   */
/*				  DSMemIdx:   the No of DS member											   */
/*				  ACSIIdx:    the SN of pACSINode											   */
/***********************************************************************************************/
//ST_INT DecodeSOE(tagDSAppLink *pDSApplink, ST_UCHAR **RptData, ST_INT DSMemIdx, ST_INT ACSIIdx)
//{
//	ST_INT i=0,k=0;
//	ST_INT SN;
//	ST_INT EvIdx[MAX_EVENT_MEM];
//	tagSOERpt SOERpt;
//	ST_UCHAR  *RptBak;
//
//	memset(&SOERpt, 0, sizeof(tagSOERpt));
//	RptBak = *RptData;
//	memset( EvIdx, 0, MAX_EVENT_MEM*sizeof(ST_INT) );
//	if( pDSApplink->EventNum == 0 ){
//		myprintf("pDSApplink->EventNum evaluate error\n");
//		return SD_FAILURE;
//	}
//
//	while(1){
//		if( i > pDSApplink->EventNum ){
//			myprintf("EventIndx evaluate error\n");
//			return SD_FAILURE;
//		}
//		if( (pDSApplink->EventIndx[i][0] - 1) == DSMemIdx ){
//			memcpy(EvIdx, pDSApplink->EventIndx[i], MAX_EVENT_MEM);
//			break;
//		}
//		i++;
//	}
//
//	while( EvIdx[k] != 0 && EvIdx[k] < MAX_DA_VMD )
//	{
//		if( pDSApplink->ApplyType[ EvIdx[k]-1 ] == 2 )
//		{
//			memcpy( SOERpt.FCDName, pDSApplink->mmsVARName[ EvIdx[k]-1 ], NAMESIZE );
//			k += 1;
//			continue;
//		}
//		else if( pDSApplink->ApplyType[ EvIdx[k]-1 ] == 0 )
//		{
//			*RptData = RptBak;
//			SN = DecodeOneApplyMember( pDSApplink, RptData, (EvIdx[k]-1), ACSIIdx );
//			myprintf("SOE: SN=%d\n", SN );
//			if( (SN >= 0) && (strstr( pDSApplink->mmsVARName[EvIdx[k]-1], "$stVal") != NULL) )
//				SOERpt.stat = pACSINode[ACSIIdx].DA[SN].Value.i;
//			if( (SN >= 0) && (strstr( pDSApplink->mmsVARName[EvIdx[k]-1], "$t") != NULL) ){
//				Convert_UTC_To_BCD( (tagEVENTTIME*)&(SOERpt.t), (pACSINode[ACSIIdx].DA[SN].Value.utctime) );
//			}
//			k += 1;
//			continue;
//		}
//		else{
//			myprintf("SOE ApplyType evaluate error! \n");
//			return SD_FAILURE;
//		}
//	}
//
//	/* Add SOE to the SOE FIFO */
//	if( (ReasonCode[DSMemIdx] != 0x40) && (ReasonCode[DSMemIdx] != 0x20) 
//		&& (ReasonCode[DSMemIdx] != 0x10) )
////	if( (ReasonCode[DSMemIdx] == 0x04) || (ReasonCode[DSMemIdx] == 0x02) )
//	{
//		myprintf("SOE reasoncode is GI or IntegPd\n");
//		return SD_SUCCESS;
//	}
//	gs_mutex_get(&gs_soe_mutex);
//	if(pSOEFIFO->numSOE < MAX_SOE_RPT){
//		_snprintf(&pSOEFIFO->SoeRPT[pSOEFIFO->writep%MAX_SOE_RPT][0],
//        118,
//		"%s-状态值%d----%d年%d月%d日 %d时%d分%d秒%d毫秒",
//		SOERpt.FCDName,
//		SOERpt.stat,
//		SOERpt.t.year,
//		SOERpt.t.month,
//		SOERpt.t.day,
//		SOERpt.t.hour,
//		SOERpt.t.minute,
//		SOERpt.t.second,
//		SOERpt.t.ms
//		);
//		pSOEFIFO->numSOE++;
//	    pSOEFIFO->writep =  (pSOEFIFO->writep+1)%MAX_SOE_RPT;
//	}
//	gs_mutex_free(&gs_soe_mutex);
//	return SD_SUCCESS;
//}

ST_RET DecodeSOE_Ex(ST_UCHAR **RptData, tagDA *pDA)
{
	ST_INT i=0,k=0;
	ST_INT EvIdx[MAX_EVENT_MEM];
	tagSOERpt SOERpt;
	ST_UCHAR  *RptBak;

	memset(&SOERpt, 0, sizeof(tagSOERpt));
	RptBak = *RptData;
	memset( EvIdx, 0, MAX_EVENT_MEM*sizeof(ST_INT) );
	//if (pDA->EventNum == 0)
	//	return SD_FAILURE;

	//while(1)
	//{
	//	if (i>pDA->EventNum)
	//	{
	//		return SD_FAILURE;
	//	}

 //		if ((pDSApplink->EventIndx[i][0] - 1) == DSMemIdx)
 //		{
 //			memcpy(EvIdx, pDSApplink->EventIndx[i], MAX_EVENT_MEM);
 //			break;
 //		}

	//	i++;
	//}

	//while (EvIdx[k] != 0 && EvIdx[k] < MAX_DA_VMD)
	//{
	//	if (pDSApplink->ApplyType[ EvIdx[k]-1 ] == 2)
	//	{
	//		memcpy( SOERpt.FCDName, pDSApplink->mmsVARName[ EvIdx[k]-1 ], NAMESIZE );
	//		k += 1;
	//		continue;
	//	}
	//	else if( pDSApplink->ApplyType[ EvIdx[k]-1 ] == 0 )
	//	{
	//		*RptData = RptBak;
	//		DecodeOneApplyMember_Ex( pDSApplink, RptData, pDA);

	//		if ((strstr( pDSApplink->mmsVARName[EvIdx[k]-1], "$stVal") != NULL))
	//			SOERpt.stat = pDA->Value.i;
	//		if ((strstr( pDSApplink->mmsVARName[EvIdx[k]-1], "$t") != NULL))
	//			Convert_UTC_To_BCD( (tagEVENTTIME*)&(SOERpt.t), (pDA->Value.utctime));

	//		k += 1;
	//		continue;
	//	}
	//	else
	//		return SD_FAILURE;
	//}

	///* Add SOE to the SOE FIFO */
	//if( (pDA->RptMsg.ReasonCode != 0x40) && (pDA->RptMsg.ReasonCode != 0x20) 
	//	&& (pDA->RptMsg.ReasonCode != 0x10) )
	//{
	//	return SD_SUCCESS;
	//}

	//gs_mutex_get(&gs_soe_mutex);

	//if (pSOEFIFO->numSOE < MAX_SOE_RPT)
	//{
	//	_snprintf(&pSOEFIFO->SoeRPT[pSOEFIFO->writep%MAX_SOE_RPT][0],
	//		118,
	//		"%s-状态值%d----%d年%d月%d日 %d时%d分%d秒%d毫秒",
	//		SOERpt.FCDName,
	//		SOERpt.stat,
	//		SOERpt.t.year,
	//		SOERpt.t.month,
	//		SOERpt.t.day,
	//		SOERpt.t.hour,
	//		SOERpt.t.minute,
	//		SOERpt.t.second,
	//		SOERpt.t.ms
	//		);
	//	pSOEFIFO->numSOE++;
	//	pSOEFIFO->writep =  (pSOEFIFO->writep+1)%MAX_SOE_RPT;
	//}

	//gs_mutex_free(&gs_soe_mutex);

	return SD_SUCCESS;
}

/************************************************************************************/
/*Function Name:  DecodeRelaySOE()													*/
/*Input Parameter:pDSApplink: the point to tagDSAppLink								*/
/*				  RptData:	  the point to the data to be decoded					*/
/*				  DSMemIdx:   the No of DS member									*/
/*				  ACSIIdx:    the SN of pACSINode									*/
/************************************************************************************/
//ST_INT DecodeRelaySOE(tagDSAppLink *pDSApplink, ST_UCHAR **RptData, ST_INT DSMemIdx,ST_INT ACSIIdx)
//{
//	ST_INT i=0,k=0,DSNo=0;
//	ST_INT SN;
//	ST_INT EvIdx[MAX_EVENT_MEM];
//	tagRELAYSOERpt RelaySOERpt;
//	ST_UCHAR *RptBak;
//
//	memset(&RelaySOERpt, 0, sizeof(tagRELAYSOERpt));
//	RptBak = *RptData;
//	memset(EvIdx, 0, MAX_EVENT_MEM*sizeof(ST_INT));
//
//	if( pDSApplink->EventNum == 0 ){
//		myprintf("pDSApplink->EventNum evaluate error\n");
//		return SD_FAILURE;
//	}
//
//	while(1){
//		if( i > pDSApplink->EventNum ){
//			myprintf("EventIndx evaluate error\n");
//			return SD_FAILURE;
//		}
//		if( ( pDSApplink->EventIndx[i][0] - 1 ) == DSMemIdx ){
//			memcpy(EvIdx, pDSApplink->EventIndx[i], MAX_EVENT_MEM);
//			break;
//		}
//		i++;
//	}
//
//	while( EvIdx[k] != 0)
//	{
//		if( pDSApplink->ApplyType[ EvIdx[k] - 1 ] == 3 ){
//			memcpy( RelaySOERpt.FCDName, pDSApplink->mmsVARName[ EvIdx[k] -1 ], NAMESIZE );
//			k += 1;
//			continue;
//		}
//		else if( pDSApplink->ApplyType[ EvIdx[k] - 1 ] == 0 ){
//			*RptData = RptBak;
//			SN = DecodeOneApplyMember( pDSApplink, RptData, (EvIdx[k] - 1), ACSIIdx );
//			if( (SN >= 0) && (strstr( pDSApplink->mmsVARName[EvIdx[k] - 1], "$general") != NULL) )
//				RelaySOERpt.general = pACSINode[ACSIIdx].DA[SN].Value.u;
//			if( (SN >= 0) && (strstr( pDSApplink->mmsVARName[EvIdx[k] - 1], "$t") != NULL) )
//				Convert_UTC_To_BCD( (tagEVENTTIME*)&(RelaySOERpt.t), pACSINode[ACSIIdx].DA[SN].DAValue.Value.utctime );
//			k += 1;
//			continue;
//		}
//		else{
//			myprintf(" Relay SOE ApplyType evaluate error! \n");
//			return SD_FAILURE;
//		}
//	}
//
//	DSNo = pDSApplink->Level[DSMemIdx][0] - 1;
//
//	/* Add SOE to the SOE FIFO */
//	if( (ReasonCode[DSNo] != 0x40) && (ReasonCode[DSNo] != 0x20) 
//		&& (ReasonCode[DSNo] != 0x10) )
//		return SD_SUCCESS;
//	gs_mutex_get(&gs_rlysoe_mutex);
//	if(pRLYSOEFIFO->numSOE < MAX_SOE_RPT){
//		_snprintf(&pRLYSOEFIFO->RelaySoeRPT[pRLYSOEFIFO->writep%MAX_SOE_RPT][0],
//        118, "%s-RelaySOE状态值%d----%d年%d月%d日 %d时%d分%d秒%d毫秒",
//		RelaySOERpt.FCDName,
//		RelaySOERpt.general,
//		RelaySOERpt.t.year,
//		RelaySOERpt.t.month,
//		RelaySOERpt.t.day,
//		RelaySOERpt.t.hour,
//		RelaySOERpt.t.minute,
//		RelaySOERpt.t.second,
//		RelaySOERpt.t.ms
//		);
//		pRLYSOEFIFO->numSOE++;
//	    pRLYSOEFIFO->writep =  (pRLYSOEFIFO->writep+1)%MAX_SOE_RPT;
//	}
//	gs_mutex_free(&gs_rlysoe_mutex);
//	return SD_SUCCESS;
//}

ST_RET DecodeRelaySOE_Ex(ST_UCHAR **RptData, tagDA *pDA)
{
	ST_INT i=0,k=0;
	tagRELAYSOERpt RelaySOERpt;
	ST_UCHAR *RptBak;

	if (pDA == NULL)
		return SD_FAILURE;

	memset(&RelaySOERpt, 0, sizeof(tagRELAYSOERpt));
	RptBak = *RptData;

	if (pDA->EventNum == 0)
		return SD_FAILURE;

	//while (EvIdx[k] != 0)
	//{
	//	if (pDA->ApplyType == 3)
	//	{
	//		memcpy(RelaySOERpt.FCDName, pDA->DAValue.mmsName, NAMESIZE);
	//		continue;
	//	}
	//	else if (pDA->ApplyType == 0)
	//	{
	//		*RptData = RptBak;
	//		SN = DecodeOneApplyMember_Ex(RptData, pDA);
	//		if ((strstr(, "$general") != NULL))
	//			RelaySOERpt.general = .Value.u;
	//		if ((strstr(, "$t") != NULL))
	//			Convert_UTC_To_BCD( (tagEVENTTIME*)&(RelaySOERpt.t), pDA->Value.utctime );

	//		k += 1;
	//		continue;
	//	}
	//	else
	//		return SD_FAILURE;
	//}

	///* Add SOE to the SOE FIFO */
	//if ((pDA->ReasonCode != 0x40) && (pDA->ReasonCode != 0x20) && (pDA->ReasonCode != 0x10))
	//	return SD_SUCCESS;

	//gs_mutex_get(&gs_rlysoe_mutex);

	//if (pRLYSOEFIFO->numSOE < MAX_SOE_RPT)
	//{
	//	_snprintf(&pRLYSOEFIFO->RelaySoeRPT[pRLYSOEFIFO->writep%MAX_SOE_RPT][0],
	//		118, "%s-RelaySOE状态值%d----%d年%d月%d日 %d时%d分%d秒%d毫秒",
	//		RelaySOERpt.FCDName,
	//		RelaySOERpt.general,
	//		RelaySOERpt.t.year,
	//		RelaySOERpt.t.month,
	//		RelaySOERpt.t.day,
	//		RelaySOERpt.t.hour,
	//		RelaySOERpt.t.minute,
	//		RelaySOERpt.t.second,
	//		RelaySOERpt.t.ms
	//		);
	//	pRLYSOEFIFO->numSOE++;
	//	pRLYSOEFIFO->writep =  (pRLYSOEFIFO->writep+1)%MAX_SOE_RPT;
	//}

	//gs_mutex_free(&gs_rlysoe_mutex);

	return SD_SUCCESS;
}

/********************************************************************************/
/*Function Name:  DecodeData()													*/
/*Input Parameter:DSIdx: the Index of DataSet									*/
/*				  *IncluData:point to the Report Inclusion						*/
/*				  DSVarNum:  the number of total DS member						*/
/*				  lpRptData: the point to the data to be decoded				*/
/*				  nACSI:     the SN of pACSINode								*/
/********************************************************************************/
//ST_INT DecodeData(tagDSAppLink *lpDSApplink, ST_UINT8 *IncluData, ST_INT DSVarNum,
//				  ST_UCHAR **lpRptData, ST_INT nACSI)
//{
//	ST_INT		i,k=0,level=0;
//	ST_INT		j=0;
//	ST_UINT8	DecodeLevel=1;
//	ST_UINT8	StartSign=0;
//	ST_INT		headlength=0;
//	ST_UCHAR	*offsetBak;
//	ST_UCHAR	*lpEntryDataEnd;
//	ST_UCHAR	*offset[MAX_DA_VMD];
//	tagasn1r_head asn1_head;
//
//	if( lpRptData == NULL ){
//		myprintf("RptData attemp to points to NULL!\n");
//		return SD_FAILURE;
//	}
//	if( DSVarNum == 0 ){
//		myprintf("DSVarNum=0 Break !\n");
//		return SD_FAILURE;
//	}
//	if( lpDSApplink->MemberNum < DSVarNum ){
//		myprintf("DS Member Num= %d, DSVarNum=%d, Evaluate the DS Member level error!\n",
//			lpDSApplink->MemberNum,DSVarNum);
//		return SD_FAILURE;
//	}
//
//	/* search the position of each DataSet member */
//	offsetBak = *lpRptData;
//	for(j=0; j<DSVarNum; j++)
//	{
//		if( BSTR_BIT_GET (IncluData, j) )
//		{
//			StartSign += 1;
//			if( StartSign == 1 )	offset[j] = offsetBak;
//			else
//			{
//				if( dec_asn1_head( lpRptData, (tagasn1r_head*)&asn1_head ) <= 0 )
//				{
//					myprintf("dec_asn1_head return value <= 0\n");
//					return SD_FAILURE;
//				}
//				offset[j] = *lpRptData + asn1_head.asn1r_elmnt_len;
//				*lpRptData += asn1_head.asn1r_elmnt_len;
//				memset( &asn1_head, 0, sizeof(tagasn1r_head) );
//			}
//		}
//	}
//
//	if( dec_asn1_head( lpRptData, (tagasn1r_head*)&asn1_head ) <= 0 )
//	{
//		myprintf("dec_asn1_head return value <= 0\n");
//		return SD_FAILURE;
//	}
//	*lpRptData += asn1_head.asn1r_elmnt_len;
//	lpEntryDataEnd = *lpRptData;
//	memset( &asn1_head, 0, sizeof(tagasn1r_head) );
//
//	*lpRptData = offsetBak;
//
//	/* decode each member */
//	for(i=0; i<DSVarNum; i++)
//	{
//		if( BSTR_BIT_GET (IncluData, i) )
//		{
//			for(j=0; j<lpDSApplink->MemberNum; j++)
//			{
//				if( lpDSApplink->Level[j][0] == i+1 )
//				{
//					switch(lpDSApplink->ApplyType[j])
//					{
//						case 1:
//							*lpRptData = offset[i];
//							DecodeYC_YX( lpDSApplink, lpRptData, j, nACSI );
//							break;
//						case 2:
//							*lpRptData = offset[i];
//							DecodeSOE( lpDSApplink, lpRptData, j, nACSI );
//							break;
//						case 3:
//							*lpRptData = offset[i];
//							DecodeRelaySOE( lpDSApplink, lpRptData, j, nACSI );
//							break;
//						default:
//							break;
//					}
//				}
//			}
//		}
//	}
//	*lpRptData = lpEntryDataEnd;
//	return SD_SUCCESS;
//}

ST_RET DecodeData_Ex(ST_UINT8 *IncluData, ST_INT *daindex, ST_INT daNum, ST_INT nVarNum, tagDA*pDA, ST_UCHAR **lpRptData, ST_UCHAR *pRptDataEnd)
{
	ST_INT ret = SD_SUCCESS;
	ST_INT		i,k=0;
	ST_INT		j=0;
	ST_UINT8	StartSign=0;
 
	ST_UCHAR	*offsetBak;
	ST_UCHAR	*lpEntryDataEnd;
	ST_UCHAR	*offset[MAX_DA_NUM];
	tagasn1r_head asn1_head;

	if (lpRptData == NULL)
		return SD_FAILURE;

	if (nVarNum == 0 || pDA == NULL)
		return SD_FAILURE;

	/* search the position of each DataSet member */
	offsetBak = *lpRptData;

	for (j=0; j<daNum; j++)
	{
		if (BSTR_BIT_GET (IncluData, j))
		{
			StartSign += 1;
			if (StartSign == 1)	
			{
				offset[j] = offsetBak;
			}
			else
			{
				if (dec_asn1_head(lpRptData, (tagasn1r_head*)&asn1_head) <= 0)
					return SD_FAILURE;

				offset[j] = *lpRptData + asn1_head.asn1r_elmnt_len;
				*lpRptData += asn1_head.asn1r_elmnt_len;
				memset( &asn1_head, 0, sizeof(tagasn1r_head) );
			}
		}
	}

	if (dec_asn1_head(lpRptData, (tagasn1r_head*)&asn1_head ) <= 0)
		return SD_FAILURE;

	*lpRptData += asn1_head.asn1r_elmnt_len;
	lpEntryDataEnd = *lpRptData;
	memset( &asn1_head, 0, sizeof(tagasn1r_head) );

	*lpRptData = offsetBak;

	/* decode each member */
	for (i=0; i<daNum; i++)
	{
		if (ret != SD_SUCCESS)
		{
			break;
		}

		if (daindex[i]==1)
		{
			if (BSTR_BIT_GET(IncluData, i))
			{
				switch(pDA[i].ApplyType)
				{
				case 0://zhouhj20180607 增加对数据变化上送的特殊处理
					*lpRptData = offset[i];
					ret = DecodeYC_YX_Ex(lpRptData, &pDA[i]);
					break;
				case 1:
					*lpRptData = offset[i];
					ret = DecodeYC_YX_Ex(lpRptData, &pDA[i]);
					break;
				case 2:
					*lpRptData = offset[i];
// 					DecodeSOE_Ex(lpRptData, &pDA[i]);
					ret = DecodeYC_YX_Ex(lpRptData, &pDA[i]);
					break;
				case 3:
					*lpRptData = offset[i];
// 					DecodeRelaySOE_Ex(lpRptData, &pDA[i]);
					ret = DecodeYC_YX_Ex(lpRptData, &pDA[i]);
					break;
				default:
					break;
				}
			}
		}
	}

	*lpRptData = lpEntryDataEnd;

	return ret;
}