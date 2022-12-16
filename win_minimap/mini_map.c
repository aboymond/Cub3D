#include "../cub3D.h"


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
				mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, i, j, WHI);
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
				mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, i, j, GRE);
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
		mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, i, y * size, RED);
		mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, i, (y * size) + size, YEL);
		i++;
	}
	while (j < ((y * size) + size))
	{
		mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, x * size, j, BLU);
		mlx_pixel_put(scene->mlx.mlx, scene->mlx.win, (x * size) + size, j, GREEN);
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

