#include "arrays.h"

namespace knylaw {
namespace jni {

// Alias
template <typename ArrayType> using AT = ArrayTraits<ArrayType>;


//
// Template specialization
//
//

// jintArray
template<> 
AT<jintArray>::ElementType* ArrayAccess<jintArray>::getArrayElement() {
    return env()->GetIntArrayElements(Marray, &MisCopy);
}

template<> 
void ArrayAccess<jintArray>::releaseArrayElements(int mode) const {
    env()->ReleaseIntArrayElements(Marray, Mbody, mode);
}

// jdoubleArray
template<> 
AT<jdoubleArray>::ElementType* ArrayAccess<jdoubleArray>::getArrayElement() {
    return env()->GetDoubleArrayElements(Marray, &MisCopy);
}

template<> 
void ArrayAccess<jdoubleArray>::releaseArrayElements(int mode) const {
    env()->ReleaseDoubleArrayElements(Marray, Mbody, mode);
}

//jcharArray
template<> 
AT<jcharArray>::ElementType* ArrayAccess<jcharArray>::getArrayElement() {
    return env()->GetCharArrayElements(Marray, &MisCopy);
}

template<> 
void ArrayAccess<jcharArray>::releaseArrayElements(int mode) const {
    env()->ReleaseCharArrayElements(Marray, Mbody, mode);
}







// jintArray
template<> 
jintArray ArrayUtils<jintArray>::newArray(jsize size) {
    return env()->NewIntArray(size);
}

template<> 
void ArrayUtils<jintArray>::setArrayRegion(jintArray array, jsize start, jsize len, const jint* buf) {
    env()->SetIntArrayRegion(array, start, len, buf);
}

// jdoubleArray
template<> 
jdoubleArray ArrayUtils<jdoubleArray>::newArray(jsize size) {
    return env()->NewDoubleArray(size);
}

template<> 
void ArrayUtils<jdoubleArray>::setArrayRegion(jdoubleArray array, jsize start, jsize len, const jdouble* buf) {
    env()->SetDoubleArrayRegion(array, start, len, buf);
}

//jcharArray
template<> 
jcharArray ArrayUtils<jcharArray>::newArray(jsize size) {
    return env()->NewCharArray(size);
}

template<> 
void ArrayUtils<jcharArray>::setArrayRegion(jcharArray array, jsize start, jsize len, const jchar* buf) {
    env()->SetCharArrayRegion(array, start, len, buf);
}


}
}