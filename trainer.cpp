#include "trainer.h"
#include <iostream>
#include <boost/thread.hpp>

#include "simaple_trainer.h"

using namespace hirop_vision;

Trainer::Trainer(){
    trainThr = NULL;
}

int Trainer::setTrainConfig(std::string fileName){

    // 获取配置信息
    std::string trainerName;
    std::string objectName;
    this->config = new Configure(fileName);

    // TODO 直接保存Configure对象
    config->getObjectName(objectName);
    config->getTrainerName(trainerName);

    std::cout << "loading: " << trainerName << std::endl;
    this->trainer = new SimapleTrainer();
    return 0;
}

int Trainer::train(){

    // 训练线程已经存在
    if(trainThr != NULL){
        std::cerr << "can't not start training: train thread was running" << std::endl;
        return -1;
    }

    // 相关训练器未加载
    if(trainer == NULL){
        std::cerr << "can't not start training: trainer was not loaded" << std::endl;
        return -1;
    }

    // 创建线程
    boost::function0<int> f =  boost::bind(&Trainer::__train,this);
    trainThr = new boost::thread(f);

    // 启动线程
    trainThr->join();

}

int Trainer::setFinishCallback(CBFUN callbackFun){
    if(callbackFun == NULL){
        std::cerr << "call back function ptr was null" << std::endl;
        return -1;
    }
    this->callbackFun = callbackFun;
    return 0;
}

int Trainer::__train(){
    int ret;
    std::string trainName;
    std::string path;

    // 进行训练
    ret = trainer->train();
    trainer->getName(trainName);

    // 调用训练完成回调函数
    if(callbackFun != NULL)
        callbackFun(ret, trainName);

    // 训练成功 保存结果
    if(ret == 0)
        __genPath(path);
        trainer->saveData(path);

    // 删除线程对象
    delete trainThr;
    return 0;
}

int Trainer::__genPath(std::string &path){

    // 数据保存的前缀路径
    std::string prefix = "~/hirop_vision/data";

    // TODO: 检查路径是否存在，如果无则生成。检查路径是否有读写权限，如无则报错。
    path = prefix;

    return 0;

}
