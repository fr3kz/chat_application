import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    AuthPage{
        id: authPage
        anchors.fill: parent
        visible: true
    }



}
