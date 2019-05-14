#ifndef COMMON_UTILS_FILE_H
#define COMMON_UTILS_FILE_H

#include <string>
#include <vector>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#include "log.h"

namespace utils {

/**
* @brief 字符串分割
* @param raw_string 需要分割的字符串
* @param vec 存放分割后子串的容器
* @param split_char 分割字符，默认为\t
*/

void string_split(const std::string& raw_string,
                  std::vector<std::string>* const vec,
                  const char* const split_char = "\t");

}  // namespace utils

#endif // COMMON_UTILS_FILE_H