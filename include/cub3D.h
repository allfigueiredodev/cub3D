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
#define MY_PI 3.1415927
#define CUB 16
#define LINE_SIZE 16
#define PLYR_SIZE CUB
#define MAPX (WIDTH / CUB)
#define MAPY (HEIGHT / CUB)

typedef struct s_player{
	float px;
	float py;
	float pdx;
	float pdy;
	float pa;
}	t_player;

typedef struct s_ray{
	int 	r;
	float	ra;
	float 	rx;
	float	ry;
	int		dof;
}	t_ray;

typedef struct s_map{
	int		mx;
	int		my;
	int		mp;
	float	xo;
	float	yo;
}	t_map;

typedef struct s_window{
	char **test;
	mlx_t* mlx;
	mlx_image_t* img;
	t_player player;
	t_ray	ray;
	t_map	map;
}	t_window;


void	clone_matrix(char ***map_copy, char **map, int x, int y);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
size_t	gnl_strlen(const char *s);

#endif