#include "FrameLabel.h"

FrameLabel::FrameLabel(QWidget *parent) : QLabel(parent) {

}

QPoint FrameLabel::getMousePos()
{
    return mouse_current_pos;
}

QPoint FrameLabel::getMouseIn() {
    return start_point;
}

QPoint FrameLabel::getMouseOut() {
    return end_point;
}

void FrameLabel::mouseMoveEvent(QMouseEvent *ev) {
    mouse_current_pos = ev->pos();
    if(mouse_current_pos.x() < 0)
        mouse_current_pos.setX(0);
    if(mouse_current_pos.y() < 0)
        mouse_current_pos.setY(0);
    if(mouse_current_pos.x() >= IMG_WIDTH)
        mouse_current_pos.setX(IMG_WIDTH-1);
    if(mouse_current_pos.y() >= IMG_HEIGHT)
        mouse_current_pos.setY(IMG_HEIGHT-1);
    emit mouseBeingMoved();
}

void FrameLabel::mousePressEvent(QMouseEvent *ev) {
    start_point = ev->pos();
    if(start_point.x() < 0)
        start_point.setX(0);
    if(start_point.y() < 0)
        start_point.setY(0);
    if(start_point.x() >= IMG_WIDTH)
        start_point.setX(IMG_WIDTH-1);
    if(start_point.y() >= IMG_HEIGHT)
        start_point.setY(IMG_HEIGHT-1);

    emit mouseIn();
}

void FrameLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    end_point = ev->pos();
    if(end_point.x() < 0)
        end_point.setX(0);
    if(end_point.y() < 0)
        end_point.setY(0);
    if(end_point.x() >= IMG_WIDTH)
        end_point.setX(IMG_WIDTH-1);
    if(end_point.y() >= IMG_HEIGHT)
        end_point.setY(IMG_HEIGHT-1);
    emit mouseOut();
}

