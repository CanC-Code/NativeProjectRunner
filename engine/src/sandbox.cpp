// NativeProjectRunner/engine/src/sandbox.cpp
#include "engine_types.h"
#include <iostream>

namespace npr {

bool executeModuleSafe(const Module& mod) {
    // Currently a placeholder: log module execution
    std::cout << "[Sandbox] Executing module: " << mod.name << std::endl;
    return true;
}

} // namespace npr