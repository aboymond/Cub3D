/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:38:26 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:24:30 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mxl_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst ;

	if ((x < 0 || y < 0) || (x >= WIN_X || y >= WIN_Y) || ((y * WIN_Y + x)
			>= WIN_X * WIN_Y - 1))
		return (p_error("Error :\n\tMinimap"));
	dst = scene->img->addr + (y * scene->img->line_length + x
			* (scene->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	mini_map_pixel(t_scene *scene, int x, int y, int floor)
{
	int	i;
	int	j;

	i = (x * scene->map.map_size);
	j = (y * scene->map.map_size);
	if (floor == 1)
	{
		while (j++ < ((y * scene->map.map_size) + scene->map.map_size))
		{
			while (i++ < ((x * scene->map.map_size) + scene->map.map_size))
				mxl_pixel_put(scene, i, j, WHI);
			i = (x * scene->map.map_size);
		}
	}
	else
	{
		while (j++ < ((y * scene->map.map_size) + scene->map.map_size))
		{
			while (i++ < ((x * scene->map.map_size) + scene->map.map_size))
				mxl_pixel_put(scene, i, j, GRE);
			i = (x * scene->map.map_size);
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
	return (0);
}
