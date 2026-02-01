# NativeProjectRunner/engine/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

add_library(engine STATIC
    src/engine.cpp
    src/project_loader.cpp
    src/sandbox.cpp
    src/wasm_runtime.cpp
)

target_include_directories(engine PUBLIC include)