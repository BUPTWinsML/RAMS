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
const cmsis_nn_cdc_dims dims={.n=1,.h=80,.w=80,.in_c=3,.dw_c=16,.out_c=8,.dw_pad_y=1};
const cmsis_nn_conv_params conv1={.input_offset=1,.output_offset=-128,.stride={.w=2,.h=2},.padding={.w=1,.h=1},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params conv1_data={.quant_param={.multiplier=Test_StNN::op0_multiplier,.shift=Test_StNN::op0_shift},.bias=Test_StNN::op0_bias,.filter=Test_StNN::op0_filter,};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op1_multiplier,.shift=Test_StNN::op1_shift},.bias=Test_StNN::op1_bias,.filter=Test_StNN::op1_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-4,.filter=Test_StNN::op2_filter,.bias=Test_StNN::op2_bias,.mul=Test_StNN::op2_multiplier,.shift=Test_StNN::op2_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+12800,.im2col2=eval_buf+12800+conv1_im2col,.im2col3=eval_buf+12800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+12800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=12800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1280) / 1280;
conv_3x3_s2_dw_3x3_conv_1x1(&ctx, data, eval_buf + 0, &dims, &conv1, &conv1_data, &dw_conv, &dw_data, &conv3, load_lines);
// 15360
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
const cmsis_nn_cdc_dims dims={.n=1,.h=40,.w=40,.in_c=8,.dw_c=48,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=4,.output_offset=-128,.filter=Test_StNN::op3_filter,.bias=Test_StNN::op3_bias,.mul=Test_StNN::op3_multiplier,.shift=Test_StNN::op3_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op4_multiplier,.shift=Test_StNN::op4_shift},.bias=Test_StNN::op4_bias,.filter=Test_StNN::op4_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-22,.filter=Test_StNN::op5_filter,.bias=Test_StNN::op5_bias,.mul=Test_StNN::op5_multiplier,.shift=Test_StNN::op5_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+12800,.im2col2=eval_buf+12800+conv1_im2col,.im2col3=eval_buf+12800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+12800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=12800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1920) / 4800;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 0, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 19520
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
const cmsis_nn_cdc_dims dims={.n=1,.h=20,.w=20,.in_c=16,.dw_c=48,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=22,.output_offset=-128,.filter=Test_StNN::op6_filter,.bias=Test_StNN::op6_bias,.mul=Test_StNN::op6_multiplier,.shift=Test_StNN::op6_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op7_multiplier,.shift=Test_StNN::op7_shift},.bias=Test_StNN::op7_bias,.filter=Test_StNN::op7_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=8,.filter=Test_StNN::op8_filter,.bias=Test_StNN::op8_bias,.mul=Test_StNN::op8_multiplier,.shift=Test_StNN::op8_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+12800,.im2col2=eval_buf+12800+conv1_im2col,.im2col3=eval_buf+12800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+12800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=12800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1920) / 1920;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 6400, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 16640
}
{
arm_elementwise_add_s8(eval_buf + 6400, eval_buf + 0, -8, 1923079390, -1, 22, 1073741824, 0, 20, eval_buf + 0, -20, 1810618269, -19, -128, 127, 6400);
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
const cmsis_nn_cdc_dims dims={.n=1,.h=20,.w=20,.in_c=16,.dw_c=48,.out_c=16,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=20,.output_offset=-128,.filter=Test_StNN::op10_filter,.bias=Test_StNN::op10_bias,.mul=Test_StNN::op10_multiplier,.shift=Test_StNN::op10_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op11_multiplier,.shift=Test_StNN::op11_shift},.bias=Test_StNN::op11_bias,.filter=Test_StNN::op11_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-4,.filter=Test_StNN::op12_filter,.bias=Test_StNN::op12_bias,.mul=Test_StNN::op12_multiplier,.shift=Test_StNN::op12_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+12800,.im2col2=eval_buf+12800+conv1_im2col,.im2col3=eval_buf+12800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+12800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=12800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 1920) / 1920;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 6400, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 16640
}
{
arm_elementwise_add_s8(eval_buf + 6400, eval_buf + 0, 4, 2093061678, -3, 20, 1073741824, 0, 20, eval_buf + 12800, -15, 2092646349, -19, -128, 127, 6400);
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
const cmsis_nn_cdc_dims dims={.n=1,.h=20,.w=20,.in_c=16,.dw_c=48,.out_c=24,.dw_pad_y=3};
const cmsis_nn_conv_params_simplified conv1={.input_offset=15,.output_offset=-128,.filter=Test_StNN::op14_filter,.bias=Test_StNN::op14_bias,.mul=Test_StNN::op14_multiplier,.shift=Test_StNN::op14_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=3,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op15_multiplier,.shift=Test_StNN::op15_shift},.bias=Test_StNN::op15_bias,.filter=Test_StNN::op15_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-16,.filter=Test_StNN::op16_filter,.bias=Test_StNN::op16_bias,.mul=Test_StNN::op16_multiplier,.shift=Test_StNN::op16_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+19200,.im2col2=eval_buf+19200+conv1_im2col,.im2col3=eval_buf+19200+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+19200+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=19200+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 4800) / 2400;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 12800, eval_buf + 0, 7, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 31104
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
const cmsis_nn_cdc_dims dims={.n=1,.h=10,.w=10,.in_c=24,.dw_c=144,.out_c=24,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=16,.output_offset=-128,.filter=Test_StNN::op17_filter,.bias=Test_StNN::op17_bias,.mul=Test_StNN::op17_multiplier,.shift=Test_StNN::op17_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op18_multiplier,.shift=Test_StNN::op18_shift},.bias=Test_StNN::op18_bias,.filter=Test_StNN::op18_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-14,.filter=Test_StNN::op19_filter,.bias=Test_StNN::op19_bias,.mul=Test_StNN::op19_multiplier,.shift=Test_StNN::op19_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+4800,.im2col2=eval_buf+4800+conv1_im2col,.im2col3=eval_buf+4800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+4800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=4800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2880) / 2880;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 0, eval_buf + 2400, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 10560
}
{
arm_elementwise_add_s8(eval_buf + 2400, eval_buf + 0, 14, 1073741824, 0, 16, 2097197732, -1, 20, eval_buf + 4800, -3, 1975777768, -19, -128, 127, 2400);
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
const int32_t dwconv_im2col = 6000;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=10,.w=10,.in_c=24,.dw_c=120,.out_c=24,.dw_pad_y=2};
const cmsis_nn_conv_params_simplified conv1={.input_offset=3,.output_offset=-128,.filter=Test_StNN::op21_filter,.bias=Test_StNN::op21_bias,.mul=Test_StNN::op21_multiplier,.shift=Test_StNN::op21_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=2,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op22_multiplier,.shift=Test_StNN::op22_shift},.bias=Test_StNN::op22_bias,.filter=Test_StNN::op22_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-3,.filter=Test_StNN::op23_filter,.bias=Test_StNN::op23_bias,.mul=Test_StNN::op23_multiplier,.shift=Test_StNN::op23_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+7200,.im2col2=eval_buf+7200+conv1_im2col,.im2col3=eval_buf+7200+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+7200+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=7200+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 4800) / 2400;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 4800, eval_buf + 0, 5, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 20400
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 4800, 3, 1155294737, -2, 3, 1073741824, 0, 20, eval_buf + 2400, -1, 2047715389, -19, -128, 127, 2400);
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
const int32_t dwconv_im2col = 14112;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=10,.w=10,.in_c=24,.dw_c=144,.out_c=40,.dw_pad_y=3};
const cmsis_nn_conv_params_simplified conv1={.input_offset=1,.output_offset=-128,.filter=Test_StNN::op25_filter,.bias=Test_StNN::op25_bias,.mul=Test_StNN::op25_multiplier,.shift=Test_StNN::op25_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=3,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op26_multiplier,.shift=Test_StNN::op26_shift},.bias=Test_StNN::op26_bias,.filter=Test_StNN::op26_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=-11,.filter=Test_StNN::op27_filter,.bias=Test_StNN::op27_bias,.mul=Test_StNN::op27_multiplier,.shift=Test_StNN::op27_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+4800,.im2col2=eval_buf+4800+conv1_im2col,.im2col3=eval_buf+4800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+4800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=4800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 7200) / 3600;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 2400, eval_buf + 0, 7, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 29712
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
const int32_t dwconv_im2col = 23520;
#else
const int32_t dwconv_im2col = 0;
#endif
#if defined(ARM_MATH_MVEI)
const int32_t conv2_im2col = 0;
#else
const int32_t conv2_im2col = 0;
#endif
const cmsis_nn_cdc_dims dims={.n=1,.h=5,.w=5,.in_c=40,.dw_c=240,.out_c=40,.dw_pad_y=3};
const cmsis_nn_conv_params_simplified conv1={.input_offset=11,.output_offset=-128,.filter=Test_StNN::op28_filter,.bias=Test_StNN::op28_bias,.mul=Test_StNN::op28_multiplier,.shift=Test_StNN::op28_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=3,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op29_multiplier,.shift=Test_StNN::op29_shift},.bias=Test_StNN::op29_bias,.filter=Test_StNN::op29_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=1,.filter=Test_StNN::op30_filter,.bias=Test_StNN::op30_bias,.mul=Test_StNN::op30_multiplier,.shift=Test_StNN::op30_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+2016,.im2col2=eval_buf+2016+conv1_im2col,.im2col3=eval_buf+2016+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+2016+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=2016+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 7200) / 2400;
conv_1x1_s1_dw_nxn_conv_1x1(&ctx, eval_buf + 0, eval_buf + 1008, 7, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 35136
}
{
arm_elementwise_add_s8(eval_buf + 1008, eval_buf + 0, -1, 1904839122, -1, 11, 1073741824, 0, 20, eval_buf + 2016, -3, 2112700174, -19, -128, 127, 1000);
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
const cmsis_nn_cdc_dims dims={.n=1,.h=5,.w=5,.in_c=40,.dw_c=240,.out_c=48,.dw_pad_y=1};
const cmsis_nn_conv_params_simplified conv1={.input_offset=3,.output_offset=-128,.filter=Test_StNN::op32_filter,.bias=Test_StNN::op32_bias,.mul=Test_StNN::op32_multiplier,.shift=Test_StNN::op32_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_dw_conv_params dw_conv={.input_offset=128,.output_offset=-128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=1,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_conv_data_params dw_data={.quant_param={.multiplier=Test_StNN::op33_multiplier,.shift=Test_StNN::op33_shift},.bias=Test_StNN::op33_bias,.filter=Test_StNN::op33_filter,};
const cmsis_nn_conv_params_simplified conv3={.input_offset=128,.output_offset=15,.filter=Test_StNN::op34_filter,.bias=Test_StNN::op34_bias,.mul=Test_StNN::op34_multiplier,.shift=Test_StNN::op34_shift,.activation={.min=-128,.max=127}};
const cmsis_nn_context_m ctx={.im2col1=eval_buf+10800,.im2col2=eval_buf+10800+conv1_im2col,.im2col3=eval_buf+10800+conv1_im2col+dwconv_im2col,.mid_buf=eval_buf+10800+conv1_im2col+dwconv_im2col+conv2_im2col,};
const int32_t mid_buf_pos=10800+conv1_im2col+dwconv_im2col+conv2_im2col;
const int32_t load_lines = (eval_buf_size - mid_buf_pos - 2400) / 2400;
conv_1x1_s1_dw_3x3_conv_1x1(&ctx, eval_buf + 2016, eval_buf + 9600, &dims, &conv1, &dw_conv, &dw_data, &conv3, load_lines);
// 15600
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -15,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op35_multiplier,.shift=Test_StNN::op35_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=48};
const cmsis_nn_dims filter_dims={.n=192,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=192};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 9600, &filter_dims, Test_StNN::op35_filter, nullptr, Test_StNN::op35_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=192};
const cmsis_nn_dims filter_dims={.n=192,.h=3,.w=3,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=192};
const cmsis_nn_context ctx={.buf=eval_buf+9600,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op36_filter, nullptr, Test_StNN::op36_bias, &output_dims, eval_buf + 4800);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -11,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op37_multiplier,.shift=Test_StNN::op37_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=192};
const cmsis_nn_dims filter_dims={.n=48,.h=1,.w=1,.c=192};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=48};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4800, &filter_dims, Test_StNN::op37_filter, nullptr, Test_StNN::op37_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 9600, 11, 1073741824, 0, -15, 1930353812, -1, 20, eval_buf + 6000, 5, 1981078658, -19, -128, 127, 1200);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = -5,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op39_multiplier,.shift=Test_StNN::op39_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=48};
const cmsis_nn_dims filter_dims={.n=240,.h=1,.w=1,.c=48};
const cmsis_nn_dims output_dims={.n=1,.h=5,.w=5,.c=240};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6000, &filter_dims, Test_StNN::op39_filter, nullptr, Test_StNN::op39_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 12400;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 12000;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=2,.h=2},.padding={.w=2,.h=2},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op40_multiplier,.shift=Test_StNN::op40_shift};
const cmsis_nn_dims input_dims={.n=1,.h=5,.w=5,.c=240};
const cmsis_nn_dims filter_dims={.n=240,.h=5,.w=5,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_context ctx={.buf=eval_buf+8160,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op40_filter, nullptr, Test_StNN::op40_bias, &output_dims, eval_buf + 6000);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -7,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op41_multiplier,.shift=Test_StNN::op41_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=240};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=240};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6000, &filter_dims, Test_StNN::op41_filter, nullptr, Test_StNN::op41_bias, &output_dims, eval_buf + 8640);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 7,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op42_multiplier,.shift=Test_StNN::op42_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=96};
const cmsis_nn_dims filter_dims={.n=480,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=480};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 8640, &filter_dims, Test_StNN::op42_filter, nullptr, Test_StNN::op42_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op43_multiplier,.shift=Test_StNN::op43_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=480};
const cmsis_nn_dims filter_dims={.n=480,.h=3,.w=3,.c=480};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=480};
const cmsis_nn_context ctx={.buf=eval_buf+8640,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op43_filter, nullptr, Test_StNN::op43_bias, &output_dims, eval_buf + 4320);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -2,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op44_multiplier,.shift=Test_StNN::op44_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=480};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=480};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 4320, &filter_dims, Test_StNN::op44_filter, nullptr, Test_StNN::op44_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 8640, 2, 2041639639, -1, 7, 1073741824, 0, 20, eval_buf + 6912, -9, 1154589191, -18, -128, 127, 864);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 9,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op46_multiplier,.shift=Test_StNN::op46_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=96};
const cmsis_nn_dims filter_dims={.n=384,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=384};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 6912, &filter_dims, Test_StNN::op46_filter, nullptr, Test_StNN::op46_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_dims filter_dims={.n=384,.h=3,.w=3,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_context ctx={.buf=eval_buf+6912,.size=im2col_buf_size,};
arm_depthwise_conv_3x3_s8(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op47_filter, nullptr, Test_StNN::op47_bias, &output_dims, eval_buf + 3456);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = -6,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op48_multiplier,.shift=Test_StNN::op48_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=384};
const cmsis_nn_dims filter_dims={.n=96,.h=1,.w=1,.c=384};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=96};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 3456, &filter_dims, Test_StNN::op48_filter, nullptr, Test_StNN::op48_bias, &output_dims, eval_buf + 0);
}
{
arm_elementwise_add_s8(eval_buf + 0, eval_buf + 6912, 6, 2114643792, -2, 9, 1073741824, 0, 20, eval_buf + 2592, -12, 2007358392, -19, -128, 127, 864);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 12,.output_offset = -128,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op50_multiplier,.shift=Test_StNN::op50_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=96};
const cmsis_nn_dims filter_dims={.n=288,.h=1,.w=1,.c=96};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=288};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2592, &filter_dims, Test_StNN::op50_filter, nullptr, Test_StNN::op50_bias, &output_dims, eval_buf + 0);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 24304;
#elif defined(ARM_MATH_DSP)
const int32_t im2col_buf_size = 28224;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_dw_conv_params dw_conv_params = {.input_offset = 128,.output_offset = -128,.ch_mult=1,.stride={.w=1,.h=1},.padding={.w=3,.h=3},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op51_multiplier,.shift=Test_StNN::op51_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=288};
const cmsis_nn_dims filter_dims={.n=288,.h=7,.w=7,.c=288};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=288};
const cmsis_nn_context ctx={.buf=eval_buf+5184,.size=im2col_buf_size,};
arm_depthwise_conv_s8_opt(&ctx, &dw_conv_params, &quant_params, &input_dims, eval_buf + 0, &filter_dims, Test_StNN::op51_filter, nullptr, Test_StNN::op51_bias, &output_dims, eval_buf + 2592);
}
{
#if defined(ARM_MATH_MVEI)
const int32_t im2col_buf_size = 0;
#else
const int32_t im2col_buf_size = 0;
#endif
const cmsis_nn_conv_params conv_params = {.input_offset = 128,.output_offset = 9,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op52_multiplier,.shift=Test_StNN::op52_shift};
const cmsis_nn_dims input_dims={.n=1,.h=3,.w=3,.c=288};
const cmsis_nn_dims filter_dims={.n=160,.h=1,.w=1,.c=288};
const cmsis_nn_dims output_dims={.n=1,.h=3,.w=3,.c=160};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 2592, &filter_dims, Test_StNN::op52_filter, nullptr, Test_StNN::op52_bias, &output_dims, eval_buf + 0);
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
const cmsis_nn_conv_params conv_params = {.input_offset = -9,.output_offset = -1,.stride={.w=1,.h=1},.padding={.w=0,.h=0},.dilation={.w=1,.h=1},.activation={.min=-128,.max=127}};
const cmsis_nn_per_channel_quant_params quant_params={.multiplier=Test_StNN::op54_multiplier,.shift=Test_StNN::op54_shift};
const cmsis_nn_dims input_dims={.n=1,.h=1,.w=1,.c=160};
const cmsis_nn_dims filter_dims={.n=2,.h=1,.w=1,.c=160};
const cmsis_nn_dims output_dims={.n=1,.h=1,.w=1,.c=2};
arm_convolve_1x1_s8_fast(nullptr, &conv_params, &quant_params, &input_dims, eval_buf + 1440, &filter_dims, Test_StNN::op54_filter, nullptr, Test_StNN::op54_bias, &output_dims, eval_buf + 0);
}
{
}
return ;
}



#include "random_data.h"
#include "demo.h"
float invoke_mw5() {
    static uint8_t arena[120000];
    int8_t *new_eval_buf = nullptr;
    ALIGN_PTR_TO_16(new_eval_buf, arena);
    auto begin = std::chrono::high_resolution_clock::now();
        invoke(tinyts_random_data, new_eval_buf, 36000);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    return (elapsed.count() * 1e-6); // ms
}