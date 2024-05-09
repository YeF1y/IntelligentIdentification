#include "worker.h"
#include <QBuffer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QImage>
Worker::Worker(QObject *parent)
    : QObject{parent}, QRunnable()
{
    setAutoDelete(true);
    //QThreadPool::setMaxThreadCount(4);
}

void Worker::setImage(QImage img)
{
    m_img=img;
    qDebug()<<"Getting a picture...";
    // //转换成 base64 编码
    // QByteArray ba;
    // QBuffer buff(&ba);
    // img.save(&buff,"png");
    // QString b64str = ba.toBase64();
    // //qDebug() << b64str;

    // //请求体 body 参数设置
    // QJsonObject postJson;
    // QJsonDocument doc;
    // postJson.insert("image",b64str);
    // postJson.insert("image_type","BASE64");
    // postJson.insert("face_field","age,expression,face_shape,gender,glasses,quality,eye_status,emotion,face_type,mask,beauty");
    // postJson.insert("liveness_control","NORMAL");
    // doc.setObject(postJson);
    // QByteArray postData = doc.toJson(QJsonDocument::Compact);
    // emit resultReady(postData);
}

void Worker::run()
{
    //转换成 base64 编码
    QByteArray ba;
    QBuffer buff(&ba);
    m_img.save(&buff,"png");
    QString b64str = ba.toBase64();
    //qDebug() << b64str;

    //请求体 body 参数设置
    QJsonObject postJson;
    QJsonDocument doc;
    postJson.insert("image",b64str);
    postJson.insert("image_type","BASE64");
    postJson.insert("face_field","age,expression,face_shape,gender,glasses,quality,eye_status,emotion,face_type,mask,beauty");
    postJson.insert("liveness_control","NORMAL");
    doc.setObject(postJson);
    QByteArray postData = doc.toJson(QJsonDocument::Compact);
    emit resultReady(postData);
}
