#include "taskunit.h"

TaskUnit::TaskUnit(std::vector<ItemUnit*> items){
    this->id = -1;
    this->order_in_list = -1;
    this->my_items = items;
    this->is_urgent = false;
    this->is_folded = false;
}

TaskUnit& TaskUnit::operator=(const TaskUnit& other){
    this->id = other.id;
    this->order_in_list = other.order_in_list;
    this->my_items = other.my_items;
    this->is_urgent = other.is_urgent;
    this->is_folded = other.is_folded;
    return *this;
}

//================================== private ============================================
void TaskUnit::sortMyItems(){
    ;// TODO: 1. Item sort(with the item->my_model->order) and list in taskunit
}

//================================== public slot ========================================
void TaskUnit::renewUrgency(){
    ;// TODO: 2. connect to a global clock, renew its `is_urgent` per second.
}


//===================================== public ==========================================
void TaskUnit::removeItem(const ItemModel* model){
    if(model == nullptr){
        qCritical("Should not use a nullptr `model` to remove item. ");
        return;
    }
    if(!model->isUser()){
        qCritical("Should not use a BASIC `model` to remove item. ");
        return;
    }
    for (std::vector<ItemUnit*>::iterator it = my_items.begin(); it != my_items.end(); it++) {
        if ((*it)->isBelongModel(model)) {
            my_items.erase(it);
        }
    }
}

void TaskUnit::setOrderInList(int order){
    this->order_in_list = order;
}

void TaskUnit::setId(int id){
    this->id = id;
}

int TaskUnit::getId()const{
    return this->id;
}


void TaskUnit::fold(){
    ;// TODO: 3.1 Fold
}
void TaskUnit::unfold(){
    ;// TODO: 3.2 Unfold
}

// TODO: 4. offer infomation for TimeLine and Reminder
//TimeUnit TaskUnit::getTimeUnit(){}
//RemindUnit TaskUnit::getRemindUnit(){}


QString TaskUnit::toQString(){
    ;// TODO: 5. toStirng, for debuging and save data
}

//=====================================================================================
