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
const cmsis_nn_cdc_dims dims={.n=1,.h=48,.w=48,.in_c=3,.dw_c=24,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params conv1={.input_offset=1,.output_offset=-128,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params conv1_data={.quant_param={.multiplier=Test_StNN::op0_multiplier,.shift=Test_StNN::op0_shift},.bias=Test_StNN::op0_bias,.filter=Test_StNN::op0_filter,};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op1_multiplier,.shift=Test_StNN::op1_shift},.bias=Test_StNN::op1_bias,.filter=Test_StNN::op1_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=6,.filter=Test_StNN::op2_filter,.bias=Test_StNN::op2_bias,.mul=Test_StNN::op2_multiplier,.shift=Test_StNN::op2_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+9216,.im2col2=eval_buf+9216+conv1_im2col,.im2col3=eval_buf+9216+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+9216+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=9216+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1152) / 1152;
conv_3x3_s2_dw_3x3_conv_1x1(&ctx, data, eval_buf + 0, &dims, &conv1, &conv1_data, &dw_conv, &dw_data, &conv3, load_lines);
// 11520
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
const int32_t dwconv_im2col = 3200;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=24,.w=24,.in_c=16,.dw_c=64,.out_c=16,.dw_pad_y=2};
const cmsis_nn_conv_params_simplified conv1={.input_offset=-6,.output_offset=-128,.filter=Test_StNN::op3_filter,.bias=Test_StNN::op3_bias,.mul=Test_StNN::op3_multiplier,.shift=Test_StNN::op3_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=2,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op4_multiplier,.shift=Test_StNN::op4_shift},.bias=Test_StNN::op4_bias,.filter=Test_StNN::op4_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=21,.filter=Test_StNN::op5_filter,.bias=Test_StNN::op5_bias,.mul=Test_StNN::op5_multiplier,.shift=Test_StNN::op5_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+9216,.im2col2=eval_buf+9216+conv1_im2col,.im2col3=eval_buf+9216+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+9216+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=9216+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 4608) / 3840;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 0, eval_buf + 0, 5, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 20864
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -21,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op6_multiplier,.shift=Test_StNN::op6_shift};
const cmsis_nn_dims input_dims={.n=1,.h=12,.w=12,.c=16};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=16};
const cmsis_nn_dims output_dims={.n=1,.h=12,.w=12,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op6_filter, nullptr, Test_StNN::op6_bias, &output_dims, eval_buf + 2304);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op7_multiplier,.shift=Test_StNN::op7_shift};
const cmsis_nn_dims input_dims={.n=1,.h=12,.w=12,.c=48};
const cmsis_nn_dims filter_dims={.n=48,.h=3,.w=3,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=12,.w=12,.c=48};
const cmsis_nn_context ctx={.buf=eval_buf+9216,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 2304, &filter_dims, Test_StNN::op7_filter, nullptr, Test_StNN::op7_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 22,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op8_multiplier,.shift=Test_StNN::op8_shift};
const cmsis_nn_dims input_dims={.n=1,.h=12,.w=12,.c=48};
const cmsis_nn_dims filter_dims={.n=16,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=12,.w=12,.c=16};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op8_filter, nullptr, Test_StNN::op8_bias, &output_dims, eval_buf + 6912);
}
{
arm_elementwise_add_s8(eval_buf + 6912, eval_buf + 0, -22, 1633779083, -1, -21, 1073741824, 0, 20, eval_buf + 0, -11, 2044708687, -19, -128, 127, 2304);
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
const cmsis_nn_cdc_dims dims={.n=1,.h=12,.w=12,.in_c=16,.dw_c=64,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=11,.output_offset=-128,.filter=Test_StNN::op10_filter,.bias=Test_StNN::op10_bias,.mul=Test_StNN::op10_multiplier,.shift=Test_StNN::op10_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op11_multiplier,.shift=Test_StNN::op11_shift},.bias=Test_StNN::op11_bias,.filter=Test_StNN::op11_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=5,.filter=Test_StNN::op12_filter,.bias=Test_StNN::op12_bias,.mul=Test_StNN::op12_multiplier,.shift=Test_StNN::op12_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+4608,.im2col2=eval_buf+4608+conv1_im2col,.im2col3=eval_buf+4608+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+4608+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=4608+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1536) / 1536;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 2304, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 7680
}
{
arm_elementwise_add_s8(eval_buf + 2304, eval_buf + 0, -5, 1229873714, -1, 11, 1073741824, 0, 20, eval_buf + 4608, -34, 1684649032, -19, -128, 127, 2304);
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
const int32_t dwconv_im2col = 7840;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=12,.w=12,.in_c=16,.dw_c=80,.out_c=24,.dw_pad_y=3};
const cmsis_nn_conv_params_simplified conv1={.input_offset=34,.output_offset=-128,.filter=Test_StNN::op14_filter,.bias=Test_StNN::op14_bias,.mul=Test_StNN::op14_multiplier,.shift=Test_StNN::op14_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=3,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op15_multiplier,.shift=Test_StNN::op15_shift},.bias=Test_StNN::op15_bias,.filter=Test_StNN::op15_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-15,.filter=Test_StNN::op16_filter,.bias=Test_StNN::op16_bias,.mul=Test_StNN::op16_multiplier,.shift=Test_StNN::op16_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+6912,.im2col2=eval_buf+6912+conv1_im2col,.im2col3=eval_buf+6912+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+6912+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=6912+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 4800) / 2400;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 4608, eval_buf + 0, 7, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 21952
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
const int32_t dwconv_im2col = 4800;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=6,.w=6,.in_c=24,.dw_c=96,.out_c=24,.dw_pad_y=2};
const cmsis_nn_conv_params_simplified conv1={.input_offset=15,.output_offset=-128,.filter=Test_StNN::op17_filter,.bias=Test_StNN::op17_bias,.mul=Test_StNN::op17_multiplier,.shift=Test_StNN::op17_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op18_multiplier,.shift=Test_StNN::op18_shift},.bias=Test_StNN::op18_bias,.filter=Test_StNN::op18_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-5,.filter=Test_StNN::op19_filter,.bias=Test_StNN::op19_bias,.mul=Test_StNN::op19_multiplier,.shift=Test_StNN::op19_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+1728,.im2col2=eval_buf+1728+conv1_im2col,.im2col3=eval_buf+1728+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+1728+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=1728+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2304) / 1152;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 0, eval_buf + 864, 5, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 9984
}
{
arm_elementwise_add_s8(eval_buf + 864, eval_buf + 0, 5, 2055534307, -2, 15, 1073741824, 0, 20, eval_buf + 8640, -16, 1821571126, -19, -128, 127, 864);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 16,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op21_multiplier,.shift=Test_StNN::op21_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=24};
const cmsis_nn_dims filter_dims={.n=120,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=120};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8640, &filter_dims, Test_StNN::op21_filter, nullptr, Test_StNN::op21_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 6000;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op22_multiplier,.shift=Test_StNN::op22_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=120};
const cmsis_nn_dims filter_dims={.n=120,.h=5,.w=5,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=120};
const cmsis_nn_context ctx={.buf=eval_buf+8640,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op22_filter, nullptr, Test_StNN::op22_bias, &output_dims, eval_buf + 4320);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 14,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op23_multiplier,.shift=Test_StNN::op23_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=120};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4320, &filter_dims, Test_StNN::op23_filter, nullptr, Test_StNN::op23_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 8640, -14, 1670652429, -2, 16, 1073741824, 0, 20, eval_buf + 4320, -16, 1800226553, -19, -128, 127, 864);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 16,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op25_multiplier,.shift=Test_StNN::op25_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=24};
const cmsis_nn_dims filter_dims={.n=120,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=6,.w=6,.c=120};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4320, &filter_dims, Test_StNN::op25_filter, nullptr, Test_StNN::op25_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 11760;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=3,.h=3},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op26_multiplier,.shift=Test_StNN::op26_shift};
const cmsis_nn_dims input_dims={.n=1,.h=6,.w=6,.c=120};
const cmsis_nn_dims filter_dims={.n=120,.h=7,.w=7,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=120};
const cmsis_nn_context ctx={.buf=eval_buf+5408,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op26_filter, nullptr, Test_StNN::op26_bias, &output_dims, eval_buf + 4320);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -5,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op27_multiplier,.shift=Test_StNN::op27_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=120};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=120};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4320, &filter_dims, Test_StNN::op27_filter, nullptr, Test_StNN::op27_bias, &output_dims, eval_buf + 3456);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 5,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op28_multiplier,.shift=Test_StNN::op28_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=48};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3456, &filter_dims, Test_StNN::op28_filter, nullptr, Test_StNN::op28_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 9600;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op29_multiplier,.shift=Test_StNN::op29_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=5,.w=5,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+3456,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op29_filter, nullptr, Test_StNN::op29_bias, &output_dims, eval_buf + 1728);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -14,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op30_multiplier,.shift=Test_StNN::op30_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=192};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1728, &filter_dims, Test_StNN::op30_filter, nullptr, Test_StNN::op30_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 3456, 14, 1520779573, -1, 5, 1073741824, 0, 20, eval_buf + 2160, -9, 2078881599, -19, -128, 127, 432);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 9,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op32_multiplier,.shift=Test_StNN::op32_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=48};
const cmsis_nn_dims filter_dims={.n=240,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=240};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2160, &filter_dims, Test_StNN::op32_filter, nullptr, Test_StNN::op32_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_dims filter_dims={.n=240,.h=3,.w=3,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_context ctx={.buf=eval_buf+4320,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op33_filter, nullptr, Test_StNN::op33_bias, &output_dims, eval_buf + 2160);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 3,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op34_multiplier,.shift=Test_StNN::op34_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_dims filter_dims={.n=56,.h=1,.w=1,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=56};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2160, &filter_dims, Test_StNN::op34_filter, nullptr, Test_StNN::op34_bias, &output_dims, eval_buf + 4320);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -3,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op35_multiplier,.shift=Test_StNN::op35_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=56};
const cmsis_nn_dims filter_dims={.n=224,.h=1,.w=1,.c=56};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=224};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4320, &filter_dims, Test_StNN::op35_filter, nullptr, Test_StNN::op35_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 11200;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op36_multiplier,.shift=Test_StNN::op36_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=224};
const cmsis_nn_dims filter_dims={.n=224,.h=5,.w=5,.c=224};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=224};
const cmsis_nn_context ctx={.buf=eval_buf+4032,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op36_filter, nullptr, Test_StNN::op36_bias, &output_dims, eval_buf + 2016);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 20,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op37_multiplier,.shift=Test_StNN::op37_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=224};
const cmsis_nn_dims filter_dims={.n=56,.h=1,.w=1,.c=224};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=56};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2016, &filter_dims, Test_StNN::op37_filter, nullptr, Test_StNN::op37_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 4320, -20, 1425446827, -1, -3, 1073741824, 0, 20, eval_buf + 5056, 7, 1959035511, -19, -128, 127, 504);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -7,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op39_multiplier,.shift=Test_StNN::op39_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=56};
const cmsis_nn_dims filter_dims={.n=280,.h=1,.w=1,.c=56};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=280};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 5056, &filter_dims, Test_StNN::op39_filter, nullptr, Test_StNN::op39_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op40_multiplier,.shift=Test_StNN::op40_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=280};
const cmsis_nn_dims filter_dims={.n=280,.h=3,.w=3,.c=280};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=280};
const cmsis_nn_context ctx={.buf=eval_buf+5056,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op40_filter, nullptr, Test_StNN::op40_bias, &output_dims, eval_buf + 2528);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 10,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op41_multiplier,.shift=Test_StNN::op41_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=280};
const cmsis_nn_dims filter_dims={.n=56,.h=1,.w=1,.c=280};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=56};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2528, &filter_dims, Test_StNN::op41_filter, nullptr, Test_StNN::op41_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 5056, -10, 1206740327, -1, -7, 1073741824, 0, 20, eval_buf + 3024, 6, 2042165847, -19, -128, 127, 504);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -6,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op43_multiplier,.shift=Test_StNN::op43_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=56};
const cmsis_nn_dims filter_dims={.n=336,.h=1,.w=1,.c=56};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=336};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3024, &filter_dims, Test_StNN::op43_filter, nullptr, Test_StNN::op43_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op44_multiplier,.shift=Test_StNN::op44_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=336};
const cmsis_nn_dims filter_dims={.n=336,.h=3,.w=3,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=336};
const cmsis_nn_context ctx={.buf=eval_buf+4368,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op44_filter, nullptr, Test_StNN::op44_bias, &output_dims, eval_buf + 3024);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 7,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op45_multiplier,.shift=Test_StNN::op45_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=336};
const cmsis_nn_dims filter_dims={.n=112,.h=1,.w=1,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=112};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3024, &filter_dims, Test_StNN::op45_filter, nullptr, Test_StNN::op45_bias, &output_dims, eval_buf + 4368);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -7,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op46_multiplier,.shift=Test_StNN::op46_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=112};
const cmsis_nn_dims filter_dims={.n=448,.h=1,.w=1,.c=112};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=448};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4368, &filter_dims, Test_StNN::op46_filter, nullptr, Test_StNN::op46_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 22400;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op47_multiplier,.shift=Test_StNN::op47_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=448};
const cmsis_nn_dims filter_dims={.n=448,.h=5,.w=5,.c=448};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=448};
const cmsis_nn_context ctx={.buf=eval_buf+3584,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op47_filter, nullptr, Test_StNN::op47_bias, &output_dims, eval_buf + 1792);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -13,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op48_multiplier,.shift=Test_StNN::op48_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=448};
const cmsis_nn_dims filter_dims={.n=112,.h=1,.w=1,.c=448};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=112};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1792, &filter_dims, Test_StNN::op48_filter, nullptr, Test_StNN::op48_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 4368, 13, 1521782614, -1, -7, 1073741824, 0, 20, eval_buf + 2688, -3, 2040718187, -19, -128, 127, 448);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 3,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op50_multiplier,.shift=Test_StNN::op50_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=112};
const cmsis_nn_dims filter_dims={.n=672,.h=1,.w=1,.c=112};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=672};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2688, &filter_dims, Test_StNN::op50_filter, nullptr, Test_StNN::op50_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op51_multiplier,.shift=Test_StNN::op51_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=672};
const cmsis_nn_dims filter_dims={.n=672,.h=3,.w=3,.c=672};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=672};
const cmsis_nn_context ctx={.buf=eval_buf+5376,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op51_filter, nullptr, Test_StNN::op51_bias, &output_dims, eval_buf + 2688);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -1,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op52_multiplier,.shift=Test_StNN::op52_shift};
const cmsis_nn_dims input_dims={.n=1,.h=2,.w=2,.c=672};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=672};
const cmsis_nn_dims output_dims={.n=1,.h=2,.w=2,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2688, &filter_dims, Test_StNN::op52_filter, nullptr, Test_StNN::op52_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#elif defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 768;
#else
const int32_t im2col_buf_size = 0;
#endif
arm_avgpool_s8_m(eval_buf + 1200, 2, 2, 1, 1, 2, 2, 2, 2, 0, 0, -128, 127, 192, 1, eval_buf + 0, eval_buf + 1008);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 1,.output_offset = -32,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op54_multiplier,.shift=Test_StNN::op54_shift};
const cmsis_nn_dims input_dims={.n=1,.h=1,.w=1,.c=192};
const cmsis_nn_dims filter_dims={.n=1000,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=1,.w=1,.c=1000};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1008, &filter_dims, Test_StNN::op54_filter, nullptr, Test_StNN::op54_bias, &output_dims, eval_buf + 0);
}
{
}
return ;
}


#include "random_data.h"
#include "demo.h"
float invoke_img10() {
    static uint8_t arena[120000];
    int8_t *new_eval_buf = nullptr;
    ALIGN_PTR_TO_16(new_eval_buf, arena);
    auto begin = std::chrono::high_resolution_clock::now();
        invoke(tinyts_random_data, new_eval_buf, 24000);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return (elapsed.count() * 1e-6); // ms
}