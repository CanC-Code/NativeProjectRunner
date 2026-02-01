// NativeProjectRunner/engine/src/engine.cpp
#include "engine_api.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace npr {

Engine::Engine() : currentProject(nullptr) {}
Engine::~Engine() = default;

bool Engine::loadProject(const std::string& projectPath) {
    namespace fs = std::filesystem;

    if (!fs::exists(projectPath) || !fs::is_directory(projectPath)) {
        std::cerr << "Project path invalid: " << projectPath << std::endl;
        return false;
    }

    auto project = std::make_shared<Project>();
    project->basePath = projectPath;
    project->name = fs::path(projectPath).filename().string();

    // Discover modules (*.cpp or module.json)
    for (auto& entry : fs::directory_iterator(projectPath + "/src")) {
        if (entry.path().extension() == ".cpp" || entry.path().extension() == ".bin") {
            Module mod;
            mod.name = entry.path().stem().string();
            mod.path = entry.path().string();
            project->modules.push_back(mod);
        }
    }

    currentProject = project;
    return true;
}

bool Engine::runModule(const std::string& moduleName) {
    if (!currentProject) return false;

    for (auto& mod : currentProject->modules) {
        if (mod.name == moduleName) {
            std::cout << "Running module: " << moduleName << std::endl;
            // Placeholder: actual module execution (JIT, sandboxed, WASM, etc.)
            return true;
        }
    }

    std::cerr << "Module not found: " << moduleName << std::endl;
    return false;
}

ProjectPtr Engine::getCurrentProject() const {
    return currentProject;
}

} // namespace npr