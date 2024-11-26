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
AdderInputWidget::AdderInputWidget(){
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

    QTextEdit* input_line;
    for(int i = 0; i < BASIC_ITEM_LIST_LENGTH;i++){
        input_line = new QTextEdit(this);
        input_line->resize(TITLE_BLOCK_WIDHT,TITLE_BLOCK_WIDHT);
        input_line->move(i*TITLE_BLOCK_WIDHT,BOTTON_HEIGHT);
        input_line->setPlaceholderText(BASIC_ITEM_NAME[i]);

        this->input_lines.push_back(input_line);
        input_line = nullptr;
    }
    this->resize(fmax(BASIC_ITEM_LIST_LENGTH*TITLE_BLOCK_WIDHT,
                     BOTTON_WIDHT * 2),
                 TITLE_BLOCK_HEIGHT+BOTTON_HEIGHT);

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
}
void AdderInputWidget::cancel(){
    //TODO: cancel input content in `input_lines`
    qDebug("Should cancel input content in the lines, "
           "and hide itself.");
    this->hide();
}

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
    input_widget = new AdderInputWidget;
}

void Adder::switchVisibility(){
    if(isVisible())
        hide();
    else
        show();
}

void Adder::mouseDoubleClickEvent(QMouseEvent *event){
    input_widget->switchVisibility();
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
