#include "constant.h"
#include <QDateTime>


bool checkDescripWithType(const QString& descrip, const int& type_idx){
    qDebug() << "descrip:" << descrip << "; type_idx:" << type_idx << "; ";
    qDebug() << "itemtype:" << (type_idx < ITEMTYPE_NUMBER? ITEMTYPE_LIST[type_idx]:"null");
    if(type_idx == (int)ITEMTYPE_INDEX::STR){
        return true;
    }
    else if(type_idx == (int)ITEMTYPE_INDEX::NUM){
        return descrip.toInt() || descrip.toFloat();
    }
    else if(type_idx == (int)ITEMTYPE_INDEX::TIME){
        return QDateTime::fromString(descrip, "yyyy-MM-dd hh:mm:ss").isValid();
    }
    else{
        qCritical("type with this index do not exist!!!!!!");
        return false;
    }
}


// lab5:only for test
void test_checkDescripWithType(){
    qDebug() << "================BEGIN test_checkDescripWithType=======================";
    qDebug() << "==============case0==============";
    qDebug() << checkDescripWithType("gugugugu",(int)ITEMTYPE_INDEX::STR);
    qDebug() << "==============case1==============";
    qDebug() << checkDescripWithType("*^*5455$&(咕咕咕",(int)ITEMTYPE_INDEX::STR);
    qDebug() << "==============case2==============";
    qDebug() << checkDescripWithType("114514",(int)ITEMTYPE_INDEX::NUM);
    qDebug() << "==============case3==============";
    qDebug() << checkDescripWithType("gudsa",(int)ITEMTYPE_INDEX::NUM);
    qDebug() << "==============case4==============";
    qDebug() << checkDescripWithType("1.5641",(int)ITEMTYPE_INDEX::NUM);
    qDebug() << "==============case5==============";
    qDebug() << checkDescripWithType("fasdgf&*^(*f",(int)ITEMTYPE_INDEX::TIME);
    qDebug() << "==============case6==============";
    qDebug() << checkDescripWithType("2024-12-45 01:01:01",(int)ITEMTYPE_INDEX::TIME);
    qDebug() << "==============case7==============";
    qDebug() << checkDescripWithType("2024-13-16 01:01:01",(int)ITEMTYPE_INDEX::TIME);
    qDebug() << "==============case8==============";
    qDebug() << checkDescripWithType("2025-1-12 24:01:01",(int)ITEMTYPE_INDEX::TIME);
    qDebug() << "==============case9==============";
    qDebug() << checkDescripWithType("2025-1-12 01:60:01",(int)ITEMTYPE_INDEX::TIME);
    qDebug() << "==============case10==============";
    qDebug() << checkDescripWithType("gugugugu",10);
    qDebug() << "=================END test_checkDescripWithType========================";
    return;
}
