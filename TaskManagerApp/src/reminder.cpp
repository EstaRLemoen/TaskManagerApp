#include "reminder.h"

Reminder::Reminder(TaskList* tlist){
    if(tlist == nullptr){
        qCritical("init reminder with nullptr tlist! reminder can't work therefore.");
        exit(1);
    }
    this->tasklist_ = tlist;
    message_list = new QTextEdit(this);
    this->cleanRemindMessage();
    this->showAllRemindMessage();
}

void Reminder::showRemindMessage(std::vector<QString*> names_and_ddls){
    QString original = message_list->toPlainText();
    if(names_and_ddls.size() % 2 != 0){
        qCritical("call Reminder to show, but illegal length for input, Why?");
        return;
    }
    int sz = names_and_ddls.size() / 2;
    for(int i = 0; i < sz; ++i){
        original += *(names_and_ddls[2*i]) + "[ddl: " + *(names_and_ddls[2*i+1]) + " ]\n";
    }
    message_list->setText(original);
    if(sz != 0){
        names_and_ddls.clear();
    }
}

void Reminder::showAllRemindMessage(){
    if(this->tasklist_ == nullptr){
        qCritical("Reminder can't work, since init this reminder with nullptr tlist.");
        return;
    }
    // TODO: get message of All task need to be remind
}

void Reminder::cleanRemindMessage(){
    message_list->setText("");
    return;
}
