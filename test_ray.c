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

	// float	tmpx;
	// float	tmpy;

	//int		hit;
	float	tmpx;
	float	tmpy;
	//float	wallx;
	//int		texx;
	//float	step;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		x;
	int		y;


	x = -1;
	side = 0;
	while (++x < WIN_X)
	{
		scene->player.cam.x = 2 * x / (double)WIN_X - 1;
		scene->player.raydir.x = scene->player.dir.x + scene->player.plane.x * scene->player.cam.x;
		scene->player.raydir.y = scene->player.dir.y + scene->player.plane.y * scene->player.cam.x;
		scene->player.x_f = floorf(scene->player.pos.x / scene->map.map_size);
		scene->player.y_f = floorf(scene->player.pos.y / scene->map.map_size);
		if (scene->player.raydir.y == 0)
			scene->player.delta.x = 0;
		else if (scene->player.raydir.x == 0)
			scene->player.delta.x = 1;
		else
		{
			tmpx = (scene->player.raydir.x * scene->player.raydir.x);
			tmpy = (scene->player.raydir.y * scene->player.raydir.y);
			scene->player.delta.x = sqrt(1 + (tmpy / tmpx));
		}
		if (scene->player.raydir.x == 0)
			scene->player.delta.y = 0;
		else if (scene->player.raydir.x == 0)
			scene->player.delta.y = 1;
		else
		{
			tmpx = (scene->player.raydir.x * scene->player.raydir.x);
			tmpy = (scene->player.raydir.y * scene->player.raydir.y);
			scene->player.delta.y = sqrt(1 + (tmpx / tmpy));
		}
		if (scene->player.dir.x < 0)
		{
			stepx = -1;
			scene->player.sdist.x = ((scene->player.pos.x / scene->map.map_size) - scene->player.x_f) * scene->player.delta.x;
			// printf("pos x = %f\n", scene->player.pos.x);
		}
		else
		{
			stepx = 1;
			scene->player.sdist.x = (scene->player.x_f + 1 - (scene->player.pos.x / scene->map.map_size)) * scene->player.delta.x;
		}
		if (scene->player.dir.y < 0)
		{
			stepy = -1;
			scene->player.sdist.y = ((scene->player.pos.y / scene->map.map_size) - scene->player.y_f) * scene->player.delta.y;
		}
		else
		{
			stepy = 1;
			scene->player.sdist.y = (scene->player.y_f + 1 - (scene->player.pos.y / scene->map.map_size)) * scene->player.delta.y;
		}
		hit = 0;
		while (hit == 0)
		{
			//printf("oieurghoiusehrgon\n");
			if (scene->player.sdist.x < scene->player.sdist.y)
			{
				scene->player.sdist.x += scene->player.delta.x;
				scene->player.x_f += stepx;
				side = 0;

			}
			else
			{
				scene->player.sdist.y += scene->player.delta.y;
				scene->player.y_f += stepy;
				//mxl_pixel_put(scene, scene->player.x_f * scene->map.map_size, scene->player.y_f * scene->map.map_size, RED);
				side = 1;
			}
			if (scene->map.tab_map[scene->player.y_f][scene->player.x_f] == '1')
			{
				hit = 1;
			}
		}
		// if (side == 0)
		// 	scene->player.perpwdist = (scene->player.sdist.x - scene->player.delta.x);
		// else
		// 	scene->player.perpwdist = (scene->player.sdist.y - scene->player.delta.y);		
		if (side == 0)
			scene->player.perpwdist = ((float)scene->player.x_f - scene->player.pos.x  / scene->map.map_size + (1 - (float)stepx) / 2) / scene->player.dir.x;
		else
			scene->player.perpwdist = ((float)scene->player.y_f - scene->player.pos.y  / scene->map.map_size + (1 - (float)stepy) / 2) / scene->player.dir.y;
		if (side == 0 && scene->player.dir.x < 0)
			scene->player.color = GRE;
		if (side == 0 && scene->player.dir.x >= 0)
			scene->player.color = GREEN;
		if (side == 1 && scene->player.dir.y < 0)
			scene->player.color = RED;
		if (side == 1 && scene->player.dir.y >= 0)
			scene->player.color = BLU;
		// if (side == 0)
		// 	wallx = scene->player.pos.y + scene->player.perpwdist * scene->player.dir.y;
		// else
		// 	wallx = scene->player.pos.x + scene->player.perpwdist * scene->player.dir.x;
		// if (side == 0 && scene->player.dir.x > 0)
		// 	texx = texWidth - texx - 1;
		// if (side == 1 && scene->player.dir.x < 0)
		// 	texx = texWidth - texx - 1;

		// step = 1.0 * texHeight / scene->player.lineh;

		scene->player.lineh = (int)(WIN_Y / scene->player.perpwdist);
		scene->player.start = -scene->player.lineh / 2 + WIN_Y / 2;
		if (scene->player.start < 0)
			scene->player.start = 0;
		scene->player.end = scene->player.lineh / 2 + WIN_Y / 2;
		if (scene->player.end >= WIN_Y || scene->player.end < 0)
			scene->player.end = WIN_Y - 1;
		y = 0;
		// scene->player.end = WIN_Y - scene->player.start;
		printf("start = %d\n", scene->player.start);
		printf("end = %d\n", scene->player.end);
		// while (++y < scene->player.start)
		// {
		// 	mxl_pixel_put(scene, x, y, YEL);
		// 	y++;
		// }
		y = scene->player.start;
		while (y < scene->player.end)
		{
			mxl_pixel_put(scene, x, y, scene->player.color);
			y++;
		}
		// while (y++ < WIN_Y)
		// 	mxl_pixel_put(scene, x, y, YEL);

	}
	return (0);
}

