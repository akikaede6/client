#include "gsettings.h"
#include "table.h"

#include <QGSettings>
#include <QDebug>

gsettings::gsettings(QObject *parent) :
    QObject (parent)
{
    if (QGSettings::isSchemaInstalled("org.healthy")) {
        m_gsettings = new QGSettings("org.healthy");
//        qInfo() << "success";
        connect(m_gsettings, &QGSettings::changed, this, &gsettings::add_message);
//        QVariant n = m_gsettings->get("name");

    }
//   qInfo() << "fail";
}

gsettings::~gsettings() {
    if (m_gsettings) {
        delete m_gsettings;
        m_gsettings = nullptr;
    }
}

void gsettings::add_message(const QString &key) {
    table one;
    gsettings in;
//    qInfo() << in.get_int_value("age");
    static int i;
    one.createview("name", 34, "phone", "id", "address", 3, i);

//    one.createview(in.get_string_value("name"), in.get_int_value("age"), get_string_value("phone"), get_string_value("id"), get_string_value("address"), get_double_value("temp"), i);
//    i++;

    qInfo() << i;
    i++;
}

QString gsettings::get_string_value(const QString &key) {
    if (!m_gsettings) {
        return QString();
    }
    const QStringList list = m_gsettings->keys();
    if (!list.contains(key)) {
        return QString();
    }
    QString value = m_gsettings->get(key).toString();
    return value;
}

int gsettings::get_int_value(const QString &key) {
    if (!m_gsettings) {
        return -999;
    }
    const QStringList list = m_gsettings->keys();
    if (!list.contains(key)) {
        return -999;
    }
    int value = m_gsettings->get(key).toInt();
    return value;
}

double gsettings::get_double_value(const QString &key) {
    if (!m_gsettings) {
        return -999;
    }
    const QStringList list = m_gsettings->keys();
    if (!list.contains(key)) {
        return -999;
    }
    double value = m_gsettings->get(key).toDouble();
    return value;
}
