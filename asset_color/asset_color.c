#include "../cube3d.h"

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
			j++;
		}
		if (valid_color_name(tmp, i) == -1)
			return (-1);
		free(tmp);
		j = 0;
		i++;
	}
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