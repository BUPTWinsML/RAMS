package com.example.cppinvoke;

import android.os.Bundle;
import android.util.Log;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;

import androidx.navigation.ui.AppBarConfiguration;

import com.example.cppinvoke.databinding.ActivityMainBinding;
import com.example.cppinvoke.databinding.ContentMainBinding;

import android.view.Menu;
import android.view.MenuItem;

import org.tensorflow.lite.Interpreter;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.util.HashMap;
import java.util.Map;

import android.content.res.AssetFileDescriptor; // 导入 AssetFileDescriptor
import java.util.Locale; // 保留小数


public class MainActivity extends AppCompatActivity {

    private AppBarConfiguration appBarConfiguration;
    private ActivityMainBinding binding;
    private ContentMainBinding contentBinding;
    private Interpreter tflite;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        // 初始化 ContentMainBinding
        contentBinding = ContentMainBinding.bind(findViewById(R.id.content_main));

        setSupportActionBar(binding.toolbar);

        // 设置按钮的点击事件
        contentBinding.runInferenceButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                runInference();
            }
        });

        binding.fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAnchorView(R.id.fab)
                        .setAction("Action", null).show();
            }
        });
    }

    private void runInference() {
        try {
            // 调用 C++ 层的 JNI 接口，获取推理耗时
            NativeLib nativeLib = new NativeLib();
            double nativeInferenceTime = nativeLib.getInferenceTime();

            // 计算推理时间并更新 UI
            // long inferenceTime = (endTime - startTime) / 1_000_000;
            String msg = String.format(Locale.US, "Cpp Inference Time: %.3f ms", nativeInferenceTime);
            contentBinding.inferenceTimeText.setText(msg);
            Log.i("CppInvoke", msg);
        } catch (Exception e) {
            Log.e("InferenceError", "Error during inference: " + e.getMessage());
        }
    }

    private MappedByteBuffer loadModelFile() throws IOException {
        Log.d("TensorFlowLite", "Attempting to load model...");
        AssetFileDescriptor fileDescriptor = getAssets().openFd("bert_model.tflite");
        Log.d("TensorFlowLite", "Open model file");
        // 使用 try-with-resources 确保文件流会被关闭
        try (FileInputStream inputStream = new FileInputStream(fileDescriptor.getFileDescriptor())) {
            FileChannel fileChannel = inputStream.getChannel();
            long startOffset = fileDescriptor.getStartOffset();
            long declaredLength = fileDescriptor.getDeclaredLength();
            return fileChannel.map(FileChannel.MapMode.READ_ONLY, startOffset, declaredLength);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
