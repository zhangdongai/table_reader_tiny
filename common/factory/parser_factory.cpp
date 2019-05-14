#include "parser_factory.h"

#include "custom/custom_array.h"
#include "custom/custom_planning.h"
#include "parsers/parser.h"

namespace common {
namespace factory {

ParserFactory::ParserFactory() {}

void ParserFactory::register_all() {
    REGISTER_PARSER(TYPE_INT, parser::IntParser);
    REGISTER_PARSER(TYPE_FLOAT, parser::FloatParser);
    REGISTER_PARSER(TYPE_STRING, parser::StringParser);
    REGISTER_PARSER(TYPE_ARRAY, parser::CustomParser<custom::Array<int>>);
    REGISTER_PARSER(TYPE_CUSTOME, parser::CustomParser<custom::Planning>);
}

void ParserFactory::register_parser(const DataType& data_type, ParserCreator creator) {
    parser_con_[data_type] = creator;
}

BaseParserPtr ParserFactory::get_new_parser(const DataType& data_type) {
    if (parser_con_.find(data_type) != parser_con_.end()) {
        return parser_con_[data_type]();
    }
    return nullptr;
}

} // namespace factory
} // namespace common
