#include "./cub3D.h"

int	init_ray(t_scene *scene)
{
	float i;

	i = 0;
	while (i < 50)
	{
		mxl_pixel_put(scene, (scene->player.dir.x * i) + scene->player.pos.x, (scene->player.dir.y * i) + scene->player.pos.y, RED);
		i++;
	}

	// scene->ray.x = (sqrt(1 + (scene->player.dir.y^2/scene->player.dir.x^2)));
	// scene->ray.x = (sqrt(1 + (scene->player.dir.x^2/scene->player.dir.y^2)));
	return (0);
}