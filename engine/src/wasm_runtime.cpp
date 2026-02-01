// NativeProjectRunner/engine/src/wasm_runtime.cpp
#include "engine_types.h"
#include <iostream>

namespace npr {

bool runWasmModule(const Module& mod) {
    std::cout << "[WASM] Running module: " << mod.name << std::endl;
    return true;
}

} // namespace npr