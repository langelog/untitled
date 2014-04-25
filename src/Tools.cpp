#include "Tools.h"

//################################################################################
// IMG_INFO:

Img_Info::Img_Info()
{
    name = "";
    x=y=width=height=0;
}

//################################################################################
// IMG_INFO:

Img_List::Img_List()
{
    img = NULL;
    size = 0;
}

void Img_List::append_new_photo(QString format) {
    // we guess the number is right:
    img[size] = new Img_Info();
    img[size]->name = genJpgName(size, format);
    img[size]->x=0;
    img[size]->y=0;
    img[size]->width=0;
    img[size]->height=0;
    size++;
}

void Img_List::print_info() {
    for(int i=0; i<size; i++) {
        cout << i << ": " << img[i]->name.toStdString() << " " <<
                img[i]->x << " " <<
                img[i]->y << " " <<
                img[i]->width << " " <<
                img[i]->height << endl;
    }
}

//################################################################################
// USEFUL FUNCTIONS:

QImage Mat2QImage(Mat &mat) {
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

QString genJpgName(int id, QString format)
{
    QString name;
    name.sprintf("%09d.",id);
    name = name+format;
    return name;
}

bool load_img_list(QString path, Img_List *list)
{
    FILE *p = NULL;
    int top=0;

    p = fopen((path+"\\"+FILE_INDEX).toUtf8(), "r");

    if(p == NULL)
        return false;
    //////////////////////////////////////////////////
    // if list is used, (for now) we destroy it:

    for(int i=list->size-1; i>=0; i--) {
        if(list->img[i] != NULL) {
            delete list->img[i];
            list->img[i] = NULL;
            cout << "Image " << i << " has been deleted" << endl;
        } else
            cout << "Image " << i << " is not present" << endl;
    }

    fscanf(p, "Number of images: %d\n", &top);

    if(top > MAX_IMG_INFO) {
        cout << "Too much images to list" << endl;
        return false;
    }

    for(int i=0; i<top; i++) {
        char dir[15];
        int x,y,w,h;
        list->img[i] = new Img_Info();
        fscanf(p, "%s %d %d %d %d\n", dir, &x, &y, &w, &h);
        list->img[i]->name.sprintf("%s", dir);
        list->img[i]->x = x;
        list->img[i]->y = y;
        list->img[i]->width  = w;
        list->img[i]->height = h;
    }

    list->size = top;

    fclose(p);
    return true;
}

bool save_img_list(QString path, Img_List *list) {
    FILE *p = NULL;

    p = fopen((path+"\\"+FILE_INDEX).toUtf8(), "w");

    if(p == NULL)
        return false;

    int top = list->size;

    fprintf(p, "Number of images: %d\n", top);

    for(int i=0; i<top; i++) {
        char name[15];
        strcpy(name, list->img[i]->name.toUtf8());
        fprintf(p, "%s %d %d %d %d\n", name,
                                       list->img[i]->x,
                                       list->img[i]->y,
                                       list->img[i]->width,
                                       list->img[i]->height);
    }

    fclose(p);
    return true;
}

bool create_img_list(QString path)
{
    FILE *p = NULL;

    p = fopen((path+"\\"+FILE_INDEX).toUtf8(), "w");

    if(p == NULL)
        return false;

    fprintf(p, "Number of images: %d\n", 0);

    fclose(p);
    return true;
}
