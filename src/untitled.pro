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
# folder version name error... but what ever...
INCLUDEPATH += C:\\OpenCV-2.8.4\\install\\include
LIBS += -LC:\\OpenCV-2.8.4\\install\\x64\\mingw\\lib \
    -lopencv_core248.dll \
    -lopencv_highgui248.dll

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
