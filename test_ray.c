#include "./cub3D.h"

void	drawline(int x2, int y2, t_scene *scene, int color)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (double)x2 - scene->player.pos.x / scene->map.map_size
		* scene->map.map_size;
	delta_y = (double)y2 - scene->player.pos.y / scene->map.map_size
		* scene->map.map_size;
	pixels = sqrt((delta_x * delta_x) +(delta_y * delta_y));
	pixel_x = scene->player.pos.x / scene->map.map_size * scene->map.map_size;
	pixel_y = scene->player.pos.y / scene->map.map_size * scene->map.map_size;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		mxl_pixel_put(scene, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

int	init_ray(t_scene *scene)
{
	float i;
	float y;
	// float	tmpx;
	// float	tmpy;
	int		stepx;
	int		stepy;
	//int		hit;
	int		side;
	int		x;

	stepx = 0;
	stepy = 0;
	side = 0;
	x = 0;
	i = 0;
	y = 0;
	// scene->player.plane.x = 0;
	// scene->player.plane.y = FOV;
	// tmpx = (scene->player.dir.x / scene->map.map_size) * (scene->player.dir.x / scene->map.map_size);
	// tmpy = (scene->player.dir.y / scene->map.map_size) * (scene->player.dir.y / scene->map.map_size);
	// scene->player.x_f = floorf(scene->player.pos.x / scene->map.map_size);
	// scene->player.y_f = floorf(scene->player.pos.y / scene->map.map_size);
	//printf ("xf = %d, xy = %d, x = %f, y = %f \n", scene->player.x_f, scene->player.y_f, scene->player.pos.x, scene->player.pos.y);
	// scene->player.delta.x = sqrt(1 + (tmpy / tmpx));
	// scene->player.delta.y = sqrt(1 + (tmpx / tmpy));
	//scene->img.img = mlx_new_image(scene->mlx.mlx, WIN_X, WIN_Y);
	while (x < WIN_X)
	{
		scene->player.cam.x = 2 * x / (double)WIN_X - 1;
		scene->player.raydir.x = scene->player.dir.x + scene->player.plane.x * scene->player.cam.x;
		scene->player.raydir.y = scene->player.dir.y + scene->player.plane.y * scene->player.cam.x;
		//mxl_pixel_put(scene, scene->player.raydir.x, scene->player.raydir.y, RED);
		// printf("camx = %f\n", scene->player.cam.x);
		// printf("rayx = %f\n", scene->player.raydir.x);
		// printf("rayy = %f\n", scene->player.raydir.y);
		x++;

	}
	while (++i < 200)
		mxl_pixel_put(scene, 0 + i, 20 + i, GREEN);
	// if (scene->player.dir.x < 0)
	// {
	// 	stepx = -1;
	// 	scene->player.sdist.x = ((scene->player.pos.x / scene->map.map_size) - scene->player.x_f) * scene->player.delta.x;
	// 	printf("pos x = %f\n", scene->player.pos.x);
	// }
	// else
	// {
	// 	stepx = 1;
	// 	scene->player.sdist.x = (scene->player.x_f + 1 - (scene->player.pos.x / scene->map.map_size)) * scene->player.delta.x;
	// }
	// if (scene->player.dir.y < 0)
	// {
	// 	stepy = -1;
	// 	scene->player.sdist.y = ((scene->player.pos.y / scene->map.map_size) - scene->player.y_f) * scene->player.delta.y;
	// }
	// else
	// {
	// 	stepy = 1;
	// 	scene->player.sdist.y = (scene->player.y_f + 1 - (scene->player.pos.y / scene->map.map_size)) * scene->player.delta.y;
	// }
	// hit = 0;
	// printf("side dist x = %f y = %f\n", scene->player.sdist.x, scene->player.sdist.y);
	// //printf("scene truc = [%c]\n", scene->map.tab_map[scene->player.y_f][scene->player.x_f]);
	// while (hit == 0)
	// {
	// 	//printf("oieurghoiusehrgon\n");
	// 	if (scene->player.sdist.x < scene->player.sdist.y)
	// 	{
	// 		scene->player.sdist.x += scene->player.delta.x;
	// 		scene->player.x_f += stepx;
	// 		side = 0;

	// 	}
	// 	else
	// 	{
	// 		scene->player.sdist.y += scene->player.delta.y;
	// 		scene->player.y_f += stepy;
	// 		//mxl_pixel_put(scene, scene->player.x_f * scene->map.map_size, scene->player.y_f * scene->map.map_size, RED);
	// 		side = 1;
	// 	}
	// 	if (scene->map.tab_map[scene->player.y_f][scene->player.x_f] != '0')
	// 	{
	// 		// printf("rayon eclate avec distx = %f\n", scene->player.sdist.x);
	// 		// printf("rayon eclate avec disty = %f\n", scene->player.sdist.y);

	// 		hit = 1;
	// 	}
	// }
	// if (side == 0)
	// 	scene->player.perpwdist = ((scene->player.x_f - (scene->player.pos.x / scene->map.map_size) + (1 - stepx) / 2) / (scene->player.dir.x));
	// else
	// 	scene->player.perpwdist = ((scene->player.y_f - (scene->player.pos.y / scene->map.map_size) + (1 - stepy) / 2) / (scene->player.dir.y));

	// while (i < scene->player.perpwdist * scene->map.map_size)
	// {
	// 	//printf("test = %f", scene->player.x_f / scene->map.map_size);
	// 	mxl_pixel_put(scene, (scene->player.dir.x * i) + scene->player.pos.x, (scene->player.dir.y * i) + scene->player.pos.y, RED);
	// 	//mxl_pixel_put(scene, (scene->player.raydir.x * i) + scene->player.pos.x, (scene->player.raydir.y * i) + scene->player.pos.y, RED);
	// 	i++;
	// }
	// printf("dir x = %f\n", scene->player.dir.x);
	// printf("dir y = %f\n", scene->player.dir.y);
	// printf("perp = %f\n", scene->player.perpwdist);
	// while (i < 20)
	// {
	// 	i++;
	// }
	return (0);
}

int	init_miniray(t_scene *scene)
{
	float i;
	float y;
	float	tmpx;
	float	tmpy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		x;

	side = 0;
	x = 0;
	i = 0;
	y = 0;
	scene->player.plane.x = 0;
	scene->player.plane.y = FOV;
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
	// printf("side dist x = %f y = %f\n", scene->player.sdist.x, scene->player.sdist.y);
	//printf("scene truc = [%c]\n", scene->map.tab_map[scene->player.y_f][scene->player.x_f]);
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
		if (scene->map.tab_map[scene->player.y_f][scene->player.x_f] != '0')
		{
			hit = 1;
		}
	}
	// float angle = atan2(scene->player.dir.y, scene->player.dir.x);
	// float angled = angle * 180.0 / M_PI;
	// printf("angle = %f\n", angle);
	// printf("angled = %f\n", angled);
	// while (angled < FOV)
	// {
		if (side == 0)
			scene->player.perpwdist = ((scene->player.x_f - (scene->player.pos.x / scene->map.map_size) + (1 - stepx) / 2) / (scene->player.dir.x));
		else
			scene->player.perpwdist = ((scene->player.y_f - (scene->player.pos.y / scene->map.map_size) + (1 - stepy) / 2) / (scene->player.dir.y));
		printf("perp = %f\n", scene->player.perpwdist * scene->map.map_size);
		printf("x = %f\n", (scene->player.pos.x + scene->player.perpwdist * scene->player.dir.x) * scene->map.map_size);
		printf("y = %f\n", (scene->player.pos.y + scene->player.perpwdist * scene->player.dir.y) * scene->map.map_size);
		// int j = 0;
		// while (j < WIN_X)
		// {
			// drawline(scene->player.perpwdist * scene->map.map_size + scene->player.pos.x, scene->player.perpwdist * scene->map.map_size + scene->player.pos.y, scene, RED);
			while (i < scene->player.perpwdist * scene->map.map_size)
			{
				if (i < scene->player.perpwdist * scene->map.map_size)
					mxl_pixel_put(scene, (scene->player.dir.x * i) + scene->player.pos.x, (scene->player.dir.y * i) + scene->player.pos.y, RED);
			// 	//printf("test = %f", scene->player.x_f / scene->map.map_size);
			// 	//mxl_pixel_put(scene, (scene->player.raydir.x * i) + scene->player.pos.x, (scene->player.raydir.y * i) + scene->player.pos.y, RED);
				i++;
			}
			// j++;
		// }

	// }
	return (0);
}
