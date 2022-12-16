#include "../cub3D.h"

int	mlx_open_win(t_scene *scene)
{
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, WIN_X, WIN_Y, "test");
	scene->img.img = mlx_new_image(scene->mlx.mlx, WIN_X, WIN_Y);
	scene->img.addr = mlx_get_data_addr(scene->img.img, &scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
	return (0);
}

// int	mlx_open_win_map(t_scene *scene)
// {
// 	scene->mlx.win = mlx_new_window(scene->mlx.mlx, WIN_X, WIN_Y, "test");
// 	scene->img.map = mlx_new_image(scene->mlx.mlx, WIN_X, WIN_Y);
// 	scene->img.addr = mlx_get_data_addr(scene->img.map, &scene->img.bits_per_pixel, &scene->img.line_length, &scene->img.endian);
// 	return (0);
// }

int	open_win(t_scene *scene)
{
	init_ray(scene);
	mini_map_init(scene);
	print_player(scene, scene->player.pos.x, scene->player.pos.y);
	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
	return (0);
}

// int	open_win_map(t_scene *scene)
// {
// 	//mini_map_init(scene);
// 	//print_player(scene, scene->player.pos.x, scene->player.pos.y);
// 	init_ray(scene);
// 	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win, scene->img.img, 0, 0);
// 	return (0);
// }
