#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "model.h"

void* setup() {
    static uint8_t tensor_arena[600000];
    const tflite::Model* model_ = tflite::GetModel(mbv2_w0_35_r144_imagenet_tflite);

    if (model_->version() != TFLITE_SCHEMA_VERSION) {
        return NULL;
    }
    tflite::MicroMutableOpResolver<7>* resolver = new tflite::MicroMutableOpResolver<7>();
    resolver->AddPad();
    resolver->AddConv2D(tflite::Register_CONV_2D_INT8());
    resolver->AddDepthwiseConv2D(tflite::Register_DEPTHWISE_CONV_2D_INT8());
    resolver->AddAdd();
    resolver->AddFullyConnected();
    resolver->AddAveragePool2D(tflite::Register_AVERAGE_POOL_2D_INT8());
    resolver->AddReshape();

    tflite::MicroInterpreter* interpreter = new tflite::MicroInterpreter(model_, *resolver, tensor_arena, 600000);
    TfLiteStatus allocate_status = interpreter->AllocateTensors();

    interpreter->Invoke();

    return NULL;
}

#include <chrono>
float invoke_mbv2() {
    auto begin = std::chrono::high_resolution_clock::now();
    setup();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return (elapsed.count() * 1e-6); // ms
    return 0;
}
