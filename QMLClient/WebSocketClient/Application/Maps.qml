import QtQuick 2.0
import QtWebEngine 1.0

Rectangle {
   WebEngineView {
      anchors.fill: parent
      url: telemetryData ? telemetryData.urlStr : "https://www.google.com/"
   }
}
