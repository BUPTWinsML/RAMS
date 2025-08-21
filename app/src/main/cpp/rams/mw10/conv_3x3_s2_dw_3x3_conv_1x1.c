#include "cmsis_nn/Include/arm_nnfunctions.h"
#include "cmsis_nn/Include/arm_nn_types.h"
#include "cmsis_nn/Include/arm_nnfunctions.h"
#include "cmsis_nn/Include/arm_nnsupportfunctions.h"
#include "arm_depthwise_conv_3x3_s8_m.h"
#include "arm_nn_mat_mult_nt_t_s8_m.h"
#include "arm_depthwise_conv_s8_opt_m.h"

#include "kernel_utils.h"
#include <stddef.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

__STATIC_FORCEINLINE void conv_3x3_s2(void *im2col_buf,
                                      const int8_t *input_data,
                                      int8_t *output_data,
                                      const int8_t *filter_data,
                                      const int32_t *bias_data,
                                      int32_t *output_mult,
                                      int32_t *output_shift,
                                      const uint16_t input_x,
                                      const uint16_t input_y,
                                      const uint16_t input_ch,
                                      const uint16_t output_x,
                                      const uint16_t output_y,
                                      const uint16_t output_ch,
                                      const uint16_t pad_x,
                                      const uint16_t pad_y,
                                      const int32_t out_activation_min,
                                      const int32_t out_activation_max,
                                      const int32_t input_offset,
                                      const int32_t out_offset) {
    int16_t *buffer_a = (int16_t *)im2col_buf;

    const int32_t input_batches = 1;
    const uint16_t kernel_x = 3;
    const uint16_t kernel_y = 3;
    const uint16_t kernel_ch = input_ch;
    const uint16_t stride_x = 2;
    const uint16_t stride_y = 2;
    const int32_t dilation_x = 1;
    const int32_t dilation_y = 1;

    const int32_t groups = 1;
    const int32_t rhs_cols = kernel_x * kernel_y * kernel_ch;
    const int32_t output_ch_per_group = output_ch / groups;

    if (input_ch % groups != 0 || output_ch % groups != 0)
    {
        return ;
    }
    const int32_t remainder = rhs_cols % 4;
    const int32_t aligned_rhs_cols = remainder != 0 ? rhs_cols + 4 - remainder : rhs_cols;

    for (int i_batch = 0; i_batch < input_batches; i_batch++)
    {

#if defined(ARM_MATH_MVEI)
        const int32_t aligned_rhs_cols_offset = aligned_rhs_cols - rhs_cols;

        /* Generate up to four columns from the input tensor a GEMM computation */
        int8_t *im2col_buf = (int8_t *)buffer_a;
#else
        /* Use as a ping-pong buffer for unordered elements */
        int8_t *im2col_buf = (int8_t *)buffer_a + aligned_rhs_cols * 2;
        int16_t *im2col_buf_start_s16 = buffer_a;
#endif
        int32_t lhs_rows = 0;

        const int8_t *filter_data_ptr = &filter_data[0];
        const int32_t *bias_data_ptr = &bias_data[0];
        const int32_t *output_mult_ptr = &output_mult[0];
        const int32_t *output_shift_ptr = &output_shift[0];

        /* This part implements the im2col function */
        for (int32_t i_group = 0; i_group < groups; i_group++)
        {
            int8_t *out = output_data + i_group * output_ch_per_group;
            for (int i_out_y = 0; i_out_y < output_y; i_out_y++)
            {
                for (int i_out_x = 0; i_out_x < output_x; i_out_x++)
                {
                    const int32_t base_idx_x = stride_x * i_out_x - pad_x;
                    const int32_t base_idx_y = stride_y * i_out_y - pad_y;

                    for (int32_t i_ker_y = 0; i_ker_y < kernel_y; i_ker_y++)
                    {
                        for (int32_t i_ker_x = 0; i_ker_x < kernel_x; i_ker_x++)
                        {
                            const int32_t k_y = base_idx_y + dilation_y * i_ker_y;
                            const int32_t k_x = base_idx_x + dilation_x * i_ker_x;

                            if (k_y < 0 || k_y >= input_y || k_x < 0 || k_x >= input_x)
                            {
                                arm_memset_s8(im2col_buf, (int8_t)-input_offset, sizeof(int8_t) * kernel_ch);
                            }
                            else
                            {
                                arm_memcpy_s8(im2col_buf,
                                              input_data + (k_y * input_x + k_x) * input_ch + i_group * kernel_ch,
                                              sizeof(int8_t) * kernel_ch);
                            }
                            im2col_buf += kernel_ch;
                        }
                    }
                    lhs_rows++;

#if defined(ARM_MATH_MVEI)
                    im2col_buf += aligned_rhs_cols_offset;

                    /* Computation is filed for every 4 columns */
                    if (lhs_rows == 4)
                    {
                        arm_nn_mat_mult_nt_t_s8((int8_t *)buffer_a,
                                                filter_data_ptr,
                                                bias_data_ptr,
                                                out,
                                                output_mult_ptr,
                                                output_shift_ptr,
                                                lhs_rows,
                                                output_ch_per_group,
                                                rhs_cols,
                                                input_offset,
                                                out_offset,
                                                out_activation_min,
                                                out_activation_max,
                                                output_ch,
                                                aligned_rhs_cols);

                        out += lhs_rows * output_ch;

                        lhs_rows = 0;
                        im2col_buf = (int8_t *)buffer_a;
                    }
#else
    #if defined(ARM_MATH_DSP)
                    /* Copy one column with input offset and no ordering */
                    arm_s8_to_s16_unordered_with_offset(
                        im2col_buf - rhs_cols, im2col_buf_start_s16, rhs_cols, (int16_t)input_offset);
    #else

                    arm_q7_to_q15_with_offset(
                        im2col_buf - rhs_cols, im2col_buf_start_s16, rhs_cols, (int16_t)input_offset);

    #endif
                    im2col_buf_start_s16 += aligned_rhs_cols;

                    if (lhs_rows == 2)
                    {
                        if (groups > 1)
                        {
                            out = arm_nn_mat_mult_kernel_row_offset_s8_s16(filter_data_ptr,
                                                                           buffer_a,
                                                                           output_ch_per_group,
                                                                           output_shift_ptr,
                                                                           output_mult_ptr,
                                                                           out_offset,
                                                                           out_activation_min,
                                                                           out_activation_max,
                                                                           rhs_cols,
                                                                           aligned_rhs_cols,
                                                                           bias_data_ptr,
                                                                           output_ch,
                                                                           out);
                        }
                        else
                        {
                            out = arm_nn_mat_mult_kernel_s8_s16(filter_data_ptr,
                                                                buffer_a,
                                                                output_ch_per_group,
                                                                output_shift_ptr,
                                                                output_mult_ptr,
                                                                out_offset,
                                                                out_activation_min,
                                                                out_activation_max,
                                                                rhs_cols,
                                                                aligned_rhs_cols,
                                                                bias_data_ptr,
                                                                out);
                        }

                        /* counter reset */
                        im2col_buf_start_s16 = buffer_a;
                        im2col_buf = (int8_t *)buffer_a + aligned_rhs_cols * 2;
                        lhs_rows = 0;
                    }
#endif
                }
            }

            if (out == NULL)
            {
                return ;
            }

            /* Handle left over columns */
            if (lhs_rows != 0)
            {
#if defined(ARM_MATH_MVEI)
                arm_nn_mat_mult_nt_t_s8((int8_t *)buffer_a,
                                        filter_data_ptr,
                                        bias_data_ptr,
                                        out,
                                        output_mult_ptr,
                                        output_shift_ptr,
                                        lhs_rows,
                                        output_ch_per_group,
                                        rhs_cols,
                                        input_offset,
                                        out_offset,
                                        out_activation_min,
                                        out_activation_max,
                                        output_ch,
                                        aligned_rhs_cols);

                out += lhs_rows * output_ch;
                lhs_rows = 0;
                im2col_buf = (int8_t *)buffer_a;
#else // #if defined(ARM_MATH_MVEI)

                const int8_t *ker_a = filter_data_ptr;
                int i;

                for (i = 0; i < output_ch_per_group; i++)
                {
                    /* Load the accumulator with bias first */
                    int32_t sum = 0;
                    if (bias_data_ptr)
                    {
                        sum = bias_data_ptr[i];
                    }

                    const int16_t *ip_as_col = buffer_a;

    #if defined(ARM_MATH_DSP)
                    /* 4 multiply and accumulates are done in one loop. */
                    uint16_t col_count = rhs_cols / 4;
                    while (col_count)
                    {
                        int32_t ker_a1, ker_a2;
                        int32_t ip_b1, ip_b2;

                        ker_a = read_and_pad_reordered(ker_a, &ker_a1, &ker_a2);

                        ip_b1 = arm_nn_read_q15x2_ia(&ip_as_col);
                        sum = SMLAD(ker_a1, ip_b1, sum);
                        ip_b2 = arm_nn_read_q15x2_ia(&ip_as_col);
                        sum = SMLAD(ker_a2, ip_b2, sum);

                        col_count--;
                    }
                    /* Handle left over mac */
                    col_count = rhs_cols & 0x3;
    #else
                    uint16_t col_count = rhs_cols;

    #endif
                    while (col_count)
                    {
                        int8_t ker_a1 = *ker_a++;
                        int16_t ip_b1 = *ip_as_col++;

                        sum += ker_a1 * ip_b1;
                        col_count--;
                    }

                    sum = arm_nn_requantize(sum, output_mult_ptr[i], output_shift_ptr[i]);
                    sum += out_offset;
                    sum = MAX(sum, out_activation_min);
                    sum = MIN(sum, out_activation_max);
                    *out++ = (int8_t)sum;
                }

                im2col_buf_start_s16 = buffer_a;
                im2col_buf = (int8_t *)buffer_a + aligned_rhs_cols * 2;
                lhs_rows = 0;
#endif // #if defined(ARM_MATH_MVEI)
            }
            filter_data_ptr += output_ch_per_group * rhs_cols;
            bias_data_ptr += output_ch_per_group;
            output_mult_ptr += output_ch_per_group;
            output_shift_ptr += output_ch_per_group;
        }
        /* Advance to the next batch */
        input_data += (input_x * input_y * input_ch);
        output_data += (output_x * output_y * output_ch);
    }
}