int	init_miniray(t_scene *scene)
{
	// float i;
	float	tmpx;
	float	tmpy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		x;
	int		y;


	side = 0;
	x = 0;
	y = 0;
	// i = 0;
	scene->player.x_f = floorf(scene->player.pos.x / scene->map.map_size);
	scene->player.y_f = floorf(scene->player.pos.y / scene->map.map_size);
	tmpx = (scene->player.dir.x / scene->map.map_size) * (scene->player.dir.x / scene->map.map_size);
	tmpy = (scene->player.dir.y / scene->map.map_size) * (scene->player.dir.y / scene->map.map_size);
	scene->player.delta.x = sqrt(1 + (tmpy / tmpx));
	scene->player.delta.y = sqrt(1 + (tmpx / tmpy));
	if (scene->player.dir.x < 0)
	{
		stepx = -1;
		scene->player.sdist.x = ((scene->player.pos.x / scene->map.map_size) - scene->player.x_f) * scene->player.delta.x;
		// printf("pos x = %f\n", scene->player.pos.x);
	}
	else
	{
		stepx = 1;
		scene->player.sdist.x = (scene->player.x_f + 1 - (scene->player.pos.x / scene->map.map_size)) * scene->player.delta.x;
	}
	if (scene->player.dir.y < 0)
	{
		stepy = -1;
		scene->player.sdist.y = ((scene->player.pos.y / scene->map.map_size) - scene->player.y_f) * scene->player.delta.y;
	}
	else
	{
		stepy = 1;
		scene->player.sdist.y = (scene->player.y_f + 1 - (scene->player.pos.y / scene->map.map_size)) * scene->player.delta.y;
	}
	hit = 0;
	while (hit == 0)
	{
		//printf("oieurghoiusehrgon\n");
		if (scene->player.sdist.x < scene->player.sdist.y)
		{
			scene->player.sdist.x += scene->player.delta.x;
			scene->player.x_f += stepx;
			side = 0;

		}
		else
		{
			scene->player.sdist.y += scene->player.delta.y;
			scene->player.y_f += stepy;
			//mxl_pixel_put(scene, scene->player.x_f * scene->map.map_size, scene->player.y_f * scene->map.map_size, RED);
			side = 1;
		}
		if (scene->map.tab_map[scene->player.y_f][scene->player.x_f] == '1')
		{
			hit = 1;
		}
	}

	if (side == 0)
		scene->player.perpwdist = ((float)scene->player.x_f - scene->player.pos.x  / scene->map.map_size + (1 - (float)stepx) / 2) / scene->player.dir.x;
	else
		scene->player.perpwdist = ((float)scene->player.y_f - scene->player.pos.y  / scene->map.map_size + (1 - (float)stepy) / 2) / scene->player.dir.y;
	if (side == 0 && scene->player.dir.x < 0)
		scene->player.color = GRE;
	if (side == 0 && scene->player.dir.x >= 0)
		scene->player.color = GREEN;
	if (side == 1 && scene->player.dir.y < 0)
		scene->player.color = RED;
	if (side == 1 && scene->player.dir.y >= 0)
		scene->player.color = BLU;

	x = 0;
	while (x < WIN_X)
	{
		scene->player.lineh = (int)(WIN_Y / scene->player.perpwdist);
		scene->player.start = -scene->player.lineh / 2 + WIN_Y / 2;
		if (scene->player.start < 0)
			scene->player.start = 0;
		scene->player.end = scene->player.lineh / 2 + WIN_Y / 2;
		if (scene->player.end >= WIN_Y)
			scene->player.end = WIN_Y - 1;
		y = 0;
		while (++y < scene->player.start)
			mxl_pixel_put(scene, x, y, YEL);
		while (y++ < scene->player.end)
		{
			mxl_pixel_put(scene, x, y, scene->player.color);
		}
		while (++y < WIN_Y)
			mxl_pixel_put(scene, x, y, YEL);
		x++;
	}
	return (0);
}
