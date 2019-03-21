#include "loader.h"
#include <dlfcn.h>

using namespace hirop_vision;

std::string Loader::prefix = "__create";
std::string Loader::path = "~/.hirop_vision/lib/";

Loader::Loader(){

}

ITrainer *Loader::loadTrainer(std::string trainerName){

    ITrainer *trainerPtr;
    FUN funPtr;
    funPtr = getCreateFun(trainerName);

    if(funPtr == NULL)
        return NULL;

    trainerPtr = (ITrainer *)funPtr();

    return trainerPtr;
}

IDetector *Loader::loadDetector(std::string detectorName){

    IDetector *detectorPtr;
    FUN funPtr;
    funPtr = getCreateFun(detectorName);

    if(funPtr == NULL)
        return NULL;

    detectorPtr = (IDetector *)funPtr();

    return detectorPtr;

}

int Loader::getCreateFunName(std::string className, std::string &funName){
    funName = prefix;
    funName += className;
    return 0;
}

FUN Loader::getCreateFun(std::string libName){

    void *libHandle;
    std::string dlfileName;
    std::string creatFunName;
    FUN funPtr;


    dlfileName = "/home/eima/tmp/qt_ws/build-hirop_framewrok-Desktop-Debug/lib";
    dlfileName += libName;
    dlfileName += ".so";

    libHandle = dlopen(dlfileName.c_str(), RTLD_LAZY);

    if(!libHandle){
        std::cerr << "Load so error: " << dlerror() << std::endl;
        return NULL;
    }

    std::cout << "load " << libName << " success" << std::endl;

    // 获取函数地址 该函数用于获取训练器实例
    getCreateFunName(libName, creatFunName);
    funPtr = (FUN)dlsym(libHandle, creatFunName.c_str());

    if(!funPtr){
        std::cerr << "Load function error" << dlerror() << std::endl;
        return NULL;
    }

    return funPtr;
}

