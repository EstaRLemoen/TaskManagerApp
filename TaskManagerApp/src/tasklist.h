#ifndef TASKLIST_H
#define TASKLIST_H

#include<QWidget>
#include "taskunit.h"

class TaskList:public QWidget{
    Q_OBJECT
private:
    int list_height;
    int list_width;
    std::vector<TaskUnit*> tasks;
    int getVaildId();
public:
    TaskList(int w,int h,QWidget *parent = nullptr);
    void switchVisibility();
    void addTask(std::vector<ItemUnit*> items);
    void delTask(int task_id);
};

#endif // TASKLIST_H
