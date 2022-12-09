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
		key_right(&scene->player);
	if (keycode == LEFT_KEY)
		key_left(&scene->player);
	if (keycode == UP_KEY)
		key_up(&scene->player, x, y);
	if (keycode == DOWN_KEY)
		key_down(&scene->player, x);
	return (0);
}

int	key_right(t_player *player)
{
	player->old_dir.x = player->dir.x;
	player->dir.x = player->dir.x * cos(SPDR) - player->dir.y * sin(SPDR);
	player->dir.y = player->old_dir.x * sin(SPDR) + player->dir.y * cos(SPDR);
	return (0);
}

int	key_left(t_player *player)
{
	player->old_dir.x = player->dir.x;
	player->dir.x = player->dir.x * cos(-SPDR) - player->dir.y * sin(-SPDR);
	player->dir.y = player->old_dir.x * sin(-SPDR) + player->dir.y * cos(-SPDR);
	return (0);
}

int	key_down(t_player *player, int x)
{
	(void)x;
	player->pos.x -= player->dir.x * SPD;
	player->pos.y -= player->dir.y * SPD;
	return (0);
}

int	key_up(t_player *player, int x, int y)
{
	(void)x;
	(void)y;
	player->pos.x += player->dir.x * SPD;
	player->pos.y += player->dir.y * SPD;
	return (0);
}