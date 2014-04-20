#include "Buffer.h"

Buffer::Buffer(int size_p)
{
    max_size  = size_p;
    buffer    = new Mat[max_size];
    size      = 0;
    head      = 0;
    tail      = 0;
}

bool Buffer::push(Mat &frame)
{
    if(size==max_size) {
        return false; // buffer is full
    } else {
        frame.copyTo(buffer[head]);
        head = (head+1)%max_size;
        size++;
        return true;
    }
}

bool Buffer::pop(Mat &out)
{
    if(head==tail)
        return false; // buffer is empty

    //out = buffer[tail];
    buffer[tail].copyTo(out);
    tail = (tail+1)%max_size;
    size--;
    return true;
}

int Buffer::usage()
{
    return (size*100)/max_size;
}
