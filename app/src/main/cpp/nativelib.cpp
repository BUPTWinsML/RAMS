#include <jni.h>
#include "tflm/img5/demo.h"  // 包含 demo.h，以便调用 get_inference_time()

// JNI 接口函数名必须遵循 Java_包名_类名_方法名 的规则
extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_cppinvoke_NativeLib_getInferenceTime(JNIEnv* env, jobject /* this */) {
    // 调用 C++ 中的业务函数，返回推理耗时
    double ms = static_cast<double>(invoke_img5());
    return ms;
}
