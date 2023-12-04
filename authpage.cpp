#include "authpage.h"

#include <QJsonDocument>
#include <QJsonObject>

authpage::authpage(QObject *parent)
    : QObject{parent}, apiService(new apiservice(this)), settings("chat_app","chat_app")
{
    connect(this, &authpage::loginsuccesful, this, &authpage::logged_in);
}

void authpage::login(QString username, QString password)
{
    QJsonObject userdata;
    userdata["username"] = username;
    userdata["password"] = password;

    QJsonDocument userdatadoc = QJsonDocument(userdata);

    QJsonDocument response = apiService->post("http://127.0.0.1:8000/users/login/", userdatadoc.toJson());
    QJsonObject jobj = response.object();

    if(!jobj.contains("message_error")) {
        settings.setValue("sessionid", jobj["message"].toString());
        settings.setValue("userid", jobj["userid"].toString());

        // przeniesc do menu
        emit loginsuccesful();
    } else {
        qDebug() << jobj["message_error"];
    }

    qDebug() << response;
}

void authpage::signup(QString username, QString password)
{
    QJsonObject userdata;
    userdata["username"] = username;
    userdata["password"] = password;

    QJsonDocument userdatadoc = QJsonDocument(userdata);

    QJsonDocument response = apiService->post("http://127.0.0.1:8000/users/register/", userdatadoc.toJson());
    QJsonObject jobj = response.object();

    if(!jobj.contains("message_error")) {
        settings.setValue("sessionid", jobj["message"].toString());
        settings.setValue("userid", jobj["userid"].toString());

        emit loginsuccesful();
    } else {
        qDebug() << jobj["message_error"];
    }

    qDebug() << response;
}

int authpage::logged_in() const
{
    // Tutaj można zwrócić rzeczywisty stan zalogowania, zamiast zawsze 1
    return 1;
}
