#ifndef ITEMUNIT_H
#define ITEMUNIT_H

#include <QWidget>
#include <QString>
#include <QTextBrowser>
#include <QTextEdit>
#include "itemmodel.h"

class ItemUnit: public QWidget{
    Q_OBJECT
private:
    const ItemModel* my_model;
    QTextBrowser* model_name;
    QTextEdit* description;
public slots:
    void updateModel();
public:
    ItemUnit(const ItemModel* my_mod, QString descripe);
    ItemUnit& operator=(const ItemUnit& other);
    void connectModel();
    void setDescription(QString descripe);
    bool isBelongModel(const ItemModel* model)const;
    QString toString() const;
};

#endif // ITEMUNIT_H
