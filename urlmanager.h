#ifndef URLMANAGER_H
#define URLMANAGER_H

#include <QObject>
#include <QUrl>
#include <QUrlQuery>
#include <QDebug>
#include <QNetworkAccessManager>

class UrlManager : public QObject
{
    Q_OBJECT
public:
    explicit UrlManager(QObject *parent = nullptr);
    QUrl ParameterSetting();
    QNetworkRequest SSLConfigure(QUrl url);

signals:

private:
    QSslConfiguration sslConfig;
};

#endif // URLMANAGER_H
