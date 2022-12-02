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
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
