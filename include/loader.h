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
#ifndef __LOADER_H__
#define __LOADER_H__

#include "itrainer.h"
#include "idetector.h"

namespace hirop_vision{


typedef void* (*FUN)();

/**
 * @brief       具体算法库加载器
 * @author      XuKunLin
 * @date        2019-03-19
 */
class Loader{

public:

    Loader();

    /**
     * @brief       加载相关的训练库
     * @param    [trainerName] 输入，训练库的名称
     * @return      返回相关训练库的指针
     */
    ITrainer *loadTrainer(std::string trainerName);

    /**
     * @brief       加载相关的识别库
     * @param    [trainerName] 输入，识别库的名称
     * @return      返回相关识别库的指针
     */
    IDetector *loadDetector(std::string trainerName);

private:
    /**
     * @brief       根据类名获取其对应的导出函数名称
     * @param       [className]输入， 类名
     *              [funName] 输出， 输出对应的函数名
     * @return      返回函数名
     */
    int getCreateFunName(std::string className, std::string &funName);


    /**
     * @brief       获取对应插件的实例创建函数
     * @param   [libName] 对应动态库的名称
     * @return      返回对应实例创建函数的指针
     */
    FUN getCreateFun(std::string libName);

private:

    // 实例创建函数的前缀
    static std::string prefix;

    // 库的加载搜索路径
    static std::string path;

};

}

#endif
