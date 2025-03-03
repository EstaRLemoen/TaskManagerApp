#include "template.h"
#include "constant.h"
#include <vector>
#include <QCloseEvent>

Template::Template(){
    //hide();
    this->setWindowTitle("Template");
    //setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    this->resize(DEFAULT_TASKLIST_WIDTH,DEFAULT_TASKLIST_HEIGHT);
    createBasicModel();
}

void Template::createBasicModel(){
    ItemModel* temp;
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH; i++){
        temp = new ItemModel(i,BASIC_ITEM_NAME[i],BASIC_ITEM_TYPE[i],true,false);
        temp->setParent(this);
        temp->move(0,TITLE_BLOCK_HEIGHT*i);
        this->all_model.push_back(temp);
        connect(temp,&ItemModel::allocateNewName,this,&Template::checkNewName);
    }
    return;
}

bool Template::addUserModel(QString new_mod_name, int new_mod_type_idx, bool new_mod_visibility){
    if(new_mod_type_idx >= ITEMTYPE_NUMBER){
        qDebug("type_idx for new_mod_name is invaild! Add user model FAILED.");
        return false;
    }
    if(this->getModel(new_mod_name) != nullptr){
        qDebug("name for new_mod_name is already used! Add user model FAILED.");
        return false;
    }

    ItemModel* temp;
    int idx = all_model.size();
    temp = new ItemModel(idx, new_mod_name, new_mod_type_idx, new_mod_visibility, true);
    temp->setParent(this);
    temp->move(0,TITLE_BLOCK_HEIGHT*idx);
    this->all_model.push_back(temp);
    connect(temp,&ItemModel::allocateNewName,this,&Template::checkNewName);
    if(new_mod_visibility){
        temp->show();
    }

    qDebug() << "Add user model SUCCEED. New Itemmodel: " << temp->toString();
    return true;
}

bool Template::deleteUserModel(QString mod_name){
    // 1. delete
    for(int i = 0 ; i < all_model.size(); i++){
        if(all_model[i]->getName() == mod_name){
            qDebug() << "DELETE MODEL: " << mod_name;
            ItemModel* temp = all_model[i];
            all_model.erase(all_model.begin()+i);
            delete temp;
            // 2. TODO: should resort it!
            return true;
        }
    }
    return false;
}

const ItemModel* Template::getModel(const QString& model_name)const{
    for(int i = 0 ; i < all_model.size(); i++){
        if(all_model[i]->getName() == model_name){
            qDebug() << "FIND MODEL: " << model_name;
            return all_model[i];
        }
    }
    qDebug() << "DO NOT FIND MODEL: " << model_name;
    return nullptr;
}

void Template::checkNewName(QString new_name){
    const ItemModel* conflict_model;
    conflict_model = getModel(new_name);
    int count_m = all_model.size();
    if(conflict_model == nullptr){
        for(int i = 0; i < count_m; ++i){
            if(all_model[i] == sender()){
                all_model[i]->useEditName();
                qDebug() << all_model[i]->toString() << "is allowed to use new name: " << new_name;
                break;
            }
        }
    }
    else{
        for(int i = 0; i < count_m; ++i){
            if(all_model[i] == sender()){
                all_model[i]->nameFallback();
                qDebug() << all_model[i]->toString() << "allocate new name FAILED. the illegal new name: " << new_name ;
                break;
            }
        }
    }
    return;
}

void Template::closeEvent(QCloseEvent *event){
    // 拦截关闭事件，仅最小化到托盘
    hide();
    event->ignore();
}


// lab5:only for test
void Template::test_addUserModel(){
    qDebug() << "================BEGIN Template::test_addUserModel=======================";
    qDebug() << "==============case0==============";
    this->addUserModel("name",0,true);
    qDebug() << "==============case1==============";
    this->addUserModel("gugu1",0,true);
    qDebug() << "==============case2==============";
    this->addUserModel("gugu1",1,true);
    qDebug() << "==============case3==============";
    this->addUserModel("gugu2",2,true);
    qDebug() << "==============case4==============";
    this->addUserModel("gugu2",2,false);
    qDebug() << "==============case5==============";
    this->addUserModel("gugu3",1,true);
    qDebug() << "==============case6==============";
    this->addUserModel("gugu4",0,false);
    qDebug() << "==============case7==============";
    this->addUserModel("gugu5",2,false);
    qDebug() << "==============case8==============";
    this->addUserModel("gugu6",1,true);
    qDebug() << "==============case9==============";
    this->addUserModel("gugu7",10,false);
    qDebug() << "=================END Template::test_addUserModel========================";
    return;
}

void Template::test_getModel(){
    qDebug() << "================BEGIN Template::test_getModel=======================";
    qDebug() << "==============case0==============";
    qDebug() << getModel("gugugu");
    qDebug() << "==============case1==============";
    qDebug() << getModel("name");
    qDebug() << "==============case2==============";
    qDebug() << getModel("NAME");
    qDebug() << "==============case3==============";
    qDebug() << getModel(" name  ");
    qDebug() << "==============case4==============";
    qDebug() << getModel("ddl");
    qDebug() << "==============case5==============";
    this->addUserModel("gugu",0,true);
    qDebug() << getModel("gugu");
    qDebug() << "==============case6==============";
    qDebug() << getModel("gugugu");
    qDebug() << "==============case7==============";
    this->deleteUserModel("gugu");
    qDebug() << getModel("gugu");
    qDebug() << "==============case8==============";
    qDebug() << getModel("234562354");
    qDebug() << "==============case9==============";
    qDebug() << getModel("*^&**(&");
    qDebug() << "=================END Template::test_getModel========================";
    return;
}

// lab5 end
