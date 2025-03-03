#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include "tasklist.h"
#include "timeunit.h"

class TimeLine:public QWidget{
    Q_OBJECT
private:
    TaskList* tasklist_;
    std::vector<TimeUnit*> timeunits;

    void sortUnit();
    void renew_contain();
public:
    TimeLine(TaskList* tasklist_);
    //TODO
};

#endif // TIMELINE_H
