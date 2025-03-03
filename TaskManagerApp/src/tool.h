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
signals:
    void sendNewTaskMsg(std::vector<QString*> bItemDescrips);
public slots:
    void switchVisibility();
    void save();
    void cancel();
public:
    AdderInputWidget(QWidget* parent_);

    // lab5:only for test
    void testhelper_setInputs(QString str0, QString str1, QString str2, QString str3);
    void test_save();
    // lab5 end
};

class Adder:public Tool{
    Q_OBJECT
private:
    AdderInputWidget* input_widget;
signals:
    void sendNewTaskMsg(std::vector<QString*> bItemDescrips);
public:
    Adder();
    ~Adder();
public slots:
    void switchVisibility();
    void getNewTaskMsg(std::vector<QString*> bItemDescrips);
public:
    void hide();
    // lab5:only for test
    void test_save();
    // lab5 end
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    //TODO: reload the hide to hide its `input_widget`
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
