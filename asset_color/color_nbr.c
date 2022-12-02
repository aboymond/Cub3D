#include "../cub3D.h"

int	is_a_digit(char **trim_str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (trim_str[i])
	{
		while (trim_str[i][j])
		{
			if (ft_isprint(trim_str[i][j]) == 0)
				break ;
			if (trim_str[i][j] == '-' && j == 0)
				j++;
			if (ft_isdigit(trim_str[i][j]) == 0 && j > 0)
			{
				free_d_tab(trim_str);
				return (p_error("Error:\n\tnot a integer"));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	color_rvb(char **trim_str)
{
	int	i;
	int	*color;

	i = 0;
	color = ft_calloc(sizeof(int), 3);
	while (trim_str[i])
	{
		color[i] = ft_atoi(trim_str[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			free_d_tab(trim_str);
			free(color);
			return (p_error("Error:\n\tInvalid RVB color"));
			return (-1);
		}
		i++;
	}
	free(color);
	return (0);
}
