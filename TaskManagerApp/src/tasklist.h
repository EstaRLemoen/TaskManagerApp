#ifndef TASKLIST_H
#define TASKLIST_H

#include<QWidget>
#include "taskunit.h"
#include "template.h"

class TaskList:public QWidget{
    Q_OBJECT
private:
    int list_height;
    int list_width;
    std::vector<TaskUnit*> tasks;
    int getVaildId();
    const Template* template_;
    const ItemModel* getModel(const QString& model_name);
public:
    TaskList(int w,int h,Template* template_, QWidget *parent = nullptr);
    void switchVisibility();
    void addTask(std::vector<ItemUnit*> items);
    void delTask(int task_id);
    std::vector<TimeUnit*> getALLTimeUnit();
public slots:
    void getNewTaskMsg(std::vector<QString*> bItemDescrips);
};

#endif // TASKLIST_H
