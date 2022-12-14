/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:42 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:35:17 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_asset(char *args, t_scene *scene)
{
	char	*tmp;
	char	*trimmed;
	int		fd;

	fd = open(args, O_RDONLY);
	compt_asset(args, scene);
	tmp = get_next_line(fd);
	trimmed = ft_strtrim(tmp, " \n\t\v\r");
	free(tmp);
	if (trimmed == NULL || check_asset(scene, trimmed) == 1)
	{
		free (trimmed);
		close (fd);
		return (1);
	}
	scene->asset.cmpt_asset_tab++;
	if (init_asset_2(trimmed, scene, tmp, fd) == 1)
		return (1);
	return (0);
}

int	init_asset_2(char *trimmed, t_scene *scene, char *tmp, int fd)
{
	while (trimmed)
	{
		free(trimmed);
		tmp = get_next_line(fd);
		trimmed = ft_strtrim(tmp, " \n\t\v\r");
		free(tmp);
		if (trimmed == NULL || check_asset(scene, trimmed) == 1)
		{
			free (trimmed);
			close (fd);
			return (1);
		}
		scene->asset.cmpt_asset_tab++;
	}
	free (trimmed);
	close (fd);
	return (0);
}

int	check_asset(t_scene *scene, char *line)
{
	if (init_asset_tab(scene, line) == 1)
	{
		if (!scene->asset.asset_color || !scene->asset.asset_nswe)
		{
			p_error("Error: \n\tMap asset = NULL !");
		}
		return (1);
	}
	return (0);
}

int	init_asset_tab(t_scene *scene, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("NSWE", line[i]))
		{
			scene->asset.asset_nswe[scene->asset.int_nswe] = ft_strdup(line);
			scene->asset.int_nswe++;
			scene->asset.cmpt_asset++;
			return (0);
		}
		if (ft_strchr("FC", line[i]))
		{
			scene->asset.asset_color[scene->asset.int_color] = ft_strdup(line);
			scene->asset.int_color++;
			scene->asset.cmpt_asset++;
			return (0);
		}
		if (ft_strchr("01", line[i]))
			return (1);
	}
	return (0);
}
