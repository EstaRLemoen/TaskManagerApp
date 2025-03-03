cmake_minimum_required(VERSION 3.16)

project(TaskManagerApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/widget.cpp
        src/widget.h
        src/widget.ui
        data
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)


qt_add_executable(TaskManagerApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        data.qrc
        src/tasklist.h
        src/tasklist.cpp
        src/itemunit.h
        src/itemunit.cpp
        src/itemmodel.h
        src/itemmodel.cpp
        src/taskunit.h
        src/taskunit.cpp
        src/tool.h
        src/tool.cpp
        src/constant.h
        src/template.h
        src/template.cpp
        src/reminder.h
        src/reminder.cpp
        src/timeline.h
        src/timeline.cpp
        src/timeunit.h
        src/timeunit.cpp
        src/remindunit.h
        src/remindunit.cpp
        src/test_lab4.cpp
        src/test.h
        src/test.cpp
        src/constant.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TaskManagerApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TaskManagerApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TaskManagerApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TaskManagerApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TaskManagerApp)
endif()
set_target_properties(TaskManagerApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TaskManagerApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TaskManagerApp)
endif()
