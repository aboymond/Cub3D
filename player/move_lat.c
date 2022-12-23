/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:16:33 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	l_right(t_scene *scene, t_player *player)
{
	float	dir;

	dir = player->dir.x;
	if (scene->map.tab_map[(int)(player->pos.y - player->dir.x * SPD)]
		[(int)(player->pos.x)] == '0')
	{
		player->pos.y += -player->dir.x * (SPD);
	}
	if (scene->map.tab_map[(int)(player->pos.y)]
			[(int)(player->pos.x + player->dir.y * SPD)] == '0')
		player->pos.x += player->dir.y * (SPD);
	return (0);
}

int	l_left(t_scene *scene, t_player *player)
{
	float	dir;

	dir = player->dir.x;
	if (scene->map.tab_map[(int)(player->pos.y + player->dir.x
			* SPD)][(int)(player->pos.x)] == '0')
	{
		player->pos.y -= -player->dir.x * (SPD);
	}
	if (scene->map.tab_map[(int)(player->pos.y)]
		[(int)(player->pos.x - player->dir.y * SPD)] == '0')
	{
		player->pos.x -= player->dir.y * (SPD);
	}
	return (0);
}
