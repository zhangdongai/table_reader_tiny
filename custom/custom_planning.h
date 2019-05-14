#ifndef CUSTOM_CUSTOM_PLANNING_FILE_H
#define CUSTOM_CUSTOM_PLANNING_FILE_H

#include <string>

namespace custom {

class Planning {
public:
    /**
    * @brief 自定义数据解析函数
    * @param data 数据表中配置的原生字符串数据，对字符串进行分割，并设置各成员变量
    */
    void parse(const std::string& data);

    void format_out() const;
public:
    int _type = 0;
    int _time_interval = 0;
    float _distance = 0.0f;
};

}  // namespace custom

#endif // CUSTOM_CUSTOM_PLANNING_FILE_H