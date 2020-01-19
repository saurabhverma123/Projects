#ifndef TELEMETRYMODEL_H
#define TELEMETRYMODEL_H

#include <QAbstractListModel>

class TelemetryModel : public QAbstractListModel
{
   Q_OBJECT

public:
   explicit TelemetryModel(QObject *parent = nullptr);

   // Basic functionality:
   int rowCount(const QModelIndex &parent = QModelIndex()) const override;

   QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

   enum TelemetryRoles {
      BarometricAltitudeRole = Qt::UserRole + 1,
      ChargeRole,
      HeadingRole,
      LatitudeRole,
      LongitudeRole,
      SignalStrengthRole
   };

private:
};

#endif // TELEMETRYMODEL_H
