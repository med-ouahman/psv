
#include "../include/psv.h"

int paint( psv data, int color ) {
	for ( int i = 0; i < data.width; i++ ) {
		for ( int j = 0; j < data.height; j++ ) {
			mlx_pixel_put(data.mlx, data.window, i, j, color);
		}
	}
	return 0;
}
