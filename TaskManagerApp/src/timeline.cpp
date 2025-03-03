#include "timeline.h"

TimeLine::TimeLine(TaskList* tlist){
    if(tlist == nullptr){
        qCritical("init reminder with nullptr tlist! reminder can't work therefore.");
        exit(1);
    }
    this->tasklist_ = tlist;

}

void TimeLine::sortUnit(){
    //TODO
}

void TimeLine::renew_contain(){
    this->timeunits.clear();
    this->timeunits = this->tasklist_->getALLTimeUnit();
    this->sortUnit();
}
