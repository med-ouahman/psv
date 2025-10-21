

#include "../include/psv.h"

int print_numbers( stack nums ) {
    
    for ( size_t i = 0; i < nums.size; i++ ) {
        printf("%i%c", nums.nums[i], i + 1 == nums.size ? '\n':' ');
    }
    return 0;
}
