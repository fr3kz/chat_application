import QtQuick 2.0

Rectangle {
    width: 640
    height: 360

    Text {
        id: text
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
