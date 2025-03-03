#include "constant.h"
#include "tasklist.h"
#include "itemunit.h"

TaskList::TaskList(int w,int h,Template* template_, QWidget* parent){
    this->setParent(parent);
    list_width=0;
    list_height=0;
    this->resize(w,h);
    this->template_ = template_;
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    hide();
}

void TaskList::switchVisibility(){
    if(isVisible())
        hide();
    else
        show();
}

void TaskList::addTask(std::vector<ItemUnit*> items){
    TaskUnit* new_task = new TaskUnit(items);
    new_task->setParent(this);
    new_task->setOrderInList(this->tasks.size());
    new_task->setId(this->getVaildId());
    new_task->move(0, list_height);
    this->list_height = list_height + new_task->size().rheight();
    this->tasks.push_back(new_task);
    new_task->show();
    qDebug().noquote() << new_task->toQString();
}

void TaskList::delTask(int task_id){
    for (std::vector<TaskUnit*>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        if ((*it)->getId() == task_id) {
            tasks.erase(it);
            return;
        }
    }
    qCritical("DO NOT EXIST a task with the id to delete. ");
}

int TaskList::getVaildId(){
    //TODO: remove old lines below, finish correctly.
    static int seed = -1;
    seed++;
    int new_id;
    new_id = seed;
    return new_id;
}

const ItemModel* TaskList::getModel(const QString& model_name){
    return this->template_->getModel(model_name);
}

void TaskList::getNewTaskMsg(std::vector<QString*> bItemDescrips){
    //TODO: assert about vector length etc.
    std::vector<ItemUnit*> items;
    ItemUnit* item = NULL;
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH;++i){
        item = new ItemUnit(this->getModel(BASIC_ITEM_NAME[i]), *(bItemDescrips[i]));
        items.push_back(item);
        item = NULL;
    }
    bItemDescrips.clear();
    addTask(items);
}

std::vector<TimeUnit*> TaskList::getALLTimeUnit(){
    std::vector<TimeUnit*> t_units;
    for(std::vector<TaskUnit*>::iterator it = tasks.begin(); it != tasks.end(); ++it) {
        t_units.push_back((*it)->getTimeUnit());
    }
}

