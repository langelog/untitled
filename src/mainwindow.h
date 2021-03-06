#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QImage>
#include <QDir>
#include <iostream>

#include "Tools.h"
#include "constants.h"
#include "Clases/Buffer.h"
#include "Clases/CaptureThread.h"
#include "Clases/ProcessingThread.h"
#include "LocatorDialog.h"

using namespace std;

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
    int               jpg_id;
    void              update_jpg_id(QString path);
    LocatorDialog    *locatorDialog;
    Img_List          img_info_list;

public slots:
    void on_actionClose_triggered();
    void on_actionOpen_Cam_triggered();
    void on_actionClose_Cam_triggered();
    void on_actionObject_Locator_triggered();

    void update_info(QString);
    void update_buffer_usage(int);
    void update_frame(const QImage &frame);
private slots:
    void on_pushButton_clicked();
    void on_line_pathPhotos_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
