/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:05 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 17:47:24 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_move(int keycode, t_scene *scene)
{
	if (keycode == ESC)
		ft_close();
	if (keycode == RIGHT_KEY)
		key_right(&scene->player);
	if (keycode == LEFT_KEY)
		key_left(&scene->player);
	if (keycode == W_KEY)
		key_up(scene, &scene->player);
	if (keycode == S_KEY)
		key_down(scene, &scene->player);
	if (keycode == D_KEY)
		l_right(scene, &scene->player);
	if (keycode == A_KEY)
		l_left(scene, &scene->player);
	return (0);
}

int	key_right(t_player *player)
{
	float	dir;
	float	plane;

	dir = player->dir.x;
	plane = player->plane.x;
	player->dir.x = player->dir.x * cos(SPDR * 0.1) - player->dir.y
		* sin(SPDR * 0.1);
	player->dir.y = dir * sin(SPDR * 0.1) + player->dir.y
		* cos(SPDR * 0.1);
	player->plane.x = player->plane.x * cos(SPDR * 0.1) - player->plane.y
		* sin(SPDR * 0.1);
	player->plane.y = plane * sin(SPDR * 0.1) + player->plane.y
		* cos(SPDR * 0.1);
	return (0);
}

int	key_left(t_player *player)
{
	float	dir;
	float	plane;

	dir = player->dir.x;
	plane = player->plane.x;
	player->dir.x = player->dir.x * cos(-SPDR * 0.1) - player->dir.y
		* sin(-SPDR * 0.1);
	player->dir.y = dir * sin(-SPDR * 0.1) + player->dir.y * cos(-SPDR * 0.1);
	player->plane.x = player->plane.x * cos(-SPDR * 0.1) - player->plane.y
		* sin(-SPDR * 0.1);
	player->plane.y = plane * sin(-SPDR * 0.1) + player->plane.y
		* cos(-SPDR * 0.1);
	return (0);
}

int	key_down(t_scene *scene, t_player *player)
{
	if (scene->map.tab_map[(int)(player->pos.y + player->dir.y
			* SPD)][(int)(player->pos.x + player->dir.x * SPD)] == '0')
	{
		player->pos.x += player->dir.x * SPD;
		player->pos.y += player->dir.y * SPD;
	}
	return (0);
}

int	key_up(t_scene *scene, t_player *player)
{
	if (scene->map.tab_map[(int)(player->pos.y - player->dir.y
			* SPD)][(int)(player->pos.x - player->dir.x * SPD)] == '0')
	{
		player->pos.x -= player->dir.x * SPD;
		player->pos.y -= player->dir.y * SPD;
	}
	return (0);
}
