#include "simaple_detector.h"
#include <unistd.h>

HVISION_MODULE(SimapleDetector)

SimapleDetector::SimapleDetector(){

}

int SimapleDetector::detection(){
    for(int i = 0; i < 100; i++){
        usleep(10000);
        //std::cout << "training: " << i << "%" << std::endl;
    }
    return 0;
}

int SimapleDetector::loadData(std::string objectName){

    std::cout << "loading data" << std::endl;
}

int SimapleDetector::getResult(pose &p){

    p.p = {1,1,1};
    p.q = {1,1,1,0};
    return 0;
}
