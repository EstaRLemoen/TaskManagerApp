#ifndef TOOL_H
#define TOOL_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>

class Tool:public QWidget{
    Q_OBJECT
public:
    Tool();
protected:
    QLabel* botton;
};

class AdderInputWidget: public QMainWindow{
    Q_OBJECT
private:
    std::vector<QTextEdit*> input_lines;
public:
    AdderInputWidget();
public slots:
    void switchVisibility();
    void save();
    void cancel();
};

class Adder:public Tool{
    Q_OBJECT
private:
    AdderInputWidget* input_widget;
public:
    Adder();
public slots:
    void switchVisibility();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
};

class Deleter:public Tool{
    Q_OBJECT
public:
    Deleter();
    //TODO: Finish Deleter
};

class TemplateEditer:public Tool{
    Q_OBJECT
public:
    TemplateEditer();
};

//TODO: class Searcher:public Tool


#endif // TOOL_H
