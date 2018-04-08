#include "clazz.h"
#include <cstdarg>

namespace knylaw {
namespace jni {





Clazz::Clazz() :JNIEnvHolder(NULL), Mname(NULL), Mclazz(NULL) {
    
}

Clazz::Clazz(const char * clazzname_, JNIEnv * env_) : JNIEnvHolder(env_), Mname(clazzname_), Mclazz(NULL) {

    try {
        initialize();
    } catch (const std::exception& e) {
        fprintf(stderr, e.what());
    }
}

jmethodID Clazz::getMeth(const char* methname, const char* sig) {

    jmethodID meth = env()->GetMethodID(Mclazz, methname, sig);
    if (meth == NULL)
        throw MethodCallFailed("GetMethodID");
    return meth;

}

void Clazz::initialize() {

    Mclazz = env()->FindClass(Mname);
    if (Mclazz == NULL) {
        throw MethodCallFailed("FindClass");
    }
}

jobject Clazz::instance(JNIEnv * env, const char * sig, ...) {

    jobject ret = NULL;

    try {
        if (!validate()) {
            throw Exception("Uninitialied Clazz object");
        }            
        
        jmethodID cstor = getMeth("<init>", sig);

        va_list arglist;
        va_start(arglist, sig);
        ret = env->NewObject(Mclazz, cstor, arglist);
        va_end(arglist);

        if (ret == NULL) {
            throw MethodCallFailed("NewObject");
        }            

    } catch (const std::exception& e) {
        fprintf(stderr, e.what());
    }

    return ret;
}

bool Clazz::validate() const {

    return Mclazz != NULL && env() != NULL;
}



}
}
