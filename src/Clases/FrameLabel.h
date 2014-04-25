#ifndef FRAMELABEL_H
#define FRAMELABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include <QPainter>
#include <iostream>

#include "Tools.h"
#include "constants.h"

using namespace std;

class FrameLabel : public QLabel
{
    Q_OBJECT

public:
    FrameLabel(QWidget *parent = 0);
    QPoint getMousePos();
    QPoint getMouseIn();
    QPoint getMouseOut();

private:
    QPoint mouse_current_pos;
    QPoint start_point;
    QPoint end_point;

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void mouseBeingMoved();
    void mouseIn();
    void mouseOut();

};

#endif // FRAMELABEL_H
