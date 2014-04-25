#ifndef LOCATORDIALOG_H
#define LOCATORDIALOG_H

#include <QDialog>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QDir>
#include <QPoint>

#include "constants.h"
#include "Tools.h"
#include "Clases/FrameLabel.h"

using namespace std;
using namespace cv;

namespace Ui {
class LocatorDialog;
}

class LocatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LocatorDialog(QWidget *parent = 0);
    ~LocatorDialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

    void update_rect();

    void set_rect_In();
    void set_rect_Out();

    void on_pushButton_5_clicked();

private:
    Ui::LocatorDialog *ui;
    Img_List          img_info_list;
    Mat               current_original;
    Mat               current_showable;
    int               current_id;
    QString           dir;
    FrameLabel        *img;

    QPoint            start_pos;
    QPoint            current_pos;
    QPoint            end_pos;

    void              load_image(QString path);
    void              save_image();
    void              update_place(int i); // this is about the place indicator on gui "x/y"
    void              show_image();
    void              update_screen();

};

#endif // LOCATORDIALOG_H
