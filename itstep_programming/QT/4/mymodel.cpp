#include "mymodel.h"

MyModel::MyModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    QFile file("data.txt");
    file.open(QIODevice::ReadOnly);
    list = QString(file.readAll()).split("\r\n");
    qDebug() << list;
    file.close();
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    return list.size()/columnCount(parent);
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole){
        return list[index.row()*3+index.column()];
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole){
        list[index.row()*3+index.column()] = value.toString();
    }
    return true;
}





