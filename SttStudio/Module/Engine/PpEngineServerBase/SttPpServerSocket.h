#ifndef _SttPpTestServerSocket_H
#define _SttPpTestServerSocket_H

#include "../../SttSocket/TestServer/QT/SttTestServerSocket.h"


class CSttPpServerSocket : public CSttTestServerSocket
{
public:
	CSttPpServerSocket();
	virtual ~CSttPpServerSocket();
	
public:
	virtual CWinTcpSocketClient* CreateNewSocketClient();
};

#endif // _SttPpTestServerSocket_H
