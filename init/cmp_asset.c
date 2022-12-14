/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:47 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 16:35:32 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	compt_asset(char *args, t_scene *scene)
{
	char	*tmp;
	int		fd;

	fd = open(args, O_RDONLY);
	tmp = get_next_line(fd);
	nb_of_asset(tmp, &scene->asset);
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL || nb_of_asset(tmp, &scene->asset) == 1)
		{
			free(tmp);
			break ;
		}
	}
	if (scene->asset.nbr_nswe != 4 || scene->asset.nbr_color != 2)
		return (p_error("Error:\n\tInvalid assets"));
	malloc_asset(&scene->asset);
	close (fd);
	return (0);
}

int	nb_of_asset(char *line, t_asset *asset)
{
	int	i;

	i = -1;
	if (line == NULL)
		return (p_error("Error:\n\tMap == NULL"));
	while (line[++i] != '\0')
	{
		if (ft_strchr("NSWE", line[i]))
		{
			asset->nbr_nswe++;
			return (0);
		}
		else if (ft_strchr("FC", line[i]))
		{
			asset->nbr_color++;
			return (0);
		}
		else if (ft_strchr("01", line[i]))
			return (1);
	}
	return (0);
}

int	malloc_asset(t_asset *asset)
{
	asset->asset_color = ft_calloc(asset->nbr_color + 1, sizeof(char *));
	asset->asset_nswe = ft_calloc(asset->nbr_nswe + 1, sizeof(char *));
	return (0);
}
