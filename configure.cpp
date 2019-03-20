#include "configure.h"

using namespace hirop_vision;

Configure::Configure(std::string fileName){
    //TODO
}

int Configure::getObjectName(std::string &objName){
    objName = "coke";
    return 0;
}

int Configure::getTrainerName(std::string &trainerName){
    trainerName="simaple_trainer";
    return 0;
}
