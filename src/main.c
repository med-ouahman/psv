#include "../include/psv.h"

long parse_num( char* s ) {
	char* end;
	long num = strtol(s, &end, 10);
	if (*end)
		return EOUT;
	if (num > INT_MAX || num < INT_MIN)
		return EOUT;
	return num;
}

int parse_nums( stack* nums, char* s )
{
	long tmp;
	size_t num_size = 0;
	char** args = ft_split(s, ' ');
	if (!args)
		return -1;
	while (args[num_size]) {
		num_size++;
	}
	printf("numsize: %zu\n", num_size);
	nums->nums = malloc(sizeof(int) * num_size);
	if (!nums->nums) {
		free(args);
		return -1;
	}
	for ( size_t i = 0; i < num_size; i++ ) {
		tmp = parse_num(args[i]);
		if (tmp == EOUT) {
			delete(args, 1);
			delete(nums->nums, 0);
			return -1;
		}
		nums->nums[i] = tmp;
	}
	nums->size = num_size;
	delete(args, 1);
	return 0;
}

int visualize( stack nums, char* source) {
	psv data;
	if (!(data.mlx = mlx_init()))
		return -1;
	data.width = 2000;
	data.height = 900;
	if (!(data.window = mlx_new_window(data.mlx, data.width, data.height, "pvs")))
		return -1;
	int fd = open(source, O_RDONLY);
	if (fd < 0)
		return -1;
	paint(data, 0x0c0e3d);
	display(data, nums);
	// run(data, nums, fd);
	mlx_loop(data.mlx);
	return 0;
}

int main( int ac, char** av ) {
	char* source;
	stack nums;

	if (ac < 2) {
		fprintf(stderr, "Usage: ./psv numbers instructions\nyou can return only with numbers if you want to read from stdin\n");
		return 1;
	}
	if (ac == 3) {
		source = av[2];
	} else {
		source = "/dev/stdin";
	}
	ft_memset(&nums, 0, sizeof(nums));
	parse_nums(&nums, av[1]);
	visualize(nums, source);
	return 0;
}

