#pragma once

#include "jni.h"
#include <string>


#define LOG_INFO(...) fprintf(stderr, "INFO: ");fprintf(stderr, __VA_ARGS__);fprintf(stderr, "\n")
#define LOG_DEBUG(...) fprintf(stderr, "DEBUG: "); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n")

namespace knylaw {
namespace jni {

class Exception: public std::runtime_error {

public:
    Exception(const std::string& message);
    ~Exception();

private:


};

class MethodCallFailed : public Exception{

public:
    MethodCallFailed(const char* functionName);
    MethodCallFailed(const std::string& functionName);
    ~MethodCallFailed();

private:

};

class JNIEnvHolder {

public:
    JNIEnvHolder(JNIEnv* env_);
    virtual ~JNIEnvHolder();
    JNIEnv* env() const;

private:

    JNIEnv* Menv;

};


}
}
