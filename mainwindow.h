#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbustrans.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QtDBus>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void insertrow(QString name, int age, QString phone, QString id, QString address, double temp);
   void getgsetting(QString name, int age, QString phone, QString id, QString address, double temp);
   void updaterow(int row, QString name, int age, QString phone, QString id, QString address, double temp);
   dbustrans text;
   void restoretable(QDomNode n, int i);
   QTableWidgetItem *newitem;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
