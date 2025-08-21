#include "cmsis_nn/Include/arm_nnfunctions.h"
#include "cmsis_nn/Include/arm_nn_types.h"
#include <cstdint>
#include <cstdlib>
#include "arm_nnsupportfunctions.h"
#include "arm_avgpool_s8_m.h"
#include "test.h"
#include <unistd.h>
#include <stdio.h>




#define ALIGN_PTR_TO_16(ptr, base) ptr = (int8_t*)((((uintptr_t)(base) + 15) / 16) * 16)

void invoke(const int8_t *data, int8_t *eval_buf, const int32_t eval_buf_size) {
{
#if defined(ARM_MATH_MVEI)
const int32_t conv1_im2col = 128;
#else
const int32_t conv1_im2col = 112;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t dwconv_im2col = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t dwconv_im2col = 0;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=64,.w=64,.in_c=3,.dw_c=16,.out_c=8,.dw_pad_y=1};
const cmsis_nn_conv_params conv1={.input_offset=1,.output_offset=-128,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params conv1_data={.quant_param={.multiplier=Test_StNN::op0_multiplier,.shift=Test_StNN::op0_shift},.bias=Test_StNN::op0_bias,.filter=Test_StNN::op0_filter,};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op1_multiplier,.shift=Test_StNN::op1_shift},.bias=Test_StNN::op1_bias,.filter=Test_StNN::op1_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=0,.filter=Test_StNN::op2_filter,.bias=Test_StNN::op2_bias,.mul=Test_StNN::op2_multiplier,.shift=Test_StNN::op2_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+8192,.im2col2=eval_buf+8192+conv1_im2col,.im2col3=eval_buf+8192+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+8192+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=8192+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1024) / 1024;
conv_3x3_s2_dw_3x3_conv_1x1(&ctx, data, eval_buf + 0, &dims, &conv1, &conv1_data, &dw_conv, &dw_data, &conv3, load_lines);
// 10240
}
{
#if defined(ARM_MATH_MVEI)
const int32_t conv1_im2col = 0;
#else
const int32_t conv1_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t dwconv_im2col = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t dwconv_im2col = 2400;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=32,.w=32,.in_c=8,.dw_c=48,.out_c=16,.dw_pad_y=2};
const cmsis_nn_conv_params_simplified conv1={.input_offset=0,.output_offset=-128,.filter=Test_StNN::op3_filter,.bias=Test_StNN::op3_bias,.mul=Test_StNN::op3_multiplier,.shift=Test_StNN::op3_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=2,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op4_multiplier,.shift=Test_StNN::op4_shift},.bias=Test_StNN::op4_bias,.filter=Test_StNN::op4_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-22,.filter=Test_StNN::op5_filter,.bias=Test_StNN::op5_bias,.mul=Test_StNN::op5_multiplier,.shift=Test_StNN::op5_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+8192,.im2col2=eval_buf+8192+conv1_im2col,.im2col3=eval_buf+8192+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+8192+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=8192+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 4608) / 3840;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 0, eval_buf + 0, 5, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 19040
}
{
#if defined(ARM_MATH_MVEI)
const int32_t conv1_im2col = 0;
#else
const int32_t conv1_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t dwconv_im2col = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t dwconv_im2col = 0;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=16,.w=16,.in_c=16,.dw_c=64,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=22,.output_offset=-128,.filter=Test_StNN::op6_filter,.bias=Test_StNN::op6_bias,.mul=Test_StNN::op6_multiplier,.shift=Test_StNN::op6_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op7_multiplier,.shift=Test_StNN::op7_shift},.bias=Test_StNN::op7_bias,.filter=Test_StNN::op7_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=6,.filter=Test_StNN::op8_filter,.bias=Test_StNN::op8_bias,.mul=Test_StNN::op8_multiplier,.shift=Test_StNN::op8_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+8192,.im2col2=eval_buf+8192+conv1_im2col,.im2col3=eval_buf+8192+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+8192+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=8192+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2048) / 2048;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 4096, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 12288
}
{
arm_elementwise_add_s8(eval_buf + 4096, eval_buf + 0, -6, 1785103811, -1, 22, 1073741824, 0, 20, eval_buf + 20480, -7, 1938331585, -19, -128, 127, 4096);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 7,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op10_multiplier,.shift=Test_StNN::op10_shift};
const cmsis_nn_dims input_dims={.n=1,.h=16,.w=16,.c=16};
const cmsis_nn_dims filter_dims={.n=80,.h=1,.w=1,.c=16};
const cmsis_nn_dims output_dims={.n=1,.h=16,.w=16,.c=80};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 20480, &filter_dims, Test_StNN::op10_filter, nullptr, Test_StNN::op10_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op11_multiplier,.shift=Test_StNN::op11_shift};
const cmsis_nn_dims input_dims={.n=1,.h=16,.w=16,.c=80};
const cmsis_nn_dims filter_dims={.n=80,.h=3,.w=3,.c=80};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=80};
const cmsis_nn_context ctx={.buf=eval_buf+25600,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op11_filter, nullptr, Test_StNN::op11_bias, &output_dims, eval_buf + 20480);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 5,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op12_multiplier,.shift=Test_StNN::op12_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=80};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=80};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 20480, &filter_dims, Test_StNN::op12_filter, nullptr, Test_StNN::op12_bias, &output_dims, eval_buf + 12288);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -5,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op13_multiplier,.shift=Test_StNN::op13_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=24};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 12288, &filter_dims, Test_StNN::op13_filter, nullptr, Test_StNN::op13_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op14_multiplier,.shift=Test_StNN::op14_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=96};
const cmsis_nn_dims filter_dims={.n=96,.h=3,.w=3,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=96};
const cmsis_nn_context ctx={.buf=eval_buf+12288,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op14_filter, nullptr, Test_StNN::op14_bias, &output_dims, eval_buf + 6144);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 2,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op15_multiplier,.shift=Test_StNN::op15_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=96};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6144, &filter_dims, Test_StNN::op15_filter, nullptr, Test_StNN::op15_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 12288, -2, 2086460944, -1, -5, 1073741824, 0, 20, eval_buf + 13824, 1, 1899219683, -19, -128, 127, 1536);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -1,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op17_multiplier,.shift=Test_StNN::op17_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=24};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 13824, &filter_dims, Test_StNN::op17_filter, nullptr, Test_StNN::op17_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op18_multiplier,.shift=Test_StNN::op18_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=96};
const cmsis_nn_dims filter_dims={.n=96,.h=3,.w=3,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=96};
const cmsis_nn_context ctx={.buf=eval_buf+12288,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op18_filter, nullptr, Test_StNN::op18_bias, &output_dims, eval_buf + 6144);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -6,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op19_multiplier,.shift=Test_StNN::op19_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=96};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6144, &filter_dims, Test_StNN::op19_filter, nullptr, Test_StNN::op19_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 13824, 6, 1765608801, -2, -1, 1073741824, 0, 20, eval_buf + 7680, 7, 1980469084, -19, -128, 127, 1536);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -7,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op21_multiplier,.shift=Test_StNN::op21_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=24};
const cmsis_nn_dims filter_dims={.n=120,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=8,.w=8,.c=120};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 7680, &filter_dims, Test_StNN::op21_filter, nullptr, Test_StNN::op21_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op22_multiplier,.shift=Test_StNN::op22_shift};
const cmsis_nn_dims input_dims={.n=1,.h=8,.w=8,.c=120};
const cmsis_nn_dims filter_dims={.n=120,.h=3,.w=3,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_context ctx={.buf=eval_buf+9600,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op22_filter, nullptr, Test_StNN::op22_bias, &output_dims, eval_buf + 7680);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -18,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op23_multiplier,.shift=Test_StNN::op23_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_dims filter_dims={.n=40,.h=1,.w=1,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=40};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 7680, &filter_dims, Test_StNN::op23_filter, nullptr, Test_StNN::op23_bias, &output_dims, eval_buf + 5120);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 18,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op24_multiplier,.shift=Test_StNN::op24_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=40};
const cmsis_nn_dims filter_dims={.n=160,.h=1,.w=1,.c=40};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=160};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5120, &filter_dims, Test_StNN::op24_filter, nullptr, Test_StNN::op24_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op25_multiplier,.shift=Test_StNN::op25_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=160};
const cmsis_nn_dims filter_dims={.n=160,.h=3,.w=3,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=160};
const cmsis_nn_context ctx={.buf=eval_buf+5120,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op25_filter, nullptr, Test_StNN::op25_bias, &output_dims, eval_buf + 2560);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -8,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op26_multiplier,.shift=Test_StNN::op26_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=160};
const cmsis_nn_dims filter_dims={.n=40,.h=1,.w=1,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=40};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2560, &filter_dims, Test_StNN::op26_filter, nullptr, Test_StNN::op26_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 5120, 8, 1825212155, -1, 18, 1073741824, 0, 20, eval_buf + 3840, -9, 1942687389, -19, -128, 127, 640);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 9,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op28_multiplier,.shift=Test_StNN::op28_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=40};
const cmsis_nn_dims filter_dims={.n=120,.h=1,.w=1,.c=40};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=120};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3840, &filter_dims, Test_StNN::op28_filter, nullptr, Test_StNN::op28_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 11760;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=3,.h=3},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op29_multiplier,.shift=Test_StNN::op29_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_dims filter_dims={.n=120,.h=7,.w=7,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_context ctx={.buf=eval_buf+3840,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op29_filter, nullptr, Test_StNN::op29_bias, &output_dims, eval_buf + 1920);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 25,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op30_multiplier,.shift=Test_StNN::op30_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_dims filter_dims={.n=40,.h=1,.w=1,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=40};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1920, &filter_dims, Test_StNN::op30_filter, nullptr, Test_StNN::op30_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 3840, -25, 1391170981, -2, 9, 1073741824, 0, 20, eval_buf + 1920, -11, 2136511470, -19, -128, 127, 640);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 11,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op32_multiplier,.shift=Test_StNN::op32_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=40};
const cmsis_nn_dims filter_dims={.n=120,.h=1,.w=1,.c=40};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=120};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1920, &filter_dims, Test_StNN::op32_filter, nullptr, Test_StNN::op32_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op33_multiplier,.shift=Test_StNN::op33_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_dims filter_dims={.n=120,.h=3,.w=3,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_context ctx={.buf=eval_buf+3840,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op33_filter, nullptr, Test_StNN::op33_bias, &output_dims, eval_buf + 1920);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -2,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op34_multiplier,.shift=Test_StNN::op34_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=120};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1920, &filter_dims, Test_StNN::op34_filter, nullptr, Test_StNN::op34_bias, &output_dims, eval_buf + 6144);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 2,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op35_multiplier,.shift=Test_StNN::op35_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=48};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6144, &filter_dims, Test_StNN::op35_filter, nullptr, Test_StNN::op35_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 4464;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op36_multiplier,.shift=Test_StNN::op36_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=3,.w=3,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+6144,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op36_filter, nullptr, Test_StNN::op36_bias, &output_dims, eval_buf + 3072);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -11,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op37_multiplier,.shift=Test_StNN::op37_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=192};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3072, &filter_dims, Test_StNN::op37_filter, nullptr, Test_StNN::op37_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 6144, 11, 1073741824, 0, 2, 1608900243, -1, 20, eval_buf + 3840, -1, 2140498155, -19, -128, 127, 768);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 1,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op39_multiplier,.shift=Test_StNN::op39_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=48};
const cmsis_nn_dims filter_dims={.n=240,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=4,.w=4,.c=240};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3840, &filter_dims, Test_StNN::op39_filter, nullptr, Test_StNN::op39_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 23520;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=3,.h=3},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op40_multiplier,.shift=Test_StNN::op40_shift};
const cmsis_nn_dims input_dims={.n=1,.h=4,.w=4,.c=240};
const cmsis_nn_dims filter_dims={.n=240,.h=7,.w=7,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=240};
const cmsis_nn_context ctx={.buf=eval_buf+4800,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op40_filter, nullptr, Test_StNN::op40_bias, &output_dims, eval_buf + 3840);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -15,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op41_multiplier,.shift=Test_StNN::op41_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=240};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3840, &filter_dims, Test_StNN::op41_filter, nullptr, Test_StNN::op41_bias, &output_dims, eval_buf + 4800);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 15,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op42_multiplier,.shift=Test_StNN::op42_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=96};
const cmsis_nn_dims filter_dims={.n=480,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=480};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4800, &filter_dims, Test_StNN::op42_filter, nullptr, Test_StNN::op42_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 24000;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op43_multiplier,.shift=Test_StNN::op43_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=480};
const cmsis_nn_dims filter_dims={.n=480,.h=5,.w=5,.c=480};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=480};
const cmsis_nn_context ctx={.buf=eval_buf+3840,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op43_filter, nullptr, Test_StNN::op43_bias, &output_dims, eval_buf + 1920);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 4,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op44_multiplier,.shift=Test_StNN::op44_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=480};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=480};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1920, &filter_dims, Test_StNN::op44_filter, nullptr, Test_StNN::op44_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 4800, -4, 1935178768, -1, 15, 1073741824, 0, 20, eval_buf + 1536, 0, 1104644408, -18, -128, 127, 384);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 0,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op46_multiplier,.shift=Test_StNN::op46_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=96};
const cmsis_nn_dims filter_dims={.n=384,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=384};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1536, &filter_dims, Test_StNN::op46_filter, nullptr, Test_StNN::op46_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 37632;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=3,.h=3},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op47_multiplier,.shift=Test_StNN::op47_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=384};
const cmsis_nn_dims filter_dims={.n=384,.h=7,.w=7,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=384};
const cmsis_nn_context ctx={.buf=eval_buf+3072,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op47_filter, nullptr, Test_StNN::op47_bias, &output_dims, eval_buf + 1536);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 12,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op48_multiplier,.shift=Test_StNN::op48_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=384};
const cmsis_nn_dims filter_dims={.n=160,.h=1,.w=1,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=160};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1536, &filter_dims, Test_StNN::op48_filter, nullptr, Test_StNN::op48_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#elif defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 640;
#else
const int32_t im2col_buf_size = 0;
#endif
arm_avgpool_s8_m(eval_buf + 800, 2, 2, 1, 1, 2, 2, 2, 2, 0, 0, -128, 127, 160, 1, eval_buf + 0, eval_buf + 640);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -12,.output_offset = 0,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op50_multiplier,.shift=Test_StNN::op50_shift};
const cmsis_nn_dims input_dims={.n=1,.h=1,.w=1,.c=160};
const cmsis_nn_dims filter_dims={.n=2,.h=1,.w=1,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=1,.w=1,.c=2};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 640, &filter_dims, Test_StNN::op50_filter, nullptr, Test_StNN::op50_bias, &output_dims, eval_buf + 0);
}
{
}
return ;
}



#include "random_data.h"
#include "demo.h"
float invoke_mw10() {
    static uint8_t arena[120000];
    int8_t *new_eval_buf = nullptr;
    ALIGN_PTR_TO_16(new_eval_buf, arena);
    auto begin = std::chrono::high_resolution_clock::now();
        invoke(tinyts_random_data, new_eval_buf, 20000);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return (elapsed.count() * 1e-6); // ms
}