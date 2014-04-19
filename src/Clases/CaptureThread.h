#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>
#include <QString>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);
    void stop();
    void config_local(int device);

signals:
    void new_text(QString);

public slots:

private:
    void         run();
    bool         running_flag;
    Mat          *current_frame;
    int          device_id;
    VideoCapture camera;

};

#endif // CAPTURETHREAD_H
