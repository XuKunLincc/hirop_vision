#include "trainer.h"

using namespace hirop_vision;

void callback(int ret, std::string name){
    std::cout << "traning finish" << std::endl;
    std::cout << "ret = " << ret << "; name = " << name << std::endl;
}

int main(int argc, char *argv[])
{
    std::cout << "hello wrold" << std::endl;
    int i;

    Trainer t;
    t.setTrainConfig("test");
    t.setFinishCallback(callback);
    t.train();

    std::cin >> i;

    return 0;
}
