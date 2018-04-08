#pragma once
#include "common.h"


namespace knylaw {
namespace jni {


//
// Template declaration
//

template<typename Array> struct ArrayTraits;

template<
    typename ArrayType,
    typename Traits = ArrayTraits<ArrayType>>
class ArrayAccess : public JNIEnvHolder {

public:
    using ElementType = typename Traits::ElementType;

    ArrayAccess(JNIEnv* env_, ArrayType array_) :
        JNIEnvHolder(env_), Marray(NULL), Mbody(NULL), Mlength(0), MisCopy(false){
        retrieveBody(array_);
    }

    ~ArrayAccess() {
        release();
    }

private:
    //
    // This constructor won't invoke jni call
    //
    ArrayAccess(JNIEnv* env_) :
        JNIEnvHolder(env_), Marray(NULL), Mbody(NULL), Mlength(0), MisCopy(false) {

    }

    //
    // Retrieve the body of the primitive array
    //
    inline void retrieveBody(ArrayType array_) {        
        Marray = array_;
        Mlength = env()->GetArrayLength(Marray);
        Mbody = getArrayElement();
        MisCopy = false;

        if (Mbody == NULL) {

            Mlength = 0;
            Marray = NULL;
            throw MethodCallFailed("getArrayElement");
        }
    }
    //
    // template function needed to be specialized.
    //
    ElementType* getArrayElement();
    //
    // template function needed to be specialized.
    //
    void releaseArrayElements(int mode) const;

public:    

    inline ElementType* body() {
        return Mbody;
    }

    inline const ElementType* body() const {
        return Mbody;
    }

    inline ElementType* begin() {
        return Mbody;
    }

    inline ElementType* end() {
        return Mbody + Mlength;
    }

    inline const ElementType* cbegin() const {
        return Mbody;
    }

    inline const ElementType* cend() const {
        return Mbody + Mlength;
    }

    inline void release(int mode = 0) const {
        if (validate())
            releaseArrayElements(mode);
    }

    inline bool validate() const {
        return Mbody != NULL;
    }

    inline jsize length() const {
        return Mlength;
    }

    inline jboolean isCopy() const {
        return MisCopy;
    }

private:

    ArrayType       Marray;
    ElementType*    Mbody;
    jsize           Mlength;
    jboolean        MisCopy;
};




template<
    typename ArrayType,
    typename Traits = ArrayTraits<ArrayType>>
class ArrayUtils: public JNIEnvHolder {

public:
    
    using ElementType = typename Traits::ElementType;

    ArrayUtils(JNIEnv* env_): JNIEnvHolder(env_) {

    }

    ArrayType createArray(jsize size, const ElementType* buf = NULL) {
        ArrayType array = newArray(size);
        if (array == NULL)
            throw MethodCallFailed("newArray");
        if (buf != NULL)
            setArrayRegion(array, 0, size, buf);
        return array;
    }

    ~ArrayUtils() {
        
    }

private:
    //
    // template function needed to be specialized.
    //
    ArrayType newArray(jsize size);

    //
    // template function needed to be specialized.
    //
    void setArrayRegion(ArrayType array, jsize start, jsize len, const ElementType* buf);


};


template<> struct ArrayTraits<jintArray> {
    using ElementType = jint;
};

template<> struct ArrayTraits<jdoubleArray> {
    using ElementType = jdouble;
};

template<> struct ArrayTraits<jcharArray> {
    using ElementType = jchar;
};




}
}