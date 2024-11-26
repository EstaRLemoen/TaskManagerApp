#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QWidget>
#include "itemmodel.h"

class Template:public QWidget{
    Q_OBJECT
private:
    std::vector<ItemModel*> all_model;
public:
    Template(){;}
    //TODO:
    //1. finish the `Template` Edition just like `TaskList`
    //2. template and tasklist should be able to switch infomation.
};

#endif // TEMPLATE_H
