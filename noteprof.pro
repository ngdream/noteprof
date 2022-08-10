QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    addteacher.cpp \
    contactdialog.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    sidebar.cpp \
    teachertable.cpp

HEADERS += \
    aboutdialog.h \
    addteacher.h \
    contactdialog.h \
    defs.h \
    home.h \
    mainwindow.h \
    sidebar.h \
    teachertable.h

FORMS += \
    about.ui \
    aboutdialog.ui \
    addteacher.ui \
    contactdialog.ui \
    home.ui \
    mainwindow.ui \
    usernotation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
