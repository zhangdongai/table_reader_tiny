#ifndef PARSER_PARSERS_FILE_H
#define PARSER_PARSERS_FILE_H

#include "common/log.h"
#include "parsers/base_parser.h"

namespace parser {

template <typename T>
class Parser : public BaseParser {
public:
    virtual ~Parser() {}
    virtual void parse(const std::string& obj_content) = 0;
    virtual void format_out() const = 0;
    virtual const T& get_data() const {return _data;}

protected:
    T _data;
};

class IntParser : public Parser<int> {
public:
    void parse(const std::string& obj_content) override {
        TRY_ENTRY
        this->_data = std::stoi(obj_content.data());
        CATCH_EXIT
    }

    void format_out() const override {
        std::cout << _data << '\t';
    }
};

class FloatParser : public Parser<float> {
public:
    void parse(const std::string& obj_content) override {
        TRY_ENTRY
        this->_data = std::stof(obj_content.data());
        CATCH_EXIT
    }

    void format_out() const override {
        std::cout << _data << '\t';
    }
};

class StringParser : public Parser<std::string> {
public:
    void parse(const std::string& obj_content) override {
        this->_data = obj_content;
    }
    void format_out() const override {
        std::cout << this->_data.data() << '\t';
    }
};

template <typename T>
class CustomParser : public Parser<T> {
public:
    void parse(const std::string& obj_content) override {
        this->_data.parse(obj_content);
    }
    void format_out() const override {
        this->_data.format_out();
    }
};

}  // namespace parser

#endif // PARSER_PARSERS_FILE_H
