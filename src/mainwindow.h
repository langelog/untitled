#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QImage>

#include "constants.h"
#include "Clases/Buffer.h"
#include "Clases/CaptureThread.h"
#include "Clases/ProcessingThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow   *ui;
    CaptureThread    *captureThread;
    ProcessingThread *processingThread;
    Buffer           *buffer;

public slots:
    void on_actionClose_triggered();
    void on_actionOpen_Cam_triggered();
    void on_actionClose_Cam_triggered();

    void update_info(QString);
    void update_buffer_usage(int);
    void update_frame(const QImage &frame);
};

#endif // MAINWINDOW_H
