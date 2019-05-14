#ifndef DATASTREAMER_DATA_STREAMER_FILE_H
#define DATASTREAMER_DATA_STREAMER_FILE_H

#include "common/base.h"

#include <sstream>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

namespace table_loader {

class DataLoader {
public:
    /**
    * @brief 加载单个数据表接口
    * @param filename 数据表文件路径
    */
    bool load(const std::string& filename);

    /**
    * @brief 获取数据表的一行数据
    * @param line 存储数据表的string指针
    */
    bool get_line(std::string* const line);

    /**
    * @brief 关闭数据表，请确保这个接口被正确调用
    */
    void close();

    SINGLETION_DECLARE(DataLoader);

private:
    std::ifstream _ifs;
};

}  // namespace table_loader

#endif // DATASTREAMER_DATA_STREAMER_FILE_H
