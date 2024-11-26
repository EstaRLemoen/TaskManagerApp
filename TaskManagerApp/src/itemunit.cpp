#include "itemunit.h"

ItemUnit::ItemUnit(const ItemModel* my_mod, QString descripe){
    this->my_model = my_mod;
    this->description = descripe;
    if(this->my_model != nullptr){
        this->showModelInfo();
    }
}

ItemUnit& ItemUnit::operator=(const ItemUnit& other){
    this->my_model = other.my_model;
    this->description = other.description;
    if(this->my_model != nullptr){
        this->showModelInfo();
    }
    return *this;
}

void ItemUnit::showModelInfo(){
    if(this->my_model == nullptr){
        qCritical("Critical: Nullptr is connected to a `ItemUnit` as its model!");
        return;
    }
    qDebug("TODO：connect the `logo` and `name` of `my_model` to itemunit's own appearance.");
}

void ItemUnit::setDescription(QString new_descripe){
    this->description = new_descripe;
}

bool ItemUnit::isBelongModel(const ItemModel* mod)const{
    return (this->my_model == mod);
}

QString ItemUnit::toQString(){
    ;// TODO: toStirng, for debuging and save data
}

