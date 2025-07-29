QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CommandSystem.cpp \
    RuleEngine.cpp \
    animationdemo.cpp \
    cameracontroller.cpp \
    datetime.cpp \
    deepseektalk.cpp \
    flipwidget.cpp \
    form123546.cpp \
    main.cpp \
    mainwin.cpp \
    transformwidget.cpp \
    widgettest.cpp

HEADERS += \
    CommandSystem.h \
    RuleEngine.h \
    animationdemo.h \
    cameracontroller.h \
    datetime.h \
    deepseektalk.h \
    flipwidget.h \
    form123546.h \
    mainwin.h \
    transformwidget.h \
    widgettest.h

FORMS += \
    datetime.ui \
    deepseektalk.ui \
    form123546.ui \
    mainwin.ui \
    widgettest.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    stylesheet.qss
