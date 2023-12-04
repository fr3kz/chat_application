import QtQuick
import QtQuick.Controls
import chat_app

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Hello World"

    AuthPage {
        id: authPage
        anchors.fill: parent


    }
    ChatPage{
        id: chatPage
        anchors.fill: parent
        visible: false;
    }

    Connections {
                   target: authpage
                   function onloginsuccesful(){
                       chatPage.visible = true;
                       authPage.visible = false;
                   }

               }
}
