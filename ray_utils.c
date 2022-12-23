/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:37:01 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:38:56 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3D.h"

int	texture(t_scene *scene)
{
	float	wallx;

	if (scene->player.side == 0)
		wallx = scene->player.rposy + scene->player.perpwdist
			* scene->player.raydir.y;
	else
		wallx = scene->player.rposx + scene->player.perpwdist
			* scene->player.raydir.x;
	wallx -= floor(wallx);
	scene->ptr.x = (int)(wallx * (float)64);
	if (scene->player.side == 0 && scene->player.raydir.x > 0)
		scene->ptr.x = 64 - scene->ptr.x - 1;
	if (scene->player.side == 1 && scene->player.raydir.y < 0)
		scene->ptr.x = 64 - scene->ptr.x - 1;
	scene->ptr.step = 1.0 * 64 / scene->player.lineh;
	scene->ptr.texpos = (scene->player.start - WIN_Y / 2
			+ scene->player.lineh / 2) * scene->ptr.step - 1;
	return (0);
}

int	convert_rvb_to_hexa(t_scene *scene)
{
	scene->asset.floor_hex = 256 * 256 * scene->asset.floor_color[0] + 256
		* scene->asset.floor_color[1] + scene->asset.floor_color[2];
	scene->asset.ceil_hex = 256 * 256 * scene->asset.ceiling_color[0] + 256
		* scene->asset.ceiling_color[1] + scene->asset.ceiling_color[2];
	return (0);
}

int	*ftmlx_img_get_pxl(t_img *img, int x, int y)
{
	if (img->h <= y || img->w <= x || x < 0 || y < 0)
		return (NULL);
	return ((int *)(img->addr + (img->line_length * y + x
			* (img->bits_per_pixel / 8))));
}

void	tex_to_pixel(t_img *tex, t_scene *scene)
{
	int	*ptr;

	ptr = ftmlx_img_get_pxl(tex, scene->ptr.x, scene->ptr.y);
	if (ptr == NULL)
		scene->ptr.color = BLU;
	else
		scene->ptr.color = *ptr;
}

int	init_color_wall(t_scene *scene)
{
	if (scene->player.side == 0)
	{
		if (scene->player.stepx > 0 && scene->player.x_f
			> (int)scene->player.rposx && scene->player.side == 0)
			scene->player.color_card = 'W';
		if (scene->player.stepx < 0 && scene->player.x_f
			< (int)scene->player.rposx && scene->player.side == 0)
			scene->player.color_card = 'E';
	}
	if (scene->player.side == 1)
	{
		if (scene->player.stepy > 0 && scene->player.y_f
			> (int)scene->player.rposy && scene->player.side == 1)
			scene->player.color_card = 'S';
		if (scene->player.stepy < 0 && scene->player.y_f
			< (int)scene->player.rposy && scene->player.side == 1)
			scene->player.color_card = 'N';
	}
	return (0);
}
