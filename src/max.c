#include "../include/psv.h"

int stack_max( stack s ) {
    int max = s.nums[0];
    for ( size_t i = 0; i < s.size; i++ ) {
        if (s.nums[i] > max)
            max = s.nums[i];
    }
    return max;
}