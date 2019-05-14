#include <gtest/gtest.h>

#include "common/factory/parser_factory.h"
#include "common/utils.h"
#include "custom/custom_array.h"
#include "parsers/parser.h"
#include "table_loader/data_loader.h"
#include "table_loader/datatype_parser.h"

using table_loader::DataLoader;
using table_loader::DataTypeParser;
using common::factory::ParserFactory;

class TableReaderTest : public ::testing::Test {
public:
    virtual void SetUp() {
    }
};

//下面的TEST测试按照ID获取数据表，并和数据表中的配置数据进行对比
TEST_F(TableReaderTest, Main) {
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
    DataLoader::instance()->get_line(&new_line);
    std::vector<std::string> data_vec;
    utils::string_split(new_line, &data_vec);
    DataType data_type = data_type_con[0];
    std::shared_ptr<parser::IntParser> intptr =
        std::static_pointer_cast<parser::IntParser>(
            ParserFactory::instance()->get_new_parser(data_type));
    if (intptr) {
        intptr->parse(data_vec[0]);
        EXPECT_EQ(intptr->get_data(), 1);
    }

    data_type = data_type_con[2];
    std::shared_ptr<parser::FloatParser> floatptr =
        std::static_pointer_cast<parser::FloatParser>(
            ParserFactory::instance()->get_new_parser(data_type));
    if (floatptr) {
        floatptr->parse(data_vec[2]);
        const float& f = floatptr->get_data();
        EXPECT_FLOAT_EQ(f, 10.4);
    }

    data_type = data_type_con[4];
    std::shared_ptr<parser::CustomParser<custom::Array<int>>> arrayptr =
        std::static_pointer_cast<parser::CustomParser<custom::Array<int>>>(
            ParserFactory::instance()->get_new_parser(data_type));
    if (arrayptr) {
        arrayptr->parse(data_vec[4]);
        const custom::Array<int>& array = arrayptr->get_data();
        EXPECT_EQ(array[0], 312);
        EXPECT_EQ(array[2], 12);
    }

    DataLoader::instance()->close();
}
