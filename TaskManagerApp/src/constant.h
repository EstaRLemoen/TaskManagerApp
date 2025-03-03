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
enum class ITEMTYPE_INDEX{
    NUM = 0,
    STR = 1,
    TIME = 2
};

// TIME_LIMIT INFO
const int REMIND_TIME_LIMIT_HOURS = 24;

// DEFAULT INFO
//      ITEMMODEL
const QString DEFAULT_ITEMMODEL_NAME = "DEFAULT";
const bool DEFAULT_ITEMMODEL_IS_USER = true;
const bool DEFAULT_ITEMMODEL_IS_VISIBLE = true;
//      ITEMUNIT
const QString DEFALUT_ITEMUNIT_DESCRIPTION = "DEFAULT";
//      TASKLIST
const int DEFAULT_TASKLIST_WIDTH = 500;
const int DEFAULT_TASKLIST_HEIGHT = 500;

// BASIC ITEM SETTING
const int BASIC_ITEM_LIST_LENGTH = 4;
const QString BASIC_ITEM_NAME[BASIC_ITEM_LIST_LENGTH] = {
    "name",
    "ddl",
    "detail",
    "importance"
};
const int BASIC_ITEM_TYPE[BASIC_ITEM_LIST_LENGTH] = {
    1,  // "string"
    2,  // "timestamp"
    1,  // "string"
    0   // "number"
};
bool checkDescripWithType(const QString& descrip, const int& type_idx);
const int IDX_TASKNAME = 0;
const int IDX_TASKDDL = 1;

// lab5:only for test
void test_checkDescripWithType();
// lab5 end

#endif // CONSTANT_H
