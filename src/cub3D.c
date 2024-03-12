#include "../include/cub3D.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

void put_block(mlx_image_t* img, int x, int y, uint32_t color)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(j < 10)
	{
		while(i < 10)
		{
			mlx_put_pixel(img, x + i, y + i, color);
			i++;
		}
		j++;
		i = 0;
	}
}

void render_matrix(char **map, mlx_image_t* img)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;

	while(y < HEIGHT)
	{
		// while((x < WIDTH) && (map && *map[i]))
		if(*map)
		{
			while(map[i][j])
			{
				if(map[i][j] && map[i][j] == '1')
					put_block(img, x, y, 0xFFFF00FF);
				else if (map[i][j] && map[i][j] == '0')
					put_block(img, x, y, 0xFF0000FF);
				else if (!ft_isalpha(map[i][j]))
					put_block(img, x, y, 0x00000000);
				else 
					put_block(img, x, y, 0x89CFF0);
				x+=10;
				j++;
			}
			y+=10;
			map++;
			x = 0;
			j = 0;
		}
		y++;
	}
}

int32_t	main(void)
{
	char *test[] = {
"       1111111111111781111111111",
"       1000000000110000000000001",
"       1011000001110000000000001",
"       1001000000000000000000001",
"111111111011000001110000000000001",
"100000000011000001110111111111111",
"11110111111111011100000010001    ",
"11110111111111011101010010001    ",
"11000000110101011100000010001    ",
"10000000000000001100000010001    ",
"10000000000000001101010010001    ",
"11000001110101011111011110N0111  ",
"11110111 1110101 101111010001    ",
"11111111 1111111 111111111111    ",
};

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 320, 200);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.

	render_matrix(test, img);

	// int x = 0;
	// int y = 0;
	// while(y < HEIGHT)
	// {
	// 	while(x < WIDTH)
	// 	{
	// 		mlx_put_pixel(img, x, y, 0xFFFF00FF);
	// 		x++;
	// 	}
	// 	y++;
	// 	x = 0;
	// }

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}