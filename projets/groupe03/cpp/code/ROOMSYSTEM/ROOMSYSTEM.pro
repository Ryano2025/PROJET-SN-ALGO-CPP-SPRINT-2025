QT       += core gui
QT       +=core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    administrateur.cpp \
    client.cpp \
    dispo.cpp \
    main.cpp \
    mainwindow.cpp \
    reserver_client.cpp \
    secondwindow.cpp \
    userinterface.cpp \
    viewadmin.cpp \
    viewreserv.cpp \
    viewuser.cpp

HEADERS += \
    administrateur.h \
    client.h \
    dispo.h \
    mainwindow.h \
    reserver_client.h \
    secondwindow.h \
    userinterface.h \
    viewadmin.h \
    viewreserv.h \
    viewuser.h

FORMS += \
    administrateur.ui \
    client.ui \
    dispo.ui \
    mainwindow.ui \
    reserver_client.ui \
    secondwindow.ui \
    userinterface.ui \
    viewadmin.ui \
    viewreserv.ui \
    viewuser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

