#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    captureThread = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionClose_Cam_triggered()
{
    if(captureThread!=NULL) {
        captureThread->stop();
    }
}

void MainWindow::update_text(QString text)
{
    ui->label_info->setText(text);
}

void MainWindow::on_actionOpen_Cam_triggered()
{
    if(captureThread == NULL) {
        captureThread = new CaptureThread();
        captureThread->config_local(CAMERA_ID);
        connect(captureThread,SIGNAL(new_text(QString)), this, SLOT(update_text(QString)));
        captureThread->start();
    } else {
        captureThread->start();
    }
}
