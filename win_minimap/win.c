/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:39:15 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 15:39:17 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	mlx_open_win(t_scene *scene)
{
	scene->mlx.win = mlx_new_window(scene->mlx.mlx, WIN_X, WIN_Y, "test");
	return (0);
}

int	open_win(t_scene *scene)
{
	scene->img = ftmlx_new_img(scene->mlx.mlx, WIN_X, WIN_Y);
	if (scene->img == NULL)
	{
		p_error("open_win scene->img");
		exit(1);
	}
	init_ray(scene);
	mini_map_init(scene);
	print_player(scene, (scene->player.pos.x)
		* scene->map.map_size, (scene->player.pos.y) * scene->map.map_size);
	mlx_put_image_to_window(scene->mlx.mlx, scene->mlx.win,
		scene->img->img, 0, 0);
	ftmlx_free_img(scene->mlx.mlx, scene->img);
	return (0);
}
