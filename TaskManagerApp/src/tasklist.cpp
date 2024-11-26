#include"tasklist.h"

TaskList::TaskList(int w,int h,QWidget* p){
    list_width=w;
    list_height=h;
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
    new_task->setOrderInList(this->tasks.size());
    new_task->setId(this->getVaildId());
    this->tasks.push_back(new_task);
}

void TaskList::delTask(int task_id){
    for (std::vector<TaskUnit*>::iterator it = tasks.begin(); it != tasks.end(); it++) {
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
