#include "constant.h"
#include "taskunit.h"

TaskUnit::TaskUnit(std::vector<ItemUnit*> items){
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    int x = 0, y = 0;
    this->id = -1;
    this->order_in_list = -1;
    this->my_items = items;
    for(int i = 0; i < items.size(); ++i){
        items[i]->setParent(this);
        items[i]->move(x,0);
        items[i]->show();
        x += items[i]->size().rwidth();
        y = fmax(items[i]->size().rheight(),y);
    }
    this->resize(x+TITLE_BLOCK_WIDHT,y);
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
    for (std::vector<ItemUnit*>::iterator it = my_items.begin(); it != my_items.end(); ++it) {
        if ((*it)->isBelongModel(model)) {
            my_items.erase(it);
            return;
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

TimeUnit* TaskUnit::getTimeUnit(){
    // TODO: 4.1 offer infomation for TimeLine
    return nullptr;
}
std::vector<QString*> TaskUnit::getRemindMessage(){
    std::vector<QString*> msgs;
    // TODO: 4.2 offer infomation for Reminder

    return msgs;
}


QString TaskUnit::toQString(){
    // TODO: 5. toStirng, for debuging and save data
    QString str = "{id:";
    str += QString::number(this->id);
    str += ", order_in_list:";
    str += QString::number(this->order_in_list);
    str += ", items:{";
    for (std::vector<ItemUnit*>::iterator it = my_items.begin(); it != my_items.end(); ++it) {
        str += "\t\n";
        str += (*it)->toString();
    }
    str += "}}";
    return str;
}

//=====================================================================================
