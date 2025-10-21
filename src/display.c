#include "../include/psv.h"
void put_number( psv data, int f, int index ) {
    
    for ( int i = data.height - 1; i != f; i-- ) {
        mlx_pixel_put(data.mlx, data.window, index, i, 0x5bb012);
    }
}

int display( psv data, stack nums ) {
    int f;
    for ( size_t i = 0; i < nums.size; i++ ) {
        if (nums.nums[i] > data.height) {
            f = nums.nums[i] % data.height;
        } else {
            f = nums.nums[i];
        }
        put_number(data, f, i);
    }
    return 0+f;
}
