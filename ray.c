/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:38:03 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:49:52 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wall(t_scene *scene)
{
	if (scene->player.color_card == 'W')
		tex_to_pixel(scene->asset.tex_w, scene);
	if (scene->player.color_card == 'E')
		tex_to_pixel(scene->asset.tex_e, scene);
	if (scene->player.color_card == 'S')
		tex_to_pixel(scene->asset.tex_s, scene);
	if (scene->player.color_card == 'N')
		tex_to_pixel(scene->asset.tex_n, scene);
	return (0);
}

int	dda_hit(t_scene *scene)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (scene->player.sdist.x < scene->player.sdist.y)
		{
			scene->player.sdist.x += scene->player.delta.x;
			scene->player.x_f += scene->player.stepx;
			scene->player.side = 0;
		}
		else
		{
			scene->player.sdist.y += scene->player.delta.y;
			scene->player.y_f += scene->player.stepy;
			scene->player.side = 1;
		}
		if (scene->map.tab_map[scene->player.y_f][scene->player.x_f] == '1')
			hit = 1;
	}
	init_color_wall(scene);
	init_perpwall(scene);
	return (0);
}

void	init_perpwall(t_scene *scene)
{
	if (scene->player.side == 0)
	scene->player.perpwdist = fabs((scene->player.x_f
					- (scene->player.rposx) + (1 - scene->player.stepx) / 2)
				/ (scene->player.raydir.x));
	if (scene->player.side == 1)
	scene->player.perpwdist = fabs((scene->player.y_f
					- (scene->player.rposy) + (1 - scene->player.stepy) / 2)
				/ (scene->player.raydir.y));
}
