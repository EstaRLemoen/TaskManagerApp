#include "constant.h"
#include "itemmodel.h"

ItemModel::ItemModel(int order, QString name,int type_idx, bool visibility,bool usr){
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    this->order = order;
    this->name = new QTextEdit(this);
    this->name->setText(name);
    connect(this->name,&QTextEdit::textChanged,this,&ItemModel::setName);
    this->name ->resize(TITLE_BLOCK_WIDHT,TITLE_BLOCK_HEIGHT);
    this->name ->move(TITLE_BLOCK_WIDHT,0);
    this->real_name = name;
    this->type_index = type_idx;
    this->is_visible_in_small_view = visibility;
    this->is_user = usr;
    if(!usr){
        this->name->setReadOnly(true);
    }
    //TODO: this->logo = ...; this->type = ...;

    //TODO: init appearance
    //this->resize(...);
    //...
    show();
    if(!this->is_visible_in_small_view){
        qDebug() << "this model is not visible in small view.";
        hide(); // temp for it to be unshown in template window
    }
}

void ItemModel::setName(){
    QString new_name = this->name->toPlainText();
    if(new_name == this->real_name){
        return;
    }
    emit allocateNewName(new_name);
}

void ItemModel::useEditName(){
    real_name = this->name->toPlainText();
}

void ItemModel::nameFallback(){
    this->name->setText(real_name);
}

//=================================================================

bool ItemModel::isUser()const{
    return this->is_user;
}

int ItemModel::getOrder()const{
    return this->order;
}

const QTextEdit* ItemModel::getNameTextEdit() const{
    return this->name;
}

QString ItemModel::getName() const{
    return this->real_name;
}

QString ItemModel::getTypeName() const{
    assert(this->type_index < ITEMTYPE_NUMBER);
    return ITEMTYPE_LIST[this->type_index];
}

QString ItemModel::toString()const{
    QString res;
    res += "{name:";
    res += this->real_name;
    res += ", is_visible_in_small_view:";
    res += (this->is_visible_in_small_view? "True":"False");
    res += ", is_user:";
    res += (this->is_user? "True":"False");
    res += ", type:";
    res += ITEMTYPE_LIST[this->type_index];
    res += "}";
    return res;
}
