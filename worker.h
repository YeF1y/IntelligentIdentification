#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
#include <QImage>
#include <QThreadPool>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    void setImage(QImage img);
    void run() override;
signals:
    void resultReady(QByteArray);
private:

    QImage m_img;
};

#endif // WORKER_H
