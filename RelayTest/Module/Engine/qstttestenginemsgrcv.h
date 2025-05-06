#ifndef QSTTTESTENGINEMSGRCV_H
#define QSTTTESTENGINEMSGRCV_H

#include <QObject>

class QSttTestEngineMsgRcv : public QObject
{
    Q_OBJECT

public:
    static long g_nObjRefCount;
    static QSttTestEngineMsgRcv *g_pSttTestEngineMsgRcv;

    static void Create();
    static void Release();

    static void emit_OnTestMsg(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen);

private:
    explicit QSttTestEngineMsgRcv(QObject *parent = nullptr);
    void in_emit_OnTestMsg(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen);


signals:
    void sig_OnTestMessage(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen);

public slots:
    void slot_OnTestMessage(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen);

};

#endif // QSTTTESTENGINEMSGRCV_H
