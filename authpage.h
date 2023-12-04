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

class authpage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int logged_in READ logged_in WRITE setLogged_in NOTIFY logged_inChanged FINAL)
public:
    explicit authpage(QObject *parent = nullptr);
    apiservice *apiService;
    QSettings settings;
    Q_INVOKABLE void login(QString username, QString password);
    Q_INVOKABLE void signup(QString username, QString password);
    int logged_in;
    int logged_in() const;


signals:
    logged_inChanged();

private:
    int m_logged_in;
};

#endif // AUTHPAGE_H
