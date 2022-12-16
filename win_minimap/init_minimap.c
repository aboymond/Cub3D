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
		while (x < scene->map.len_map - 1/* || scene->map.tab_map[y][x]*/)
		{
			if (utils_c_w(scene->map.tab_map[y][x], 0) == 1)
			{
				init_pos_player(scene, y, x, size);
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

	x = 0;
	y = 0;
	while (y < ft_tablen(scene->map.tab_map))
	{
		while (x < scene->map.len_map - 1/* || scene->map.tab_map[y][x]*/)
		{
			if (scene->map.tab_map[y][x] == ' ')
				scene->map.tab_map[y][x] = '1';
			if (scene->map.tab_map[y][x] == '1')
				mini_map_pixel(scene, x, y, 1, scene->map.map_size);
			if (scene->map.tab_map[y][x] == '0')
				mini_map_pixel(scene, x, y, 0, scene->map.map_size);
			if (utils_c_w(scene->map.tab_map[y][x], 0) == 1)
			{
				mini_map_pixel(scene, x, y, 0, scene->map.map_size);
				init_pos_player_map(scene, y, x);
				scene->map.tab_map[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
