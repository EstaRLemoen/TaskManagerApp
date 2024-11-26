#ifndef TIMELINE_H
#define TIMELINE_H

#include <QWidget>
#include "timeunit.h"

class TimeLine:public QWidget{
    Q_OBJECT
private:
    std::vector<TimeUnit*> timeunits;
public:
    TimeLine(){;}
    //TODO
};

#endif // TIMELINE_H
