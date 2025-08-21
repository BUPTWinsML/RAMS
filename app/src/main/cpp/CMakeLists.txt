# cpp/tflm相关推理使用如下部分：

cmake_minimum_required(VERSION 3.10.2)
project(nativelib)

# config，编译不同apk时在这里替换
set(MODEL_ROOT "tflm" CACHE STRING "Top-level model root under cpp")
set(MODEL_NAME "img5" CACHE STRING "Model folder inside MODEL_ROOT")

# 添加头文件搜索路径
# 当前目录、tflm/img5（业务代码目录）以及各第三方库目录
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME})
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/third_party/kissfft)
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/third_party/gemmlowp)
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/third_party/flatbuffers/include)
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/third_party/cmsis_nn/Include)
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/third_party/cmsis_nn)
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/third_party/ruy)
include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/tensorflow.lite)


# 设置 C 和 C++ 编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wnon-virtual-dtor -O3 -Wall")

# 添加宏定义（等同于 Makefile 中的 COMMON_FLAGS 和后续宏定义）
add_definitions(-DCMSIS_NN_USE_SINGLE_ROUNDING -DTF_LITE_DISABLE_X86_NEON -DNDEBUG -DCMSIS_NN)
add_definitions(-DTF_LITE_STATIC_MEMORY)

# 收集业务代码及 JNI 实现代码
# 收集 tflm/img5 下的所有 C 源文件和 C++ 源文件
file(GLOB_RECURSE IMG5_C_SOURCES "${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/*.c")
file(GLOB_RECURSE IMG5_CPP_SOURCES "${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/*.cc")
# 指定 JNI 实现文件（假设 native-lib.cpp 位于 CMakeLists.txt 同一目录下）
set(JNI_SOURCE "${CMAKE_SOURCE_DIR}/nativelib.cpp")

# 合并所有源文件
set(SOURCE_FILES ${IMG5_C_SOURCES} ${IMG5_CPP_SOURCES} ${JNI_SOURCE})

# 生成动态库（Android JNI 使用共享库）
add_library(nativelib SHARED ${SOURCE_FILES})

# 设置链接器标志（链接数学库和其他标志）
set_target_properties(nativelib PROPERTIES LINK_FLAGS "-lm -Wl,--fatal-warnings -Wl,--gc-sections")

# 如需要链接 Android 日志库，可取消下面注释
# target_link_libraries(native-lib log)


## cpp/rams相关推理使用如下部分：
#
#cmake_minimum_required(VERSION 3.10.2)
#project(nativelib)
#
## config，编译不同apk时在这里替换
#set(MODEL_ROOT "rams" CACHE STRING "Top-level model root under cpp")
#set(MODEL_NAME "img5" CACHE STRING "Model folder inside MODEL_ROOT")
#
## 添加头文件搜索路径：包含 cpp 根目录和 rams/img5 子目录
#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME})
#include_directories(${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/cmsis_nn/Include)
#
## 设置 C 和 C++ 编译选项
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -O3 -Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions -Wnon-virtual-dtor -O3 -Wall")
#
## 添加宏定义，相当于 -DCMSIS_NN_USE_SINGLE_ROUNDING -DNDEBUG -DCMSIS_NN
#add_definitions(-DCMSIS_NN_USE_SINGLE_ROUNDING -DNDEBUG -DCMSIS_NN)
#
## 递归收集所有的 C 和 C++ 源文件
#file(GLOB_RECURSE IMG5_C_SOURCES "${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/*.c")
#file(GLOB_RECURSE IMG5_CPP_SOURCES "${CMAKE_SOURCE_DIR}/${MODEL_ROOT}/${MODEL_NAME}/*.cc")
#set(JNI_SOURCE "${CMAKE_SOURCE_DIR}/nativelib.cpp")
#
## 合并所有源文件列表
#set(SOURCE_FILES ${IMG5_C_SOURCES} ${IMG5_CPP_SOURCES} ${JNI_SOURCE})
#
## 生成动态库（库名为 native-lib，与 System.loadLibrary("native-lib") 对应）
#add_library(nativelib SHARED ${SOURCE_FILES})
#
## 设置链接器标志，例如链接数学库
#set_target_properties(nativelib PROPERTIES LINK_FLAGS "-lm -Wl,--fatal-warnings -Wl,--gc-sections")
#
## 如需要链接 Android 的 log 库，可取消下面注释
## target_link_libraries(nativelib log)