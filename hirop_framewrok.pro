TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += BOOST_USE_LIB

SOURCES += \
#    simaple_trainer.cpp \
    main.cpp \
    trainer.cpp \
    detector.cpp \
    configure.cpp \
    loader.cpp \
    #simape_detector.cpp

LIBS += \
    /usr/lib/x86_64-linux-gnu/libboost_thread.so \
    /usr/lib/x86_64-linux-gnu/libboost_system.so \
    -ldl

INCLUDEPATH += include

HEADERS += \
    include/idetector.h \
    include/loader.h \
    include/vision.h \
    include/itrainer.h\
    include/simaple_trainer.h \
    include/trainer.h \
    include/simaple_detector.h \
    include/data_writer.h \
    include/configure.h \
    include/detector.h
