TEMPLATE = lib
CONFIG += console c++11 dll
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11 -Wl,--export-dynamic

DEFINES += BOOST_USE_LIB DEBUG __LINUX__

TARGET = hirop_vision

win32 {
      OPENCV_INC = F:/Program Files (x86)/opencv/opencv/build/include
      BOOST_INC = F:\Program Files\PCL 1.6.0\3rdParty\Boost\include
}

PYTHON_INC =  /home/fshs/anaconda3/include/python3.6m
PYTHON_LIBPATH = /home/fshs/anaconda3/lib
PYTHON_LIBS = -lpython3.6m

SOURCES += \
    src/trainer.cpp \
    src/detector.cpp \
    src/configure.cpp \
    src/c_base_trainer.cpp \
    src/c_base_detector.cpp \
    src/py_base_detector.cpp \
    src/py_loader.cpp \
    src/utils/py_lock_helper.cpp \
    src/cpp_loader.cpp

LIBS += \
    -lboost_thread \
    -lboost_system \
    -L../out/libs \
    $$PWD/libs/libyaml-cpp.so.0.6 \
    -Wl,-rpath=$$PWD/libs/ \
    -Wl,-rpath=../out/libs  \
    -Wl,-rpath=$$PYTHON_LIBPATH \
    -L$$PYTHON_LIBPATH \
    -lpython3.6m \
    -lHPlugin \
    -ldl

INCLUDEPATH += include \
      $$quote($$OPENCV_INC) \
      $$quote($$BOOST_INC) \
      $$PYTHON_INC \
      ../out/include

INSTALLPATH = ../out

inst.files += \
    include/idetector.h \
    include/vision.h \
    include/itrainer.h\
    include/simaple_trainer.h \
    include/trainer_listener.h \
    include/c_base_detector.h \
    include/c_base_trainer.h \
    include/detector.h \
    include/trainer.h \
    include/configure.h \
    include/loader.h \
    include/detection_listener.h \
    include/hirop_debug.h \
    include/py_loader.h


inst.path = $$INSTALLPATH/include

libinst.files += \
    libhirop_vision.so \
    libhirop_vision.so.1 \
    libhirop_vision.so.1.0 \
    libhirop_vision.so.1.0.0 \
    libs/* 

libinst.path = $$INSTALLPATH/libs

INSTALLS += libinst inst

HEADERS += \
    include/idetector.h \
    include/vision.h \
    include/itrainer.h\
    include/simaple_trainer.h \
    include/trainer.h \
    include/simaple_detector.h \
    include/data_writer.h \
    include/configure.h \
    include/detector.h \
    include/yaml-cpp/contrib/anchordict.h \
    include/yaml-cpp/contrib/graphbuilder.h \
    include/yaml-cpp/node/detail/bool_type.h \
    include/yaml-cpp/node/detail/impl.h \
    include/yaml-cpp/node/detail/iterator.h \
    include/yaml-cpp/node/detail/iterator_fwd.h \
    include/yaml-cpp/node/detail/memory.h \
    include/yaml-cpp/node/detail/node.h \
    include/yaml-cpp/node/detail/node_data.h \
    include/yaml-cpp/node/detail/node_iterator.h \
    include/yaml-cpp/node/detail/node_ref.h \
    include/yaml-cpp/node/convert.h \
    include/yaml-cpp/node/emit.h \
    include/yaml-cpp/node/impl.h \
    include/yaml-cpp/node/iterator.h \
    include/yaml-cpp/node/node.h \
    include/yaml-cpp/node/parse.h \
    include/yaml-cpp/node/ptr.h \
    include/yaml-cpp/node/type.h \
    include/yaml-cpp/anchor.h \
    include/yaml-cpp/binary.h \
    include/yaml-cpp/dll.h \
    include/yaml-cpp/emitfromevents.h \
    include/yaml-cpp/emitter.h \
    include/yaml-cpp/emitterdef.h \
    include/yaml-cpp/emittermanip.h \
    include/yaml-cpp/emitterstyle.h \
    include/yaml-cpp/eventhandler.h \
    include/yaml-cpp/exceptions.h \
    include/yaml-cpp/mark.h \
    include/yaml-cpp/null.h \
    include/yaml-cpp/ostream_wrapper.h \
    include/yaml-cpp/parser.h \
    include/yaml-cpp/stlemitter.h \
    include/yaml-cpp/traits.h \
    include/yaml-cpp/yaml.h \
    include/trainer_listener.h \
    include/detection_listener.h \
    include/linemod_trainer.h \
    include/c_base_trainer.h \
    include/c_base_detector.h \
    include/entity_factory.h \
    include/hirop_debug.h \
    include/py_base_detector.h \
    include/py_loader.h \
    include/utils/py_lock_helper.h \
    include/cpp_loader.h
