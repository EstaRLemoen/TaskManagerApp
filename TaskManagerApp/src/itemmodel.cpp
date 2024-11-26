#include"itemmodel.h"

ItemModel::ItemModel(int order, QString name,bool visbility,bool usr){
    this->order = order;
    this->name = name;
    this->is_visible_in_small_view = visbility;
    this->is_user = usr;
    //TODO: this->logo = ...; this->type = ...;

    //TODO: init appearance
    //this->resize(...);
    //this->setWindowTitle(this->name);
    //...
    hide();
}

void ItemModel::setName(QString new_name){
    this->name = new_name;
}

bool ItemModel::isUser()const{
    return this->is_user;
}

int ItemModel::getOrder()const{
    return this->order;
}
