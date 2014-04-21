#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    captureThread    = NULL;
    buffer           = NULL;
    processingThread = NULL;
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
        // set up stop flags:
        processingThread->stop();
        captureThread->stop();

        // distroy connected signal/slots:
        disconnect(captureThread,SIGNAL(new_info(QString)));
        disconnect(captureThread,SIGNAL(inform_usage(int)));
        disconnect(processingThread,SIGNAL(new_info(QString)));
        disconnect(processingThread,SIGNAL(new_frame(QImage)));

        // terminate them:
        processingThread->terminate();
        captureThread->terminate();

        // destroy them:
        processingThread->deleteLater();
        captureThread->deleteLater();
    }
}

void MainWindow::update_info(QString text)
{
    ui->plainTextEdit->insertPlainText("* "+text+"\n");
}

void MainWindow::update_buffer_usage(int p)
{
    ui->bufferUsage->setValue(p);
}

void MainWindow::update_frame(const QImage &frame)
{
    ui->label_main->setPixmap(QPixmap::fromImage(frame));
}

void MainWindow::on_actionOpen_Cam_triggered()
{
    if(captureThread == NULL) {
        // creating objects:
        buffer           = new Buffer(BUFFER_SIZE);
        captureThread    = new CaptureThread();
        processingThread = new ProcessingThread();
        // configuring:
        captureThread->config_local(CAMERA_ID, buffer);
        processingThread->configure(buffer);
        // connecting:
        connect(captureThread,SIGNAL(new_info(QString)), this, SLOT(update_info(QString)));
        connect(captureThread,SIGNAL(inform_usage(int)), this, SLOT(update_buffer_usage(int)));
        connect(processingThread,SIGNAL(new_info(QString)),this,SLOT(update_info(QString)));
        connect(processingThread,SIGNAL(new_frame(QImage)),this,SLOT(update_frame(QImage)));
        // starting:
        captureThread->start();
        processingThread->start();
    } else {
        // its necessary to improve the deletion of
        // the objects.
        captureThread->start();
    }
}
