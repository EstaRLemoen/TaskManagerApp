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
    RemindUnit(QString name, QString ddl);
};

#endif // REMINDUNIT_H
