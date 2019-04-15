#include "detector.h"

using namespace hirop_vision;

Detector::Detector(){
    detectionThr = NULL;
    listener = NULL;
    loader = new Loader();
}

int Detector::detectionOnce(std::string objectName, std::string detectorName, cv::Mat &inputImg){
    /**
     * @todo
     *      1, 根据训练器名称，加载训练器
     *      2, 根据物体名称，调用训练器加载函数，加载相关数据
     *      3, 建立线程，调用训练器的检测函数
     *
     **/

    IDetector *detectorPtr;

    this->objectName = objectName;
    this->detectorName = detectorName;

    if(detectionThr){
        std::cerr << "start detection error: detection thread was runnig" << std::endl;
        return -1;
    }

    detectorPtr = loader->loadDetector(detectorName);
    if(!detectorPtr){
        std::cerr << "start detection error: load detector was error" << std::endl;
        return -1;
    }

    detectorPtr->setImg(inputImg);

    boost::function0<int> f =  boost::bind(&Detector::__detection,this, objectName, detectorPtr);
    detectionThr = new boost::thread(f);

    // 启动线程
    detectionThr->join();

    return 0;

}

int Detector::setOnStateChangeCallback(DetectStateListener *listener){
    if(listener == NULL){
        std::cerr << "set state listener was error: listener can't be NULL" << std::endl;
        return -1;
    }

    this->listener = listener;
    return 0;
}

int Detector::__detection(const std::string objName, IDetector *detector){

    pose result;
    int ret;

    // 数据保存的前缀路径
    std::string prefix = "/home/fshs/hirop_vision/data/";
    std::string detectorName = "LinemodTrainer";

    // 加载参数
    ret = detector->loadData(prefix + detectorName + "/" + objName, objName);
    if(ret){
        std::cerr << "load data error" << std::endl;
        return -1;
    }

    // 开始识别[阻塞式函数]
    ret = detector->detection();
    if(ret){
        std::cerr << "detection error" << std::endl;
        return -1;
    }

    ret = detector->getResult(result);
    if(ret){
        std::cerr << "get result error" << std::endl;
        return -1;
    }

    /**
      * @todo 传递给监听者正确的识别结束状态码
      */
    listener->onDetectDone("SimapleDetector", ret, result);

    return 0;
}
