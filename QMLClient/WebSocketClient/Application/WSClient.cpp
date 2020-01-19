#include "WSClient.h"
#include "IComm.h"
#include "Communication.h"

#include <QWebSocket>

struct WSClientData
{
    WSClientData() :
        webSocketAddress("ws://localhost:10001"),
        webComm(0)
    {}

    QString webSocketAddress;
    Asteria::ICommAddendum1 *webComm;
};

WSClient::WSClient(const QString& address)
{
    d = new WSClientData;
    d->webSocketAddress = address;
}

WSClient::~WSClient()
{

}

void WSClient::connectWebSocketServer()
{
    if(d->webComm)
        this->disconnectWebSocketServer();

    d->webComm = dynamic_cast<Asteria::ICommAddendum1*>(
                Communication::instance().webComm(this));

    if(!d->webComm)
        return;

    connect(d->webComm->containerObject(),
            SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,
            SLOT(onStateChanged(QAbstractSocket::SocketState)));
    connect(d->webComm->containerObject(),
            SIGNAL(textReceived(QString)),
            this,
            SLOT(onMessageReceived(QString)));

    d->webComm->setAddress(d->webSocketAddress);
    d->webComm->start();
}

void WSClient::disconnectWebSocketServer()
{
    if(d->webComm)
    {
        d->webComm->stop();
        d->webComm->containerObject()->disconnect(0, 0, 0, 0);
        d->webComm->containerObject()->deleteLater();
        d->webComm = 0;
    }
}

void WSClient::writeMessage(const QString &message)
{
    qDebug() << "wsClient write: " << message;
    if(d->webComm)
        qDebug() << d->webComm->writeText(message);
}

void WSClient::onStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "\nWS state: " << state;
}

void WSClient::onMessageReceived(const QString &text)
{
    qDebug() << "\nTextReceived: " << text;
    telemetryData.setMessage(text);
}

QObject* WSClient::getTelemetryData()
{
    return &telemetryData;
}

