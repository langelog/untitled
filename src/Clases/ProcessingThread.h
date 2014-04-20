#ifndef PROCESSINGTHREAD_H
#define PROCESSINGTHREAD_H

#include <QThread>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

class ProcessingThread : public QThread
{
    Q_OBJECT
public:
    explicit ProcessingThread(QObject *parent = 0);

private:
    void         run();

};

#endif // PROCESSINGTHREAD_H
