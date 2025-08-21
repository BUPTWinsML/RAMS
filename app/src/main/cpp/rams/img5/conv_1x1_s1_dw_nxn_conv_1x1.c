#include "cmsis_nn/Include/arm_nnfunctions.h"
#include "cmsis_nn/Include/arm_nn_types.h"
#include "cmsis_nn/Include/arm_nnfunctions.h"
#include "cmsis_nn/Include/arm_nnsupportfunctions.h"
#include "arm_nn_mat_mult_nt_t_s8_m.h"
#include "arm_depthwise_conv_3x3_s8_m.h"
#include "arm_depthwise_conv_s8_opt_m.h"

#include "kernel_utils.h"
#include <stddef.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

/* conv1: s = 1; dw: s = 1, 2; conv2: s = 1 */
void conv_1x1_s1_dw_nxn_conv_1x1(const cmsis_nn_context_m *ctx,
                              const int8_t *input_data,
                              int8_t *output_data,
                              const int32_t kernel_h,
                              const cmsis_nn_cdc_dims *dims,
                              const cmsis_nn_conv_params_simplified *conv1,
                              const cmsis_nn_dw_conv_params *dw_conv,
                              const cmsis_nn_conv_data_params *dw_data,
                              const cmsis_nn_conv_params_simplified *conv3,
                              const int32_t load_lines) {

    const int32_t n = 1;
    const int32_t in_h = dims->h;
    const int32_t in_w = dims->w;
    const int32_t in_c = dims->in_c;
    const int32_t dw_c = dims->dw_c;
    const int32_t out_c = dims->out_c;
    const int32_t stride_w = dw_conv->stride.w;
    const int32_t stride_h = dw_conv->stride.h;

    const int32_t out_h = custom_ceil((float)in_h / stride_h);
    const int32_t out_w = custom_ceil((float)in_w / stride_w);

    // const int32_t l1 = MIN(load_lines, out_h); // conv3: stride = 1, filter_h = 1
    // const int32_t l0 = MIN(kernel_h + stride_h * (load_lines - 1), in_h);

    const int32_t l1 = (load_lines >= out_h) ? out_h : ((load_lines >= (out_h + 1) / 2) ? (out_h + 1) / 2 : load_lines);
    // const int32_t l0 = (load_lines >= (out_h + kernel_h - 1) / kernel_h) ? (out_h + kernel_h - 1) / kernel_h : load_lines;
    const int32_t l0 = MIN(in_h + dims->dw_pad_y, kernel_h + stride_h * (l1 - 1));

    cmsis_nn_dims dw_input_dims = {n, l0, in_w, dw_c};
    cmsis_nn_dims dw_filter_dims = {1, kernel_h, kernel_h, dw_c};
    cmsis_nn_dims dw_output_dims = {n, l1, out_w, dw_c};

    const int32_t mid_buf0_size = ((l0 * in_w * dw_c + 15) / 16) * 16;
    const int32_t mid_buf1_size = ((l1 * in_w * dw_c + 15) / 16) * 16;
    int8_t *mid_buf0 = ctx->mid_buf;
    int8_t *mid_buf1 = mid_buf0 + mid_buf0_size;

    const cmsis_nn_context ctx2 = {.buf=mid_buf1 + mid_buf1_size,.size=0};

    const int8_t *in = input_data;
    const int8_t *out = output_data;

    arm_memset_s8(mid_buf0, -dw_conv->input_offset, in_w * dw_c * (dims->dw_pad_y));

    int left_rows = in_h;
    int left_rows2 = out_h;
    int dw_reuse = MAX(0, kernel_h - stride_h);

    dw_input_dims.h = MIN(dw_input_dims.h, dims->dw_pad_y + in_h);

    const int32_t loop_blocks = (out_h + l1 - 1) / l1;
    // printf("l0 = %d, l1 = %d, dw_reuse = %d, loop_blocks = %d\n", l0, l1, dw_reuse, loop_blocks);
    for (int i = 0; i < loop_blocks; i ++) {
        // int row = (i == 0 ? kernel_h - dims->dw_pad_y : stride_h);
        int row = (i == 0 ? l0 - dims->dw_pad_y : l0 - dw_reuse);
        row = MIN(row, left_rows);
        row = MAX(0, row);
        int start = (i == 0 ? dims->dw_pad_y : dw_reuse);

        arm_nn_mat_mult_nt_t_s8_m(input_data,
                                conv1->filter,
                                conv1->bias,
                                mid_buf0 + start * in_w * dw_c,
                                conv1->mul,
                                conv1->shift,
                                in_w * row,
                                dw_c,
                                in_c,
                                conv1->input_offset,
                                conv1->output_offset,
                                conv1->activation.min,
                                conv1->activation.max,
                                dw_c,
                                in_c);

        input_data += in_w * in_c * row;
        left_rows -= row;

        // if (i == 0) {
        //     for (int i = 0; i < row * in_w * dw_c; i++) {
        //         printf("%hhd, ", mid_buf0[start * in_w * dw_c + i]);
        //     }
        // }

        // int tmp = stride_h - row;
        // dw_input_dims.h = tmp > 0 ? dw_input_dims.h - tmp : dw_input_dims.h;
        int tmp_in_h = MIN(left_rows2, l1);
        dw_input_dims.h = MIN(dw_input_dims.h, row + dw_reuse);
        dw_output_dims.h = tmp_in_h;

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

        arm_nn_mat_mult_nt_t_s8_m(mid_buf1,
                                conv3->filter,
                                conv3->bias,
                                output_data,
                                conv3->mul,
                                conv3->shift,
                                tmp_in_h * out_w * n,
                                out_c, dw_c,
                                conv3->input_offset,
                                conv3->output_offset,
                                conv3->activation.min,
                                conv3->activation.max,
                                out_c, dw_c);
        // printf("row = %d, start = %d, left_rows = %d, dw_input_h = %d, tmp_in_h = %d\n", row, start, left_rows, dw_input_dims.h, tmp_in_h);
        left_rows2 -= tmp_in_h;
        output_data += out_w * out_c * tmp_in_h;

        move_back2front(mid_buf0, l0 - dw_reuse, in_w, dw_c, dw_reuse);
    }
}
