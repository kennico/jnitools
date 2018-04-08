#pragma once
#include "common.h"

namespace knylaw {
namespace jni {



class Clazz:public JNIEnvHolder {

private:
    Clazz();

public:
    Clazz(const char* clazzname, JNIEnv* env);
    /*
    Call constructor
    */
    jobject instance(JNIEnv* env, const char* signature, ...);

    /*
    Check if it is inialized.
    */
    bool validate() const;

private:

    jmethodID getMeth(const char* methname, const char* signature);

    void initialize();

private:
    const char* Mname;
    jclass      Mclazz;
};



}
}

