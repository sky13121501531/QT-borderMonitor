
#include "qttcpsocekt.h"
#define TIMER_TIMEOUT   (300)
XSocketClient::XSocketClient(QObject *parent)
{
}
XSocketClient::~XSocketClient()
{
    if(nullptr != m_pClientSocket)
    {
        m_pClientSocket->deleteLater();
    }
}
void XSocketClient::SetAcceptSocket(QTcpSocket *pSocket)
{
    m_pClientSocket = pSocket;
    InitClientSocket(m_pClientSocket);
}
QByteArray XSocketClient::utf8ToGb2312(QByteArray strUtf8)
{
    QTextCodec* utf8Codec= QTextCodec::codecForName("utf-8");
    QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");

    string stdString(strUtf8.constData(), strUtf8.length());
    QString strUnicode= utf8Codec->toUnicode(stdString.c_str());
    QByteArray ByteGb2312= gb2312Codec->fromUnicode(strUnicode);

    return ByteGb2312;//注意这里要fromLocal8Bit()
}
int XSocketClient::ConnectTo(QString ip, quint16 port,QByteArray by,int timeout)
{
    if(nullptr == m_pClientSocket)
    {
        m_pClientSocket = new QTcpSocket(this);
    }
    InitClientSocket(m_pClientSocket);
    m_pClientSocket->connectToHost(QHostAddress(ip), port);
    if (m_pClientSocket->waitForConnected(timeout))
    {              
        QByteArray tmpby = utf8ToGb2312(by);
        if(!SendData(tmpby))
        {
            return ERROR_SEND;
        }
        else
        {
            qDebug()<<"成功发送数据:"<<by;
            return ERROR_NO;
        }
    }
    else
    {
        return ERROR_CONNECT;
    }
}
bool XSocketClient::IsConnected()
{
    bool bre = false;
    if(nullptr != m_pClientSocket)
    {
        bre = (m_pClientSocket->state() == QTcpSocket::ConnectedState);
    }
    return bre;
}
bool XSocketClient::SendData(QByteArray by)
{
    bool bre = false;
    if(nullptr != m_pClientSocket)
    {
        bre = (by.size() == m_pClientSocket->write(by));
    }
    return bre;
}

int XSocketClient::read(int timeout)
{
    if(m_pClientSocket->waitForReadyRead(timeout))
    {
        return ERROR_NO;
    }
    else
    {
        return ERROR_RECV_TIMEOUT;
    }
}

QTcpSocket *XSocketClient::GetSocket()
{
    return m_pClientSocket;
}
void XSocketClient::OnDataReady()
{
    QTcpSocket *pSocket = qobject_cast<QTcpSocket*>(sender());
    if(nullptr != pSocket)
    {
        recvData = pSocket->readAll();
        emit signalOnReceiveData(recvData);
        OnData(recvData);
        qDebug()<<"成功接收数据:"<<recvData;
    }
}
void XSocketClient::OnConnected()
{
    //QTcpSocket *pSocket = qobject_cast<QTcpSocket*>(sender());
}

void XSocketClient::OnDisconnected()
{
    //QTcpSocket *pSocket = qobject_cast<QTcpSocket*>(sender());
}
void XSocketClient::InitClientSocket(QTcpSocket *pSocket)
{
    if(nullptr != pSocket)
    {
        connect(pSocket, SIGNAL(readyRead()),this ,SLOT(OnDataReady()));
        connect(pSocket, SIGNAL(connected()), this ,SLOT(OnConnected()));
        connect(pSocket, SIGNAL(disconnected()), this ,SLOT(OnDisconnected()));
        connect(pSocket, SIGNAL(connected()), this ,SIGNAL(signalOnConnected()));
        connect(pSocket, SIGNAL(disconnected()), this ,SIGNAL(signalOnDisconnected()));
    }
}
