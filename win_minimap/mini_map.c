#include "../cub3D.h"

int	mlx_open_win(t_scene *scene)
{
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, WIN_X, WIN_Y, "test");
	scene->img.img = mlx_new_image(scene->mlx.mlx, WIN_X, WIN_Y);
	scene->img.addr = mlx_get_data_addr(scene->img.img, &scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
	return (0);
}

int	open_win(t_scene *scene)
{
	mini_map_init(scene);
	print_player(scene, scene->player.pos.x, scene->player.pos.y);
	mxl_pixel_put(scene, (scene->player.dir.x * 4) + scene->player.pos.x, (scene->player.dir.y * 4) + scene->player.pos.y, RED);
	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
	return (0);
}

int	mxl_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst ;

	if ((x < 0 || y < 0) || (x > WIN_X || y > WIN_Y))
		return(p_error("Error :\n\tMinimap"));
	dst = scene->img.addr + (y * scene->img.line_length + x * (scene->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (0);
}

int	mini_map_pixel(t_scene *scene, int x, int y, int floor, int size)
{
	int	i;
	int	j;

	i = (x * size);
	j = (y * size);
	if (floor == 1)
	{
		while (j < ((y * size) + size))
		{
			while (i < ((x * size) + size))
			{
				mxl_pixel_put(scene, i, j, WHI);
				i++;
			}
			i = (x * size);
			j++;
		}
		//mini_map_pixel_border(scene, x, y, size);
	}
	else
	{
		while (j < ((y * size) + size))
		{
			while (i < ((x * size) + size))
			{
				mxl_pixel_put(scene, i, j, GRE);
				i++;
			}
			i = (x * size);
			j++;
		}
	}

	return (0);
}

int	mini_map_pixel_border(t_scene *scene, int x, int y, int size)
{
	int	i;
	int	j;

	i = (x * size);
	j = (y * size);
	while (i < ((x * size) + size))
	{
		mxl_pixel_put(scene, i, y * size, RED);
		mxl_pixel_put(scene, i, (y * size) + size, YEL);
		i++;
	}
	while (j < ((y * size) + size))
	{
		mxl_pixel_put(scene, x * size, j, BLU);
		mxl_pixel_put(scene, (x * size) + size, j, GREEN);
		j++;
	}
	// i = (x * size);
	// j = (y * size);
	// while (i < ((x * size) + size))
	// {
	// 	i++;
	// }
	// while (j < ((y * size) + size))
	// {
	// 	j++;
	// }
	return (0);
}