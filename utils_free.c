/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:37:42 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 15:37:47 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->asset.tab_path[i])
	{
		free(scene->asset.tab_path[i]);
		i++;
	}
	free(scene->asset.tab_path);
	i = 0;
}
