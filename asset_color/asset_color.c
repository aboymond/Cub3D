#include "../cub3D.h"

int	asset_color(t_asset *asset)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 0;
	while (++i <= 1)
	{
		tmp = ft_calloc(2, sizeof(char));
		while (asset->asset_color[i][j] != ' ')
		{
			tmp[j] = asset->asset_color[i][j];
			j++;
		}
		if (valid_color_name(tmp, i) == -1)
		{
			free(tmp);
			return (-1);
		}
		j = 0;
	}
	free(tmp);
	if (value_color(asset) == -1)
		return (-1);
	return (0);
}

int	valid_color_name(char *str, int i)
{
	if (i == 0)
	{
		if (ft_strcmp(str, "F") != 0)
			return (-1);
	}
	if (i == 1)
	{
		if (ft_strcmp(str, "C") != 0)
			return (-1);
	}
	return (0);
}

int	value_color(t_asset *asset)
{
	char	*c_floor;
	char	*c_ceiling;

	c_floor = ft_strdup(asset->asset_color[0]);
	c_ceiling = ft_strdup(asset->asset_color[1]);
	if (valid_color(c_floor) == -1 || valid_color(c_ceiling) == -1)
		return (-1);
	return (0);
}

int	valid_color(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == '-')
			break ;
		i++;
	}
	if (color_into_d_tab(&str[i]) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int	color_into_d_tab(char *str)
{
	char	**trim_str;
	int		i;

	i = -1;
	trim_str = ft_split(str, ' ');
	if (count_nbr_color(trim_str) == -1)
		return (-1);
	while (trim_str[++i])
		trim_str[i] = ft_strtrim(trim_str[i], ",");
	if (is_a_digit(trim_str) == -1)
		return (-1);
	if (color_rvb(trim_str) == -1)
		return (-1);
	free_d_tab(trim_str);
	return (0);
}