/* conv1: s = 2; dw: s = 1, 2; conv2: s = 1 */
void conv_3x3_s2_dw_3x3_conv_1x1(const cmsis_nn_context_m *ctx,
                              const int8_t *input_data,
                              int8_t *output_data,
                              const cmsis_nn_cdc_dims *dims,
                              const cmsis_nn_conv_params *conv1,
                              const cmsis_nn_conv_data_params *conv1_data,
                              const cmsis_nn_dw_conv_params *dw_conv,
                              const cmsis_nn_conv_data_params *dw_data,
                              const cmsis_nn_conv_params_simplified *conv3,
                              const int32_t load_lines) {

    const int32_t n = 1;
    const int32_t conv1_in_h = dims->h;
    const int32_t conv1_in_w = dims->w;
    const int32_t in_c = dims->in_c;
    const int32_t dw_c = dims->dw_c;
    const int32_t out_c = dims->out_c;
    const int32_t conv1_stride_h = 2;
    const int32_t conv1_stride_w = 2;
    const int32_t dw_stride_h = dw_conv->stride.h;
    const int32_t dw_stride_w = dw_conv->stride.w;
    const int32_t dw_in_h = custom_ceil((float)conv1_in_h / conv1_stride_h);
    const int32_t dw_in_w = custom_ceil((float)conv1_in_h / conv1_stride_w);
    const int32_t dw_out_h = custom_ceil((float)dw_in_h / dw_stride_h);
    const int32_t dw_out_w = custom_ceil((float)dw_in_w / dw_stride_w);

    const int32_t l1 = (load_lines >= dw_out_h) ? dw_out_h : ((load_lines >= (dw_out_h + 1) / 2) ? (dw_out_h + 1) / 2 : load_lines);
    const int32_t l0 = MIN(dw_in_h + dims->dw_pad_y, 3 + dw_stride_h * (l1 - 1));

    cmsis_nn_dims dw_input_dims = {n, l0, dw_in_w, dw_c};
    cmsis_nn_dims dw_filter_dims = {1, 3, 3, dw_c};
    cmsis_nn_dims dw_output_dims = {n, l1, dw_out_w, dw_c};

    int8_t *im2col_buf1 = ctx->im2col1;
    const cmsis_nn_context ctx2 = {.buf=ctx->im2col2,.size=0};

    const int32_t mid_buf0_size = (((l0 * dw_in_w * dw_c) + 15) / 16 ) * 16;
    int8_t *mid_buf0 = ctx->mid_buf;
    int8_t *mid_buf1 = mid_buf0 + mid_buf0_size;

    arm_memset_s8(mid_buf0, -dw_conv->input_offset, dw_in_w * dw_c * (dims->dw_pad_y));

    int left_output_y = dw_in_h;
    int left_input_y = conv1_in_h;
    int dw_reuse = MAX(0, 3 - dw_stride_h);
    const int32_t loop_blocks = (dw_out_h + l1 - 1) / l1;
    int left_output_y2 = dw_out_h;

    const int8_t *input_ptr = input_data;
    int chwid = conv1_in_w * in_c;

    // printf("l0 = %d, l1 = %d, dw_reuse = %d, loop_blocks = %d\n", l0, l1, dw_reuse, loop_blocks);
    for (int i = 0; i < loop_blocks; i ++) {
        int conv1_out_y = (i == 0 ? l0 - dims->dw_pad_y : MIN(left_output_y, l0 - dw_reuse));
        int conv1_pad_y = (i == 0 ? conv1->padding.h : 0);
        int conv1_in_y = (conv1_out_y == 0 ? 0 : 3 + 2 * (conv1_out_y - 1));
        conv1_in_y = MIN(left_input_y, conv1_in_y);
        int conv1_start = (i == 0 ? dims->dw_pad_y : dw_reuse);

        conv_3x3_s2(im2col_buf1, input_ptr,
                    mid_buf0 + conv1_start * dw_in_w * dw_c, conv1_data->filter,
                    conv1_data->bias, conv1_data->quant_param.multiplier,
                    conv1_data->quant_param.shift, conv1_in_w, conv1_in_y,
                    in_c, dw_in_w, conv1_out_y, dw_c,
                    conv1->padding.w, conv1_pad_y, conv1->activation.min,
                    conv1->activation.max, conv1->input_offset,
                    conv1->output_offset);
        left_output_y -= conv1_out_y;

        dw_input_dims.h = MIN(dw_input_dims.h, conv1_out_y + dw_reuse);
        int tmp_in_h = MIN(left_output_y2, l1);
        dw_output_dims.h = tmp_in_h;
        // printf("[%3d] : conv1_in_y = %d, conv1_pad_y = %d, conv1_out_y = %d,"
        //         "conv1_start = %d, dw_input_h = %d\n", i, conv1_in_y, conv1_pad_y, conv1_out_y, conv1_start, dw_input_dims.h);

        // if (i == 0)
        // {
        //     for (int j = 0; j < conv1_out_y * dw_in_w * dw_c; j ++) {
        //         printf("%d, ", mid_buf0[conv1_start * dw_in_w * dw_c + j]);
        //     }
        // }

#if !defined(ARM_MATH_MVEI)
        arm_depthwise_conv_3x3_s8_m(&ctx2,
                            dw_conv,
                            &dw_data->quant_param,
                            &dw_input_dims,
                            mid_buf0,
                            &dw_filter_dims,
                            dw_data->filter,
                            NULL,
                            dw_data->bias,
                            &dw_output_dims,
                            mid_buf1);
    // if (i == 0)
    // for (int j = 0; j < dw_output_dims.h * dw_output_dims.w * dw_output_dims.c; j ++) {
    //     printf("%d, ", mid_buf1[j]);
    // }

#else
        arm_depthwise_conv_s8_opt_m(&ctx2,
                                dw_conv,
                                &dw_data->quant_param,
                                &dw_input_dims,
                                mid_buf0,
                                &dw_filter_dims,
                                dw_data->filter,
                                NULL,
                                dw_data->bias,
                                &dw_output_dims,
                                mid_buf1);
#endif

        arm_nn_mat_mult_nt_t_s8_m(mid_buf1,
                                conv3->filter,
                                conv3->bias,
                                output_data,
                                conv3->mul,
                                conv3->shift,
                                tmp_in_h * dw_out_w * n,
                                out_c, dw_c,
                                conv3->input_offset,
                                conv3->output_offset,
                                conv3->activation.min,
                                conv3->activation.max,
                                out_c, dw_c);
        output_data += dw_out_w * out_c * tmp_in_h;

        move_back2front(mid_buf0, l0 - dw_reuse, dw_in_w, dw_c, dw_reuse);
        left_output_y2 -= tmp_in_h;
        input_ptr += (conv1_out_y * 2 - conv1_pad_y) * chwid;
        left_input_y -= (conv1_out_y * 2 - conv1_pad_y);
    }

}

