#ifndef _RPTDECODEH
#define _RPTDECODEH

#include "asn1r.h"
#include "sharemem.h"

#define   MAX_YC		8000
#define   MAX_YX		8000
#define   MAX_YM		2000

#define   MAX_LEVEL		23

#define   DEVICE_STAT_UNUSED	0	/*不通*/
#define   DEVICE_STAT_NORMAL	1	/*正常*/
#define   DEVICE_STAT_ERROR		2	/*通、不正常*/

#define	  MAX_EVENT		1000
#define	  MAX_EVENT_MEM	20
#define   MAX_DSMEMBER  1000
extern ST_UCHAR ReasonCode[MAX_DSMEMBER];

typedef struct
{
	ST_INT		year;
	ST_INT		month;
	ST_INT		day;
	ST_INT		hour;
	ST_INT		minute;
	ST_INT		second;
	ST_INT		ms;
}tagEVENTTIME;

typedef struct
{
	ST_INT		dwInteger;
	ST_INT		dwFraction;
	ST_CHAR		tQuality;
}tagTimeStamp;

typedef struct
{
	ST_CHAR		FCDName[NAMESIZE];
	ST_INT		stat;	/*0-分 1-合 2-异常*/
	tagEVENTTIME	t;
}tagSOERpt;

typedef struct
{
	ST_CHAR		FCDName[NAMESIZE];
	ST_INT		general;
	ST_INT		isDirection;	/*1-方向 0-非方向*/
		/*0-接地 1-A相故障 2-B相故障 3-C相故障 4-AB相故障 5-CA相故障 6-BC相故障 7-ABC相故障*/
	ST_INT		fault;
		/*0-中线故障方向 1-A相故障方向 2-B相故障方向 3-C相故障方向 4-双向*/
	ST_INT		direction;
	tagEVENTTIME	t;
}tagRELAYSOERpt;

typedef struct
{
	ST_INT	EventNum;
	ST_CHAR	DSName[NAMESIZE];
	ST_INT	MemberNum;
	ST_CHAR mmsVARName[MAX_DA_VMD][NAMESIZE];
	ST_INT	Level[MAX_DA_VMD][LEVELSIZE];
	ST_INT	SN_DA[MAX_DA_VMD];
	ST_CHAR DataType[MAX_DA_VMD][10];		/*INT, BOOL 等*/
	ST_INT	ApplyType[MAX_DA_VMD];			/* 0-EventMember 1-YC/YX 2-SOE 3-RelaySOE ( 2、3 for FCD )*/
	ST_INT  EventIndx[MAX_EVENT][MAX_EVENT_MEM];
}tagDSAppLink;
extern tagDSAppLink struDSAppLink[];

typedef struct
{
	ST_UCHAR   asn1r_constr_element;/*是否构造类型 primitive or constructed */
	ST_UCHAR   asn1r_element_class;	/*type of tag: Bit7~5*/
	ST_UINT16  asn1r_element_id;	/*tagvalue：数据类型*/
	ST_INT	   asn1r_elmnt_len;		/*长度*/
	ST_BOOLEAN asn1r_indef_flag;	/*是否不定长类型*/
}tagasn1r_head;

/*cli_rpt_dec.c*/
//extern ST_VOID myprintf(char* fmt, ...);

extern ST_INT IsEvent( ST_CHAR *lpmmsVarName );
extern ST_VOID linkDS_DAMember_Ex(ST_INT numDA, tagDA *pDA);

extern ST_INT DifEventFromVar( ST_INT DSIndex, ST_INT NumDSMember);
extern ST_INT DifEventFromVar_Ex(tagDA *pDA, ST_INT *daindex, ST_INT numVar, ST_INT nDANum);

extern ST_VOID Convert_UTC_To_BCD(tagEVENTTIME* lpTimeBCD, MMS_UTC_TIME UTCTime);
extern ST_INT DecodeReasonCode( ST_INT *daindex, ST_INT DSVarNum, ST_UCHAR **lpReasonData, ST_INT RptNum);
extern ST_INT dec_asn1_head( ST_CHAR **lpRptData_temp, tagasn1r_head* asn1_head_point );

