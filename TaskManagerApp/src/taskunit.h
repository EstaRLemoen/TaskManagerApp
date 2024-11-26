#ifndef TASKUNIT_H
#define TASKUNIT_H

#include <QWidget>
#include "itemunit.h"
#include "timeunit.h"
#include "remindunit.h"

class TaskUnit: public QWidget{
    Q_OBJECT
private:
    int id;
    int order_in_list;
    std::vector<ItemUnit*> my_items;
    bool is_urgent;
    bool is_folded;
    void sortMyItems();
public slots:
    void renewUrgency();
public:
    TaskUnit(std::vector<ItemUnit*> items);
    TaskUnit& operator=(const TaskUnit& other);
    void removeItem(const ItemModel* model);
    void setOrderInList(int order);
    void setId(int id);
    int getId()const;

    void fold();
    void unfold();
    TimeUnit getTimeUnit();
    RemindUnit getRemindUnit();
    QString toQString();

};

#endif // TASKUNIT_H
