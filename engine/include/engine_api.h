// NativeProjectRunner/engine/include/engine_api.h
#pragma once
#include "engine_types.h"
#include <string>
#include <memory>

namespace npr {

class Engine {
public:
    Engine();
    ~Engine();

    // Load a project from a given path or SAF URI
    bool loadProject(const std::string& projectPath);

    // Run a specific module by name
    bool runModule(const std::string& moduleName);

    // Get current loaded project
    ProjectPtr getCurrentProject() const;

private:
    ProjectPtr currentProject;
};

} // namespace npr