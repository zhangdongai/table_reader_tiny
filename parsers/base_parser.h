#ifndef PARSER_BASE_PARSER_FILE_H
#define PARSER_BASE_PARSER_FILE_H

#include <iostream>
#include <memory>
#include <string>

namespace parser {

class BaseParser {
public:
    virtual ~BaseParser() {}
    virtual void parse(const std::string& obj_content) = 0;
    virtual void format_out() const = 0;
};

}  // namespace parser

using BaseParserPtr = std::shared_ptr<parser::BaseParser>;

#endif // PARSER_BASE_PARSER_FILE_H