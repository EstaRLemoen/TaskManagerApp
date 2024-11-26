#ifndef TIMEUNIT_H
#define TIMEUNIT_H

#include <QWidget>

class TimeUnit:public QWidget{
    Q_OBJECT
private:
    int task_id;
    const QString* name;
    const QString* ddl;
    const bool* is_urgent;
    void renewUrgency();
public:
    TimeUnit(int, const QString*, const QString*, const bool*);
    bool isBelongTask(int id)const;
    bool isUrgent()const;
};

#endif // TIMEUNIT_H
