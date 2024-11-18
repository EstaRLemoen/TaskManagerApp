#include "widget.h"
#include "./ui_widget.h"

#include "QImage"
#include "QLabel"
#include "QMouseEvent"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    is_moved = false;

    //设置图标样式
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->resize(46, 40);
    //加载图标图片
    QImage background;
    background.load("./resource/image/floatingbutton.png");
    background = background.scaled(46, 40);
    QLabel* botton = new QLabel(this);
    botton->setPixmap(QPixmap::fromImage(background));
    botton->resize(46, 40);
    botton->move(0, 0);
    botton->show();

    //增加托盘图标
    //  创建系统托盘图标
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("./resource/image/floatingbutton.png")); // 设置托盘图标
    trayIcon->setToolTip("托盘示例应用");
    //  创建托盘菜单
    QMenu *trayMenu = new QMenu(this);
    QAction *showAction = new QAction("显示窗口", this);
    QAction *exitAction = new QAction("退出", this);
    trayMenu->addAction(showAction);
    trayMenu->addAction(exitAction);
    //  绑定托盘菜单
    trayIcon->setContextMenu(trayMenu);
    //  信号与槽
    connect(showAction, &QAction::triggered, this, &Widget::showWindow);
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &Widget::onTrayIconActivated);
    //  显示托盘图标
    trayIcon->show();
    //  隐藏任务栏图标
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        dragPosition = event->globalPosition() - this->pos();
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
        x = event->globalPosition().rx() - dragPosition.rx();
        y = event->globalPosition().ry() - dragPosition.ry();
        move(x,y);
        event->accept();
        is_moved = true;
        //qDebug("should Just move the FloatingButton");
    }

}

void Widget::showWindow() {
    showNormal(); // 恢复窗口
    raise();      // 确保窗口在最前
    activateWindow();   //TODO:这是什么?
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(!is_moved){
        if(event->button()==Qt::LeftButton){
            qDebug("should TaskList on/off");
            event->accept();
        }
        else if(event->button()==Qt::RightButton){
            qDebug("should TimeLine on/off");
            event->accept();
        }
    }
    else{
        is_moved = false;
    }
}

void Widget::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason){
    if (reason == QSystemTrayIcon::Trigger) { // 单击托盘图标
        if (isHidden()) {
            showWindow();
        } else {
            hide();
        }
    }
}

void Widget::closeEvent(QCloseEvent *event){
    // 拦截关闭事件，仅最小化到托盘
    if (trayIcon->isVisible()) {
        hide();
        event->ignore();
    }
}

