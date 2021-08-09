#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbustrans.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList excel;

    excel.append("姓名");
    excel.append("年龄");
    excel.append("电话");
    excel.append("身份证");
    excel.append("地址");
    excel.append("温度");
    excel.append("是否放行");

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(excel);
    ui->tableWidget->setColumnWidth(2, 200);
    ui->tableWidget->setColumnWidth(3, 200);
    ui->tableWidget->setColumnWidth(4, 200);
    text.setUIWindow(this);
    QFile file("test.xml");
    if(!file.open(QFile::ReadOnly)) {
        text.initxml();
    }
    else {
        text.readxml();
    }
//    qInfo() << "ye";
    connect(ui->tableWidget, &QTableWidget::cellClicked, &text, &dbustrans::updatelabel);
//    w.readxml();
    QDBusConnection bus = QDBusConnection::sessionBus();
    bus.registerService("org.healthy");
    bus.registerObject("/healthy/text", &text, QDBusConnection::ExportAllSlots);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::restoretable(QDomNode n, int i) {
    if (i == 0) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    }
    newitem = new QTableWidgetItem();
    newitem->setText(n.toElement().text());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, i, newitem);
}

void MainWindow::insertrow(QString name, int age, QString phone, QString id, QString address, double temp)
{
    int rowcount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowcount);
    ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(QString::number(age)));
    ui->tableWidget->setItem(rowcount,2,new QTableWidgetItem(phone));
    ui->tableWidget->setItem(rowcount,3,new QTableWidgetItem(id));
    ui->tableWidget->setItem(rowcount,4,new QTableWidgetItem(address));
    ui->tableWidget->setItem(rowcount,5,new QTableWidgetItem(QString::number(temp)));
    if (temp > 37.2) {
        ui->tableWidget->setItem(rowcount,6,new QTableWidgetItem("否"));
    }
    else {
        ui->tableWidget->setItem(rowcount,6,new QTableWidgetItem("是"));
    }
    qInfo() << "successs";
}

void MainWindow::updaterow(int row, QString name, int age, QString phone, QString id, QString address, double temp) {
    qInfo() << "update";
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(name));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::number(age)));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(phone));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(id));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(address));
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(temp)));
    if (temp > 37.2) {
        ui->tableWidget->setItem(row,6,new QTableWidgetItem("否"));
    }
    else {
        ui->tableWidget->setItem(row,6,new QTableWidgetItem("是"));
    }
}

void MainWindow::getgsetting(QString name, int age, QString phone, QString id, QString address, double temp) {
    ui->label->setText(name);
    ui->label_2->setText(QString::number(age));
    ui->label_3->setText(phone);
    ui->label_4->setText(id);
    ui->label_5->setText(address);
    ui->label_6->setText(QString::number(temp));
}
