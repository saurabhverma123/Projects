#ifndef WSCLIENT_H
#define WSCLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include "TelemetryData.h"

struct WSClientData;

class WSClient : public QObject
{
    Q_OBJECT

public:
    WSClient(const QString& address = "ws://localhost:10001");
    ~WSClient();

    void connectWebSocketServer();
    void disconnectWebSocketServer();

    // use writeMessage to send command to telemetryServer
    Q_INVOKABLE void writeMessage(const QString &message);
    QObject* getTelemetryData();


private slots:
    void onStateChanged(QAbstractSocket::SocketState state);

    // receives the telemetry in JSON string format inside this slot
    void onMessageReceived(const QString &text);

private:
    WSClientData *d;
    TelemetryData telemetryData;
};

#endif // WSCLIENT_H
