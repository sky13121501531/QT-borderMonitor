#ifndef XSOCKETCLIENT_H
#define XSOCKETCLIENT_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QTextCodec>
#include "externType.h"

class XSocketClient : public QObject
{
    Q_OBJECT
public:
    XSocketClient(QObject* parent = NULL);
    ~XSocketClient();
    //做为服务端接受连接时，设置接受的socket
    void SetAcceptSocket(QTcpSocket *pSocket);
    //做为客户端主动连接时使用
    int ConnectTo(QString ip, quint16 port,QByteArray by,int timeout=3000);
    bool IsConnected();
    bool SendData(QByteArray by);
    QByteArray utf8ToGb2312(QByteArray strUtf8);
    //string utf8ToGb2312(string strUtf8);
    int read(int timeout=30000);
    QTcpSocket *GetSocket();
    QByteArray GetRecvData() {
        return recvData;
    }
signals:
    void signalOnReceiveData(QByteArray by);
    void signalOnConnected();
    void signalOnDisconnected();
protected slots:
    virtual void OnData(QByteArray by){}
    virtual void OnConnected();
    virtual void OnDisconnected();
    void OnDataReady();

private:
    void InitClientSocket(QTcpSocket *pSocket);
private:
    QTcpSocket *m_pClientSocket = nullptr;
    QByteArray recvData;
};
#endif  //XSOCKETCLIENT_H
