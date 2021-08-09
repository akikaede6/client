#ifndef DBUSTRANS_H
#define DBUSTRANS_H

#include <QString>
#include <QObject>
#include <QFile>
#include <QGSettings>
#include <QXmlStreamWriter>
#include <QDomElement>
#include <QTableWidget>

class MainWindow;
class dbustrans : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.healthy.text")

public slots:
    int setarg(QString _name, int _age, QString _phone, QString _id, QString _address, double _temp);
    QString getname();
    int getage();
    QString getphone();
    QString getid();
    QString getaddress();
    double gettemp();
//    void senddbus();
    void setUIWindow(MainWindow* w);
    void updatelabel(int _row, int _column);

public:
    void addXML();
    void initxml();
    void readxml();

    void updatexml();
//    friend class setsettings;


private:
    QString name;
    int age;
    QString phone;
    QString id;
    QString address;
    double temp;
    QVector<QString> foo;
    QVector< QVector<QString> > info;
    bool again = false;
    int row = 0;
    MainWindow* m_mainWindow;
    QGSettings *m_gsettings = nullptr;
//    QTableWidgetItem *newitem;
};

#endif // DBUSTRANS_H
