#include "timeunit.h"

TimeUnit::TimeUnit(int task_id, const QString* task_name, const QString* task_ddl, const bool* task_urgency){
    this->task_id = task_id;
    this->name = task_name;
    this->ddl = task_ddl;
    this->is_urgent = task_urgency;
    // TODO: Finish TimeUnit
}

void TimeUnit::renewUrgency(){
    // TODO: renew its urgency with a global clock
    return;
}

bool TimeUnit::isBelongTask(int id)const{
    return (this->task_id == id);
}
bool TimeUnit::isUrgent()const{
    return this->is_urgent;
}
