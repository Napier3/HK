#pragma once

#include "../SttClientSocketBase.h"
#include <QTcpSocket>

class CSttClientSocket : public QObject, public CSttClientSocketBase
{
    Q_OBJECT
public:
	CSttClientSocket();
	virtual ~CSttClientSocket();

    QTcpSocket *m_pSocket;
    bool m_bConnectSucc;

public:
        virtual BOOL ConnectServer(const char *pszIP, int nPort);
        virtual BOOL ConnectServer(const CString &strIPServer,long nPort);
    void CloseSocket();

	virtual long ReceiveBuffer(BYTE *pBuf, long nLen);
	virtual long SendBuffer(BYTE *pBuf, long nLen);

public slots:
    void Connected_Qt();
    void CloseSocket_Qt();
    void ReceiveBuffer_Qt();
    void OnError(QAbstractSocket::SocketError);

};

