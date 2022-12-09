#include "../cub3D.h"

int	key_move(int keycode, t_scene *scene)
{
	int	x;
	int	y;

	y = (int)scene->player.pos.y / scene->map.map_size;
	x = (int)scene->player.pos.x / scene->map.map_size;
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT_KEY)
		key_right(scene);
	if (keycode == LEFT_KEY)
		key_left(scene);
	if (keycode == UP_KEY)
		key_up(scene, x, y);
	if (keycode == DOWN_KEY)
		key_down(scene, x);
	return (0);
}

int	key_right(t_scene *scene)
{
	scene->player.old_dir.x = scene->player.dir.x;
	scene->player.dir.x = scene->player.dir.x * cos(SPD) - scene->player.dir.y * sin(SPD);
	scene->player.dir.y = scene->player.old_dir.x * sin(SPD) + scene->player.dir.y * cos(SPD);
	return (0);
}

int	key_left(t_scene *scene)
{
	scene->player.old_dir.x = scene->player.dir.x;
	scene->player.dir.x = scene->player.dir.x * cos(-SPD) - scene->player.dir.y * sin(-SPD);
	scene->player.dir.y = scene->player.old_dir.x * sin(-SPD) + scene->player.dir.y * cos(-SPD);
	return (0);
}

int	key_down(t_scene *scene, int x)
{
	scene->player.pos.x -= scene->player.dir.x * SPD;
	scene->player.pos.y -= scene->player.dir.y * SPD;
	return (0);
}

int	key_up(t_scene *scene, int x, int y)
{
	scene->player.pos.x += scene->player.dir.x * SPD;
	scene->player.pos.y += scene->player.dir.y * SPD;
	return (0);
}