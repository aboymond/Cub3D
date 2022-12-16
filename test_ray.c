#include "./cub3D.h"

// void	drawline(int x2, int y2, t_scene *scene, int color)
// {
// 	double	pixel_x;
// 	double	pixel_y;
// 	double	delta_x;
// 	double	delta_y;
// 	int		pixels;

// 	delta_x = (double)x2 - scene->player.pos.x / scene->map.map_size
// 		* scene->map.map_size;
// 	delta_y = (double)y2 - scene->player.pos.y / scene->map.map_size
// 		* scene->map.map_size;
// 	pixels = sqrt((delta_x * delta_x) +(delta_y * delta_y));
// 	pixel_x = scene->player.pos.x / scene->map.map_size * scene->map.map_size;
// 	pixel_y = scene->player.pos.y / scene->map.map_size * scene->map.map_size;
// 	delta_x /= pixels;
// 	delta_y /= pixels;
// 	while (pixels)
// 	{
// 		mxl_pixel_put(scene, pixel_x, pixel_y, color);
// 		pixel_x += delta_x;
// 		pixel_y += delta_y;
// 		pixels--;
// 	}
// }

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
		init_color_wall(scene);
		dda_hit(scene);
		init_height_wall(scene);
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
			hit = 1;
		}
	}
	if (scene->player.side == 0)
		scene->player.perpwdist = scene->player.sdist.x - scene->player.delta.x ;
	else
		scene->player.perpwdist = scene->player.sdist.y - scene->player.delta.y ;
	return (0);
}

int	init_ray_dir(t_scene *scene, int x)
{
	scene->player.cam.x = 2 * x / (float)WIN_X - 1;
	scene->player.raydir.x = scene->player.dir.x + scene->player.plane.x * scene->player.cam.x;
	scene->player.raydir.y = scene->player.dir.y + (scene->player.plane.y * scene->player.cam.x);
	scene->player.x_f = (int)(scene->player.pos.x / scene->map.map_size);
	scene->player.y_f = (int)(scene->player.pos.y / scene->map.map_size);
	return (0);
}

int	init_delta(t_scene *scene)
{
	// float	tmpx;
	// float	tmpy;

	//tmpx = (scene->player.raydir.x * scene->player.raydir.x);
	//tmpy = (scene->player.raydir.y * scene->player.raydir.y);

	if (scene->player.raydir.x == 0)
		scene->player.delta.x = INFINITY;
	else
		scene->player.delta.x = fabs(1 / scene->player.raydir.x);
	if (scene->player.raydir.y == 0)
		scene->player.delta.y = INFINITY;
	else
		scene->player.delta.y = fabs(1 / scene->player.raydir.y);
	return (0);
}

int	init_sdist(t_scene *scene)
{
		if (scene->player.dir.x < 0)
		{
			scene->player.stepx = -1;
			scene->player.sdist.x = ((scene->player.pos.x / scene->map.map_size)
				- scene->player.x_f) * scene->player.delta.x;
		}
		else
		{
			scene->player.stepx = 1;
			scene->player.sdist.x = (scene->player.x_f + 1 - (float)(scene->player.pos.x / scene->map.map_size)) * scene->player.delta.x;
		}
		if (scene->player.dir.y < 0)
		{
			scene->player.stepy = -1;
			scene->player.sdist.y = ((float)(scene->player.pos.y / scene->map.map_size)
				- scene->player.y_f) * scene->player.delta.y;
		}
		else
		{
			scene->player.stepy = 1;
			scene->player.sdist.y = (scene->player.y_f + 1 - (float)(scene->player.pos.y
				 / scene->map.map_size)) * scene->player.delta.y;
		}
		return (0);
}

int	init_color_wall(t_scene *scene)
{
	printf("dir x = %f, dir y = %f\n",scene->player.dir.x, scene->player.dir.y);
	printf("ray dir x = %f, ray dir y = %f\n",scene->player.raydir.x, scene->player.raydir.y);
	if (scene->player.side == 0 && scene->player.dir.x < 0)
		scene->player.color = GRE;
	if (scene->player.side == 0 && scene->player.dir.x > 0)
		scene->player.color = GREEN;
	if (scene->player.side == 1 && scene->player.dir.y < 0)
		scene->player.color = RED;
	if (scene->player.side == 1 && scene->player.dir.y > 0)
		scene->player.color = BLU;
	return (0);
}

int	init_height_wall(t_scene *scene)
{
	scene->player.lineh = (WIN_Y / scene->player.perpwdist);
	scene->player.start = -scene->player.lineh / 2 + WIN_Y / 2;
	if (scene->player.start < 0)
		scene->player.start = 0;
	scene->player.end = scene->player.lineh / 2 + WIN_Y / 2;
	if (scene->player.end >= WIN_Y || scene->player.end < 0)
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
		mxl_pixel_put(scene, x, y, YEL);
		y++;
	}
	y = scene->player.start;
	while (y < scene->player.end)
	{
		mxl_pixel_put(scene, x, y, scene->player.color);
		y++;
	}
	while (y++ < WIN_Y)
		mxl_pixel_put(scene, x, y, YEL);
	return (0);
}