#include "widget.h"
#include "./ui_widget.h"

#include "QImage"
#include "QLabel"
#include "QMouseEvent"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

QPoint Widget::getTaskListPosition(){
    //TODO
    return QPoint(0,0);
}

void Widget::init_all_parts(){
    this->tasklist = new TaskList(DEFAULT_TASKLIST_WIDTH,DEFAULT_TASKLIST_HEIGHT);
    this->tasklist->hide();
    //TODO: template_
    this->adder = new Adder();
    this->adder->hide();
    // TODO: deleter, template_editer, searcher
    // TODO: Timeline
    // TODO: Reminder
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->is_moved = false;

    //增加托盘图标
    //  创建系统托盘图标
    this->tray_icon = new QSystemTrayIcon(this);
    this->tray_icon->setIcon(QIcon("://data/image/floatingbutton.png"));
    this->tray_icon->setToolTip("TaskManagerApp");
    //  创建托盘菜单
    QMenu *tray_menu = new QMenu(this);
    QAction *show_action = new QAction("显示窗口", this);
    QAction *unshow_action = new QAction("隐藏窗口", this);
    QAction *exit_action = new QAction("退出", this);
    tray_menu->addAction(show_action);
    tray_menu->addAction(unshow_action);
    tray_menu->addAction(exit_action);
    //  绑定托盘菜单
    this->tray_icon->setContextMenu(tray_menu);
    //  信号与槽
    connect(show_action, &QAction::triggered, this, &Widget::show);//showWindow);
    connect(unshow_action, &QAction::triggered, this, &Widget::hide);
    connect(exit_action, &QAction::triggered, qApp, &QApplication::quit);
    connect(tray_icon, &QSystemTrayIcon::activated, this, &Widget::onTrayIconActivated);
    //  显示托盘图标
    this->tray_icon->show();
    //  隐藏任务栏图标
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

    //设置图标样式
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->resize(46, 40);
    //加载图标图片
    QImage background;
    background.load("://data/image/floatingbutton.png");
    background = background.scaled(46, 40);
    QLabel* botton = new QLabel(this);
    botton->setPixmap(QPixmap::fromImage(background));
    botton->resize(46, 40);
    botton->move(0, 0);
    botton->show();

    this->init_all_parts();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::hide(){
    this->QWidget::hide();
    this->tasklist->hide();
    this->adder->hide();
    //this->deleter->hide();
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {

        this->drag_position = event->globalPosition().toPoint() - this->pos();
        //event->accept();
    }
    if(event->button()==Qt::RightButton)
    {
        ;//close();
    }
}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        int x=0, y=0;

        //x = event->globalPosition().rx() - dragPosition.rx();
        //y = event->globalPosition().ry() - dragPosition.ry();
        move(event->globalPosition().toPoint()-(this->drag_position));

        //TODO: taskList->move(x',y');

        //TODO: adder->move(x'',y'');

        //TODO: deleter->move(x''',y''');

        //TODO:...

        event->accept();
        this->is_moved = true;
        //qDebug("should move the FloatingButton along with other widgets");
    }

}

/*
void Widget::showWindow() {
    showNormal(); // 恢复窗口
    //raise();      // 确保窗口在最前
    activateWindow();   //TODO:这是什么?
}
*/

void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(!this->is_moved){
        if(event->button()==Qt::LeftButton){
            tasklist->switchVisibility();
            adder->switchVisibility();
            //qDebug("should TaskList on/off");
            event->accept();
        }
        else if(event->button()==Qt::RightButton){

            qDebug("should TimeLine on/off");
            event->accept();
        }
    }
    else{
        this->is_moved = false;
    }
}

void Widget::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason){
    if (reason == QSystemTrayIcon::Trigger) { // 单击托盘图标
        if (isHidden()) {
            //showWindow();
            show();
        } else {
            hide();
        }
    }
}

void Widget::closeEvent(QCloseEvent *event){
    // 拦截关闭事件，仅最小化到托盘
    if (this->tray_icon->isVisible()) {
        hide();
        event->ignore();
    }
}


