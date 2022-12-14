/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:41:32 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 17:33:03 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	asset_is_valid(t_asset *asset)
{
	if (asset_p_cardinal(asset) == -1 || path_not_valid(asset) == -1)
	{
		return (p_error("Error:\n\tInvalid assets p_cardinal"));
	}
	else if (asset_color(asset) == -1)
	{
		return (p_error("Error:\n\tInvalid assets color"));
	}
	return (0);
}

int	asset_p_cardinal(t_asset *asset)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (i <= 3)
	{
		tmp = ft_calloc(3, sizeof(char));
		while (asset->asset_nswe[i][j] != ' ')
		{
			tmp[j] = asset->asset_nswe[i][j];
			j++;
		}
		if (valid_p_cardinal_name(tmp, i) == -1)
			return (-1);
		j = 0;
		i++;
	}
	return (0);
}

int	valid_p_cardinal_name(char *str, int i)
{
	if (i == 0)
	{
		if (ft_strcmp(str, "NO") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (i == 1)
	{
		if (ft_strcmp(str, "SO") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (valid_p_cardinal_name2(str, i) == -1)
	{
		return (-1);
	}
	free(str);
	return (0);
}

int	valid_p_cardinal_name2(char *str, int i)
{
	if (i == 2)
	{
		if (ft_strcmp(str, "WE") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (i == 3)
	{
		if (ft_strcmp(str, "EA") != 0)
		{
			free(str);
			return (-1);
		}
	}
	return (0);
}
