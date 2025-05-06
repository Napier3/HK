#include "stdafx.h"
#include "SttProtocolBufBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSttProtocolBufBase::CSttProtocolBufBase()
{
	m_nSendIndex = 0;
	m_nRecvIndex = 0;
	m_nPortLocal = 0;
	m_nPortRemote = 0;

	m_oExpandRecvBuf.AllocBuffer();
}

CSttProtocolBufBase::~CSttProtocolBufBase()
{

}
#include <QDebug>
void CSttProtocolBufBase::OnReceiveBuffer(BYTE *pBuf, long nLen)
{
	if (nLen <= 0)
	{
		return;
	}
    //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
	m_oExpandRecvBuf.AppendBuffer(pBuf,nLen);
    //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
	AnalysisRecvBuf();
    //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
}
#include <QDebug>
BOOL CSttProtocolBufBase::AnalysisRecvBuf()
{
	BYTE *pTemp = (BYTE *)m_oExpandRecvBuf.GetDataBuffer();
	long nDataLen = m_oExpandRecvBuf.GetDataLength();
	long nReadPos = 0;
	long nPkgDataLen = 0;
	long nPkgLen = 0;
	BOOL bSucc = TRUE;
    //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
	while(nDataLen - nReadPos >= STT_PKG_HEAD_LEN)
	{
		if(!stt_pkg_match_head(pTemp))
		{
			nReadPos += 1;
			pTemp += 1;
            //for debug
           // CLogPrint::LogFormatString(XLOGLEVEL_DEBUG,_T("解析报文头出错【nReadPos=%d】"), nReadPos);
            //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
			continue;//
		}

		nPkgDataLen = stt_pkg_get_data_len(pTemp);
		if (nPkgDataLen < 0 || nPkgDataLen > 33554432)
		{
            CLogPrint::LogFormatString(XLOGLEVEL_DEBUG,_T("解析数据长度出错【nPkgDataLen=%d】"),nPkgDataLen);
			nReadPos += 2;
			pTemp += 2;
            //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
			continue;//
		}
		nPkgLen = nPkgDataLen + STT_PKG_HEAD_LEN;
		
		if (nPkgLen > nDataLen - nReadPos)
		{//余下的报文长度不够一个完整的报文
            //for debug
//             CLogPrint::LogFormatString(XLOGLEVEL_DEBUG,_T("余下的报文长度不够一个完整的报文【nPkgLen=%d   nDataLen=%d   nReadPos=%d】")
//                                        , nPkgLen, nDataLen, nReadPos);//zhouhj 20220713 软件发布 删除此打印信息
            //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
            break;
		}
        //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
		m_nRecvIndex = stt_pkg_get_send_index(pTemp);
		memcpy(m_pRecvPkgHead, pTemp, STT_PKG_HEAD_LEN);
        //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
		ProcessRecvPacket(pTemp, nPkgLen);
        //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
		nReadPos += nPkgLen;
		pTemp += nPkgLen ;
	}

	//非完整包数据移到缓存开头
	m_oExpandRecvBuf.PosMoveByUsedLen(nReadPos);

	return TRUE;
}

void stt_InitPktBuffer_Head(BYTE *pPkgBuffer,long nTypeCmd, long nDataLen, DWORD nIDTester, long nSendIndex, BYTE bCompress)
{
	stt_pkg_set_head(pPkgBuffer);
	stt_pkg_set_cmd_type(pPkgBuffer, (BYTE)nTypeCmd);
	stt_pkg_set_idtester(pPkgBuffer, nIDTester);
	stt_pkg_set_send_index(pPkgBuffer, nSendIndex);
	//	stt_pkg_set_compress(pPkgBuffer, bCompress);

	stt_pkg_set_data_len_cmd_other(pPkgBuffer, nDataLen);
}
