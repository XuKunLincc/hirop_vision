#ifndef __TRAINER_H__
#define __TRAINER_H__

#include "configure.h"
#include "itrainer.h"
#include <boost/thread.hpp>

namespace hirop_vision {

/**
 * @brief         hirop_vision的training接口类，使用该类可以进行相关的物体识别等接口
 * @author        XuKunLin
 * @date          2019-03-20
 */
class Trainer
{

typedef void (*CBFUN)(int, std::string);

public:

    /**
     * @brief   默认构造函数
     */
    Trainer();

    /**
     * @brief   训练接口，调用该接口则开始进行训练
     * @return
     *          0 开始训练成功
     *          -1 开始训练失败
     */
    int train();

    /**
     * @brief   传递训练配置文件
     * @param [fileName] 配置文件名称。 可指定路径
     * @return
     *          0  传递成功
     *          -1 传递失败
     */
    int setTrainConfig(std::string fileName);

//    /**
//     * @brief   列出当前系统中已训练的所有物体
//     * @return  物体列表
//     */
//    int listObject();

//    /**
//     * @brief   删除指定物体
//     * @return  物体列表
//     */
//    int deteObject();

//    /**
//     * @brief   列出当前系统中已加载的训练器
//     * @return  物体列表
//     */
//    int listTrain();

    /**
     * @brief   设置当训练结束时候的回调函数
     * @return
     *          0   设置成功
     *          -1  设置失败
     */
    int setFinishCallback(CBFUN callbackFun);

private:

    /**
     * @brief   执行具体的训练任务
     * @return
     *          0 开始训练成功
     *          -1 开始训练失败
     */
    int __train();

    /**
     * @brief       生成文件保存路径
     * @param  [path] 输出 生成的路径
     * @return
     *          0   成功
     *          -1   失败
     */
    int __genPath(std::string &path);


private:
    // 训练线程
    boost::thread *trainThr;

    // 具体的训练器
    hirop_vision::ITrainer *trainer;

    // 训练结束时的回调函数
    CBFUN callbackFun;

    // 当前的配置信息
    Configure *config;
};
}


#endif
