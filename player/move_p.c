#include "../cub3D.h"

int	key_move(int keycode, t_scene *scene)
{
	int	x;
	int	y;

	y = (int)scene->player.pos.y / scene->map.map_size;
	x = (int)scene->player.pos.x / scene->map.map_size;
	printf("key = %d\n", keycode);
	if (keycode == ESC)
	{
		free_main(scene);

	}
	if (keycode == RIGHT_KEY)
		key_right(&scene->player);
	if (keycode == LEFT_KEY)
		key_left(&scene->player);
	if (keycode == UP_KEY)
		key_up(scene, &scene->player, x, y);
	if (keycode == DOWN_KEY)
		key_down(scene, &scene->player, x);
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

int	key_down(t_scene *scene, t_player *player, int x)
{
	(void)x;
	(void)scene;
	if (scene->player.perpwdist <= 0.5)
		return (0);
	//if (scene->map.tab_map[(int)(player->pos.y - (player->dir.y * SPD))][(int)player->pos.x] == '0')
		player->pos.y -= player->dir.y * SPD;
	//if (scene->map.tab_map[(int)player->pos.y][(int)(player->pos.x - (player->dir.x * SPD))] == '0')
		player->pos.x -= player->dir.x * SPD;
	return (0);
}

int	key_up(t_scene *scene, t_player *player, int x, int y)
{
	(void)x;
	(void)y;
	(void)scene;
	// if (scene->player.perpudist <= 0.5)
	// 	return (0);
	//if (scene->map.tab_map[(int)(player->pos.y + (player->dir.y * SPD))][(int)player->pos.x] == '0')
		player->pos.y += player->dir.y * SPD;
	//if (scene->map.tab_map[(int)player->pos.y][(int)(player->pos.x + (player->dir.x * SPD))] == '0')
		player->pos.x += player->dir.x * SPD;
	return (0);
}

		// if (recup->map[(int)(recup->ray.posx + (recup->ray.dirx * recup->
		// 				ray.movespeed * 2))][(int)recup->ray.posy] == '0')