/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2019, Foshan Huashu Robotics Co.,Ltd
 * All rights reserved.
 *
 * Author: Kunlin Xu <1125290220@qq.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *      * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *      * Neither the name of the Southwest Research Institute, nor the names
 *      of its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 */
#ifndef __DETCTOR_H__
#define __DETCTOR_H__


#include "vision.h"
#include "loader.h"
#include "detection_listener.h"

#include <boost/thread.hpp>

namespace hirop_vision {

/**
 * @brief           hirop_vision相关detector的接口类
 * @author          XuKunLin
 * @date            2019-03-20
 * @todo            1，当传递检测器名称时，检测检测器是否存在
 *                  2，当传递物体名称给检测器时，检测是否有该物体。
 *                  3，支持多物体、多训练器
 *                  4，增加状态枚举
 *                  5，增加析构函数，进行内存回收
 */
class Detector{

/**
 * @brief       检测完成后的回调函数原型
 * @param       [detectorName] 检测器的名称
 * @param       [pose]         检测结果，姿态。 基于相机坐标的位姿，四元数表示法。
 * @return      无返回
 */
typedef void (*CBFUN)(std::string detectorName, pose p);

public:

    /**
     * @brief       构造函数
     */
    Detector();

    /**
     * @brief   开始进行物体识别，只检测一次，检测成功后即返回
     * @param [objectName]      指定需要识别物体的名称
     * @param [detectorName]   指定识别器名称
     * @return
     *          0  开始识别成功
     *          -1 开始识别失败
     */
    int detectionOnce(std::string objectName, std::string detectorName, cv::Mat &inputImg);


    /**
     * @brief       设置当识别状态监听者实例
     * @param [listener] 监听者实例
     * @return  0 成功 1 失败
     */
    int setOnStateChangeCallback(DetectStateListener *listener);

private:

    /**
     * @brief       执行具体的识别工作，将会已线程的方式被调用
     * @param [objName] 被检测的物体名称
     * @param [detector] 即将执行识别工作的识别器实例
     * @return
     */
    int __detection(const std::string objName, IDetector *detector);

private:
    // 状态监听者实例
    DetectStateListener *listener;

    // 识别线程
    boost::thread *detectionThr;

    // 识别的配置信息
    std::string objectName;
    std::string detectorName;

    // 动态库加载器
    Loader *loader;
};

}

#endif
