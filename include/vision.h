#ifndef __VISION_H__
#define __VISION_H__

#include <iostream>

namespace hirop_vision {

/**
 * @brief 用于生成相关的导出函数，只需传递类名，该宏就会自动生成导出函数
 */
#define HVISION_MODULE(className) \
extern "C" { \
    void* __create##className(){ \
    return new className;       \
    }\
}

enum ENTITY_TYPE{
    PYTHON = 0,
    CPP
};

typedef struct quaternion{
    float x;
    float y;
    float z;
    float w;
} quaternion;

typedef struct position{
    float x;
    float y;
    float z;
} position;

typedef struct pose{
    struct quaternion quaternion;
    struct position position;
} pose;

}

#endif
