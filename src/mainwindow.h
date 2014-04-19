#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "constants.h"
#include "Clases/CaptureThread.h"

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
    Ui::MainWindow *ui;
    CaptureThread  *captureThread;

public slots:
    void on_actionClose_triggered();
    void on_actionOpen_Cam_triggered();
    void on_actionClose_Cam_triggered();

    void update_text(QString);
};

#endif // MAINWINDOW_H
