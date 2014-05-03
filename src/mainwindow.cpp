#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    captureThread     = NULL;
    buffer            = NULL;
    processingThread  = NULL;
    jpg_id            = 0;
    locatorDialog     = NULL;
    img_info_list.img = new Img_Info*[MAX_IMG_INFO];
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_jpg_id(QString path) {
    FILE   *p;
    int     id = 0;

    p = fopen((path+DS+FILE_INDEX).toUtf8(), "a+");
    rewind(p);
    fscanf(p, "%d", &id);
    if(feof(p)) {
        id = 0;
        fprintf(p, "%d ", id);
    }
    fclose(p);
    // si id==0, es la primera foto:
    jpg_id = id;

    // guardamos la proxima id:
    p = fopen((path+DS+FILE_INDEX).toUtf8(), "w");
    id++;
    fprintf(p, "%d ", id);
    fclose(p);
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

        // terminate them:
        processingThread->terminate();
        captureThread->terminate();

        // distroy connected signal/slots:
        disconnect(captureThread,SIGNAL(new_info(QString)));
        disconnect(captureThread,SIGNAL(inform_usage(int)));
        disconnect(processingThread,SIGNAL(new_info(QString)));
        disconnect(processingThread,SIGNAL(new_frame(QImage)));

        // destroy them:
        processingThread->deleteLater();
        captureThread->deleteLater();
    }
}

void MainWindow::on_actionObject_Locator_triggered()
{
    if(locatorDialog==NULL) {
        locatorDialog = new LocatorDialog();
    }
    locatorDialog->show();
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

void MainWindow::on_pushButton_clicked()
{
    QString path = ui->line_pathPhotos->text();

    if(processingThread!=NULL)
        if(processingThread->isRunning() && (QDir(path).exists())) {
            if(!load_img_list(path, &img_info_list))
                create_img_list(path);
            cout << img_info_list.size << endl;
            // save new image.
            processingThread->savePhoto(ui->line_pathPhotos->text()+DS+genJpgName(img_info_list.size, ui->line_format->text()));
            // create new index.
            img_info_list.append_new_photo(ui->line_format->text());
            // save new index.
            save_img_list(path, &img_info_list);


            //
            //cout << (path+genJpgName()).toStdString() << endl;
            //update_jpg_id(path);
            //processingThread->savePhoto(ui->line_pathPhotos->text()+genJpgName());
        }
}

void MainWindow::on_line_pathPhotos_textChanged(const QString &arg1)
{
    QPalette *palette = new QPalette();
    if(QDir(arg1).exists())
        palette->setColor(QPalette::Text,Qt::green);
    else
        palette->setColor(QPalette::Text,Qt::red);
    ui->line_pathPhotos->setPalette(*palette);
}
