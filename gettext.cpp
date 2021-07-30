#include "gettext.h"

#include <QString>
#include <QDebug>

bool gettext::setarg(QString name, int age, QString telephone, QString idnumber, QString address, double tempure) {
    this->name = name;
    this->age = age;
    this->telephone = telephone;
    this->idnumber = idnumber;
    this->address = address;
    this->tempure = tempure;
    if (tempure < 37.2)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

QString gettext::getName() {
    return name;
}

int gettext::getAge() {
    return age;
}

QString gettext::getTelephone() {
    return telephone;
}

QString gettext::getIdnumber() {
    return idnumber;
}

QString gettext::getAddress() {
    return address;
}

double gettext::getTempure() {
    return tempure;
}
