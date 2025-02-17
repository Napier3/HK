#include "stdafx.h"

#include "SttClientSocket.h"
#include "../../../Engine/SttTestEngineBase.h"
#include "QHostAddress"


CSttClientSocket::CSttClientSocket()
{
qDebug() << "debug sun: CSttClientSocket::CSttClientSocket() constructor";
}

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
    qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  created";
    m_pSocket = new QTcpSocket(this);
    qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  1";
    connect(m_pSocket,SIGNAL(connected()),this,SLOT(Connected_Qt()));
    //connect(m_pSocket,SIGNAL(error(QAbstractSocket::SocketError))),this,SLOT(OnError(QAbstractSocket::SocketError));
    m_pSocket->connectToHost(QHostAddress(pszIP), nPort);
qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  2";
    m_strIPRemote = pszIP;
    m_nPortRemote = nPort;
qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  3";
    return TRUE;
}

BOOL CSttClientSocket::ConnectServer(const CString &strIPServer,long nPort)
{
    qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  created";
    m_pSocket = new QTcpSocket(this);
    qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  1";
    connect(m_pSocket,SIGNAL(connected()),this,SLOT(Connected_Qt()));
    //connect(m_pSocket,SIGNAL(error(QAbstractSocket::SocketError))),this,SLOT(OnError(QAbstractSocket::SocketError));
    m_pSocket->connectToHost(QHostAddress(strIPServer), nPort);
qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  2";
    m_strIPRemote = strIPServer;
    m_nPortRemote = nPort;
qDebug() << "debug sun:  BOOL CSttClientSocket::ConnectServer(const char *pszIP, int nPort)  3";
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
     qDebug() << "debug sun:  long CSttClientSocket::SendBuffer  1";
    stt_pkg_set_send_index(pBuf, m_nSendIndex++);
    qDebug() << "debug sun:  long CSttClientSocket::SendBuffer  2";
    if(!m_pSocket)
    {
        qDebug() << "debug sun:  long CSttClientSocket::SendBuffer  m_pSocket is nullllllllllllllllllllptrrrrrrrrrrrrrrr";
    }
    int nRet=m_pSocket->write((const char*)pBuf,nLen);
    qDebug() << "debug sun:  long CSttClientSocket::SendBuffer  3";
    return nRet;
}
