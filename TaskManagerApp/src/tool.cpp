#include "tool.h"
#include "constant.h"


#include <QToolBar>
#include <QPushButton>

//===================================== class Tool ==============================================
Tool::Tool(){
    //设置图标样式
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->resize(BOTTON_WIDHT, BOTTON_HEIGHT);
    this->botton = nullptr;
}

//============================ class Adder and AdderInputWidget ================================
AdderInputWidget::AdderInputWidget(QWidget* parent_){
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    this->setParent(parent_);

    QTextEdit* input_line;
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH;i++){
        input_line = new QTextEdit(this);
        input_line->resize(TITLE_BLOCK_WIDHT,TITLE_BLOCK_WIDHT);
        input_line->move(i*TITLE_BLOCK_WIDHT,BOTTON_HEIGHT);
        input_line->setPlaceholderText(BASIC_ITEM_NAME[i]);
        if(BASIC_ITEM_TYPE[i] == (int)ITEMTYPE_INDEX::TIME){
            input_line->setPlaceholderText(BASIC_ITEM_NAME[i] + ": " + "yyyy-MM-dd hh:mm:ss");
        }
        this->input_lines.push_back(input_line);
        input_line = nullptr;
    }
    this->resize(fmax(BASIC_ITEM_LIST_LENGTH*TITLE_BLOCK_WIDHT,
                     BOTTON_WIDHT*2)+10,
                 TITLE_BLOCK_HEIGHT+BOTTON_HEIGHT+10);

    QFont form_;
    form_.setPointSize(TEXT_SIZE);
    QPushButton* btn_save = new QPushButton;
    btn_save->setFont(form_);
    btn_save->setText("save task");
    btn_save->setFixedSize(TITLE_BLOCK_WIDHT,TITLE_BLOCK_HEIGHT);
    QPushButton* btn_cancel = new QPushButton;
    btn_cancel->setFont(form_);
    btn_cancel->setText("cancel");
    btn_cancel->setFixedSize(TITLE_BLOCK_WIDHT,TITLE_BLOCK_HEIGHT);

    QToolBar* toolbar = new QToolBar;
    toolbar->addWidget(btn_save);
    toolbar->addWidget(btn_cancel);

    this->addToolBar(toolbar);
    toolbar->setAllowedAreas(Qt::BottomToolBarArea);
    toolbar->setMovable(false);
    connect(btn_save,&QPushButton::clicked,this,&AdderInputWidget::save);
    connect(btn_cancel,&QPushButton::clicked,this,&AdderInputWidget::cancel);
}

void AdderInputWidget::switchVisibility(){
    if(isVisible())
        hide();
    else
        show();
}

void AdderInputWidget::save(){
    //TODO: collecting texts
    qDebug("Should collect texts and save it as itemunits, "
           "and send them to tasklist.");
    std::vector<QString*> b_item_descrips;
    QString* temp;
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH; i++){
        if(!checkDescripWithType(input_lines[i]->toPlainText(), BASIC_ITEM_TYPE[i])){
            qCritical("contain ERROR for this type");
            //report error
            return;
        }
    }
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH; i++){
        temp = new QString;
        *temp = (input_lines[i])->toPlainText();
        b_item_descrips.push_back(temp);
        input_lines[i]->setText("");
    }
    emit sendNewTaskMsg(b_item_descrips);
    this->hide();
}
void AdderInputWidget::cancel(){
    //TODO: cancel input content in `input_lines`
    //qDebug("Should cancel input content in the lines, and hide itself.");
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH; i++){
        input_lines[i]->setText("");
    }
    this->hide();
}

