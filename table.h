#ifndef TABLE_H
#define TABLE_H

#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItemModel>

class table : public QWidget
{
    Q_OBJECT

public:
    table(QWidget *parent = 0);
    void createview(QString name, int age, QString phone, QString id, QString address, double temp, int i);

private:
    QVBoxLayout *mainlayout;
    QTableView *tableview;
    QStandardItemModel *standitemmodel;
    QStandardItem *standitem0;
    QStandardItem *standitem1;
    QStandardItem *standitem2;
    QStandardItem *standitem3;
    QStandardItem *standitem4;
    QStandardItem *standitem5;
    QStandardItem *standitem6;
};

#endif // TABLE_H
