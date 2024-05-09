#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>

class NetWorkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetWorkManager(QObject *parent = nullptr);
    ~NetWorkManager();
    QNetworkAccessManager Init();

public slots:
    void tokenReply(QNetworkReply *reply);
    void imgReply(QNetworkReply *reply);
    void tokenGet(QNetworkRequest req, QNetworkAccessManager& tokenManager);

signals:

private:
    QTimer* netTimer;
    QSslConfiguration sslConfig;
    QString accessToken;

};

#endif // NETWORKMANAGER_H
