#include <gtest/gtest.h>

#include "common/factory/parser_factory.h"
#include "common/log.h"
#include "common/utils.h"
#include "parsers/parser.h"
#include "table_loader/data_loader.h"
#include "table_loader/datatype_parser.h"

using table_loader::DataLoader;
using table_loader::DataTypeParser;
using common::factory::ParserFactory;

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    DEBUG_LOG("int comlog end!");

    ParserFactory::instance()->register_all();

    // 加载planning数据表
    DataLoader::instance()->load("./config/table_planning.txt");
    // 获取数据表类型配置
    std::string datatypes;
    DataLoader::instance()->get_line(&datatypes);
    // 对数据表类型进行分割，并转换为enum DataType
    std::vector<std::string> data_types_vec;
    utils::string_split(datatypes, &data_types_vec);
    std::vector<DataType> data_type_con;
    DataTypeParser::instance()->convert_datatype(data_types_vec, &data_type_con);

    // 依次读取每一行数据。进行分割、解析、转换和输出
    std::string new_line;
    while (DataLoader::instance()->get_line(&new_line)) {
        std::vector<std::string> data_vec;
        utils::string_split(new_line, &data_vec);
        std::size_t data_index = 0;
        for (const auto& e : data_vec) {
            const DataType data_type = data_type_con[data_index];
            BaseParserPtr ptr =
                ParserFactory::instance()->get_new_parser(data_type);
            if (ptr) {
                ptr->parse(e);
                ptr->format_out();
            }
            else {
                ERROR_LOG("can not find Parser with datatype %d", static_cast<int32_t>(data_type));
            }
            ++data_index;
        }
        std::cout << std::endl;
    }
    
    DataLoader::instance()->close();
    
    //以下内容会输出到屏幕上
    DEBUG_LOG("run GTEST finally!");
    return RUN_ALL_TESTS();
}
