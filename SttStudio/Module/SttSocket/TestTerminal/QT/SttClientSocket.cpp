#include "stdafx.h"

#include "SttClientSocket.h"
#include "../../../Engine/SttTestEngineBase.h"
#include "QHostAddress"


CSttClientSocket::CSttClientSocket(){}

CSttClientSocket::~CSttClientSocket()
{
     disconnect(m_pSocket,SIGNAL(connected()),this,SLOT(Connected_Qt()));
    disconnect(m_pSocket,SIGNAL(disconnected()),this,SLOT(CloseSocket_Qt()));
    disconnect(m_pSocket,SIGNAL(readyRead()),this,SLOT(ReceiveBuffer_Qt()));
}

void CSttClientSocket::Connected_Qt()
{
    //sun g_pSttTestEngine->SetRefSocket(this);
    connect(m_pSocket,SIGNAL(disconnected()),this,SLOT(CloseSocket_Qt()));
    connect(m_pSocket,SIGNAL(readyRead()),this,SLOT(ReceiveBuffer_Qt()));
}

void CSttClientSocket::CloseSocket_Qt()
{
    //sun g_pSttTestEngine->CloseSocket(this);
}

void CSttClientSocket::ReceiveBuffer_Qt()
{
    OnReceiveBuffer(0);
}

void CSttClientSocket::OnError(QAbstractSocket::SocketError)
{//connect error
    CloseSocket();
}

BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)
{
    m_pSocket = new QTcpSocket(this);
    connect(m_pSocket,SIGNAL(connected()),this,SLOT(Connected_Qt()));
    m_pSocket->connectToHost(QHostAddress(pszIP), nPort);
    m_strIPRemote = pszIP;
    m_nPortRemote = nPort;
    return TRUE;
}

BOOL CSttClientSocket::ConnectServer(const CString &strIPServer,long nPort)
{
    m_pSocket = new QTcpSocket(this);
    connect(m_pSocket,SIGNAL(connected()),this,SLOT(Connected_Qt()));
    m_pSocket->connectToHost(QHostAddress(strIPServer), nPort);
    m_strIPRemote = strIPServer;
    m_nPortRemote = nPort;
    return TRUE;
}

void CSttClientSocket::CloseSocket()
{
    m_pSocket->close();
}

long CSttClientSocket::ReceiveBuffer(BYTE *pBuf, long nLen)
{
    long nRcvLen = m_pSocket->read((char*)pBuf, nLen);
    return nRcvLen;
}

long CSttClientSocket::SendBuffer(BYTE *pBuf, long nLen)
{
    stt_pkg_set_send_index(pBuf, m_nSendIndex++);
    if(!m_pSocket)
    {
    }
    int nRet=m_pSocket->write((const char*)pBuf,nLen);
    return nRet;
}
