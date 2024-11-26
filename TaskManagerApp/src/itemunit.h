#ifndef ITEMUNIT_H
#define ITEMUNIT_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include "itemmodel.h"

class ItemUnit: public QWidget{
    Q_OBJECT
private:
    const ItemModel* my_model;
    QString description;
public:
    ItemUnit(const ItemModel* my_mod, QString descripe);
    ItemUnit& operator=(const ItemUnit& other);
    void showModelInfo();
    void setDescription(QString descripe);
    bool isBelongModel(const ItemModel* model)const;
    QString toQString();
};

#endif // ITEMUNIT_H
