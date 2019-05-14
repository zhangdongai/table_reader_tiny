#ifndef COMMON_DATATYPE_H
#define COMMON_DATATYPE_H

#include <cstddef>

enum DataType {
    TYPE_INVALID   = -1,
    TYPE_INT       = 0,
    TYPE_FLOAT     = 1,
    TYPE_STRING    = 2,
    TYPE_ARRAY     = 3,
    TYPE_CUSTOME   = 4,
    TYPE_NUM,           //所有新增类型定义在上面
};

struct EnumHash {
    template <typename T>
    std::size_t operator()(T t) const {
        return static_cast<std::size_t>(t);
    }
};

#endif // COMMON_DATATYPE_H