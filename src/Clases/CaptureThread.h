#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QThread>

class CaptureThread : public QThread
{
    Q_OBJECT
public:
    explicit CaptureThread(QObject *parent = 0);

signals:

public slots:

private:
    void run();

};

#endif // CAPTURETHREAD_H
