#ifndef TELEMETRYDATA_H
#define TELEMETRYDATA_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include "logdata.h"

class TelemetryData : public QObject
{
   Q_OBJECT

private:
    Q_PROPERTY(qreal qbarometricAltitude MEMBER barometricAltitude NOTIFY qbarometricAltitudeChanged)
    Q_PROPERTY(qreal qcharge MEMBER charge NOTIFY qchargeChanged)
    Q_PROPERTY(qreal qheading MEMBER heading NOTIFY qheadingChanged)
    Q_PROPERTY(qreal qlatitude MEMBER latitude NOTIFY qlatitudeChanged)
    Q_PROPERTY(qreal qlongitude MEMBER longitude NOTIFY qlongitudeChanged)
    Q_PROPERTY(qreal qsignalStrength MEMBER signalStrength NOTIFY qsignalStrengthChanged)
    Q_PROPERTY(QString urlStr READ getUrlStr WRITE setUrlStr NOTIFY urlStrChanged)

public:
   TelemetryData();
   void setMessage(const QString &text);
   void printData() const;
   QString getUrlStr() const;
   void setUrlStr(const QString& url);

Q_SIGNALS:
    void qbarometricAltitudeChanged(qreal barometricAltitude);
    void qchargeChanged(qreal charge);
    void qheadingChanged(qreal heading);
    void qlatitudeChanged(qreal latitude);
    void qlongitudeChanged(qreal longitude);
    void qsignalStrengthChanged(qreal signalStrength);
    void urlStrChanged(QString newVal);

private:
   void parserMessage();
   void logTelemetryData();
   QString stringMessage;

   double barometricAltitude{};
   double charge{};
   double heading{};
   double latitude{};
   double longitude{};
   double signalStrength{};

   static const QString urlPrefix;
   QString urlStr{};
   LogData logData{};
};

#endif // TELEMETRYDATA_H
