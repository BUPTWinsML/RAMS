package com.example.cppinvoke;

public class NativeLib {
    // 静态代码块中加载动态库，库名应与 CMakeLists.txt 中 add_library 指定的名称一致
    static {
        System.loadLibrary("nativelib");
    }

    // 声明 native 方法，例如获取推理耗时
    public native double getInferenceTime();
}
