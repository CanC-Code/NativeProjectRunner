// NativeProjectRunner/Android/app/src/main/cpp/android_platform.cpp
#include <jni.h>
#include <android/log.h>
#include <string>

#define LOG_TAG "AndroidPlatform"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

namespace npr::platform {

std::string uriToPath(JNIEnv* env, jobject contentResolver, jobject uri) {
    // Placeholder: in Android 14+, SAF URIs may require more complex handling
    jclass uriClass = env->GetObjectClass(uri);
    jmethodID toStringMethod = env->GetMethodID(uriClass, "toString", "()Ljava/lang/String;");
    jstring jUriString = (jstring)env->CallObjectMethod(uri, toStringMethod);
    const char* cUri = env->GetStringUTFChars(jUriString, nullptr);
    std::string path(cUri);
    env->ReleaseStringUTFChars(jUriString, cUri);
    LOGI("Converted URI to path: %s", path.c_str());
    return path;
}

} // namespace npr::platform