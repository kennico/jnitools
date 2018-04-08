#include <algorithm>
#include <cassert>

#include "clazz.h"
#include "arrays.h"
#pragma comment(lib, "jnitools.lib")


#include "serkenny_jnitools_NativeMethods.h"


#define TEST(...) fprintf(stderr, __VA_ARGS__)


using knylaw::jni::ArrayAccess;
using knylaw::jni::ArrayUtils;

void JNICALL Java_serkenny_jnitools_NativeMethods_testHelloWorld(JNIEnv *, jobject) {
    fprintf(stdout, "Hello world!\n");
}



void JNICALL Java_serkenny_jnitools_NativeMethods_testClassNotFound(JNIEnv * env, jobject obj) {
    static const char* CLS = "serkenny/numt/console/MisakaMikoto";
    knylaw::jni::Clazz cls(CLS, env);
}



void JNICALL Java_serkenny_jnitools_NativeMethods_testConstructorNotFound(JNIEnv * env, jobject obj) {
    static const char* CLS = "serkenny/numt/console/Function";
    static const char* SIG = "(IIII)V";
    jint a, b, c, d;
    a = b = c = d = 0;
    knylaw::jni::Clazz(CLS, env).instance(env, SIG, a, b, c, d);
}

void JNICALL Java_serkenny_jnitools_NativeMethods_testAccessIntArray(JNIEnv * env, jobject, jintArray array) {
    ArrayAccess<jintArray> access(env, array);
    std::for_each(access.cbegin(), access.cend(), [](auto e) {
        TEST("%ld ", e);
    });
}

void JNICALL Java_serkenny_jnitools_NativeMethods_testAccessDoubleArray(JNIEnv * env, jobject, jdoubleArray array) {
    ArrayAccess<jdoubleArray> access(env, array);
    std::for_each(access.cbegin(), access.cend(), [](auto e) {
        TEST("%lf ", e);
    });
}

void JNICALL Java_serkenny_jnitools_NativeMethods_testAccessCharArray(JNIEnv * env, jobject, jcharArray array) {
    ArrayAccess<jcharArray> access(env, array);
    std::for_each(access.cbegin(), access.cend(), [](auto e) {
        TEST("%hu ", e);
    });
}

jintArray JNICALL Java_serkenny_jnitools_NativeMethods_testCreateIntArray(JNIEnv * env, jobject) {
    jint temp[] = {9982,10031,10032,20001};
    return ArrayUtils<jintArray>(env).createArray(sizeof(temp) / sizeof(jint), temp);
}

jdoubleArray JNICALL Java_serkenny_jnitools_NativeMethods_testCreateDoubleArray(JNIEnv * env, jobject) {
    jdouble temp[] = { 9.982,1.0031,1.0032,2.0001 };
    return ArrayUtils<jdoubleArray>(env).createArray(sizeof(temp) / sizeof(jdouble), temp);
}

jcharArray JNICALL Java_serkenny_jnitools_NativeMethods_testCreateCharArray(JNIEnv * env, jobject) {
    jchar temp[] = { 'm','i','s','a','k','a','1','0','0','3','2' };
    return ArrayUtils<jcharArray>(env).createArray(sizeof(temp) / sizeof(jchar), temp);
}
