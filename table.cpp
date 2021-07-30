#include "table.h"

table::table(QWidget *parent)
    : QWidget (parent)
{
    mainlayout = new QVBoxLayout;
    tableview = new QTableView;
    standitemmodel = new QStandardItemModel;

    standitemmodel->setColumnCount(7);
    standitemmodel->setHeaderData(0, Qt::Horizontal, QStringLiteral("姓名"));
    standitemmodel->setHeaderData(1, Qt::Horizontal, QStringLiteral("年龄"));
    standitemmodel->setHeaderData(2, Qt::Horizontal, QStringLiteral("手机"));
    standitemmodel->setHeaderData(3, Qt::Horizontal, QStringLiteral("身份证号"));
    standitemmodel->setHeaderData(4, Qt::Horizontal, QStringLiteral("地址"));
    standitemmodel->setHeaderData(5, Qt::Horizontal, QStringLiteral("体温"));
    standitemmodel->setHeaderData(6, Qt::Horizontal, QStringLiteral("是否放行"));

    tableview->setModel(standitemmodel);

    tableview->setColumnWidth(0, 100);
    tableview->setColumnWidth(1, 100);
    tableview->setColumnWidth(2, 200);
    tableview->setColumnWidth(3, 200);
    tableview->setColumnWidth(4, 200);
    tableview->setColumnWidth(5, 100);
    tableview->setColumnWidth(6, 100);
    tableview->setColumnWidth(7, 100);

//    createview(QString name, int age, QString phone, QString id, QString address, double temp);
//    createview("name", 2, "234", "23432", "sadf", 12.3);

    standitem0 = new QStandardItem("sdf");
    standitem1 = new QStandardItem(2);
    standitem2 = new QStandardItem("phone");
    standitem3 = new QStandardItem("id");
    standitem4 = new QStandardItem("address");
    standitem5 = new QStandardItem(4.3);
    standitem6 = new QStandardItem("NO");

    int i = 0;
    standitemmodel->setItem(i, 0, standitem0);
    standitemmodel->setItem(i, 1, standitem1);
    standitemmodel->setItem(i, 2, standitem2);
    standitemmodel->setItem(i, 3, standitem3);
    standitemmodel->setItem(i, 4, standitem4);
    standitemmodel->setItem(i, 5, standitem5);
    standitemmodel->setItem(i, 6, standitem6);

    mainlayout->addWidget(tableview);
    this->setLayout(mainlayout);
    update();
}

void table::createview(QString name, int age, QString phone, QString id, QString address, double temp, int i) {
    standitem0 = new QStandardItem(name);
    standitem1 = new QStandardItem(age);
    standitem2 = new QStandardItem(phone);
    standitem3 = new QStandardItem(id);
    standitem4 = new QStandardItem(address);
    standitem5 = new QStandardItem(temp);

    standitemmodel->setItem(i, 0, standitem0);
    standitemmodel->setItem(i, 1, standitem1);
    standitemmodel->setItem(i, 2, standitem2);
    standitemmodel->setItem(i, 3, standitem3);
    standitemmodel->setItem(i, 4, standitem4);
    standitemmodel->setItem(i, 5, standitem5);
//    standitemmodel->setItem(i, 6, standitem6);
}
