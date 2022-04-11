QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    ffmpeg_test_01_avio_list_dir.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    main.h

DISTFILES += \
    libcfg/ffmpeg/sample4.aac \
    libcfg/ffmpeg/sample_640x360.mp4 \
    libcfg/ffmpeg/movie.ogg


#includeLib:libavfilter-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lavfilter 
INCLUDEPATH += /usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libavformat-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lavformat 
INCLUDEPATH += usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libavdevice-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lavdevice 
INCLUDEPATH += /usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libavutil-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lavutil 
INCLUDEPATH += /usr/include/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libswresample-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lswresample 
INCLUDEPATH += /usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libpostproc-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lpostproc 
INCLUDEPATH += /usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libswscale-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lswscale 
INCLUDEPATH += /usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/

#includeLib:libavcodec-dev::7:4.1.6-1
LIBS += -L/usr/lib/aarch64-linux-gnu/ -lavcodec 
INCLUDEPATH += /usr/include/aarch64-linux-gnu/
DEPENDPATH += /usr/lib/aarch64-linux-gnu/
