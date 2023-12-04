#ifndef AUTHPAGE_H
#define AUTHPAGE_H

#include <QObject>
#include <QSettings>
#include "apiservice.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QByteArray>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QByteArray>
#include <QtQml>

class authpage : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit authpage(QObject *parent = nullptr);
    apiservice *apiService;
    QSettings settings;
    Q_INVOKABLE void login(QString username, QString password);
    Q_INVOKABLE void signup(QString username, QString password);
    int logged_in() const;


signals:
    void loginsuccesful();

private:
    int m_logged_in;
};

#endif // AUTHPAGE_H
