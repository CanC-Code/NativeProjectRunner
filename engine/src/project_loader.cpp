// NativeProjectRunner/engine/src/project_loader.cpp
#include "engine_types.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace npr {

bool loadFileToBuffer(const std::string& path, std::vector<uint8_t>& outBuffer) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open()) return false;

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    outBuffer.resize(size);
    if (!file.read(reinterpret_cast<char*>(outBuffer.data()), size)) return false;
    return true;
}

} // namespace npr