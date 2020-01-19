import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    Item {
        height : 10
    }
    RowLayout{
        Label{
            Layout.fillWidth: true
            text: qsTr("Mode")

        }

        Button{
            width : 50
            height: 40
        text: qsTr("NAV")
        }
    }

}
