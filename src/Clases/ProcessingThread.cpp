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

void ProcessingThread::run() {
    running_flag = true;

    Mat current;

    emit new_info("ProcessingThread has started.");

    while(running_flag) {
        // if true: operate with image
        if(buffer_cap->pop(current)) {
            emit new_frame(Mat2QImage(current));
        }
        // otherwise: buffer is empty

        msleep(50); // task: make this act by signal/slot
                    // not by sleeping.
    }

    emit new_info("ProcessingThread has stopped.");
}

QImage ProcessingThread::Mat2QImage(Mat &mat) {
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        return QImage();
    }
}
