// Top-level build file where you can add configuration options common to all sub-projects/modules.
plugins {
    alias(libs.plugins.android.application) apply false
}

// 根目录下的 build.gradle.kts 文件
buildscript {
    dependencies {
        // Android 构建工具
        classpath("com.android.tools.build:gradle:8.7.3")
    }
}