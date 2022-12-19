#include "../cub3D.h"

int	key_ESC(int keycode, t_scene *scene)
{
	if (keycode == ESC)
		free_main(scene);
	return (0);
}

int	key_move(int keycode, t_scene *scene)
{
	int	x;
	int	y;

	y = (int)scene->player.pos.y / scene->map.map_size;
	x = (int)scene->player.pos.x / scene->map.map_size;
	if (keycode == RIGHT_KEY)
		key_right(&scene->player);
	if (keycode == LEFT_KEY)
		key_left(&scene->player);
	if (keycode == UP_KEY)
		key_up(scene, &scene->player, x, y);
	if (keycode == DOWN_KEY)
		key_down(scene, &scene->player, x, y);
	return (0);
}

int	key_right(t_player *player)
{
	float	dir;
	float	plane;

	dir = player->dir.x;
	plane = player->plane.x;
	player->dir.x = player->dir.x * cos(SPDR * 0.1) - player->dir.y * sin(SPDR * 0.1);
	player->dir.y = dir * sin(SPDR * 0.1) + player->dir.y * cos(SPDR * 0.1);
	player->plane.x = player->plane.x * cos(SPDR * 0.1) - player->plane.y * sin(SPDR * 0.1);
	player->plane.y = plane * sin(SPDR * 0.1) + player->plane.y * cos(SPDR * 0.1);

	// player->old_dir.x = player->dir.x;
	// player->dir.x = player->dir.x * cos(SPDR) - player->dir.y * sin(SPDR);
	// player->dir.y = player->old_dir.x * sin(SPDR) + player->dir.y * cos(SPDR);
	// player->old_plane.x = player->plane.x;
	// player->plane.x = player->plane.x * sin(SPDR) - player->plane.y * cos(SPDR);
	// player->plane.y = player->old_plane.x * sin(SPDR) + player->plane.y * cos(SPDR);
	return (0);
}

int	key_left(t_player *player)
{
	
	float	dir;
	float	plane;

	dir = player->dir.x;
	plane = player->plane.x;
	player->dir.x = player->dir.x * cos(-SPDR * 0.1) - player->dir.y * sin(-SPDR * 0.1);
	player->dir.y = dir * sin(-SPDR * 0.1) + player->dir.y * cos(-SPDR * 0.1);
	player->plane.x = player->plane.x * cos(-SPDR * 0.1) - player->plane.y * sin(-SPDR * 0.1);
	player->plane.y = plane * sin(-SPDR * 0.1) + player->plane.y * cos(-SPDR * 0.1);

	// player->old_dir.x = player->dir.x;
	// player->dir.x = player->dir.x * cos(-SPDR) - player->dir.y * sin(-SPDR);
	// player->dir.y = player->old_dir.x * sin(-SPDR) + player->dir.y * cos(-SPDR);
	// player->old_plane.x = player->plane.x;
	// player->plane.x = player->plane.x * sin(-SPDR) - player->plane.y * cos(-SPDR);
	// player->plane.y = player->old_plane.x * sin(-SPDR) + player->plane.y * cos(-SPDR);

	return (0);
}

int	key_down(t_scene *scene, t_player *player, int x, int y)
{
	if (scene->map.tab_map[(int)(y - (player->dir.y * SPD))][(int)x] == '0')
		player->pos.y -= player->dir.y * SPD;
	if (scene->map.tab_map[(int)y][(int)(x - (player->dir.x * SPD))] == '0')
		player->pos.x -= player->dir.x * SPD;
	return (0);
}

int	key_up(t_scene *scene, t_player *player, int x, int y)
{
		if (scene->map.tab_map[(int)(y + (player->dir.y * SPD))][(int)x] == '0')
			player->pos.y += player->dir.y * SPD;
		if (scene->map.tab_map[(int)y][(int)(x + (player->dir.x * SPD))] == '0')
			player->pos.x += player->dir.x * SPD;
	return (0);
}

		// if (recup->map[(int)(recup->ray.posx + (recup->ray.dirx * recup->
		// 				ray.movespeed * 2))][(int)recup->ray.posy] == '0')