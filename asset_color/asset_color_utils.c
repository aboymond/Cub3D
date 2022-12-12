#include "../cub3D.h"

int	count_nbr_color(char **tab_color)
{
	int	i;

	i = 0;
	while (tab_color[i])
	{
		i++;
	}
	if (i > 3)
	{
		free_d_tab(tab_color);
		return (-1);
	}
	return (0);
}

void	free_d_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	convert_tab_char_to_int(char *floor, char *ceiling, t_asset *asset)
{
	create_tab_integer_floor(floor, asset);
	create_tab_integer_ceiling(ceiling, asset);
}

void	create_tab_integer_floor(char *str, t_asset *asset)
{
	int		i;
	char	*fdp;
	char	*tmp_trim;
	char	**tmp;
	i = -1;
	asset->floor_color = malloc(sizeof(int) * 3);
	fdp = ft_substr(str, 2, ft_strlen(str));
	//free(str);
	tmp = ft_split(fdp, ' ');
	free(fdp);
	while (tmp[++i])
	{
		tmp_trim = ft_strtrim(tmp[i], ",");
		free(tmp[i]);
		asset->floor_color[i] = ft_atoi(tmp_trim);
	}
	free(tmp);
}

void	create_tab_integer_ceiling(char *str, t_asset *asset)
{
	int		i;
	char	*fdp;
	char	*tmp_trim;
	char	**tmp;
	i = -1;
	asset->ceiling_color = malloc(sizeof(int) * 3);
	fdp = ft_substr(str, 2, ft_strlen(str));
	//free(str);
	tmp = ft_split(fdp, ' ');
	free(fdp);
	while (tmp[++i])
	{
		tmp_trim = ft_strtrim(tmp[i], ",");
		free(tmp[i]);
		asset->ceiling_color[i] = ft_atoi(tmp_trim);
	}
	free(tmp);
}