#include "../include/psv.h"


int execute( stack nums, char* instr) {
    (void)nums;
    (void)instr;
    return 0;
}

int run( psv data, stack nums, int fd ) {
    char* line;
    return 0;
    while ((line = get_next_line(fd))) {
        execute(nums, line);
        display(data, nums);
        free(line);
    }
    return 0;
}

