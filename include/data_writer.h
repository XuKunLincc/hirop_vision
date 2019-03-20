#ifndef __DATA_WIRTER_H__
#define __DATA_WIRTER_H__

namespace hirop_vision {

/**
 * @brief       负责对训练信息进行保存
 * @author      XuKunLin
 * @date        2019-03-20
 */
class DataWiter{

public:

    /**
     * @brief   添加新的数据
     * @return
     *          0   设置成功
     *          -1  设置失败
     */
    int add();

    /**
     * @brief   删除数据
     * @return
     *          0   设置成功
     *          -1  设置失败
     */
    int del();

    /**
     * @brief   查找数据
     * @return
     *          0   设置成功
     *          -1  设置失败
     */
    int serach();

    /**
     * @brief   修改数据
     * @return
     *          0   设置成功
     *          -1  设置失败
     */
    int change();

private:
    int create();

};

}

#endif
