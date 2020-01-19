import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
   visible: true
   width: 1500
   height: 870
   title: qsTr("WS Client")
   minimumWidth: 400
   minimumHeight: 600

   ColumnLayout {
      spacing: 20
      anchors.fill: parent
      width: parent.width
      Item {
         height: 10
      }
      TelemetryFrame {
         id: telemetryFrameId
         Layout.alignment: Qt.AlignHCenter
      }

      Item {
         height: 10
      }
      Maps{
         id: mapsId
         Layout.fillHeight: true
         Layout.preferredWidth: parent.width * 0.75
         Layout.preferredHeight: parent.height / 2
         Layout.alignment: Qt.AlignHCenter
      }
   }
}
