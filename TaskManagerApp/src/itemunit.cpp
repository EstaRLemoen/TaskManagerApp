#include "constant.h"
#include "itemunit.h"

ItemUnit::ItemUnit(const ItemModel* my_mod, QString descripe){
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->resize(TITLE_BLOCK_WIDHT,3*TITLE_BLOCK_HEIGHT);

    this->my_model = my_mod;

    this->model_name = new QTextBrowser(this);
    this->model_name ->resize(TITLE_BLOCK_WIDHT,TITLE_BLOCK_HEIGHT);
    this->model_name ->move(0,0);

    this->description = new QTextEdit(this);
    this->description->setText(descripe);
    this->description->resize(TITLE_BLOCK_WIDHT,2*TITLE_BLOCK_HEIGHT);
    this->description->move(0,TITLE_BLOCK_HEIGHT);

    if(this->my_model != nullptr){
        this->connectModel();
    }
    else{
        qCritical("Created a ItemUnit with nullptr for its ItemModel! Error 1");
        exit(1);
    }
    qDebug() << this->toString();
}

ItemUnit& ItemUnit::operator=(const ItemUnit& other){
    this->my_model = other.my_model;
    this->description->setText(other.description->toPlainText());
    if(this->my_model != nullptr){
        this->connectModel();
    }
    return *this;
}

void ItemUnit::connectModel(){
    if(this->my_model == nullptr){
        qCritical("Critical: Nullptr is connected to this `ItemUnit` as its model!");
        return;
    }
    //qDebug("TODO：connect the `logo` of `my_model` to itemunit's own appearance.");
    model_name->setText(my_model->getName());
    connect(my_model->getNameTextEdit(), &QTextEdit::textChanged, this, &ItemUnit::updateModel);
}

void ItemUnit::updateModel(){
    model_name->setText(my_model->getName());
}

void ItemUnit::setDescription(QString new_descripe){
    this->description->setText(new_descripe);
}

bool ItemUnit::isBelongModel(const ItemModel* mod)const{
    return (this->my_model == mod);
}

QString ItemUnit::toString()const{
    QString res;
    res += "{model:";
    if(this->model_name != nullptr){
        res += this->my_model->toString();
    }
    else{
        res += "nullptr";
    }
    res += ", description:";
    res += this->description->toPlainText();
    res += "}";
    return res;
}

