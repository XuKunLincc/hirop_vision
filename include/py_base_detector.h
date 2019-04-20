#ifndef __PY_BASE_DETECTOR_H__
#define __PY_BASE_DETECTOR_H__

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "idetector.h"

namespace  hirop_vision{
class PyBaseDetector:public IDetector{

public:
    PyBaseDetector(PyObject *pClass, std::string detectorName);
    ~PyBaseDetector();

    int detection();

    int loadData(const std::string path, const std::string objectName);

    void setColorImg(const cv::Mat &inputImg);

    void setDepthImg(const cv::Mat &inputImg);

    int getResult(std::vector<pose> &poses);

    int getName(std::string &name);

    ENTITY_TYPE getEntityType();

private:
    int initNump();

private:
    PyObject *pClass;
    PyObject *pClassInstance;
    PyObject  *pDict;
};
}


#endif
