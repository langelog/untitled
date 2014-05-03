#-------------------------------------------------
#
# Project created by QtCreator 2014-04-18T00:47:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# -- INCLUDE FOR OPENCV --
win32 {
INCLUDEPATH += C:\\OpenCV2.4.9\\install\\include
LIBS += -LC:\\OpenCV2.4.9\\install\\x64\\mingw\\lib \
    -lopencv_core249.dll \
    -lopencv_highgui249.dll \
    -lopencv_imgproc249.dll \
    -lopencv_features2d249.dll \
    -lopencv_calib3d249.dll
}
unix:LIBS += `pkg-config --cflags --libs opencv`
#--------------------------

SOURCES += main.cpp\
        mainwindow.cpp \
    Clases/CaptureThread.cpp \
    Clases/Buffer.cpp \
    Clases/ProcessingThread.cpp \
    Clases/ImgProcessor.cpp \
    LocatorDialog.cpp \
    Tools.cpp \
    Clases/FrameLabel.cpp

HEADERS  += mainwindow.h \
    Clases/CaptureThread.h \
    constants.h \
    Clases/Buffer.h \
    Clases/ProcessingThread.h \
    Clases/ImgProcessor.h \
    LocatorDialog.h \
    Tools.h \
    Clases/FrameLabel.h

FORMS    += mainwindow.ui \
    LocatorDialog.ui
