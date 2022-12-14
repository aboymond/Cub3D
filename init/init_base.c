/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:37 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:35:32 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init(t_scene *scene)
{
	init_struct_map(scene);
	init_player(scene);
	init_asset_var(scene);
}

void	init_struct_map(t_scene *scene)
{
	scene->map.tab_map = NULL;
	scene->map.len_map = 0;
}

void	init_player(t_scene *scene)
{
	scene->player.pos.x = 0;
	scene->player.pos.y = 0;
	scene->player.plane.x = 0;
	scene->player.plane.y = 0;
	scene->player.sdist.x = 0;
	scene->player.sdist.y = 0;
	scene->player.start = 0;
	scene->player.end = 0;
	scene->player.lineh = 0;
}

void	init_asset_var(t_scene *scene)
{
	scene->asset.cmpt_asset = 0;
	scene->asset.cmpt_asset_tab = 0;
	scene->asset.int_color = 0;
	scene->asset.nbr_color = 0;
	scene->asset.int_nswe = 0;
	scene->asset.nbr_nswe = 0;
	init_assets(&scene->asset);
}

void	callocmap(t_scene *scene, int haut)
{
	int	i;

	i = 0;
	if (haut <= 2)
		p_error("Error:\n\tMap non conforme");
	scene->map.tab_map = ft_calloc(haut, sizeof(char *));
	while (i < haut - 1)
	{
		scene->map.tab_map[i] = ft_calloc(scene->map.len_map + 1, sizeof(char));
		i++;
	}
}
