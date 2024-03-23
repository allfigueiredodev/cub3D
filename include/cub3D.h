#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#define WIDTH 800
#define HEIGHT 600
#define PI 3.14159265359

typedef struct s_player{
	float px;
	float py;
	float pdx;
	float pdy;
	float pa;
} t_player;

typedef struct s_window{
	char **test;
	mlx_t* mlx;
	mlx_image_t* img;
} t_window;

#endif