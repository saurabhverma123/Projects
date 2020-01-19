#ifndef LOGDATA_H
#define LOGDATA_H
#include <QFile>

class LogData
{
public:
    LogData();
    void writeData(const QString&  data);
    void addHeader(const QString &argHeader);

private:

    QFile file;
    QString header;
};

#endif // LOGDATA_H
