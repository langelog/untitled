#include "CaptureThread.h"

CaptureThread::CaptureThread(QObject *parent) : QThread(parent) {
    running_flag  = false;
    current_frame = NULL;
    device_id     = 0;
}

void CaptureThread::stop() {
    running_flag = false;
}

void CaptureThread::config_local(int device)
{
    device_id = device;
    camera.open(device_id);
}

void CaptureThread::run()
{
    running_flag = true;

    Mat img;

    while(running_flag && camera.isOpened()) {
        camera >> img;

        emit new_text("CaptureThread Running");
        msleep(100);
    }

    emit new_text("CaptureThread stopped");
}
