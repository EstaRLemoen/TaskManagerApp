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

protected:
    void hide();
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *event);

private:
    QPoint drag_position;
    QSystemTrayIcon *tray_icon;
    bool is_moved;

    void init_all_parts();
    QPoint getTaskListPosition();   //TODO: 根据浮动按钮的全局位置获取TaskList应当被显示在何处
    //QPoint getTimeLinePosition()  //TODO: 类似上方
    QPoint getToolPosition(int ind);

public:
    //Below is sub widgets
    TaskList *tasklist;
    Template *template_;
    Adder *adder;
    Deleter *deleter;
    TemplateEditer *template_editer;
    //Searcher *seacher;


private slots:
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

};
#endif // WIDGET_H
