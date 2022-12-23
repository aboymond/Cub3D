/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:37:54 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:50:24 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_ray(t_scene *scene)
{
	int	x;

	x = -1;
	scene->player.side = 0;
	while (++x < WIN_X)
	{
		init_ray_dir(scene, x);
		init_delta(scene);
		init_sdist(scene);
		dda_hit(scene);
		init_height_wall(scene);
		texture(scene);
		convert_rvb_to_hexa(scene);
		draw_wall(scene, x);
	}
	return (0);
}

int	init_ray_dir(t_scene *scene, int x)
{
	scene->player.cam.x = 2 * x / (float)WIN_X - 1;
	scene->player.raydir.x = -scene->player.dir.x + scene->player.plane.x
		* scene->player.cam.x;
	scene->player.raydir.y = -scene->player.dir.y + scene->player.plane.y
		* scene->player.cam.x;
	scene->player.rposx = (scene->player.pos.x);
	scene->player.rposy = (scene->player.pos.y);
	scene->player.x_f = (int)scene->player.rposx;
	scene->player.y_f = (int)scene->player.rposy;
	scene->player.sdist.x = 0;
	scene->player.sdist.y = 0;
	return (0);
}

int	init_delta(t_scene *scene)
{
	if (scene->player.raydir.x == 0)
		scene->player.delta.x = INFINITY;
	else
		scene->player.delta.x = sqrt(1 + (scene->player.raydir.y
					* scene->player.raydir.y) / (scene->player.raydir.x
					* scene->player.raydir.x));
	if (scene->player.raydir.y == 0)
		scene->player.delta.y = INFINITY;
	else
		scene->player.delta.y = sqrt(1 + (scene->player.raydir.x
					* scene->player.raydir.x) / (scene->player.raydir.y
					* scene->player.raydir.y));
	return (0);
}

int	init_sdist(t_scene *scene)
{
	scene->player.stepx = 0;
	scene->player.stepy = 0;
	scene->player.perpwdist = 0;
	if (scene->player.raydir.x < 0)
	{
		scene->player.stepx = -1;
		scene->player.sdist.x = (scene->player.rposx
				- scene->player.x_f) * scene->player.delta.x;
	}
	else
	{
		scene->player.stepx = 1;
		scene->player.sdist.x = (scene->player.x_f + 1.0 - scene->player.rposx)
			* scene->player.delta.x;
	}
	init_sdist_2(scene);
	return (0);
}

void	init_sdist_2(t_scene *scene)
{
	if (scene->player.raydir.y < 0)
	{
		scene->player.stepy = -1;
		scene->player.sdist.y = (scene->player.rposy
				- scene->player.y_f) * scene->player.delta.y;
	}
	else
	{
		scene->player.stepy = 1;
		scene->player.sdist.y = (scene->player.y_f + 1.0 - scene->player.rposy)
			* scene->player.delta.y;
	}
}
