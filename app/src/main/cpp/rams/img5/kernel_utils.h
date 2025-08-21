#include <stdint.h>
#include "Internal/arm_nn_compiler.h"

// NHWC 3x3
__STATIC_FORCEINLINE void move_back2front(int8_t* buf, const int src_pos, const int width, const int channel, const int line) {
    int block_size = line * width * channel;
    int8_t *head = buf;
    int8_t *tail = buf + src_pos * width * channel;

#ifdef ARM_USE_MVEI
    while (block_size >= 16) {
        int8x16_t data = vld1q_s8(tail);
        vst1q_s8(head, data);

        head += 16;
        tail += 16;
        block_size -= 16;
    }
#endif

    while (block_size > 0) {
        *head = *tail;
        head++;
        tail++;
        block_size--;
    }
}

// fill id-th line with pad_value
__STATIC_FORCEINLINE void fill_buf_pad_value(int8_t *buf, const int8_t pad_value, const int width, const int channel, const int id) {
    int8_t *head = buf + id * width * channel;
    int block_size = width * channel;
    while (block_size --) {
        *head = pad_value;
        head++;
    }
}


__STATIC_FORCEINLINE int custom_ceil(float value) {
    int int_value = (int)value;
    return (value > int_value) ? (int_value + 1) : int_value;
}
