#ifndef __DETCTOR_H__
#define __DETCTOR_H__

#include "vision.h"

namespace hirop_vision {
/**
 * @brief           hirop_vision相关detector的接口类
 * @author          XuKunLin
 * @date            2019-03-20
 */
class Detector{

    typedef void (*CBFUN)(int ret, pose p);

public:

    /**
     * @brief       构造函数
     */
    Detector();

    /**
     * @brief   开始进行物体识别
     * @param [objectName]      指定需要识别物体的名称
     * @param [detectorName]   指定识别器名称
     * @return
     *          0  开始识别成功
     *          -1 开始识别失败
     */
    int detection(std::string objectName, std::string detectorName);

    /**
     * @brief   设置物体识别成功后的回调函数
     * @param [func]        回调函数指针
     * @return
     *          0  设置成功
     *          -1 设置失败
     */
    int setFinishCallback(CBFUN callbackFunc);

private:

    // 识别成功后的回调函数
    CBFUN callbackFunc;
};

}

#endif
