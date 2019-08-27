#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QtWidgets>

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
    QStringList list;
public:
    explicit MyModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role)override;
};

#endif // MYMODEL_H
