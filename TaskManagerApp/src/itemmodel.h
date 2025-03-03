#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QWidget>
#include <QString>
#include <QTextEdit>

class ItemModel:public QWidget{
    Q_OBJECT
private:
    int order;
    bool is_visible_in_small_view;
    bool is_user;
    QTextEdit* name;
    QString real_name;
    int type_index;
    //Logo logo

signals:
    void allocateNewName(QString);
public slots:
    void useEditName();
    void nameFallback();
    void setName();
public:
    ItemModel(int order, QString name,int type_idx, bool visibility,bool usr);
    const QTextEdit* getNameTextEdit() const;
    QString getTypeName()const;
    QString getName()const;
    bool isUser()const;
    int getOrder()const;
    QString toString() const;
    //TODO:
    //void setLogo(Logo new_logo);
    //void setType(const ItemType* new_type);
};



#endif // ITEMMODEL_H
