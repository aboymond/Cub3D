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
	mxl_pixel_put(scene, x, y, WHI);
	mxl_pixel_put(scene, x - 1, y, WHI);
	mxl_pixel_put(scene, x, y - 1, WHI);
	mxl_pixel_put(scene, x + 1, y, WHI);
	mxl_pixel_put(scene, x, y + 1, WHI);
	mxl_pixel_put(scene, x - 1, y + 1, WHI);
	mxl_pixel_put(scene, x + 1, y - 1, WHI);
	mxl_pixel_put(scene, x + 1, y + 1, WHI);
	mxl_pixel_put(scene, x - 1, y - 1, WHI);

	return (0);
}

// int	print_dir(t_scene *scene, int x, int y)
// {
	
// 	return (0);
// }