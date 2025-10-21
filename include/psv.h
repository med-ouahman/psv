#pragma once

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <fcntl.h>

typedef void* mlx_ptr;
typedef void* window_ptr;

#define EOUT LONG_MAX

typedef struct {
	int* nums; /* stack a */
	// int* nums2; /* stack b */
	size_t size;
	// size_t size2;
} stack;

typedef struct {
	mlx_ptr mlx;
	window_ptr window;
	int width;
	int height;
} psv;

int delete( void* ptr, int type );
int run( psv data, stack nums, int fd );
int display( psv data, stack nums );
int stack_max( stack s );
int stack_min( stack s );
int paint( psv data, int color );
int print_numbers( stack nums );