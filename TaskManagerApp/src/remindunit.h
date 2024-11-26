#ifndef REMINDUNIT_H
#define REMINDUNIT_H

#include <QWidget>
#include <QString>

class RemindUnit:public QWidget{
    Q_OBJECT
private:
    QString name;
    QString ddl;
public:
    RemindUnit(QString, QString);
};

#endif // REMINDUNIT_H
