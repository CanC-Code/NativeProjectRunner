# NativeProjectRunner/Android/app/src/main/cpp/CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(NativeProjectRunner)

set(CMAKE_CXX_STANDARD 17)

# Engine source
add_library(engine STATIC
    ../../../../engine/src/engine.cpp
    ../../../../engine/src/project_loader.cpp
    ../../../../engine/src/sandbox.cpp
    ../../../../engine/src/wasm_runtime.cpp
)

add_library(nativebridge SHARED
    jni_bridge.cpp
    android_platform.cpp
)

target_include_directories(engine PUBLIC
    ../../../../engine/include
)

target_link_libraries(nativebridge
    engine
    android
    log
)