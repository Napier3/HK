#include "qstttestenginemsgrcv.h"
#include "SttTestEngineBase.h"


long QSttTestEngineMsgRcv::g_nObjRefCount = 0;
QSttTestEngineMsgRcv* QSttTestEngineMsgRcv::g_pSttTestEngineMsgRcv = 0;

void QSttTestEngineMsgRcv::Create()
{
    g_nObjRefCount++;

    if (g_nObjRefCount == 1)
    {
        g_pSttTestEngineMsgRcv = new QSttTestEngineMsgRcv();
    }
}

void QSttTestEngineMsgRcv::Release()
{
    g_nObjRefCount--;

    if (g_nObjRefCount == 0)
    {
        delete g_pSttTestEngineMsgRcv;
        g_pSttTestEngineMsgRcv = 0;
    }
}

void QSttTestEngineMsgRcv::emit_OnTestMsg(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen)
{
    g_pSttTestEngineMsgRcv->in_emit_OnTestMsg(pEngine, pClientSocket, pPkgBuf, nLen);
}

void QSttTestEngineMsgRcv::in_emit_OnTestMsg(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen)
{
    emit sig_OnTestMessage(pEngine, pClientSocket, pPkgBuf, nLen);
}

QSttTestEngineMsgRcv::QSttTestEngineMsgRcv(QObject *parent) : QObject(parent)
{
    connect(this
            , SIGNAL(sig_OnTestMessage(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen))
            ,this
            , SLOT(slot_OnTestMessage(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen))
            );//,Qt::QueuedConnection);
}

#include <QDebug>
void QSttTestEngineMsgRcv::slot_OnTestMessage(void *pEngine, void *pClientSocket, char *pPkgBuf, long nLen)
{
    qDebug() << "slot_OnTestMessage";

    CSttTestEngineBase *p = (CSttTestEngineBase*)pEngine;
    p->Call_OnTestMsg((CSttXcmdChInterface*)pClientSocket, (unsigned char*) pPkgBuf, nLen);
    delete pPkgBuf;
}

