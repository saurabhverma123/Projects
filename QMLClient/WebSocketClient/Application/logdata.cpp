#include "logdata.h"
#include <QDebug>

LogData::LogData() : file("TelemetryData.csv")
{
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "\nError in log file creation";
    else
    {
        file.close();
    }
}

void LogData::addHeader(const QString &argHeader)
{
    header = argHeader;
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(header.toStdString().c_str());
        file.close();
    }
}

void LogData::writeData(const QString&  data)
{
    if (file.size() > 100000)
    {
        addHeader(header);
    }
    if (file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append) )
    {

        file.write(data.toStdString().c_str());
        file.close();
    }
}

