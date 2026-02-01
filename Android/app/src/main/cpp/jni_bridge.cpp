// NativeProjectRunner/Android/app/src/main/cpp/jni_bridge.cpp
#include <jni.h>
#include <string>
#include <android/log.h>
#include "engine_api.h"
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>

#define LOG_TAG "NativeBridge"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static std::unique_ptr<npr::Engine> gEngine = nullptr;

extern "C" {

// Initialize engine singleton
JNIEXPORT void JNICALL
Java_io_canccode_nativeprojectrunner_NativeBridge_nativeInit(JNIEnv* env, jclass clazz) {
    if (!gEngine) {
        gEngine = std::make_unique<npr::Engine>();
        LOGI("Engine initialized");
    }
}

// Load project from SAF URI string
JNIEXPORT jboolean JNICALL
Java_io_canccode_nativeprojectrunner_NativeBridge_loadProject(
        JNIEnv* env, jclass clazz,
        jobject contentResolver, jobject uri) {

    if (!gEngine) return JNI_FALSE;

    // Convert URI to string path
    jclass uriClass = env->GetObjectClass(uri);
    jmethodID toStringMethod = env->GetMethodID(uriClass, "toString", "()Ljava/lang/String;");
    jstring jUriString = (jstring)env->CallObjectMethod(uri, toStringMethod);
    const char* cUri = env->GetStringUTFChars(jUriString, nullptr);

    std::string path(cUri);
    env->ReleaseStringUTFChars(jUriString, cUri);

    LOGI("Loading project: %s", path.c_str());

    bool result = gEngine->loadProject(path);
    return result ? JNI_TRUE : JNI_FALSE;
}

// Run a module by name
JNIEXPORT void JNICALL
Java_io_canccode_nativeprojectrunner_NativeBridge_runProjectModule(
        JNIEnv* env, jclass clazz,
        jobject uri, jstring moduleName) {

    if (!gEngine) return;

    const char* cModule = env->GetStringUTFChars(moduleName, nullptr);
    std::string moduleStr(cModule);
    env->ReleaseStringUTFChars(moduleName, cModule);

    LOGI("Running module: %s", moduleStr.c_str());
    gEngine->runModule(moduleStr);
}

} // extern "C"