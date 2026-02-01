// NativeProjectRunner/engine/include/engine_types.h
#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <memory>

namespace npr {

// Represents a loaded project module
struct Module {
    std::string name;       // Module name
    std::string path;       // Absolute or SAF path
    std::vector<uint8_t> code; // Raw binary or interpreted content
};

// Represents a loaded project
struct Project {
    std::string name;
    std::string basePath;
    std::vector<Module> modules;
};

using ProjectPtr = std::shared_ptr<Project>;

} // namespace npr