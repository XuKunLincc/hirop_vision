TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11 -Wl,--export-dynamic

DEFINES += BOOST_USE_LIB DEBUG

SOURCES += \
 #   simaple_trainer.cpp \
    main.cpp \
    trainer.cpp \
    detector.cpp \
    configure.cpp \
    loader.cpp \
    c_base_trainer.cpp \
    c_base_detector.cpp
    #simape_detector.cpp

LIBS += \
    /usr/lib/x86_64-linux-gnu/libboost_thread.so \
    /usr/lib/x86_64-linux-gnu/libboost_system.so \
    /home/eima/tmp/qt_ws/hirop_framewrok/libs/libyaml-cpp.a \
    /home/eima/tmp/qt_ws/simaple_trainer/libSimapleTrainer.so \
    -ldl

INCLUDEPATH += include


inst.files += \
    include/idetector.h \
    include/vision.h \
    include/itrainer.h\
    include/simaple_trainer.h \
    include/trainer_listener.h \

inst.path = install/

INSTALLS += inst

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
    include/entity_factory.h
