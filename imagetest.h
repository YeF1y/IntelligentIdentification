#ifndef IMAGETEST_H
#define IMAGETEST_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QTimer>
#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QBuffer>
#include <QJsonArray>
#include <QThread>
#include <QPainter>
#include "worker.h"
#include <QThreadPool>


QT_BEGIN_NAMESPACE
namespace Ui {
class ImageTest;
}
QT_END_NAMESPACE

class ImageTest : public QWidget
{
    Q_OBJECT

public:
    ImageTest(QWidget *parent = nullptr);
    ~ImageTest();

public slots:
    void showCamera(int id,QImage preview);
    void takePicture();
    void tokenReply(QNetworkReply *reply);
    void beginFaceDetect(QByteArray postData);
    void imgReply(QNetworkReply *reply);
    void controlWorker();
    void pickCamera(int idx);
signals:
    void operate(QImage img);

private:
    Ui::ImageTest *ui;

    QCamera* camera;
    QCameraViewfinder* finder;
    QCameraImageCapture* imageCapture;
    QTimer* refreshTimer;
    QTimer* netTimer;
    QNetworkAccessManager* tokenManager;
    QNetworkAccessManager* imgManager;
    QSslConfiguration sslConfig;
    QString accessToken;
    QImage img;
    double faceLeft;
    double faceTop;
    double faceWidth;
    double faceHeight;
    double liveness;
    QList<QCameraInfo> camerasInfo;
    double age;
    QString gender;
    QString emotion;
    double beauty;
    int mask;
    QString glasses;
    int latestTime;
};
#endif // IMAGETEST_H
