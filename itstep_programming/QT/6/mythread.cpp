#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{
}

void MyThread::run()
{
    for(int i = 0; i < 100; i ++)
    {
       qDebug() << i;
    }
}
