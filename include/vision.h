#ifndef __VISION_H__
#define __VISION_H__

#include <iostream>

namespace hirop_vision {

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
    struct quaternion q;
    struct position p;
} pose;

}

#endif
