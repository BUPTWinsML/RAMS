# RAMS Android Invoke APP Demo

*News* 🔥
- [2025/12] We have extended RAMS to support attention-based (transformer) architecture models. The transformer model files and quick-start demo are now available at [here](#install-run-demo)

## About

This is an open-sourced demo application that allows for easy testing of RAMS. Using the source code, you can build an APP with Android Studio that can perform inference using a neural network implemented in C++ and display the inference time. The inference framework of neural networks includes two types: RAMS and TFLM.

RAMS can perform inference on the following devices:

<p align="center">
    <img src="assets/device.png" height="400" alt="device">
</p>

## To Install / Run Demo

### Quick start with APK

All ten APKS are available in **[Download APK](apks_10)**

1. Download the APK corresponding to the framework and neural network that you want to use

2. Use adb to connect to smartphones or mobile platforms (Android basic system)

3. Install the APK
   
   ```bash
   adb install -t '.\nnPerfAPKinstaller\rams_img5.apk'
   ```

### Build project

The executable model implementation is located in `app/src/main/cpp`. Compile APKS to execute different model inference. For example, to inference the model in `cpp/rams/img5`:

1. Install Android Studio (Recommand Android Studio Narwhal | 2025.1.1 Patch 1)

2. Import project

   File -> Open -> Current file directory

3. Android Studio setting

   ```bash
   Android Gradle Plugin Version: 8.7.3

   Gradle Version:                8.9

   NDK Version:                   27.0.12077973

   JDK Verison:                   21.0.7

   Complile Sdk Version:          34
   ```

4. Modify `app/src/main/cpp/nativelib.cpp`

```C++
#include "rams/img5/demo.h"
Java_com_example_cppinvoke_NativeLib_getInferenceTime(JNIEnv* env, jobject /* this */) {
    double ms = static_cast<double>(invoke_img5()); // Modify the function name
    return ms;
}
```

5. Modify `app/src/main/cpp/CMakeLists.txt`

```txt
# First select your framework type. The code for the RAMS framework is located in the upper section
set(MODEL_ROOT "rams" CACHE STRING "Top-level model root under cpp")
set(MODEL_NAME "img5" CACHE STRING "Model folder inside MODEL_ROOT")
```

6. Build your APK

   Build -> Generate App Bundles or APKs -> Generate APKs

<a id="install-run-demo"></a>
## Add Support for Attention-based (transformer) Architecture Models

### Start with compiled executable files

Under path `attention-based_models/`, we provide transformer architecture models. These models can be executed on both Linux and Android system. And the models list as follow:

- Openai/clip-vit-large-patch14-336
- Facebook/deit-base-patch16-224
- Facebook/dinov3-vitl16-pretrain-lvd1689m

To quickly start, we have already built **pre-compiled executables** for the models listed above. To run them on an **IoT device**, you can:

```bash
adb push attention-based_models/rams/android/rams_clip /data/local/tmp/
adb shell "chmod 755 /data/local/tmp/rams_clip"
adb push /path/to/libc++_shared.so /data/local/tmp/
adb shell 'cd /data/local/tmp && LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH ./rams_clip'
```

The required shared library (libc++_shared.so) is included in this repo under `lib/`
