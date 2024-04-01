#include "../include/cub3D.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_print_matrix(char **matrix)
{
	while (*matrix)
	{
		ft_printf("%s\n", *matrix);
		matrix++;
	}
}
// Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// void raycast(void *window)
// {
// 	t_window *cast = (t_window *)window;
// 	float atan;
// 	cast->ray.ra = cast->player.pa;
// 	cast->ray.r = 0;

// 	while(cast->ray.r < 1)
// 	{
// 		cast->ray.dof = 0;
// 		atan = -1/tan(cast->player.pa);
		
// 		// printf("Tha value of (float)MY_PI: %f\n", (float)MY_PI);
// 		if (cast->ray.ra > (float)MY_PI)
// 		{
// 			cast->ray.ry = (((int)cast->player.py >> 4) << 4) - 0.0001;
// 			cast->ray.rx = (cast->player.py - cast->ray.ry) * atan + cast->player.px;
// 			cast->map.yo = -16;
// 			cast->map.xo = -cast->map.yo * atan;			 
// 		}
// 		else if (cast->ray.ra < (float)MY_PI)
// 		{
// 			cast->ray.rx = (((int)cast->player.py >> 4) << 4) + CUB; 
// 			cast->ray.rx = (cast->player.py - cast->ray.ry) * atan + cast->player.px;
// 			cast->map.yo = 16;
// 			cast->map.xo = -cast->map.yo * atan;	
// 		}
// 		if (cast->ray.ra == 0 || cast->ray.ra == (float)MY_PI)
// 		{
// 			cast->ray.rx = cast->player.px;
// 			cast->ray.ry = cast->player.py;
// 			cast->ray.dof = 8;
// 		}
// 		while (cast->ray.dof < 8)
// 		{
// 			cast->map.mx = (int)(cast->ray.rx) >> 4;
// 			cast->map.my = (int)(cast->ray.ry) >> 4;
// 			// printf("The value of MAPX: %d\n", MAPX);
// 			// printf("The value of MAPY: %d\n", MAPY);
// 			cast->map.mp = cast->map.my * MAPX + cast->map.mx;
// 			if (cast->map.mp < (MAPX * MAPY) && *cast->test[cast->map.mp] == '1') // here
// 				cast->ray.dof = 8;
// 			else
// 			{
// 				cast->ray.rx += cast->map.xo;
// 				cast->ray.ry += cast->map.yo;
// 				cast->ray.dof += 1;
// 			}
// 		}
// 		cast->ray.r++;
// 		mlx_put_pixel(cast->img, cast->ray.rx, cast->ray.ry, 0x89CFF0);
// 	}
// }

void close_and_free(void *window)
{
	t_window *cast = (t_window *)window;

	mlx_close_window(cast->mlx);
}

// void put_target(void *window)
// {
// 	float i = 0;
// 	t_window *cast = (t_window *)window;
	
// 	while(i <= LINE_SIZE)
// 	{
// 		// printf("X: %f, Y: %f\n", cast->player.px + cast->player.pdx * i, cast->player.py + cast->player.pdy * i);
// 		if ((cast->player.py + CUB / 2 + cast->player.pdy * i) >= 0 
// 		&& (cast->player.px + CUB / 2 + cast->player.pdx * i) >= 0)
// 		{
// 			mlx_put_pixel(cast->img, (cast->player.py + CUB / 2 + cast->player.pdy * i),
// 				(cast->player.px + CUB / 2 + cast->player.pdx * i), 0x89CFF0);
// 		}
// 		i+= 0.1;
// 	}
// }

void put_player(void *window)
{
	t_window *cast = (t_window *)window;
	int i;
	int j;
	float k;

	i = 0;
	j = 0;
	k = 0;

	while(j <= PLYR_SIZE)
	{
		while(i <= PLYR_SIZE)
		{
			mlx_put_pixel(cast->img, cast->player.px + i, cast->player.py + j, 0x89CFF0);
			i++;
		}
		j++;
		i = 0;
	}
	while(k < LINE_SIZE)
	{
		if((cast->player.px + PLYR_SIZE / 2) + cast->player.pdx * k >= 0
			&& (cast->player.py + PLYR_SIZE / 2) + cast->player.pdy * k >=0)
			{
				mlx_put_pixel(cast->img, (cast->player.px + PLYR_SIZE / 2) + cast->player.pdx * k, 
					(cast->player.py + PLYR_SIZE / 2) + cast->player.pdy * k, 0x89CFF0);
			}
		k+= 0.1;
	}
}

void turn (void *param, float angle)
{
	t_window *cast = (t_window *)param;

	cast->player.pa = cast->player.pa + angle;
	if(cast->player.pa < 0)
		cast->player.pa = 2 * (float)MY_PI;
	else if(cast->player.pa > 2 * (float)MY_PI)
		cast->player.pa = 0;
	cast->player.pdx = (float)cos(cast->player.pa) * 5;
	cast->player.pdy = (float)sin(cast->player.pa) * 5;
	printf("pda: %f\n", cast->player.pa);
	printf("pdx: %f\n", cast->player.pdx);
	printf("pdy: %f\n", cast->player.pdy);

}

