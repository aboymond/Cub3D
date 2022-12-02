#include "cub3D.h"

int	open_win(t_scene *scene)
{
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, 1920, 1080, "test");
	scene->img.img = mlx_new_image(scene->mlx.mlx, 1920, 1080);
	scene->img.addr = mlx_get_data_addr(scene->img.img, &scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
	mini_map_init(scene);
	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
	return (0);
}

int	mxl_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst ;

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
		mini_map_pixel_border(scene, x, y, size);
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
		i++;
	}
	while (j < ((y * size) + size))
	{
		mxl_pixel_put(scene, x * size, j, RED);
		j++;
	}
	i = (x * size);
	j = (y * size);
	while (i < ((x * size) + size))
	{
		mxl_pixel_put(scene, i, (y * size) + size, RED);
		i++;
	}
	while (j < ((y * size) + size))
	{
		mxl_pixel_put(scene, (x * size) + size, j, RED);
		j++;
	}
	return (0);
}

int	mini_map_init(t_scene *scene)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	y = 0;
	size = 15;
	while (y < ft_tablen(scene->map.tab_map))
	{
		while (x < (int)ft_strlen(scene->map.tab_map[y]))
		{
			// if (scene->map.tab_map[y][x] == ' ')
			// 	scene->map.tab_map[y][x] = '1';
			if (scene->map.tab_map[y][x] == '1')
				mini_map_pixel(scene, x, y, 1, size);
			if (scene->map.tab_map[y][x] == '0')
				mini_map_pixel(scene, x, y, 0, size);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}