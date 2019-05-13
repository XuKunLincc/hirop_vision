#include "trainer.h"
#include "vision.h"
#include "detector.h"
#include "c_base_trainer.h"

using namespace hirop_vision;

void callback(int ret, std::string name){
    std::cout << "traning finish" << std::endl;
    std::cout << "ret = " << ret << "; name = " << name << std::endl;
}

void detectionCB(std::string name, pose p){

    std::cout << "detection finish" << name << std::endl;
    std::cout << "pose: p.x = " << p.position.x << "  p.y = " << p.position.y << std::endl;

}


int main(int argc, char *argv[])
{
    int i;

    Trainer t;
    t.setTrainConfig("test.yaml");
    t.train();

    Detector d;
    d.detectionOnce("cokecan", "LinemodDetector");

    std::cin >> i;

    return 0;
}
