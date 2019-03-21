#ifndef __SIMAPLE_DETECTOR_H__
#define __SIMAPLE_DETECTOR_H__

#include "idetector.h"

using namespace hirop_vision;

class SimapleDetector:public IDetector{


public:
    SimapleDetector();

    int detection();

    int loadData(std::string objectName);

    int getResult(pose &p);

};

#endif // SIMAPLE_DETECTOR_H
