/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:36:01 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:35:32 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	path_not_valid(t_asset *asset)
{
	int		i;
	char	**tab_path;

	i = 0;
	tab_path = ft_calloc(asset->nbr_nswe + 1, sizeof(char *));
	while (asset->asset_nswe[i])
	{
		tab_path[i] = ft_strdup(asset->asset_nswe[i]);
		free(asset->asset_nswe[i]);
		i++;
	}
	delete_p_cardinal(tab_path, asset);
	if (two_same_path(asset->tab_path) == -1)
		return (p_error("Error:\n\tthere is same path"));
	trim_space_in_path(asset->tab_path);
	return (0);
}

void	delete_p_cardinal(char **tab_path, t_asset *asset)
{
	int	i;

	i = 0;
	asset->tab_path = ft_calloc(asset->nbr_nswe + 1, sizeof(char *));
	while (tab_path[i])
	{
		asset->tab_path[i] = ft_substr(tab_path[i], 3, ft_strlen(tab_path[i]));
		free(tab_path[i]);
		i++;
	}
	free(tab_path);
}

int	two_same_path(char **path)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (path[i])
	{
		while (path[j])
		{
			if (ft_strcmp(path[i], path[j]) == 0)
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	trim_space_in_path(char	**path)
{
	int		i;
	char	*tmp;
	int		fd;

	i = 0;
	while (path[i])
	{
		tmp = ft_strdup(path[i]);
		free(path[i]);
		path[i] = ft_strtrim(tmp, " \n\t\v\r");
		free(tmp);
		fd = open(path[i], O_RDONLY);
		if (fd == -1)
		{
			close (fd);
			return (p_error("texture not valid\n"));
		}
		close(fd);
		i++;
	}
	return (0);
}
