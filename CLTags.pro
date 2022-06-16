QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ftagsmov.cpp \
    ftagsstock.cpp \
    ftimage.cpp \
    ftmodmov.cpp \
    ftoperate.cpp \
    ftoverview.cpp \
    ftprint.cpp \
    ftsettings.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ftagsmov.h \
    ftagsstock.h \
    ftimage.h \
    ftmodmov.h \
    ftoperate.h \
    ftoverview.h \
    ftprint.h \
    ftsettings.h \
    mainwindow.h

FORMS += \
    ftagsmov.ui \
    ftagsstock.ui \
    ftimage.ui \
    ftmodmov.ui \
    ftoperate.ui \
    ftoverview.ui \
    ftprint.ui \
    ftsettings.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
