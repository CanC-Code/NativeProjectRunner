// NativeProjectRunner/engine/include/project_api.h
#pragma once
#include <string>

namespace npr {

// Project modules must implement this interface
class IModule {
public:
    virtual ~IModule() = default;

    // Called when module is loaded
    virtual bool onLoad() = 0;

    // Execute the module
    virtual bool onRun() = 0;

    // Optional: unload / cleanup
    virtual void onUnload() = 0;

    virtual std::string getName() const = 0;
};

} // namespace npr