#include "urlmanager.h"

UrlManager::UrlManager(QObject *parent)
    : QObject{parent}
{}

QUrl UrlManager::ParameterSetting()
{
    QUrl url("https://aip.baidubce.com/oauth/2.0/token");
    //QUrlQuery query;
    //query.addQueryItem("grant_type","client_credentials");
    //query.addQueryItem("client_id","P2b5h1vg1s3pjSuRmD3UKcVI");
    //query.addQueryItem("client_secret","Lil37xbKf53EgjdzSSU5wNdhpuJRy53B");

    //query.addQueryItem("client_id","oQXBR1aW4BrlvqrvMpCAkyCd");
    //query.addQueryItem("client_secret","BxjQcEpqiKDuUR19e1vv3F4CFTBQgPpj");
    //url.setQuery(query);
    qDebug() << url;
    return url;
}

QNetworkRequest UrlManager::SSLConfigure(QUrl url)
{
    if(QSslSocket::supportsSsl())
    {
        qDebug() << "支持SSL";
    }
    else
    {
        qDebug() << "不支持SSL";
    }
    //SSL配置
    sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::QueryPeer);
    sslConfig.setProtocol(QSsl::TlsV1_2);
    //组装请求
    QNetworkRequest req;
    req.setUrl(url);
    req.setSslConfiguration(sslConfig);
    return req;
}
