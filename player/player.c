#include "../cub3D.h"

int	init_pos_player(t_scene *scene, int y, int x, int size)
{
	if (scene->map.tab_map[y][x] == 'N')
	{
		scene->player.dir = (t_vec2){0, -1};
		scene->player.pos = (t_vec2){(x + 0.5) * size, (y + 0.5)* size};
		print_player(scene,scene->player.pos.x, scene->player.pos.y);

	}
	else if (scene->map.tab_map[y][x] == 'S')
	{
		scene->player.dir = (t_vec2){0, 1};
		scene->player.pos = (t_vec2){(x + 0.5) * size, (y + 0.5)* size};
		print_player(scene,scene->player.pos.x, scene->player.pos.y);
	}
	else if (scene->map.tab_map[y][x] == 'W')
	{
		scene->player.dir = (t_vec2){-1, 0};
		scene->player.pos = (t_vec2){(x + 0.5) * size, (y + 0.5)* size};
		print_player(scene,scene->player.pos.x, scene->player.pos.y);
	}
	else if (scene->map.tab_map[y][x] == 'E')
	{
		scene->player.dir = (t_vec2){1, 0};
		scene->player.pos = (t_vec2){(x + 0.5) * size, (y + 0.5)* size};
		print_player(scene,scene->player.pos.x, scene->player.pos.y);
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
	while (i < 20)
	{
		if (i < scene->player.perpwdist * scene->map.map_size)
			mxl_pixel_put(scene, (scene->player.dir.x * i) + scene->player.pos.x, (scene->player.dir.y * i) + scene->player.pos.y, RED);
	// 	//printf("test = %f", scene->player.x_f / scene->map.map_size);
	// 	//mxl_pixel_put(scene, (scene->player.raydir.x * i) + scene->player.pos.x, (scene->player.raydir.y * i) + scene->player.pos.y, RED);
		i++;
	}
	return (0);
}

// int	print_dir(t_scene *scene, int x, int y)
// {
	
// 	return (0);
// }