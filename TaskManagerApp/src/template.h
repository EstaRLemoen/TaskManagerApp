#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QWidget>
#include "itemmodel.h"

class Template:public QWidget{
    Q_OBJECT
private:
    std::vector<ItemModel*> all_model;
    void createBasicModel();
    bool addUserModel(QString new_mod_name, int new_mod_type_idx, bool new_mod_visibility);
    bool deleteUserModel(QString mod_name);
protected:
    void closeEvent(QCloseEvent *event);
public slots:
    void checkNewName(QString new_name);
public:
    Template();
    const ItemModel* getModel(const QString& model_name)const;
    //TODO:
    //1. finish the `Template` Edition just like `TaskList`
    //2. template and tasklist should be able to switch infomation.

    // lab5:only for test
    void test_addUserModel();
    void test_getModel();
    // lab5 end
};

#endif // TEMPLATE_H
