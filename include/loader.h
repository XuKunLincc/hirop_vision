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


};

}

#endif
