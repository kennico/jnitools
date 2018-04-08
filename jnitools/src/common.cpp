#include "common.h"
#include "util.h"



namespace knylaw {
namespace jni {

Exception::Exception(const std::string & message): std::runtime_error(message) {

}

Exception::~Exception() {

}



MethodCallFailed::MethodCallFailed(const char * functionName)
    :Exception(util::format_str("JNI function call %s failed", functionName)) {

}

MethodCallFailed::MethodCallFailed(const std::string & functionName)
    :Exception(util::format_str("JNI function call %s failed", functionName.c_str())) {

}

MethodCallFailed::~MethodCallFailed() {

}

JNIEnvHolder::JNIEnvHolder(JNIEnv * env_): Menv(env_) {

}

JNIEnvHolder::~JNIEnvHolder() {

}

JNIEnv * JNIEnvHolder::env() const {
    return Menv;
}

}
}
