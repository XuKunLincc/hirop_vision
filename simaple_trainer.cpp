#include "simaple_trainer.h"
#include <unistd.h>

HVISION_MODULE(SimapleTrainer)

SimapleTrainer::SimapleTrainer():CBaseTrainer("simaple_trainer"){
}

int SimapleTrainer::train(){
    this->feed =0;
    for(int i = 0; i < 100; i++){
        usleep(10000);
        std::cout << "training: " << i << "%" << std::endl;
    }
    return 0;
}

int SimapleTrainer::saveData(std::string path){
    std::cout << "svaing data" << std::endl;
    return 0;
}

int SimapleTrainer::deleteData(){
    std::cout << "deteting data" << std::endl;
    return 0;
}

int SimapleTrainer::feedback(){
    return feed;
}

int SimapleTrainer::parseConfig(){
    std::cout << "parsing config" << std::endl;
    return 0;
}
