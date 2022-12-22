#include "./cub3D.h"

int	init_ray(t_scene *scene)
{
	int		x;

	x = -1;
	scene->player.side = 0;
	while (++x < WIN_X)
	{
		init_ray_dir(scene, x);
		init_delta(scene);
		init_sdist(scene);
		dda_hit(scene);
		init_height_wall(scene);
		init_color_wall(scene);
		init_texture(scene);
		draw_wall(scene, x);

		// if (side == 0)
		// 	wallx = scene->player.pos.y + scene->player.perpwdist * scene->player.dir.y;
		// else
		// 	wallx = scene->player.pos.x + scene->player.perpwdist * scene->player.dir.x;
		// if (side == 0 && scene->player.dir.x > 0)
		// 	texx = texWidth - texx - 1;
		// if (side == 1 && scene->player.dir.x < 0)
		// 	texx = texWidth - texx - 1;

		// step = 1.0 * texHeight / scene->player.lineh;
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
	// float	tmpx;
	// float	tmpy;

	// scene->player.delta.x = sqrt(1 + ((scene->player.pos.y / scene->map.map_size) * env->ray.rdiry) /
		// (env->ray.rdirx * env->ray.rdirx));
	// tmpx = (scene->player.raydir.x * scene->player.raydir.x);
	// tmpy = (scene->player.raydir.y * scene->player.raydir.y);
	// scene->player.delta.x = sqrt(1 + (tmpy / tmpx));
	// scene->player.delta.y = sqrt(1 + (tmpx / tmpy));
	// printf("raydir x = %f, raydir y = %f\n", scene->player.raydir.x, scene->player.raydir.y);
	// if (scene->player.raydir.x == 0)
	// {
	// 	scene->player.delta.x = INFINITY;
	// 	// printf("raydir x = %f, raydir y = %f\n", scene->player.raydir.x, scene->player.raydir.y);
	// }
	// else
	// {
		scene->player.delta.x = sqrt(1 + (scene->player.raydir.y * scene->player.raydir.y) / (scene->player.raydir.x * scene->player.raydir.x));
	// printf("raydir x = %f, raydir y = %f\n", scene->player.raydir.x, scene->player.raydir.y);
	// }
	// if (scene->player.raydir.y == 0)
	// 	scene->player.delta.y = INFINITY;
	// else
		scene->player.delta.y = sqrt(1 + (scene->player.raydir.x * scene->player.raydir.x) / (scene->player.raydir.y * scene->player.raydir.y));
	
	return (0);
}

int	init_sdist(t_scene *scene)
{
	scene->player.stepx = 0;
	scene->player.stepy = 0;
	scene->player.perpwdist = 0;
		if (scene->player.raydir.x > 0)
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
		if (scene->player.raydir.y > 0)
		{
			scene->player.stepy = -1;
			scene->player.sdist.y = (scene->player.rposy
				- scene->player.y_f) * scene->player.delta.y;
		}
		else
		{
			scene->player.stepy = 1;
			scene->player.sdist.y = (scene->player.y_f + 1.0 - scene->player.rposy) * scene->player.delta.y;
		}
		return (0);
}

int	init_color_wall(t_scene *scene)
{
	// printf("dir x = %f, dir y = %f\n",scene->player.dir.x, scene->player.dir.y);
	// printf("ray dir x = %f, ray dir y = %f\n",scene->player.raydir.x, scene->player.raydir.y);
	if (scene->player.side == 0)
	{
		if (scene->player.stepx > 0 && scene->player.x_f > (int)scene->player.rposx && scene->player.side == 0)
			scene->player.color = GRE;
		if (scene->player.stepx < 0 && scene->player.x_f < (int)scene->player.rposx && scene->player.side == 0)
			scene->player.color = GREEN;
	}
	if (scene->player.stepy > 0 && scene->player.y_f > (int)scene->player.rposy && scene->player.side == 1)
		scene->player.color = RED;
	if (scene->player.stepy < 0 && scene->player.y_f < (int)scene->player.rposy && scene->player.side == 1)
		scene->player.color = BLU;
	return (0);
}

int	dda_hit(t_scene *scene)
{
	int hit;

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
		{
			// printf("map car = [%c] %s\n", scene->map.tab_map[scene->player.y_f][scene->player.x_f], scene->map.tab_map[scene->player.y_f]);
			hit = 1;
		}
	}
	if (scene->player.side == 0)
		scene->player.perpwdist = fabs((scene->player.x_f - (scene->player.rposx) + (1 - scene->player.stepx) / 2) / (scene->player.raydir.x));
	if (scene->player.side == 1)
		scene->player.perpwdist = fabs((scene->player.y_f - (scene->player.rposy) + (1 - scene->player.stepy) / 2) / (scene->player.raydir.y));
	
	return (0);
}

int	init_height_wall(t_scene *scene)
{
	// if (scene->player.side == 0)
	// 	scene->player.perpwdist = scene->player.sdist.x - scene->player.delta.x ;
	// else
	// 	scene->player.perpwdist = scene->player.sdist.y - scene->player.delta.y ;
		// printf("prep u dist = %f\n", scene->player.perpwdist);
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
	// scene->player.end = WIN_Y - scene->player.start;
	//printf("start = %d\n", scene->player.start);
	//printf("end = %d\n", scene->player.end);
	while (y < scene->player.start)
	{
		mxl_pixel_put(scene, x, y, 0xFFFFFF);
		y++;
	}
	y = scene->player.start;
	while (y < scene->player.end)
	{
		mxl_pixel_put(scene, x, y, scene->player.color);
		y++;
	}
	while (y++ < WIN_Y - 1)
		mxl_pixel_put(scene, x, y, YEL);
	return (0);
}

int texture(t_scene *scene)
{
	float   step;
	float texpos;

	step = 0.0;
	if (scene->player.side == 0)
		scene->player.wallx = scene->player.pos.y + scene->player.perpwdist * scene->player.raydir.y;
	else
		scene->player.wallx = scene->player.pos.x + scene->player.perpwdist * scene->player.raydir.x;
	if (scene->player.side == 0 && scene->player.raydir.x > 0)
		scene->player.texx = texWidth - scene->player.texx - 1;
	if (scene->player.side == 1 && scene->player.raydir.y < 0)
		scene->player.texx = texWidth - scene->player.texx - 1;

	step = 1.0 * texHeight / scene->player.lineh;
	texpos = (scene->player.start - WIN_Y / 2 + scene->player.lineh / 2) * step;
	
	return (0);
}

int init_texture(t_scene *scene)
{
	scene->asset.floor_hex = 256 * 256 * scene->asset.floor_color[0] + 256 * scene->asset.floor_color[1] + scene->asset.floor_color[2];
	scene->asset.ceil_hex = 256 * 256 * scene->asset.ceiling_color[0] + 256 * scene->asset.ceiling_color[1] + scene->asset.ceiling_color[2];
	return (0);
}
