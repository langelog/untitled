#include "ProcessingThread.h"

ProcessingThread::ProcessingThread(QObject *parent) : QThread(parent) {
    running_flag = false;
    buffer_cap = NULL;
}

void ProcessingThread::configure(Buffer *buf) {
    buffer_cap = buf;
}

void ProcessingThread::stop() {
    running_flag = false;
}

bool ProcessingThread::savePhoto(QString path) {
    Mat temp;
    current.copyTo(temp);
    return imwrite(path.toStdString(),temp);
}

void ProcessingThread::run() {
    running_flag = true;

    emit new_info("ProcessingThread has started.");

    while(running_flag) {
        ///##############################################################################
        ///##############################################################################
        if(buffer_cap->pop(current)) {



            emit new_frame(Mat2QImage(current));
        }
        ///##############################################################################
        ///##############################################################################

        //msleep(20); // task: make this act by signal/slot
                    // not by sleeping.
    }

    emit new_info("ProcessingThread has stopped.");
}
