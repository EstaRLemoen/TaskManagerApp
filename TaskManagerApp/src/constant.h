#ifndef CONSTANT_H
#define CONSTANT_H

#include <QString>

// UI SIZE INFO
const int BOTTON_HEIGHT = 40;
const int BOTTON_WIDHT = 46;
const int TITLE_BLOCK_HEIGHT = 30;
const int TITLE_BLOCK_WIDHT = 100;
const int TEXT_SIZE = 12;

// ITEMTYPE INFO
const int ITEMTYPE_NUMBER = 3;
const QString ITEMTYPE_LIST[ITEMTYPE_NUMBER] = {
    "number",
    "string",
    "timestamp"
};

// BASIC ITEM SETTING
const int BASIC_ITEM_LIST_LENGTH = 2;
const QString BASIC_ITEM_NAME[BASIC_ITEM_LIST_LENGTH] = {
    "name",
    "ddl"
};
const QString BASIC_ITEM_TYPE[BASIC_ITEM_LIST_LENGTH] = {
    "string",
    "timestamap"
};
const int IDX_TASKNAME = 0;
const int IDX_TASKDDL = 1;

// TASKLIST SIZE INFO
const int DEFAULT_TASKLIST_WIDTH = 300;
const int DEFAULT_TASKLIST_HEIGHT = 700;

#endif // CONSTANT_H
