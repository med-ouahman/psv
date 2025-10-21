#include "../include/psv.h"


void vfree( void** ptr ) {
    for ( int i = 0; ptr[i]; i++ ) {
        free(ptr[i]);
    }
    free(ptr);
}

/* smart function to delete any type of allocation */


int delete( void* ptr, int type ) {
    
    if (type == 0) {
        free(ptr);
        return 0;
    }
    else if (type == 1) {
        vfree(ptr);
    }
    return 0;
}