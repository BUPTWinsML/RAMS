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
const cmsis_nn_cdc_dims dims={.n=1,.h=96,.w=96,.in_c=3,.dw_c=16,.out_c=8,.dw_pad_y=1};
const cmsis_nn_conv_params conv1={.input_offset=1,.output_offset=-128,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params conv1_data={.quant_param={.multiplier=Test_StNN::op0_multiplier,.shift=Test_StNN::op0_shift},.bias=Test_StNN::op0_bias,.filter=Test_StNN::op0_filter,};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op1_multiplier,.shift=Test_StNN::op1_shift},.bias=Test_StNN::op1_bias,.filter=Test_StNN::op1_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-6,.filter=Test_StNN::op2_filter,.bias=Test_StNN::op2_bias,.mul=Test_StNN::op2_multiplier,.shift=Test_StNN::op2_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+18432,.im2col2=eval_buf+18432+conv1_im2col,.im2col3=eval_buf+18432+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+18432+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=18432+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1536) / 1536;
conv_3x3_s2_dw_3x3_conv_1x1(&ctx, data, eval_buf + 0, &dims, &conv1, &conv1_data, &dw_conv, &dw_data, &conv3, load_lines);
// 21504
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
const cmsis_nn_cdc_dims dims={.n=1,.h=48,.w=48,.in_c=8,.dw_c=32,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=6,.output_offset=-128,.filter=Test_StNN::op3_filter,.bias=Test_StNN::op3_bias,.mul=Test_StNN::op3_multiplier,.shift=Test_StNN::op3_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op4_multiplier,.shift=Test_StNN::op4_shift},.bias=Test_StNN::op4_bias,.filter=Test_StNN::op4_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-17,.filter=Test_StNN::op5_filter,.bias=Test_StNN::op5_bias,.mul=Test_StNN::op5_multiplier,.shift=Test_StNN::op5_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+18432,.im2col2=eval_buf+18432+conv1_im2col,.im2col3=eval_buf+18432+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+18432+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=18432+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1536) / 3840;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 0, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 23808
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
const cmsis_nn_cdc_dims dims={.n=1,.h=24,.w=24,.in_c=16,.dw_c=48,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=17,.output_offset=-128,.filter=Test_StNN::op6_filter,.bias=Test_StNN::op6_bias,.mul=Test_StNN::op6_multiplier,.shift=Test_StNN::op6_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op7_multiplier,.shift=Test_StNN::op7_shift},.bias=Test_StNN::op7_bias,.filter=Test_StNN::op7_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=6,.filter=Test_StNN::op8_filter,.bias=Test_StNN::op8_bias,.mul=Test_StNN::op8_multiplier,.shift=Test_StNN::op8_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+18432,.im2col2=eval_buf+18432+conv1_im2col,.im2col3=eval_buf+18432+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+18432+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=18432+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2304) / 2304;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 9216, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 23040
}
{
arm_elementwise_add_s8(eval_buf + 9216, eval_buf + 0, -6, 1073741824, 0, 17, 1595385034, -1, 20, eval_buf + 0, 8, 1699908023, -19, -128, 127, 9216);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t conv1_im2col = 0;
#else
const int32_t conv1_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t dwconv_im2col = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t dwconv_im2col = 4704;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=24,.w=24,.in_c=16,.dw_c=48,.out_c=24,.dw_pad_y=3};
const cmsis_nn_conv_params_simplified conv1={.input_offset=-8,.output_offset=-128,.filter=Test_StNN::op10_filter,.bias=Test_StNN::op10_bias,.mul=Test_StNN::op10_multiplier,.shift=Test_StNN::op10_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=3,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op11_multiplier,.shift=Test_StNN::op11_shift},.bias=Test_StNN::op11_bias,.filter=Test_StNN::op11_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-18,.filter=Test_StNN::op12_filter,.bias=Test_StNN::op12_bias,.mul=Test_StNN::op12_multiplier,.shift=Test_StNN::op12_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+12672,.im2col2=eval_buf+12672+conv1_im2col,.im2col3=eval_buf+12672+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+12672+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=12672+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 5760) / 2880;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 0, eval_buf + 9216, 7, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 26016
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
const cmsis_nn_cdc_dims dims={.n=1,.h=12,.w=12,.in_c=24,.dw_c=120,.out_c=24,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=18,.output_offset=-128,.filter=Test_StNN::op13_filter,.bias=Test_StNN::op13_bias,.mul=Test_StNN::op13_multiplier,.shift=Test_StNN::op13_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op14_multiplier,.shift=Test_StNN::op14_shift},.bias=Test_StNN::op14_bias,.filter=Test_StNN::op14_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-14,.filter=Test_StNN::op15_filter,.bias=Test_StNN::op15_bias,.mul=Test_StNN::op15_multiplier,.shift=Test_StNN::op15_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+12672,.im2col2=eval_buf+12672+conv1_im2col,.im2col3=eval_buf+12672+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+12672+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=12672+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2880) / 2880;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 9216, eval_buf + 0, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 18432
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 9216, 14, 1073741824, 0, 18, 1848035287, -1, 20, eval_buf + 17280, -22, 1870044568, -19, -128, 127, 3456);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 22,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op17_multiplier,.shift=Test_StNN::op17_shift};
const cmsis_nn_dims input_dims={.n=1,.h=12,.w=12,.c=24};
const cmsis_nn_dims filter_dims={.n=120,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=12,.w=12,.c=120};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 17280, &filter_dims, Test_StNN::op17_filter, nullptr, Test_StNN::op17_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op18_multiplier,.shift=Test_StNN::op18_shift};
const cmsis_nn_dims input_dims={.n=1,.h=12,.w=12,.c=120};
const cmsis_nn_dims filter_dims={.n=120,.h=3,.w=3,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=120};
const cmsis_nn_context ctx={.buf=eval_buf+21600,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op18_filter, nullptr, Test_StNN::op18_bias, &output_dims, eval_buf + 17280);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 1,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op19_multiplier,.shift=Test_StNN::op19_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=120};
const cmsis_nn_dims filter_dims={.n=40,.h=1,.w=1,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=40};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 17280, &filter_dims, Test_StNN::op19_filter, nullptr, Test_StNN::op19_bias, &output_dims, eval_buf + 11520);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -1,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op20_multiplier,.shift=Test_StNN::op20_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=40};
const cmsis_nn_dims filter_dims={.n=160,.h=1,.w=1,.c=40};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=160};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11520, &filter_dims, Test_StNN::op20_filter, nullptr, Test_StNN::op20_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 15680;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=3,.h=3},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op21_multiplier,.shift=Test_StNN::op21_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=160};
const cmsis_nn_dims filter_dims={.n=160,.h=7,.w=7,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=160};
const cmsis_nn_context ctx={.buf=eval_buf+11520,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op21_filter, nullptr, Test_StNN::op21_bias, &output_dims, eval_buf + 5760);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -15,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op22_multiplier,.shift=Test_StNN::op22_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=160};
const cmsis_nn_dims filter_dims={.n=40,.h=1,.w=1,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=40};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5760, &filter_dims, Test_StNN::op22_filter, nullptr, Test_StNN::op22_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 11520, 15, 1073741824, 0, -1, 2065697433, -1, 20, eval_buf + 5760, -4, 1953248659, -19, -128, 127, 1440);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 4,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op24_multiplier,.shift=Test_StNN::op24_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=40};
const cmsis_nn_dims filter_dims={.n=160,.h=1,.w=1,.c=40};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=160};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5760, &filter_dims, Test_StNN::op24_filter, nullptr, Test_StNN::op24_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 8000;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op25_multiplier,.shift=Test_StNN::op25_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=160};
const cmsis_nn_dims filter_dims={.n=160,.h=5,.w=5,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=160};
const cmsis_nn_context ctx={.buf=eval_buf+11520,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op25_filter, nullptr, Test_StNN::op25_bias, &output_dims, eval_buf + 5760);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -8,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op26_multiplier,.shift=Test_StNN::op26_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=160};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5760, &filter_dims, Test_StNN::op26_filter, nullptr, Test_StNN::op26_bias, &output_dims, eval_buf + 11520);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 8,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op27_multiplier,.shift=Test_StNN::op27_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=48};
const cmsis_nn_dims filter_dims={.n=144,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=144};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11520, &filter_dims, Test_StNN::op27_filter, nullptr, Test_StNN::op27_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op28_multiplier,.shift=Test_StNN::op28_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=144};
const cmsis_nn_dims filter_dims={.n=144,.h=3,.w=3,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=144};
const cmsis_nn_context ctx={.buf=eval_buf+10368,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op28_filter, nullptr, Test_StNN::op28_bias, &output_dims, eval_buf + 5184);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 2,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op29_multiplier,.shift=Test_StNN::op29_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=144};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5184, &filter_dims, Test_StNN::op29_filter, nullptr, Test_StNN::op29_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 11520, -2, 1884804326, -1, 8, 1073741824, 0, 20, eval_buf + 13824, 0, 1809301335, -19, -128, 127, 1728);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 0,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op31_multiplier,.shift=Test_StNN::op31_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=48};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 13824, &filter_dims, Test_StNN::op31_filter, nullptr, Test_StNN::op31_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op32_multiplier,.shift=Test_StNN::op32_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=3,.w=3,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+13824,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op32_filter, nullptr, Test_StNN::op32_bias, &output_dims, eval_buf + 6912);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -7,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op33_multiplier,.shift=Test_StNN::op33_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=192};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6912, &filter_dims, Test_StNN::op33_filter, nullptr, Test_StNN::op33_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 13824, 7, 1546308785, -1, 0, 1073741824, 0, 20, eval_buf + 8640, -4, 2021282153, -19, -128, 127, 1728);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 4,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op35_multiplier,.shift=Test_StNN::op35_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=48};
const cmsis_nn_dims filter_dims={.n=240,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=240};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8640, &filter_dims, Test_StNN::op35_filter, nullptr, Test_StNN::op35_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op36_multiplier,.shift=Test_StNN::op36_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=240};
const cmsis_nn_dims filter_dims={.n=240,.h=7,.w=7,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_context ctx={.buf=eval_buf+10800,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op36_filter, nullptr, Test_StNN::op36_bias, &output_dims, eval_buf + 8640);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -3,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op37_multiplier,.shift=Test_StNN::op37_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8640, &filter_dims, Test_StNN::op37_filter, nullptr, Test_StNN::op37_bias, &output_dims, eval_buf + 6912);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 3,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op38_multiplier,.shift=Test_StNN::op38_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=96};
const cmsis_nn_dims filter_dims={.n=384,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=384};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6912, &filter_dims, Test_StNN::op38_filter, nullptr, Test_StNN::op38_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 19200;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op39_multiplier,.shift=Test_StNN::op39_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_dims filter_dims={.n=384,.h=5,.w=5,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_context ctx={.buf=eval_buf+6912,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op39_filter, nullptr, Test_StNN::op39_bias, &output_dims, eval_buf + 3456);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -11,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op40_multiplier,.shift=Test_StNN::op40_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3456, &filter_dims, Test_StNN::op40_filter, nullptr, Test_StNN::op40_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 6912, 11, 1916523343, -1, 3, 1073741824, 0, 20, eval_buf + 7776, -5, 1743699543, -19, -128, 127, 864);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 5,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op42_multiplier,.shift=Test_StNN::op42_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=96};
const cmsis_nn_dims filter_dims={.n=384,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=384};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 7776, &filter_dims, Test_StNN::op42_filter, nullptr, Test_StNN::op42_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 19200;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op43_multiplier,.shift=Test_StNN::op43_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_dims filter_dims={.n=384,.h=5,.w=5,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_context ctx={.buf=eval_buf+6912,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op43_filter, nullptr, Test_StNN::op43_bias, &output_dims, eval_buf + 3456);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 3,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op44_multiplier,.shift=Test_StNN::op44_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3456, &filter_dims, Test_StNN::op44_filter, nullptr, Test_StNN::op44_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 7776, -3, 1073741824, 0, 5, 2118685251, -1, 20, eval_buf + 5184, -10, 1645784421, -19, -128, 127, 864);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 10,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op46_multiplier,.shift=Test_StNN::op46_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=96};
const cmsis_nn_dims filter_dims={.n=576,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=576};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5184, &filter_dims, Test_StNN::op46_filter, nullptr, Test_StNN::op46_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op47_multiplier,.shift=Test_StNN::op47_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=576};
const cmsis_nn_dims filter_dims={.n=576,.h=3,.w=3,.c=576};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=576};
const cmsis_nn_context ctx={.buf=eval_buf+10368,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op47_filter, nullptr, Test_StNN::op47_bias, &output_dims, eval_buf + 5184);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -3,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op48_multiplier,.shift=Test_StNN::op48_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=576};
const cmsis_nn_dims filter_dims={.n=160,.h=1,.w=1,.c=576};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=160};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5184, &filter_dims, Test_StNN::op48_filter, nullptr, Test_StNN::op48_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#elif defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 640;
#else
const int32_t im2col_buf_size = 0;
#endif
arm_avgpool_s8_m(eval_buf + 1600, 3, 3, 1, 1, 3, 3, 3, 3, 0, 0, -128, 127, 160, 1, eval_buf + 0, eval_buf + 1440);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 3,.output_offset = -35,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op50_multiplier,.shift=Test_StNN::op50_shift};
const cmsis_nn_dims input_dims={.n=1,.h=1,.w=1,.c=160};
const cmsis_nn_dims filter_dims={.n=1000,.h=1,.w=1,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=1,.w=1,.c=1000};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1440, &filter_dims, Test_StNN::op50_filter, nullptr, Test_StNN::op50_bias, &output_dims, eval_buf + 0);
}
{
}
return ;
}


#include "random_data.h"
#include "demo.h"
float invoke_img5() {
    static uint8_t arena[120000];
    int8_t *new_eval_buf = nullptr;
    ALIGN_PTR_TO_16(new_eval_buf, arena);
    auto begin = std::chrono::high_resolution_clock::now();
        invoke(tinyts_random_data, new_eval_buf, 30000);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return (elapsed.count() * 1e-6); // ms
}