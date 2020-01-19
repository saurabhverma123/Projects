#include "TelemetryData.h"
#include <QDebug>
#include <math.h>

const QString TelemetryData::urlPrefix = "https://www.google.com/maps/place/";
TelemetryData::TelemetryData() : urlStr(urlPrefix)
{
    QString header("Altitude,Charge,Heading,Latitide,Longitiude,Signal\n");
    logData.addHeader(header);
}

void TelemetryData::setMessage(const QString &text)
{
   stringMessage = text;
   parserMessage();
}

void TelemetryData::parserMessage()
{
   QJsonDocument jsonResponse = QJsonDocument::fromJson(stringMessage.toUtf8());
   QJsonObject jsonObject = jsonResponse.object();
   double oldLatitude{latitude};
   double oldLongitude{longitude};
   barometricAltitude = jsonObject["barometricAltitude"].toDouble();
   emit qbarometricAltitudeChanged(barometricAltitude);
   charge = jsonObject["charge"].toDouble();
   emit qchargeChanged(charge);
   heading = jsonObject["heading"].toDouble();
   emit qheadingChanged(heading);
   latitude = jsonObject["latitude"].toDouble();
   emit qlatitudeChanged(latitude);
   longitude = jsonObject["longitude"].toDouble();
   emit qlongitudeChanged(longitude);
   signalStrength = jsonObject["signalStrength"].toDouble();
   emit qsignalStrengthChanged(signalStrength);

   double changeInPosition = latitude + longitude - oldLongitude - oldLatitude;
   // loading the maps only when there is a delta of more than 0.00001 in position
   if (fabs(changeInPosition) > 0.00001)
      setUrlStr(urlStr);
   logTelemetryData();
//   printData();
}

QString TelemetryData::getUrlStr() const
{
   return urlStr;
}

void TelemetryData::setUrlStr(const QString& url)
{
   Q_UNUSED(url)
   urlStr = urlPrefix + QString("%1").arg(latitude) + QString(",") + QString("%1").arg(longitude);
   emit urlStrChanged(urlStr);
}

void TelemetryData::logTelemetryData()
{
    QString data = QString("%1").arg(barometricAltitude) + QString(",");
    data += QString("%1").arg(charge) + QString(",");
    data += QString("%1").arg(heading) + QString(",");
    data += QString("%1").arg(latitude) + QString(",");
    data += QString("%1").arg(longitude) + QString(",");
    data += QString("%1").arg(signalStrength) + QString("\n");
    logData.writeData(data);
}

void TelemetryData::printData() const
{
   qDebug() << "barometricAltitude: " << barometricAltitude;
   qDebug() << "charge: " << charge;
   qDebug() << "heading: " << heading;
   qDebug() << "latitude: " << latitude;
   qDebug() << "longitude: " << longitude;
   qDebug() << "signalStrength: " << signalStrength;
   qDebug() << "----------------";
}

