#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QSystemTrayIcon>

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
    QPointF dragPosition;
    QSystemTrayIcon *trayIcon;
    bool is_moved;
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *event);
private slots:
    void showWindow();
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

};
#endif // WIDGET_H
