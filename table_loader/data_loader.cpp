#include "data_loader.h"

#include "datatype_parser.h"
#include "common/log.h"

namespace table_loader {

DataLoader::DataLoader() {}

bool DataLoader::load(const std::string& filename) {
    // 检查当前是否正在打开某个数据表
    // 若是，则首先关闭
    if (_ifs.is_open()) {
        _ifs.close();
    }

    DEBUG_LOG("begin to load file %s.", filename.c_str());
    _ifs.open(filename.c_str(), std::ios::in);
    if (!_ifs.is_open()) {
        ERROR_LOG("cannot load file %s.", filename.c_str());
        _ifs.close();
        return false;
    }

    char temp[2048] = {0};
    // 读取第一行并丢弃，第一行是用户注释
    _ifs.getline(temp, sizeof(temp));

    DEBUG_LOG("load file %s successfully.", filename.c_str());

    return true;
}

bool DataLoader::get_line(std::string* const line) {
    CHECK_NULL_RETBOOL(line);
    if (!_ifs.is_open()) {
        return false;
    }

    if (!std::getline(_ifs, *line)) {
        return false;
    }
    return true;
}

void DataLoader::close() {
    _ifs.close();
}

}  // namespace table_loader
