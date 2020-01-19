#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtWebEngine>
#include "WSClient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QtWebEngine::initialize();

    WSClient *wsclient = new WSClient();
    wsclient->connectWebSocketServer();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("wsClient", wsclient);
    engine.rootContext()->setContextProperty("telemetryData", wsclient->getTelemetryData());

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