extern ST_INT asn1r_dec_bool( ST_CHAR **lpRptData_temp, ST_INT Length,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx );
extern ST_VOID asn1r_dec_bool_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA);

extern ST_INT asn1r_dec_integer (ST_CHAR **lpRptData_temp, ST_INT Length,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx );
extern ST_VOID asn1r_dec_integer_Ex (ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA);

extern ST_INT asn1r_dec_UINT( ST_CHAR **lpRptData_temp, ST_INT Length,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx );
extern ST_VOID asn1r_dec_UINT_Ex(ST_CHAR **lpRptData_temp, ST_INT Length,tagDA*pDA);

extern ST_INT asn1r_dec_Bitstring(ST_CHAR **lpRptData_temp, ST_INT Length, ST_INT Max_Bits,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx );
extern ST_VOID asn1r_dec_Bitstring_Ex(ST_CHAR **lpRptData_temp, ST_INT Length, ST_INT Max_Bits,tagDA*pDA);

extern ST_VOID CharStrToBinaryStr( char *pucCharStr, int iSize,  char *pszHexStr);

extern ST_INT asn1r_dec_UTC( ST_CHAR **lpRptData_temp, tagDSAppLink *pDSAppLK,
						ST_INT DSMemIdx, ST_INT ACSIIdx);
extern ST_VOID asn1r_dec_UTC_Ex( ST_CHAR **lpRptData_temp, tagDA*pDA);

extern ST_INT asn1r_dec_float( ST_CHAR **lpRptData_temp, ST_INT Length,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx );
extern ST_VOID asn1r_dec_float_Ex( ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA );

extern ST_INT asn1r_dec_double( ST_CHAR **lpRptData_temp, ST_INT Length,
						tagDSAppLink *pDSAppLK, ST_INT DSMemIdx, ST_INT ACSIIdx );
extern ST_VOID asn1r_dec_double_Ex( ST_CHAR **lpRptData_temp, ST_INT Length, tagDA*pDA );

/* Client_SCADA.c */
extern ST_ULONG ShareMem_gSOERpt();
extern ST_ULONG ShareMem_gRelaySOERpt();

extern ST_INT DecodeBasicTypeData(ST_CHAR **pRptData_tmp, tagDSAppLink *lpDSApplk,ST_INT DSMemIndex, ST_INT nACSIIdx);
extern ST_RET DecodeBasicTypeData_Ex( ST_CHAR **pRptData_tmp, tagDA *pDA);

extern ST_INT DecodeYC_YX(tagDSAppLink *pDSApplink, ST_UCHAR **RptData, ST_INT DSMemIdx, ST_INT ACSIIdx);
extern ST_INT DecodeYC_YX_Ex(ST_UCHAR **lpRptData, tagDA *pDA);

extern ST_INT DecodeSOE(tagDSAppLink *pDSApplink, ST_UCHAR **RptData, ST_INT DSMemIdx, ST_INT ACSIIdx);
extern ST_RET DecodeSOE_Ex(ST_UCHAR **RptData, tagDA *pDA);

extern ST_INT DecodeRelaySOE(tagDSAppLink *pDSApplink, ST_UCHAR **RptData, ST_INT DSMemIdx, ST_INT ACSIIdx);
extern ST_RET DecodeRelaySOE_Ex(ST_UCHAR **RptData, tagDA *pDA);		

extern ST_INT DecodeData(tagDSAppLink *lpDSApplink, ST_UINT8 *IncluData, ST_INT DSVarNum, ST_UCHAR **lpRptData, ST_INT nACSI);
extern ST_RET DecodeData_Ex(ST_UINT8 *IncluData, ST_INT *daindex, ST_INT daNum, ST_INT nVarNum, tagDA *pDA, ST_UCHAR **lpRptData, ST_UCHAR *pRptDataEnd);

extern ST_INT DecodeOneApplyMember(tagDSAppLink *pDSApplink, ST_UCHAR **RptData, ST_INT DSMemIdx, ST_INT nACSIIdx);
extern ST_RET DecodeOneApplyMember_Ex(ST_UCHAR **RptData, tagDA*pDA);
//extern double GeCurrTime_double();
extern ST_VOID GeCurrTime_double(double *pdTime,int *pnTmMs);//zhouhj 20200113

#endif