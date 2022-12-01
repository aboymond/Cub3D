#include "../cub3D.h"

int	asset_color(t_asset *asset)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (i <= 1)
	{
		tmp = ft_strdup("");
		while (asset->asset_color[i][j] != ' ')
		{
			tmp[j] = asset->asset_color[i][j];
			printf("tmp[%d] = %c\n", j, tmp[j]);
			j++;
		}
		if (valid_color_name(tmp, i) == -1)
			return (-1);
		j = 0;
		i++;
	}
	if (value_color(asset) == -1)
		return (-1);
	return (0);
}

int	valid_color_name(char *str, int i)
{
	if (i == 0)
	{
		if (ft_strcmp(str, "F") != 0)
		{
			free(str);
			return (-1);
		}
	}
	if (i == 1)
	{
		if (ft_strcmp(str, "C") != 0)
		{
			free(str);
			return (-1);
		}
	}
	free(str);
	return (0);
}

int	value_color(t_asset *asset)
{
	char	*c_floor;
	char	*c_ceiling;

	c_floor = ft_strdup(asset->asset_color[0]);
	c_ceiling = ft_strdup(asset->asset_color[1]);
	if (valid_color(c_floor) == -1 /*|| valid_color(c_ceiling) == -1*/)
		return (-1);
	return (0);
}

int valid_color(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str) != 0)
			printf("test\n");
		str++;
	}
	return (0);
}