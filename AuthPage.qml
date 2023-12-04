import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: parent.width   // Ustaw szerokość na szerokość rodzica (czyli AuthPage w main.qml)
    height: parent.height  // Ustaw wysokość na wysokość rodzica
    Rectangle {
        width: parent.width
        height: parent.height
        color: "darkblue"

        Column {
            anchors.centerIn: parent

            TextField {
                id: usernameInput
                width: 200
                placeholderText: "Username"
                font.pixelSize: 14
            }

            TextField {
                id: passwordInput
                width: 200
                placeholderText: "Password"
                font.pixelSize: 14
                echoMode: TextInput.Password
            }

            Button {
                text: "Login"
                width: 200
                onClicked: {

                    authpage.login(usernameInput.text, passwordInput.text);

                }
            }
            Button {
                text: "Zarejestruj"
                width: 200
                onClicked: {

                   register_form.visible = true;

                }
            }
        }
    }


    Rectangle {
        id: register_form
        width: parent.width
        height: parent.height
        color: "darkblue"
        visible: false

        Column {
            anchors.centerIn: parent

            TextField {
                id: usernameInput1
                width: 200
                placeholderText: "Username"
                font.pixelSize: 14
            }

            TextField {
                id: passwordInput2
                width: 200
                placeholderText: "Password"
                font.pixelSize: 14
                echoMode: TextInput.Password
            }

            Button {
                text: "Login"
                width: 200
                onClicked: {

                    authpage.signup(usernameInput1.text, passwordInput2.text);

                }


            }
            Button {
                text: "Zaloguj"
                width: 200
                onClicked: {

                   register_form.visible = false;

                }
            }

        }
    }
}
