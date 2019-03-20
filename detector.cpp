#include "detector.h"

using namespace hirop_vision;

Detector::Detector(){

}

int Detector::detection(std::string objectName, std::string detectorName){
    /**
     * @todo
     *      1, 根据训练器名称，加载训练器
     *      2, 根据物体名称，调用训练器加载函数，加载相关数据
     *      3, 建立线程，调用训练器的检测函数
     *
     **/
}


int Detector::setFinishCallback(CBFUN callbackFunc){
    if(callbackFunc == NULL){
        std::cerr << "detector callback was null" << std::endl;
        return -1;
    }

    this->callbackFunc = callbackFunc;
    return 0;
}
