#ifndef COMMON_FACTORY_PARSER_FACTORY_FILE_H
#define COMMON_FACTORY_PARSER_FACTORY_FILE_H

#include <unordered_map>

#include "common/base.h"
#include "common/data_type.h"
#include "parsers/base_parser.h"

namespace common {
namespace factory {

class ParserFactory {
public:
    using ParserCreator = std::function<BaseParserPtr (void)>;

    /**
    * @brief 注册所有类型Parser的接口，会从main函数调用过来
    *        新增数据类型需要在该函数中增加Parser的注册
    */
    void register_all();

    /**
    * @brief 通过数据类型枚举获取数据类型对应的Parser对象指针
    * @param name 数据类型枚举
    * @return 如果存在该数据类型对应的Parser，则返回对象指针；否则返回nullptr
    */
    BaseParserPtr get_new_parser(const DataType& data_type);

private:
    void register_parser(const DataType& data_type, ParserCreator creator);
    
    std::unordered_map<DataType, ParserCreator, EnumHash> parser_con_;

    SINGLETION_DECLARE(ParserFactory);
};

#define REGISTER_PARSER(DATATYPE, CLASS) \
    ParserFactory::instance()->register_parser(     \
        DATATYPE, []() -> BaseParserPtr {           \
            return BaseParserPtr(new CLASS);        \
    });

} // namespace factory
} // namespace common

#endif // COMMON_FACTORY_PARSER_FACTORY_FILE_H
