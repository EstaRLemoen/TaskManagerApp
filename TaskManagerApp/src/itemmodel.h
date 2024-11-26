#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QWidget>
#include <QString>
#include <QLineEdit>

class ItemModel:public QWidget{
private:
    //const ItemType* type
    int order;
    bool is_visible_in_small_view;
    bool is_user;
    QString name;
    //Logo logo
public:
    ItemModel(int,QString,bool,bool);
    void setName(QString new_name);
    bool isUser()const;
    int getOrder()const;
    //TODO:
    //void setLogo(Logo new_logo);
    //void setType(const ItemType* new_type);
};



#endif // ITEMMODEL_H