// lab5:only for test
void AdderInputWidget::testhelper_setInputs(QString str0, QString str1, QString str2, QString str3){
    input_lines[0]->setText(str0);
    input_lines[1]->setText(str1);
    input_lines[2]->setText(str2);
    input_lines[3]->setText(str3);
}
void AdderInputWidget::test_save(){
    qDebug() << "================BEGIN Template::AdderInputWidget::test_save=======================";
    qDebug() << "==============case0==============";
    testhelper_setInputs("this is a task", "2024-12-20 23:55:59", "desicription", "114514");save();
    qDebug() << "==============case1==============";
    testhelper_setInputs("gugu", "2012-43512-12 12:12:12", "gugu", "gugu");save();
    qDebug() << "==============case2==============";
    testhelper_setInputs("gugu", "2012-52-12 12:12:12", "gugu", "12134");save();
    qDebug() << "==============case3==============";
    testhelper_setInputs("2012-12-12 12:12:72", "2012-12-12 12:12:12", "gugu", "8.3512");save();
    qDebug() << "==============case4==============";
    testhelper_setInputs("gugu", "2024-12-20 23:55:59", "gugugu!", "324525");save();
    qDebug() << "==============case5==============";
    testhelper_setInputs("sgfd", "2024-12-20 23:55:59", "2012-12-12 12:12:12", "12ghfrstg");save();
    qDebug() << "==============case6==============";
    testhelper_setInputs("24323", "2012-12-12 12:12:12", "424", "-0.1234");save();
    qDebug() << "==============case7==============";
    testhelper_setInputs("\n", "fef", "53", "gu");save();
    qDebug() << "==============case8==============";
    testhelper_setInputs("?", "?", "?", "?");save();
    qDebug() << "==============case9==============";
    testhelper_setInputs("*(&^", "2012-12-12 12:12:12", "(*&(*", "-0.4432");save();
    qDebug() << "=================END AdderInputWidget::test_save========================";
    return;
}
void Adder::test_save(){
    if(this->input_widget == nullptr){
        qCritical("this adder DO NOT HAVE input_widget!!!!");
        exit(2);
    }
    this->input_widget->test_save();
}
// lab5 end


Adder::Adder(){
    //加载图标图片
    QImage background;
    background.load("://data/image/adder.png");
    background = background.scaled(BOTTON_WIDHT, BOTTON_HEIGHT);
    botton = new QLabel(this);
    botton->setPixmap(QPixmap::fromImage(background));
    botton->resize(BOTTON_WIDHT, BOTTON_HEIGHT);
    botton->move(0, 0);
    botton->show();
    //子窗口
    input_widget = new AdderInputWidget(nullptr);
    connect(input_widget,&AdderInputWidget::sendNewTaskMsg,this,&Adder::getNewTaskMsg);
}

void Adder::switchVisibility(){
    if(isVisible())
        hide();
    else
        show();
}

void Adder::getNewTaskMsg(std::vector<QString*> bItemDescrips){
    emit sendNewTaskMsg(bItemDescrips);
}

void Adder::mouseDoubleClickEvent(QMouseEvent *event){
    input_widget->switchVisibility();
}

void Adder::hide(){
    this->input_widget->hide();
    this->Tool::hide();
}

Adder::~Adder(){
    delete this->input_widget;
}

//=========================================== class Deleter ==============================================
Deleter::Deleter(){
    //加载图标图片
    QImage background;
    background.load("://data/image/deleter.png");
    background = background.scaled(BOTTON_WIDHT, BOTTON_HEIGHT);
    botton = new QLabel(this);
    botton->setPixmap(QPixmap::fromImage(background));
    botton->resize(BOTTON_WIDHT, BOTTON_HEIGHT);
    botton->move(0, 0);
    botton->show();
    //TODO: 完成Deleter功能
}

//=========================================== class TemplateEditer ==============================================
TemplateEditer::TemplateEditer(){
    //加载图标图片
    QImage background;
    background.load("://data/image/templateediter.png");
    background = background.scaled(BOTTON_WIDHT, BOTTON_HEIGHT);
    botton = new QLabel(this);
    botton->setPixmap(QPixmap::fromImage(background));
    botton->resize(BOTTON_WIDHT, BOTTON_HEIGHT);
    botton->move(0, 0);
    botton->show();
    //TODO: 完成TemplateEditer功能
}
