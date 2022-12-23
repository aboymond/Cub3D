/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:38:12 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 17:50:30 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	scene->mlx.mlx = mlx_init();
	erreur_args(argc, argv);
	init(scene);
	if (init_asset(argv[1], scene) == 1)
		asset_is_valid(&scene->asset);
	else
		return (0);
	compt_map(argv[1], scene);
	map_is_close(scene);
	search_player(scene);
	if (load_assets(scene->mlx.mlx, &scene->asset))
	{
		p_error("load assets failed");
		return (1);
	}
	mlx_open_win(scene);
	mlx_loop_hook(scene->mlx.mlx, open_win, scene);
	mlx_hook(scene->mlx.win, 02, 1L << 0, key_move, scene);
	mlx_hook(scene->mlx.win, 17, 1L << 0, ft_close, scene);
	mlx_loop(scene->mlx.mlx);
	free_main(scene);
	return (0);
}

int	free_main(t_scene *scene)
{
	int	i;

	i = -1;
	while (scene->map.tab_map[++i])
		free(scene->map.tab_map[i]);
	i = -1;
	while (scene->asset.tab_path[++i])
		free(scene->asset.tab_path[i]);
	i = -1;
	while (scene->asset.asset_color[++i])
		free(scene->asset.asset_color[i]);
	free_assets(scene->mlx.mlx, &scene->asset);
	free(scene->asset.asset_color);
	free(scene->asset.asset_nswe);
	free(scene->asset.ceiling_color);
	free(scene->asset.floor_color);
	free(scene->asset.tab_path);
	free(scene->map.tab_map);
	free(scene);
	exit (0);
}

int	key_esc(int keycode, t_scene *scene)
{
	(void)scene;
	if (keycode == ESC)
		ft_close();
	return (0);
}

int	ft_close(void)
{
	exit(0);
	return (0);
}
