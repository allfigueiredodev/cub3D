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

void controller(mlx_key_data_t keydata, void* param)
{
	(void)param;

	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.action == MLX_PRESS)
			puts("A ");
		else if (keydata.action == MLX_REPEAT)
		{
			while (keydata.action == MLX_REPEAT && keydata.action != MLX_REPEAT)
				puts("A ");
		}
	}
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.action == MLX_PRESS)
			puts("D ");
		else if (keydata.action == MLX_REPEAT)
		{
			while (keydata.action == MLX_REPEAT && keydata.action != MLX_REPEAT)
				puts("D ");
		}
	}
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.action == MLX_PRESS)
			puts("W ");
		else if (keydata.action == MLX_REPEAT)
		{
			while (keydata.action == MLX_REPEAT && keydata.action != MLX_REPEAT)
				puts("W ");
		}
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.action == MLX_PRESS)
			puts("S ");
		else if (keydata.action == MLX_REPEAT)
		{
			while (keydata.action == MLX_REPEAT && keydata.action != MLX_REPEAT)
				puts("S ");
		}
	}
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.action == MLX_PRESS)
			puts("LEFT ");
		else if (keydata.action == MLX_REPEAT)
		{
			while (keydata.action == MLX_REPEAT && keydata.action != MLX_REPEAT)
				puts("LEFT ");
		}
	}
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.action == MLX_PRESS)
			puts("RIGHT ");
		else if (keydata.action == MLX_REPEAT)
		{
			while (keydata.action == MLX_REPEAT && keydata.action != MLX_REPEAT)
				puts("RIGHT ");
		}
	}
}

void put_block(mlx_image_t* img, int x, int y, uint32_t color)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(j <= 16)
	{
		while(i <= 16)
		{
			if(!i || !j || i == 16 || j == 16)
				mlx_put_pixel(img, x + j, y + i, 0xFFFFFFFF);
			else
				mlx_put_pixel(img, x + j, y + i, color);
			i++;
		}
		j++;
		i = 0;
	}
}

// void render_matrix(char **map, mlx_image_t* img)
void render_matrix(void *window)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	t_window *cast = (t_window *)window;

	while(y < HEIGHT)
	{
		if(*cast->test && cast->test[i][j])
		{
			while(cast->test[i][j])
			{
				if(cast->test[i][j] && cast->test[i][j] == '1')
					put_block(cast->img , x, y, 0xFF00FFFF);
				else if (cast->test[i][j] && cast->test[i][j] == '0')
					put_block(cast->img , x, y, 0xFF8800FF);
				else if (!ft_isalpha(cast->test[i][j]))
					put_block(cast->img , x, y, 0x00000000);
				else 
					put_block(cast->img , x, y, 0x89CFF0);
				x+=16;
				j++;
			}
			y+=16;
			cast->test++;
			x = 0;
			j = 0;
		}
		y++;
	}
}

int32_t	main(void)
{
	t_player player;
	t_window window;
	char *twoD[] = {
"        1111111111111111111111111",
"        1000000000110000000000001",
"        1011000001110000000000001",
"        1001000000000000000000001",
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
	window.test = twoD;

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	// mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	window.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!window.mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	// mlx_image_t* img = mlx_new_image(mlx, 800, 600);
	window.img = mlx_new_image(window.mlx, 800, 600);
	if (!window.img || (mlx_image_to_window(window.mlx, window.img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.

	// render_matrix(test, img);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(window.mlx, controller, &player);
	mlx_loop_hook(window.mlx, render_matrix, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	return (EXIT_SUCCESS);
}