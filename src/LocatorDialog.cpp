#include "LocatorDialog.h"
#include "ui_LocatorDialog.h"

Scalar box_color     = Scalar(0,0,255);
int    box_thickness = 1;

LocatorDialog::LocatorDialog(QWidget *parent) :QDialog(parent),ui(new Ui::LocatorDialog)
{
    ui->setupUi(this);
    img_info_list.img = new Img_Info*[MAX_IMG_INFO];
    current_id        = 0;
    img               = new FrameLabel();
    connect(img, SIGNAL(mouseBeingMoved()), this, SLOT(update_rect()));
    connect(img, SIGNAL(mouseIn()), this, SLOT(set_rect_In()));
    connect(img, SIGNAL(mouseOut()), this, SLOT(set_rect_Out()));
}

LocatorDialog::~LocatorDialog()
{
    delete ui;
}

void LocatorDialog::on_pushButton_clicked()
{
    dir = ui->line_path->text();
    if(!QDir(dir).exists()) {
        cout << "Directory doesn't exists!" << endl;
        return;
    }

    if(!load_img_list(dir, &img_info_list)) {
        cout << "inapropiate folder" << endl;
        return;
    }

    if(img_info_list.size==0) {
        cout << "Empty folder" << endl;
        return;
    }

    // this should be implemented on the mobile viewer:
    update_screen();
}

void LocatorDialog::load_image(QString path)
{
    current_original = imread(path.toStdString());
    current_original.copyTo(current_showable);

    // if the photo has object info:
    int x = img_info_list.img[current_id]->x;
    int y = img_info_list.img[current_id]->y;
    int width = img_info_list.img[current_id]->width;
    int height = img_info_list.img[current_id]->height;

    if(!(   (x == 0) && (y == 0)&&
            (width == 0) && (height == 0))) {
        cv::rectangle(current_showable, cv::Rect(x,y,width,height), box_color, box_thickness);
    }
}

void LocatorDialog::save_image()
{
    if(!QDir(dir).exists()) {
        cout << "Directory doesn't exists!" << endl;
        return;
    }

    save_img_list(dir, &img_info_list);

}

void LocatorDialog::update_place(int i)
{
    ui->line_current->setText(QString::number(i)+"/"+QString::number(img_info_list.size-1));
}

void LocatorDialog::show_image()
{
    // prepare the image:
    //current_original.copyTo(current_showable);

    //connect(img, SIGNAL(newMousePos(QPoint)),this, SLOT(update_mouse_pos(QPoint)));

    img->setPixmap(QPixmap::fromImage(Mat2QImage(current_showable)));
    ui->scroll_Locator->setWidget(img);
}

void LocatorDialog::update_screen()
{
    // I know this can be done better... but whatever
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);

    if(current_id == 0 && current_id == img_info_list.size-1) {
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    } else if(current_id == 0)
        ui->pushButton_2->setEnabled(false);
    else if(current_id == img_info_list.size-1)
        ui->pushButton_3->setEnabled(false);
    else if(current_id > 0 || current_id < img_info_list.size-1) {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    } else {
        cout << "out of range" << endl;
        return;
    }

    load_image(dir+"\\"+img_info_list.img[current_id]->name);
    show_image();
    update_place(current_id);
}

void LocatorDialog::on_pushButton_3_clicked() {
    current_id++;
    update_screen();
}

void LocatorDialog::on_pushButton_2_clicked() {
    current_id--;
    update_screen();
}

void LocatorDialog::update_rect() {
    current_pos = img->getMousePos();
    current_original.copyTo(current_showable);
    cv::Point a, b;
    a.x = start_pos.x();
    a.y = start_pos.y();
    b.x = current_pos.x();
    b.y = current_pos.y();
    cv::rectangle(current_showable,a, b, box_color, box_thickness);
    show_image();


}

void LocatorDialog::set_rect_In()
{
    start_pos = img->getMouseIn();
    ui->label_x->setNum(start_pos.x());
    ui->label_y->setNum(start_pos.y());
}

void LocatorDialog::set_rect_Out()
{
    end_pos = img->getMouseOut();
    current_original.copyTo(current_showable);
    cv::Point p[4];
    p[0].x = start_pos.x();
    p[0].y = start_pos.y();
    p[1].x = end_pos.x();
    p[1].y = end_pos.y();
    cv::rectangle(current_showable,p[0], p[1], box_color, box_thickness);
    show_image();

    // get width, height and primary point:

    int width = abs(p[0].x - p[1].x);
    int height = abs(p[0].y - p[1].y);

    // extrapolate the other 2 points
    p[2].x = p[1].x;
    p[2].y = p[0].y;
    p[3].x = p[0].x;
    p[3].y = p[1].y;

    // find the first:
    int x = 9999999 , y = 9999999; // this must be a pretty high number
    for(int i=0; i<4; i++) {
        if(x > p[i].x || y > p[i].y) {
            x = p[i].x;
            y = p[i].y;
        }
    }


    ui->label_width->setNum(width);
    ui->label_height->setNum(height);
    ui->label_x->setNum(x);
    ui->label_y->setNum(y);

    img_info_list.img[current_id]->x = x;
    img_info_list.img[current_id]->y = y;
    img_info_list.img[current_id]->width = width;
    img_info_list.img[current_id]->height = height;

}

void LocatorDialog::on_pushButton_5_clicked()
{
    save_image();
}