void move (void *param, int x, int y)
{
	t_window *cast = (t_window *)param;

	// printf("cast->test[%d][%d]\n", (cast->player.px / CUB) + y, (cast->player.py / CUB) + x);
	// ft_print_matrix(cast->test);
	// if (cast->test[(cast->player.px / CUB) + y][(cast->player.py / CUB) + x] == '0')
	// {
	// 	cast->test[(cast->player.px / CUB) + y][(cast->player.py / CUB) + x] = 'X';
	// 	cast->test[(cast->player.px / CUB)][(cast->player.py / CUB)] = '0';
		cast->player.px = cast->player.px + (x * (CUB / 2)); // (x * CUB);
		cast->player.py = cast->player.py + (y * (CUB / 2)); // (y * CUB);
	// }
}

void controller(mlx_key_data_t keydata, void* param)
{
	(void)param;

	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		// 2 or greater values will make the player move faster as it jumps in the grid by two pixels or more at time,
		// this is great to walk around but not to move the camera sideways, to turn left and right in the player axel,
		// try go from 1 first. 
		move(param, -1, 0);
		puts("A ");
	}
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		move(param, 1, 0);
		puts("D ");
	}
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		move(param, 0, -1);
		puts("W ");
	}
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		move(param, 0, 1);
		puts("S ");
	}
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		turn(param, -0.1);
		puts("LEFT ");
	}
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		turn(param, 0.1);
		puts("RIGHT ");
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_and_free(param);
}


void put_block(mlx_image_t* img, int x, int y, uint32_t color)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(j <= CUB)
	{
		while(i <= CUB)
		{
			if(!i || !j || i == CUB || j == CUB)
				mlx_put_pixel(img, x + j, y + i, 0xFFFFFFFF);
			else
				mlx_put_pixel(img, x + j, y + i, color);
			i++;
		}
		j++;
		i = 0;
	}
}

void render_matrix(void *window)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	t_window *cast = (t_window *)window;
	char **bkp = cast->test;

	while(y < HEIGHT)
	{
		if(*cast->test && *cast->test[j])
		{
			while((*cast->test)[j])
			{
				if((*cast->test)[j] && (*cast->test)[j] == '1')
					put_block(cast->img , x, y, 0xFF00FFFF);
				else if ((*cast->test)[j] && (*cast->test)[j] == '0')
					put_block(cast->img , x, y, 0xFF8800FF);
				else if (!ft_isalpha((*cast->test)[j]))
					put_block(cast->img , x, y, 0x00000000);
				// else
				// {
				// 	put_block(cast->img , x, y, 0x89CFF0);
				// 	cast->player.px = i * CUB;
				// 	cast->player.py = j * CUB;
				// }
				x+=CUB;
				j++;
			}
			y+=CUB;
			i++;
			cast->test++;
			x = 0;
			j = 0;
		}
		y++;
	}
	cast->test = bkp;
}

int32_t	main(void)
{
	t_window window;
	char *twoD[] = {
"        1111111111111111111111111",
"        1000000000110000000000001",
"        101100000111000000N000001",
"        1001000000000000000000001",
"111111111011000001110000000000001",
"100000000011000001110111111111111",
"11110111111111011100000010001    ",
"11110111111111011101010010001    ",
"11000000110101011100000010001    ",
"10000000000000001100000010001    ",
"10000000000000001101010010001    ",
"1100000111010101111101111000111  ",
"11110111 1110101 101111010001    ",
"11111111 1111111 111111111111    ",
};
	clone_matrix(&window.test, twoD, 33, 14);
	window.player.px = 300;
	window.player.py = 200;
	window.player.pa = (float)MY_PI; // this should be initialised accordingly with the player respaw direction N,E,S,W -> E = 2 * (float)MY_PI, N = (float)MY_PI/2, W = (float)MY_PI, S = 3*(float)MY_PI / 2
	window.player.pdx = (float)cos(window.player.pa) * 5; 
	window.player.pdy = (float)sin(window.player.pa) * 5;
	window.ray.rx = window.player.px;
	window.ray.ry = window.player.py;
	window.map.mp = 0;


	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	window.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!window.mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	window.img = mlx_new_image(window.mlx, 800, 600);
	if (!window.img || (mlx_image_to_window(window.mlx, window.img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(window.mlx, controller, &window);
	mlx_loop_hook(window.mlx, render_matrix, &window);
	mlx_loop_hook(window.mlx, put_player, &window);
	// mlx_loop_hook(window.mlx, put_target, &window);
	// mlx_loop_hook(window.mlx, raycast, &window);
	mlx_loop(window.mlx);
	mlx_terminate(window.mlx);
	return (EXIT_SUCCESS);
}