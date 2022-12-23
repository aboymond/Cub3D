/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:39:27 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:40:14 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_height_wall(t_scene *scene)
{
	scene->player.lineh = fabs(WIN_Y / scene->player.perpwdist);
	scene->player.lineh -= WIN_Y / 50;
	scene->player.start = (-1 * (scene->player.lineh) / 2 + WIN_Y / 2);
	scene->player.end = scene->player.lineh / 2 + WIN_Y / 2;
	if (scene->player.start < 0)
		scene->player.start = 0;
	if (scene->player.end >= WIN_Y)
		scene->player.end = WIN_Y - 1;
	return (0);
}

int	draw_wall(t_scene *scene, int x)
{
	int	y;

	y = 0;
	while (y < scene->player.start)
	{
		mxl_pixel_put(scene, x, y, scene->asset.ceil_hex);
		y++;
	}
	y = scene->player.start;
	while (y < scene->player.end)
	{
		scene->ptr.y = (int)scene->ptr.texpos & (64 - 1);
		scene->ptr.texpos += scene->ptr.step;
		wall(scene);
		mxl_pixel_put(scene, x, y, scene->ptr.color);
		y++;
	}
	while (y++ < WIN_Y - 1)
		mxl_pixel_put(scene, x, y, scene->asset.floor_hex);
	return (0);
}
