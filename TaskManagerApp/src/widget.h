#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QScreen>
#include <QPoint>

#include "tasklist.h"
#include "tool.h"
#include "template.h"

#define DEFAULT_TASKLIST_WIDTH 300
#define DEFAULT_TASKLIST_HEIGHT 700

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;


private:
    QPoint drag_position;
    QSystemTrayIcon *tray_icon;
    bool is_moved;
    //BELOW: sub widgets
    TaskList *tasklist;
    Template *template_;
    Adder *adder;
    Deleter *deleter;
    TemplateEditer *template_editer;
    //Searcher *seacher;
    void init_all_parts();

protected:
    void hide();
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *event);
    QPoint getTaskListPosition(); //TODO: 根据浮动按钮的全局位置获取TaskList应当被显示在何处
    QPoint getTimeLinePosition(){return QPoint(0,0);}; //TODO:
    //QPoint (){return maptoGlobal(QPoint(0,0));};
private slots:
    //void showWindow();
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

};
#endif // WIDGET_H
