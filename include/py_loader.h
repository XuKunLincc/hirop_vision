#ifndef __PY_LOADER_H__
#define __PY_LOADER_H__

#include <iostream>

#include "itrainer.h"
#include "idetector.h"

namespace hirop_vision{

class PyLoader{

public:
    IDetector *loadDetector(const std::string &detectorName);

//    ITrainer *loadTrainer(const std::string &trainerName);

    static PyLoader *getPyLoader();

private:
    PyLoader();

    int initSysPath();

public:
    const static std::string PATH;
    static PyLoader *instance;
};

}

#endif
