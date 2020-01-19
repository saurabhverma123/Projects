//import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Frame{
   property int rectWidth: 415
   ColumnLayout {
      id: mainLayout
      anchors.fill: parent
      width: parent.width
      Layout.margins: 20
      RowLayout {
         id: rowLayoutBarometricAltitudeId
         //            anchors.fill: parent
         Layout.alignment: Qt.AlignHCenter
         Label{

            text: qsTr("Signal")
            Layout.fillWidth: true
         }
         Rectangle {
            width : rectWidth
            height: 40
            border.color: "black"
            Layout.alignment: Qt.AlignRight
            Text {
               anchors.centerIn: parent
               text: telemetryData ? telemetryData.qsignalStrength : "NA"
            }
         }
      }
      Item {
         height : 10
      }
      RowLayout {
         Label{
            Layout.fillWidth: true
            text: qsTr("Charge")
         }
         Rectangle {
            width : rectWidth
            height: 40
            border.color: "black"
            Text {
               anchors.centerIn: parent
               text: telemetryData ? telemetryData.qcharge : "NA"
            }
         }
      }
      Item {
         height : 10
      }
      RowLayout {
         Label{
            Layout.fillWidth: true
            text: qsTr("Latitude")
            fontSizeMode: fontSizeMode
         }
         Rectangle {
            width : rectWidth
            height: 40
            border.color: "black"
            Text {
               anchors.centerIn: parent
               text: telemetryData ? telemetryData.qlatitude : "NA"
            }
         }
      }
      Item {
         height : 10
      }
      RowLayout {
         Label{
            Layout.fillWidth: true
            text: qsTr("Longitude")
            fontSizeMode: fontSizeMode
         }
         Rectangle {
            width : rectWidth
            height: 40
            border.color: "black"
            Text {
               anchors.centerIn: parent
               text: telemetryData ? telemetryData.qlongitude : "NA"
            }
         }
      }
      Item {
         height : 10
      }
      RowLayout {
         Label{
            Layout.fillWidth: true
            text: qsTr("Altitude")
            fontSizeMode: fontSizeMode
         }
         Rectangle {
            width : rectWidth
            height: 40
            border.color: "black"
            Text {
               anchors.centerIn: parent
               text: telemetryData ? telemetryData.qbarometricAltitude : "NA"
            }
         }
      }
      Item {
         height : 10
      }
      RowLayout {
         Label{
            Layout.fillWidth: true
            text: qsTr("Heading")
            fontSizeMode: fontSizeMode
         }
         Rectangle {
            width : rectWidth
            height: 40
            border.color: "black"
            Text {
               anchors.centerIn: parent
               text: telemetryData ? telemetryData.qheading : "NA"
            }
         }
      }

      Item {
         height : 10
      }
      RowLayout{
         Label{
            Layout.fillWidth: true
            text: qsTr("Mode")
         }

         Button{
            width : rectWidth / 4
            height: 40
            text: qsTr("NAV")
            onClicked: wsClient.writeMessage("{“command”: “RTL”}")
         }
         Button{
            width : rectWidth / 4
            height: 40
            text: qsTr("LTR")
            onClicked: wsClient.writeMessage("{“command”: “LTR”}")
         }
         Button{
            width : rectWidth / 4
            height: 40
            text: qsTr("LND")
            onClicked: wsClient.writeMessage("{“command”: “LND”}")
         }
         Button{
            width : rectWidth / 4
            height: 40
            text: qsTr("RTL")
            onClicked: wsClient.writeMessage("{“command”: “RTL”}")
         }
      }
   }
}
