#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <iostream>
#include <QThread>
#include <QString>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "Clases/Buffer.h"

#include <iostream>

using namespace cv;
using namespace std;

class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);
    void     stop();
    void     config_local(int device, Buffer *buf);

signals:
    void new_info(QString);
    void inform_usage(int);

public slots:

private:
    void         run();
    bool         running_flag;
    Mat          *current_frame;
    int          device_id;
    VideoCapture camera;
    Buffer       *buffer_cap;

};

#endif // CAPTURETHREAD_H
