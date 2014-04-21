#ifndef PROCESSINGTHREAD_H
#define PROCESSINGTHREAD_H

#include <QThread>
#include <QString>
#include <QImage>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "Clases/Buffer.h"

using namespace cv;

class ProcessingThread : public QThread
{
    Q_OBJECT
public:
    explicit ProcessingThread(QObject *parent = 0);
    void     configure(Buffer *buf);
    void     stop();

signals:
    void new_info(QString);
    void new_frame(const QImage &frame);

private:
    void         run();
    bool         running_flag;
    Buffer      *buffer_cap;

    QImage       Mat2QImage(Mat &img);
};

#endif // PROCESSINGTHREAD_H
