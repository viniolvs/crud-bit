QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    confirmpasswordwindow.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    newuserwindow.cpp \
    searchuserwindow.cpp \
    updateuserwindow.cpp \
    user.cpp \
    userwindow.cpp

HEADERS += \
    confirmpasswordwindow.h \
    database.h \
    mainwindow.h \
    newuserwindow.h \
    searchuserwindow.h \
    updateuserwindow.h \
    user.h \
    userwindow.h

FORMS += \
    confirmpasswordwindow.ui \
    mainwindow.ui \
    newuserwindow.ui \
    searchuserwindow.ui \
    updateuserwindow.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
