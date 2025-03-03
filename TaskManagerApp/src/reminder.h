#ifndef REMINDER_H
#define REMINDER_H

#include <QMessageBox>
#include "tasklist.h"

class Reminder:public QWidget{
    Q_OBJECT
private:
    TaskList* tasklist_;
    QTextEdit* message_list;
    void showAllRemindMessage();
public slots:
    void showRemindMessage(std::vector<QString*> names_and_ddls);
    void cleanRemindMessage();
public:
    Reminder(TaskList* tlist);
};

#endif // REMINDER_H
