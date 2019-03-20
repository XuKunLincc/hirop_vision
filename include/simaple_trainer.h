#ifndef __SIMAPLE_TRAINER_H__
#define __SIMAPLE_TRAINER_H__

#include "include/itrainer.h"

using namespace hirop_vision;

/**
 * @brief         测试使用的简单训练器
 * @author        XuKunLin
 * @date          2019-03-20
 */
class SimapleTrainer:public ITrainer{

private:
    int feed;
    int objectName;

public:
    /**
     * @brief   构造函数
     */
    SimapleTrainer();

    /**
     * @brief   虚函数实现，详见 itrainer.h
     */
    int train();

    /**
     * @brief   虚函数实现，详见 itrainer.h
     */
    int saveData(std::string path);

    /**
     * @brief   虚函数实现，详见 itrainer.h
     */
    int feedback();

    /**
     * @brief   虚函数实现，详见 itrainer.h
     */
    int parseConfig();

    /**
     * @brief   虚函数实现，详见 itrainer.h
     */
    int deleteData();

    /**
     * @brief   虚函数实现，详见 itrainer.h
     */
    int getName(std::string &name);

};

#endif // SIMAPLE_TRAINER_H
