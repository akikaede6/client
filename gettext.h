#ifndef GETTEXT_H
#define GETTEXT_H

#include <QString>
#include <QObject>
#include <QWidget>

class gettext : public QObject {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.healthy.text")

public slots:
    bool setarg(QString name, int age, QString telephone, QString idnumber, QString address, double tempure);
    QString getName();
    int getAge();
    QString getTelephone();
    QString getIdnumber();
    QString getAddress();
    double getTempure();


private:
    QString name = "test";
    int age = 0;
    QString telephone;
    QString idnumber;
    QString address;
    double tempure;
};


#endif // GETTEXT_H
