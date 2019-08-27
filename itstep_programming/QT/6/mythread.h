#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>


class MyThread : public QThread
{
public:
    explicit MyThread(QObject *parent = nullptr);
    void run() override;
};

#endif // MYTHREAD_H
