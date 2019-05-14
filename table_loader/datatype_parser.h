/**
* @brief 为了方便用户配置数据表时确认数据类型，数据类型采用字符串形式直接配置在数据表中。
*        目前支持的类型有"INT", "FLOAT", "STRING", "INTARRAY", "CUSTOM"。分别代表整型，浮点型，
*        字符串类型，整形数组和自定义类型。
*        同时为了提高代码可读性，避免在代码中出现过多的字符串比较，提供parse_datatype
*        接口将字符串类型转换为DataType类型，在以后的逻辑中仅仅比较DataType变量。
*        转换规则为：
*        "INT"-->TYPE_INT
*        "FLOAT"-->TYPE_FLOAT
*        "STRING"-->TYPE_STRING
*        "INTARRAY"-->TYPE_INTARRAY
*        "CUSTOM"-->TYPE_CUSTOM
*/

#ifndef DATASTREAMER_DATA_PARSER_FILE_H
#define DATASTREAMER_DATA_PARSER_FILE_H

#include "common/base.h"

#include <string>
#include <vector>

#include "common/data_type.h"

namespace table_loader {

class DataTypeParser {
public:
    /**
    * @brief 对数据表中读取的字符串记录的数据类型进行解析，
    *        转换为DataType类型（data_type.h）
    * @param type_str_con 从数据表中读取的数据类型行对应的字符串，
    *                     并且已经过分割
    * @param type_con 转换成DataType后的数据
    */
    void convert_datatype(
        const std::vector<std::string>& type_str_con,
        std::vector<DataType>* const type_con);

    SINGLETION_DECLARE(DataTypeParser);
};

}  // namespace table_loader

#endif // DATASTREAMER_DATA_PARSER_FILE_H
