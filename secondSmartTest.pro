QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# OPENCV_DIR = E:/Opencv4.9/opencv/build



# 头文件路径
# INCLUDEPATH += $$OPENCV_DIR/include


# 库文件路径
# LIBS += $$OPENCV_DIR/x64/mingw/lib/libopencv_*.a  # MinGW版本
# 或 MSVC版本:
# LIBS += $$OPENCV_DIR/x64/vc15/lib/opencv_world455.lib  # 发布版
# LIBS += $$OPENCV_DIR/x64/vc15/lib/opencv_world455d.lib # 调试版


# QMAKE_CXXFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    # CommandSystem.cpp \
    RuleEngine.cpp \
    animationdemo.cpp \
    cameracontroller.cpp \
    commandbox.cpp \
    datetime.cpp \
    deepseektalk.cpp \
    flipwidget.cpp \
    form123546.cpp \
    main.cpp \
    mainwin.cpp \
    # opencv_viewer.cpp \
    terminalwidget.cpp \
    transformwidget.cpp \
    widgettest.cpp \


HEADERS += \
    # CommandSystem.h \
    CommandSystemMap.h \
    RuleEngine.h \
    animationdemo.h \
    cameracontroller.h \
    commandbox.h \
    datetime.h \
    deepseektalk.h \
    flipwidget.h \
    form123546.h \
    mainwin.h \
    # opencv_viewer.h \
    terminalwidget.h \
    transformwidget.h \
    widgettest.h    \



# # OpenCV配置 - 请根据你的实际安装路径修改
# OPENCV_DIR = E:/Opencv4.9/opencv/build  # 替换为你的OpenCV build目录

# # 库文件路径
# LIBS += -L$$OPENCV_DIR/x64/mingw/lib

# # 链接OpenCV库（根据实际版本号调整，这里是490对应4.9.0版本）
# CONFIG(debug, debug|release): {
#     LIBS += -lopencv_world490d  # Debug版本
# } else {
#     LIBS += -lopencv_world490   # Release版本
# }

FORMS += \
    commandbox.ui \
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
