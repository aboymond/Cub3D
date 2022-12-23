/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:38:43 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:21:24 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	search_player(t_scene *scene)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	y = 0;
	size = 350 / scene->map.len_map;
	scene->map.map_size = size;
	while (y < ft_tablen(scene->map.tab_map))
	{
		while (x < scene->map.len_map - 1)
		{
			if (utils_c_w(scene->map.tab_map[y][x], 0) == 1)
			{
				init_pos_player(scene, y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	mini_map_init(t_scene *scene)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < ft_tablen(scene->map.tab_map))
	{
		while (++x < scene->map.len_map - 1)
		{
			if (scene->map.tab_map[y][x] == ' ')
				scene->map.tab_map[y][x] = '1';
			if (scene->map.tab_map[y][x] == '1')
				mini_map_pixel(scene, x, y, 1);
			if (scene->map.tab_map[y][x] == '0')
				mini_map_pixel(scene, x, y, 0);
			if (utils_c_w(scene->map.tab_map[y][x], 0) == 1)
			{
				mini_map_pixel(scene, x, y, 0);
				init_pos_player_map(scene, y, x, scene->map.map_size);
				scene->map.tab_map[y][x] = '0';
			}
		}
		x = -1;
	}
	return (0);
}
