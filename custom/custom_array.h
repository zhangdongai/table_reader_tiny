#ifndef CUSTOM_CUSTOM_INTARRAY_FILE_H
#define CUSTOM_CUSTOM_INTARRAY_FILE_H

#include <iostream>
#include <string>
#include <vector>

#include "common/utils.h"

namespace custom {

template <typename T>
class Array {
public:
    virtual ~Array() {}
    /**
    * @brief 解析字符串。该函数需要根据不同类型进行特化
    * @param obj_content 原始字符串
    */
    void parse(const std::string& obj_content);
    
    const T& operator[] (const std::size_t index) const {
        static T invalid_T;
        if (index < 0 || index >= _array.size()) {
            return invalid_T;
        }
        return _array[index];
    }

    void format_out() const {
        for (const auto& e : _array) {
            std::cout << e << ',';
        }
        std::cout << '\t';
    }
private:
    std::vector<T> _array;
};

/**
* @brief 解析字符串。int型数组的特化版本
* @param obj_content 原始字符串
*/
template <>
void Array<int>::parse(const std::string& obj_content);

} // namespace custom

#endif // CUSTOM_CUSTOM_INTARRAY_FILE_H
