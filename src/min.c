#include "../include/psv.h"


int stack_min( stack s ) {
    int min = s.nums[0];
    for ( size_t i = 0; i < s.size; i++ ) {
        if (s.nums[i] < min)
            min = s.nums[i];
    }
    return min;
}