#ifndef BUFFER_H
#define BUFFER_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <vector>

using namespace cv;
using namespace std;

// may be a future adtition is a historial, in time lapse. Instead of a stack of images
class Buffer
{
public:
    Buffer(int size_p);

    bool push(Mat &frame);
    bool pop(Mat &out);
    int  usage(); // gives percentage of usage.

private:
    int  max_size;
    int  size;
    Mat *buffer;
    int  head;
    int  tail;
};

#endif // BUFFER_H
