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
	scene->player.raydir.x = -scene->player.dir.x + scene->player.plane.x * scene->player.cam.x;
	scene->player.raydir.y = -scene->player.dir.y + scene->player.plane.y * scene->player.cam.x;
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
		scene->player.delta.x = sqrt(1 + (scene->player.raydir.y * scene->player.raydir.y) / (scene->player.raydir.x * scene->player.raydir.x));
	if (scene->player.raydir.y == 0)
		scene->player.delta.y = INFINITY;
	else
		scene->player.delta.y = sqrt(1 + (scene->player.raydir.x * scene->player.raydir.x) / (scene->player.raydir.y * scene->player.raydir.y));
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
		scene->player.sdist.x = (scene->player.x_f + 1.0 - scene->player.rposx) * scene->player.delta.x;
	}
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
	return (0);
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
	if (scene->player.side == 0)
		scene->player.perpwdist = fabs((scene->player.x_f
					- (scene->player.rposx) + (1 - scene->player.stepx) / 2)
				/ (scene->player.raydir.x));
	if (scene->player.side == 1)
		scene->player.perpwdist = fabs((scene->player.y_f
					- (scene->player.rposy) + (1 - scene->player.stepy) / 2)
				/ (scene->player.raydir.y));
	return (0);
}

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
