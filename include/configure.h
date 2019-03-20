#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__

#include <iostream>

namespace hirop_vision {

class Configure{

public:
    /**
     * @brief 构造函数
     * @param [file] 输入， yaml配置文件名称
     */
    Configure(std::string file);

    /**
     * @brief       获取配置文件中的物体名称
     * @param    [objName] 输出， 物体名称
     * @return
     *          0 成功
     *          1 失败
     */
    int getObjectName(std::string &objName);

    /**
     * @brief       获取配置文件中训练器名称
     * @param   [trainerName] 输出，训练器名称
     * @return
     *          0 成功
     *          1 失败
     */
    int getTrainerName(std::string &trainerName);

};

}

#endif // CONFIGURE_H
