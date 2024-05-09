#include "networkmanager.h"

NetWorkManager::NetWorkManager(QObject *parent)
    : QObject{parent}
{

}

NetWorkManager::~NetWorkManager(){
    //netTimer->deleteLater();
}

QNetworkAccessManager NetWorkManager::Init()
{
    QNetworkAccessManager tokenManager;
    QNetworkAccessManager imgManager;

    //connect(&tokenManager,&QNetworkAccessManager::finished,this,&NetWorkManager::tokenReply);

    //connect(&imgManager,&QNetworkAccessManager::finished,this,&NetWorkManager::imgReply);
    qDebug() << tokenManager.supportedSchemes();
    return tokenManager;
}

void NetWorkManager::tokenReply(QNetworkReply *reply)
{
    qDebug() << "tokenReply";
}

void NetWorkManager::imgReply(QNetworkReply *reply)
{
    qDebug() << "imgReply";
}

void NetWorkManager::tokenGet(QNetworkRequest req, QNetworkAccessManager& tokenManager)
{
    qDebug() << "tokenGet";
    tokenManager.get(req);
}
