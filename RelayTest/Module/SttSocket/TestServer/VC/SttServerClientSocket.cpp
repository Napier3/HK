#include "stdafx.h"
#include "SttServerClientSocket.h"

CSttServerClientSocket::CSttServerClientSocket()
{

}

CSttServerClientSocket::~CSttServerClientSocket()
{
	
}

void CSttServerClientSocket::OnReceive(int nErrorCode)
{
	OnReceiveBuffer(nErrorCode);
}

//判断是远程还是本地断链
void CSttServerClientSocket::OnClose(int nErrorCode)
{
	OnSocketClose(nErrorCode);
}

void CSttServerClientSocket::CloseSocket()
{
	Close();
}

long CSttServerClientSocket::ReceiveBuffer(BYTE *pBuf, long nLen)
{
	return 0;
}

long CSttServerClientSocket::SendBuffer(BYTE *pBuf, long nLen)
{
	return Send((char*)pBuf, nLen);
}

#include <QDebug>

long CSttServerClientSocket::OnReceive(BYTE *pRcvBuf, int iLen)
{
    //qDebug() << __FILE__ << __FUNCTION__ << __LINE__;
	OnReceiveBuffer(pRcvBuf, iLen);
	return 0;
}
