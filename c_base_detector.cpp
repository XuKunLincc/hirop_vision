#include "c_base_detector.h"

using namespace hirop_vision;

CBaseDetector::CBaseDetector(std::string name){
    this->name = name;
    this->entityType = CPP;
}

int CBaseDetector::getName(std::string &name){
    name = this->name;
    return 0;
}

ENTITY_TYPE CBaseDetector::getEntityType(){
    return this->entityType;
}
