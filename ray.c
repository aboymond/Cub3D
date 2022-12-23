#include "cub3D.h"

typedef struct s_dda
{
	t_vec2	pos;
	float	dist;
	char	face;
}	t_dda;

int	init_height_wall(t_scene *scene, t_dda dda)
{
	t_vec2	lh;

	scene->player.lineh = fabs(WIN_Y / dda.dist);
	scene->player.lineh -= WIN_Y / 50;
	scene->player.start = (-1 * (scene->player.lineh) / 2 + WIN_Y / 2);
	scene->player.end = scene->player.lineh / 2 + WIN_Y / 2;
	if (scene->player.start < 0)
		scene->player.start = 0;
	if (scene->player.end >= WIN_Y)
		scene->player.end = WIN_Y - 1;
	return (0);
}

int	init_ray_2(t_scene *scene, int x)
{
	t_dda	dda;
	t_vec2	lh;

	lh.x = scene->player.start;
	lh.y = scene->player.end;
	dda.pos.x = scene->player.x_f;
	dda.pos.y = scene->player.y_f;
	dda.dist = scene->player.perpwdist;
	dda.face = scene->player.color_card;
	init_height_wall(scene, dda);
	texture(scene);
	convert_rvb_to_hexa(scene);
	draw_wall(scene, x);
	return (0);
}
