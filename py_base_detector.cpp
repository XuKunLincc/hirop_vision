#include "py_base_detector.h"
#include "hirop_debug.h"
#include "utils/py_lock_helper.h"

#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <numpy/arrayobject.h>

using namespace hirop_vision;

PyBaseDetector::PyBaseDetector(PyObject *pClass, std::string detectorName){

    this->pClass = pClass;
    this->name = detectorName;

    if(!pClass){
        IErrorPrint("%s", "Python instance load failed: the class was null");
        return;
    }
    pClassInstance = PyInstanceMethod_New(pClass);
    if(!pClassInstance)
        IErrorPrint("%s", "Python Detector can't intance");

    entityType = PYTHON;
    initNump();
}

PyBaseDetector::~PyBaseDetector(){

    if(pClassInstance)
        Py_DECREF(pClassInstance);

}

int PyBaseDetector::initNump(){
    import_array();
}

int PyBaseDetector::loadData(const std::string path, const std::string objectName){

    PyLockHelper lock;

    if(!pClassInstance){
        IErrorPrint("%s", "Python detector load data failed: the class not instance");
        PyErr_Print();
        return -1;
    }

    PyObject* ret =  PyObject_CallMethod(pClassInstance, "loadData", "Oss", pClassInstance, path.c_str(), objectName.c_str());

    if(!ret){
        PyErr_Print();
        return -1;
    }

    return 0;
}

int PyBaseDetector::detection(){

    PyLockHelper lock;

    if(!pClassInstance){
        IErrorPrint("%s", "Python detector start detetion error: the class not instance");
        return -1;
    }

    PyObject *ret = PyObject_CallMethod(pClassInstance, "detection", "O", pClassInstance);
    if(!ret){
        PyErr_Print();
        return -1;
    }
    return 0;
}

void PyBaseDetector::setColorImg(const cv::Mat &inputImg){

    PyLockHelper lock;

    int rows =  inputImg.rows;
    int cols = inputImg.cols;
    int channels = inputImg.channels();

    IDebug("rows = %d, cols = %d, channels = %d", rows, cols, channels);

    //@todo 此处会造成内存泄露
    char * colorTmp= new char[rows * cols * channels];
    memcpy(colorTmp, inputImg.ptr<uchar>(0), rows * cols * channels);

    IDebug("memcpy mat finish");

    npy_intp Dims[3] = {rows, cols, channels};
    PyObject *matObj = PyArray_SimpleNewFromData(3, Dims, NPY_UBYTE, colorTmp);

    IDebug("PyArray_SimpleNewFromData finish");

    PyObject *ret = PyObject_CallMethod(pClassInstance, "setColorImg", "OO", pClassInstance, matObj);
    if(!ret)
        PyErr_Print();
}

void PyBaseDetector::setDepthImg(const cv::Mat &inputImg){

    PyLockHelper lock;
    int rows =  inputImg.rows;
    int cols = inputImg.cols;
    int channels = inputImg.channels();

    IDebug("rows = %d, cols = %d, channels = %d", rows, cols, channels);

    //@todo 此处会造成内存泄露
    char * depthTmp= new char[rows * cols * channels];
    memcpy(depthTmp, inputImg.ptr<uchar>(0), rows * cols * channels);

    IDebug("memcpy mat finish");

    npy_intp Dims[3] = {rows, cols, channels};
    PyObject *matObj = PyArray_SimpleNewFromData(3, Dims, NPY_UBYTE, depthTmp);

    IDebug("PyArray_SimpleNewFromData finish");

    PyObject *ret = PyObject_CallMethod(pClassInstance, "setDepthImg", "OO", pClassInstance, matObj);

    if(!ret)
        PyErr_Print();
}

int PyBaseDetector::getResult(std::vector<pose> &poses){
    PyLockHelper lock;

    if(!pClassInstance){
        IErrorPrint("%s", "Python detector getResult: the class not instance");
        return -1;
    }

    //    PyObject* ret =  PyObject_CallMethod(pClassInstance, "loadData", "Oss", pClassInstance, path.c_str(), objectName.c_str());

    //    PyArrayObject *array = (PyArrayObject *) ret;
    //    int rows = array->dimensions[0], columns = array->dimensions[1];
    //    std::cout << "Rows = "  << rows << "columns ="<<  columns <<std::endl;
    //    for( int Index_m = 0; Index_m < rows; Index_m++){

    //        for(int Index_n = 0; Index_n < columns; Index_n++){
    //            std::cout<<*(double *)(array->data + Index_m * array->strides[0] + Index_n * array->strides[1])<<" ";
    //        }
    //        std::cout<<std::endl;
    //    }

    return 0;
}

int PyBaseDetector::getName(std::string &name){
    name = this->name;
    return 0;
}

ENTITY_TYPE PyBaseDetector::getEntityType(){
    return entityType;
}
