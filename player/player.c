#include "../cub3D.h"

int	init_pos_player(t_scene *scene, int y, int x)
{
	if (scene->map.tab_map[y][x] == 'N')
	{
		scene->player.dir.y = 0.99;
		scene->player.plane.x = 0.80;
		scene->player.pos = (t_vec2){(x + 0.5), (y + 0.5)};
	}
	else if (scene->map.tab_map[y][x] == 'S')
	{
		scene->player.dir.y = -0.99;
		scene->player.plane.x = -0.80;
		scene->player.pos = (t_vec2){x + 0.5, y + 0.5};
	}
	else if (scene->map.tab_map[y][x] == 'W')
	{
		scene->player.dir.x = -0.99;
		scene->player.plane.y = 0.80;
		scene->player.pos = (t_vec2){x + 0.5, y + 0.5};
	}
	else if (scene->map.tab_map[y][x] == 'E')
	{
		scene->player.dir.x = 0.99;
		scene->player.plane.y = -0.80;
		scene->player.pos = (t_vec2){x + 0.5, y + 0.5};
	}
	return (0);
}

int	init_pos_player_map(t_scene *scene, int y, int x, int size)
{
	if (scene->map.tab_map[y][x] == 'N')
	{
		print_player(scene, (scene->player.pos.x) * size, (scene->player.pos.y)
			* size);
	}
	else if (scene->map.tab_map[y][x] == 'S')
	{
		print_player(scene, (scene->player.pos.x) * size, (scene->player.pos.y)
			* size);
	}
	else if (scene->map.tab_map[y][x] == 'W')
	{
		print_player(scene, (scene->player.pos.x) * size, (scene->player.pos.y)
			* size);
	}
	else if (scene->map.tab_map[y][x] == 'E')
	{
		print_player(scene, (scene->player.pos.x) * size, (scene->player.pos.y)
			* size);
	}
	return (0);
}

int	print_player(t_scene *scene, int x, int y)
{
	int	i;

	i = 0;
	mxl_pixel_put(scene, x, y, GREEN);
	mxl_pixel_put(scene, x - 1, y, GREEN);
	mxl_pixel_put(scene, x, y - 1, GREEN);
	mxl_pixel_put(scene, x + 1, y, GREEN);
	mxl_pixel_put(scene, x, y + 1, GREEN);
	mxl_pixel_put(scene, x - 1, y + 1, GREEN);
	mxl_pixel_put(scene, x + 1, y - 1, GREEN);
	mxl_pixel_put(scene, x + 1, y + 1, GREEN);
	mxl_pixel_put(scene, x - 1, y - 1, GREEN);
	while (i < 10)
	{
		if (i < scene->player.perpwdist * scene->map.map_size)
			mxl_pixel_put(scene, (-scene->player.dir.x * i)
				+ (scene->player.pos.x) * scene->map.map_size,
				(-scene->player.dir.y * i) + (scene->player.pos.y)
				* scene->map.map_size, RED);
		i++;
	}
	return (0);
}
