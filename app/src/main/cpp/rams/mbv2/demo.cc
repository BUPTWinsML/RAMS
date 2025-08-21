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
const cmsis_nn_cdc_dims dims={.n=1,.h=144,.w=144,.in_c=3,.dw_c=16,.out_c=8,.dw_pad_y=1};
const cmsis_nn_conv_params conv1={.input_offset=1,.output_offset=-128,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params conv1_data={.quant_param={.multiplier=Test_StNN::op0_multiplier,.shift=Test_StNN::op0_shift},.bias=Test_StNN::op0_bias,.filter=Test_StNN::op0_filter,};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op1_multiplier,.shift=Test_StNN::op1_shift},.bias=Test_StNN::op1_bias,.filter=Test_StNN::op1_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-1,.filter=Test_StNN::op2_filter,.bias=Test_StNN::op2_bias,.mul=Test_StNN::op2_multiplier,.shift=Test_StNN::op2_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+41472,.im2col2=eval_buf+41472+conv1_im2col,.im2col3=eval_buf+41472+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+41472+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=41472+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2304) / 2304;
conv_3x3_s2_dw_3x3_conv_1x1(&ctx, data, eval_buf + 0, &dims, &conv1, &conv1_data, &dw_conv, &dw_data, &conv3, load_lines);
// 46080
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
const cmsis_nn_cdc_dims dims={.n=1,.h=72,.w=72,.in_c=8,.dw_c=48,.out_c=8,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=1,.output_offset=-128,.filter=Test_StNN::op3_filter,.bias=Test_StNN::op3_bias,.mul=Test_StNN::op3_multiplier,.shift=Test_StNN::op3_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op4_multiplier,.shift=Test_StNN::op4_shift},.bias=Test_StNN::op4_bias,.filter=Test_StNN::op4_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-12,.filter=Test_StNN::op5_filter,.bias=Test_StNN::op5_bias,.mul=Test_StNN::op5_multiplier,.shift=Test_StNN::op5_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+41472,.im2col2=eval_buf+41472+conv1_im2col,.im2col3=eval_buf+41472+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+41472+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=41472+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 3456) / 8640;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 0, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 53568
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
const cmsis_nn_cdc_dims dims={.n=1,.h=36,.w=36,.in_c=8,.dw_c=48,.out_c=8,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=12,.output_offset=-128,.filter=Test_StNN::op6_filter,.bias=Test_StNN::op6_bias,.mul=Test_StNN::op6_multiplier,.shift=Test_StNN::op6_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op7_multiplier,.shift=Test_StNN::op7_shift},.bias=Test_StNN::op7_bias,.filter=Test_StNN::op7_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-3,.filter=Test_StNN::op8_filter,.bias=Test_StNN::op8_bias,.mul=Test_StNN::op8_multiplier,.shift=Test_StNN::op8_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+20736,.im2col2=eval_buf+20736+conv1_im2col,.im2col3=eval_buf+20736+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+20736+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=20736+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 3456) / 3456;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 10368, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 27648
}
{
arm_elementwise_add_s8(eval_buf + 10368, eval_buf + 0, 3, 1073741824, 0, 12, 1913040876, -1, 20, eval_buf + 0, -24, 1740768239, -19, -128, 127, 10368);
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
const cmsis_nn_cdc_dims dims={.n=1,.h=36,.w=36,.in_c=8,.dw_c=48,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=24,.output_offset=-128,.filter=Test_StNN::op10_filter,.bias=Test_StNN::op10_bias,.mul=Test_StNN::op10_multiplier,.shift=Test_StNN::op10_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op11_multiplier,.shift=Test_StNN::op11_shift},.bias=Test_StNN::op11_bias,.filter=Test_StNN::op11_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-3,.filter=Test_StNN::op12_filter,.bias=Test_StNN::op12_bias,.mul=Test_StNN::op12_multiplier,.shift=Test_StNN::op12_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+15552,.im2col2=eval_buf+15552+conv1_im2col,.im2col3=eval_buf+15552+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+15552+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=15552+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1728) / 4320;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 10368, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 21600
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
const cmsis_nn_cdc_dims dims={.n=1,.h=18,.w=18,.in_c=16,.dw_c=96,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=3,.output_offset=-128,.filter=Test_StNN::op13_filter,.bias=Test_StNN::op13_bias,.mul=Test_StNN::op13_multiplier,.shift=Test_StNN::op13_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op14_multiplier,.shift=Test_StNN::op14_shift},.bias=Test_StNN::op14_bias,.filter=Test_StNN::op14_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-12,.filter=Test_StNN::op15_filter,.bias=Test_StNN::op15_bias,.mul=Test_StNN::op15_multiplier,.shift=Test_StNN::op15_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+15552,.im2col2=eval_buf+15552+conv1_im2col,.im2col3=eval_buf+15552+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+15552+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=15552+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 3456) / 3456;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 10368, eval_buf + 0, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 22464
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 10368, 12, 1471433446, -1, 3, 1073741824, 0, 20, eval_buf + 5184, -14, 1655828686, -19, -128, 127, 5184);
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
const cmsis_nn_cdc_dims dims={.n=1,.h=18,.w=18,.in_c=16,.dw_c=96,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=14,.output_offset=-128,.filter=Test_StNN::op17_filter,.bias=Test_StNN::op17_bias,.mul=Test_StNN::op17_multiplier,.shift=Test_StNN::op17_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op18_multiplier,.shift=Test_StNN::op18_shift},.bias=Test_StNN::op18_bias,.filter=Test_StNN::op18_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=4,.filter=Test_StNN::op19_filter,.bias=Test_StNN::op19_bias,.mul=Test_StNN::op19_multiplier,.shift=Test_StNN::op19_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+10368,.im2col2=eval_buf+10368+conv1_im2col,.im2col3=eval_buf+10368+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+10368+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=10368+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 3456) / 3456;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 5184, eval_buf + 0, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 17280
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 5184, -4, 1392450788, -1, 14, 1073741824, 0, 20, eval_buf + 31104, 4, 1647111832, -19, -128, 127, 5184);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -4,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op21_multiplier,.shift=Test_StNN::op21_shift};
const cmsis_nn_dims input_dims={.n=1,.h=18,.w=18,.c=16};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=16};
const cmsis_nn_dims output_dims={.n=1,.h=18,.w=18,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 31104, &filter_dims, Test_StNN::op21_filter, nullptr, Test_StNN::op21_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=18,.w=18,.c=96};
const cmsis_nn_dims filter_dims={.n=96,.h=3,.w=3,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=96};
const cmsis_nn_context ctx={.buf=eval_buf+38880,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op22_filter, nullptr, Test_StNN::op22_bias, &output_dims, eval_buf + 31104);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -4,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op23_multiplier,.shift=Test_StNN::op23_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=96};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 31104, &filter_dims, Test_StNN::op23_filter, nullptr, Test_StNN::op23_bias, &output_dims, eval_buf + 23328);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 4,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op24_multiplier,.shift=Test_StNN::op24_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=24};
const cmsis_nn_dims filter_dims={.n=144,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 23328, &filter_dims, Test_StNN::op24_filter, nullptr, Test_StNN::op24_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=144,.h=3,.w=3,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_context ctx={.buf=eval_buf+23328,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op25_filter, nullptr, Test_StNN::op25_bias, &output_dims, eval_buf + 11664);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 19,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op26_multiplier,.shift=Test_StNN::op26_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11664, &filter_dims, Test_StNN::op26_filter, nullptr, Test_StNN::op26_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 23328, -19, 1456378408, -1, 4, 1073741824, 0, 20, eval_buf + 25280, -4, 1995390438, -19, -128, 127, 1944);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 4,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op28_multiplier,.shift=Test_StNN::op28_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=24};
const cmsis_nn_dims filter_dims={.n=144,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 25280, &filter_dims, Test_StNN::op28_filter, nullptr, Test_StNN::op28_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op29_multiplier,.shift=Test_StNN::op29_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=144,.h=3,.w=3,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_context ctx={.buf=eval_buf+23328,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op29_filter, nullptr, Test_StNN::op29_bias, &output_dims, eval_buf + 11664);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -5,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op30_multiplier,.shift=Test_StNN::op30_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11664, &filter_dims, Test_StNN::op30_filter, nullptr, Test_StNN::op30_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 25280, 5, 1223308808, -1, 4, 1073741824, 0, 20, eval_buf + 23328, 13, 2020444430, -19, -128, 127, 1944);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -13,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op32_multiplier,.shift=Test_StNN::op32_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=24};
const cmsis_nn_dims filter_dims={.n=144,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 23328, &filter_dims, Test_StNN::op32_filter, nullptr, Test_StNN::op32_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=144,.h=3,.w=3,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_context ctx={.buf=eval_buf+23328,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op33_filter, nullptr, Test_StNN::op33_bias, &output_dims, eval_buf + 11664);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 11,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op34_multiplier,.shift=Test_StNN::op34_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=24,.h=1,.w=1,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=24};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11664, &filter_dims, Test_StNN::op34_filter, nullptr, Test_StNN::op34_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 23328, -11, 1177989276, -1, -13, 1073741824, 0, 20, eval_buf + 11664, 3, 1086752385, -18, -128, 127, 1944);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -3,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op36_multiplier,.shift=Test_StNN::op36_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=24};
const cmsis_nn_dims filter_dims={.n=144,.h=1,.w=1,.c=24};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11664, &filter_dims, Test_StNN::op36_filter, nullptr, Test_StNN::op36_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op37_multiplier,.shift=Test_StNN::op37_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=144,.h=3,.w=3,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_context ctx={.buf=eval_buf+23328,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op37_filter, nullptr, Test_StNN::op37_bias, &output_dims, eval_buf + 11664);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -2,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op38_multiplier,.shift=Test_StNN::op38_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=144};
const cmsis_nn_dims filter_dims={.n=32,.h=1,.w=1,.c=144};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=32};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11664, &filter_dims, Test_StNN::op38_filter, nullptr, Test_StNN::op38_bias, &output_dims, eval_buf + 31104);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 2,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op39_multiplier,.shift=Test_StNN::op39_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=32};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=32};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 31104, &filter_dims, Test_StNN::op39_filter, nullptr, Test_StNN::op39_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=3,.w=3,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+31104,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op40_filter, nullptr, Test_StNN::op40_bias, &output_dims, eval_buf + 15552);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 8,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op41_multiplier,.shift=Test_StNN::op41_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_dims filter_dims={.n=32,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=32};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 15552, &filter_dims, Test_StNN::op41_filter, nullptr, Test_StNN::op41_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 31104, -8, 1798431249, -1, 2, 1073741824, 0, 20, eval_buf + 33696, -16, 1685128535, -19, -128, 127, 2592);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 16,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op43_multiplier,.shift=Test_StNN::op43_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=32};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=32};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 33696, &filter_dims, Test_StNN::op43_filter, nullptr, Test_StNN::op43_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op44_multiplier,.shift=Test_StNN::op44_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=3,.w=3,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+31104,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op44_filter, nullptr, Test_StNN::op44_bias, &output_dims, eval_buf + 15552);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 12,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op45_multiplier,.shift=Test_StNN::op45_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_dims filter_dims={.n=32,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=32};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 15552, &filter_dims, Test_StNN::op45_filter, nullptr, Test_StNN::op45_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 33696, -12, 1073741824, 0, 16, 2007977665, -1, 20, eval_buf + 15552, 0, 1414001035, -19, -128, 127, 2592);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 0,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op47_multiplier,.shift=Test_StNN::op47_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=32};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=32};
const cmsis_nn_dims output_dims={.n=1,.h=9,.w=9,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 15552, &filter_dims, Test_StNN::op47_filter, nullptr, Test_StNN::op47_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op48_multiplier,.shift=Test_StNN::op48_shift};
const cmsis_nn_dims input_dims={.n=1,.h=9,.w=9,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=3,.w=3,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+20352,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op48_filter, nullptr, Test_StNN::op48_bias, &output_dims, eval_buf + 15552);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -9,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op49_multiplier,.shift=Test_StNN::op49_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=192};
const cmsis_nn_dims filter_dims={.n=56,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=56};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 15552, &filter_dims, Test_StNN::op49_filter, nullptr, Test_StNN::op49_bias, &output_dims, eval_buf + 20352);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 9,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op50_multiplier,.shift=Test_StNN::op50_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=56};
const cmsis_nn_dims filter_dims={.n=336,.h=1,.w=1,.c=56};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=336};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 20352, &filter_dims, Test_StNN::op50_filter, nullptr, Test_StNN::op50_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_dims filter_dims={.n=336,.h=3,.w=3,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_context ctx={.buf=eval_buf+16800,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op51_filter, nullptr, Test_StNN::op51_bias, &output_dims, eval_buf + 8400);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -11,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op52_multiplier,.shift=Test_StNN::op52_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_dims filter_dims={.n=56,.h=1,.w=1,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=56};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8400, &filter_dims, Test_StNN::op52_filter, nullptr, Test_StNN::op52_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 20352, 11, 1693221254, -1, 9, 1073741824, 0, 20, eval_buf + 16800, -4, 1997830355, -19, -128, 127, 1400);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 4,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op54_multiplier,.shift=Test_StNN::op54_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=56};
const cmsis_nn_dims filter_dims={.n=336,.h=1,.w=1,.c=56};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=336};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 16800, &filter_dims, Test_StNN::op54_filter, nullptr, Test_StNN::op54_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op55_multiplier,.shift=Test_StNN::op55_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_dims filter_dims={.n=336,.h=3,.w=3,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_context ctx={.buf=eval_buf+16800,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op55_filter, nullptr, Test_StNN::op55_bias, &output_dims, eval_buf + 8400);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 48,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op56_multiplier,.shift=Test_StNN::op56_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_dims filter_dims={.n=56,.h=1,.w=1,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=56};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8400, &filter_dims, Test_StNN::op56_filter, nullptr, Test_StNN::op56_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 16800, -48, 1073741824, 0, 4, 1352203664, -1, 20, eval_buf + 8400, 36, 1557959978, -19, -128, 127, 1400);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -36,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op58_multiplier,.shift=Test_StNN::op58_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=56};
const cmsis_nn_dims filter_dims={.n=336,.h=1,.w=1,.c=56};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=336};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8400, &filter_dims, Test_StNN::op58_filter, nullptr, Test_StNN::op58_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op59_multiplier,.shift=Test_StNN::op59_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_dims filter_dims={.n=336,.h=3,.w=3,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_context ctx={.buf=eval_buf+16800,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op59_filter, nullptr, Test_StNN::op59_bias, &output_dims, eval_buf + 8400);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -5,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op60_multiplier,.shift=Test_StNN::op60_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=336};
const cmsis_nn_dims filter_dims={.n=112,.h=1,.w=1,.c=336};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=112};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8400, &filter_dims, Test_StNN::op60_filter, nullptr, Test_StNN::op60_bias, &output_dims, eval_buf + 16800);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 5,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op61_multiplier,.shift=Test_StNN::op61_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=112};
const cmsis_nn_dims filter_dims={.n=448,.h=1,.w=1,.c=112};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=448};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 16800, &filter_dims, Test_StNN::op61_filter, nullptr, Test_StNN::op61_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#elif defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 1792;
#else
const int32_t im2col_buf_size = 0;
#endif
arm_avgpool_s8_m(eval_buf + 11648, 5, 5, 1, 1, 5, 5, 5, 5, 0, 0, -128, 127, 448, 1, eval_buf + 0, eval_buf + 11200);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -44,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op63_multiplier,.shift=Test_StNN::op63_shift};
const cmsis_nn_dims input_dims={.n=1,.h=1,.w=1,.c=448};
const cmsis_nn_dims filter_dims={.n=1000,.h=1,.w=1,.c=448};
const cmsis_nn_dims output_dims={.n=1,.h=1,.w=1,.c=1000};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 11200, &filter_dims, Test_StNN::op63_filter, nullptr, Test_StNN::op63_bias, &output_dims, eval_buf + 0);
}
{
}
return ;
}


#include "random_data.h"
#include "demo.h"
float invoke_mbv2() {
    static uint8_t arena[120000];
    int8_t *new_eval_buf = nullptr;
    ALIGN_PTR_TO_16(new_eval_buf, arena);
    auto begin = std::chrono::high_resolution_clock::now();
        invoke(tinyts_random_data, new_eval_buf, 54000);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return (elapsed.count() * 1e-6); // ms
}