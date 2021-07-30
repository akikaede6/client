#include "mainwindow.h"
#include "gettext.h"
#include "gsettings.h"
#include "table.h"

#include <QApplication>
#include <QtDBus>
#include <QtDebug>
#include <QDBusInterface>

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    table w;
    w.resize(1050,500);
    w.show();

    QDBusConnection bus = QDBusConnection::sessionBus();
    bus.registerService("org.healthy");
    gettext text;
    qDebug("test");
    bus.registerObject("/healthy/text", &text, QDBusConnection::ExportAllSlots);
    gsettings test;
//    qInfo() << test.get_int_value("age");

    return a.exec();
}
