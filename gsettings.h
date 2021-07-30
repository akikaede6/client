#ifndef GSETTINGS_H
#define GSETTINGS_H

#include <QObject>
#include <QString>
#include <QGSettings>

class gsettings : public QObject
{
    Q_OBJECT

public:
    QString get_string_value(const QString &key);
    int get_int_value(const QString &key);
    double get_double_value(const QString &key);
    explicit gsettings(QObject *parent = 0);
    void add_message(const QString &key);
    ~gsettings();

private:
    QGSettings *m_gsettings = nullptr;

};


#endif // GSETTINGS_H
