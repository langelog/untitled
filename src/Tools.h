#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <QString>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QImage>

#include "constants.h"

using namespace std;
using namespace cv;

class Img_Info {
public:
    Img_Info();

    QString name;
    // this info about the object location:
    int x;
    int y;
    int width;
    int height;
};

class Img_List {
public:
    Img_List();
    void append_new_photo(QString format);
    void print_info();

    int size;
    Img_Info **img;
};

QImage       Mat2QImage(Mat &img);
QString      genJpgName(int id, QString format);
bool         load_img_list(QString path, Img_List *list);
bool         create_img_list(QString path);
bool         save_img_list(QString path, Img_List *list);

#endif // TOOLS_H
