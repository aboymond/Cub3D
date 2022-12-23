/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:52 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:34:48 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_tab(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->asset.tab_path[i])
	{
		free(scene->asset.tab_path[i]);
		i++;
	}
	i = 0;
	while (scene->asset.asset_color[i])
	{
		free(scene->asset.asset_color[i]);
		i++;
	}
	free(scene->asset.asset_color);
	free(scene->asset.tab_path);
	free(scene->asset.floor_color);
	free(scene->asset.asset_nswe);
}

void	tab_free(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str != NULL)
			free(str);
		i++;
	}
}
