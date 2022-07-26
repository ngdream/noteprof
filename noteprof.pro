QT       += core gui
QT       += sql
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    absence.cpp \
    addabsence.cpp \
    adddelay.cpp \
    addnote.cpp \
    addteacher.cpp \
    contactdialog.cpp \
    delay.cpp \
    edition.cpp \
    editteacher.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    sidebar.cpp \
    teachertable.cpp

HEADERS += \
    aboutdialog.h \
    absence.h \
    addabsence.h \
    adddelay.h \
    addnote.h \
    addteacher.h \
    contactdialog.h \
    defs.h \
    delay.h \
    edition.h \
    editteacher.h \
    home.h \
    mainwindow.h \
    sidebar.h \
    teachertable.h

FORMS += \
    about.ui \
    aboutdialog.ui \
    absence.ui \
    addabsence.ui \
    adddelay.ui \
    addnote.ui \
    addteacher.ui \
    contactdialog.ui \
    delay.ui \
    edition.ui \
    editteacher.ui \
    home.ui \
    mainwindow.ui \
    usernotation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
