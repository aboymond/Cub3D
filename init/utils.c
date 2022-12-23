#include "../cub3D.h"

int	comp_size_len(t_scene *scene, char *line)
{
	int	i;

	i = 0;
	i = (int)ft_strlen(line);
	if (i > scene->map.len_map)
		scene->map.len_map = i;
	return (0);
}

int	cpy_map_to_tab(t_scene *scene, char *line, int i)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(line))
	{
		if (line[j] == '1')
			printf("\033[1;31m%c\033[00m", line[j]);
		else
			printf("%c", line[j]);
		scene->map.tab_map[i][j] = line[j];
		j++;
	}
	j--;
	while (j < scene->map.len_map)
	{
		scene->map.tab_map[i][j] = ' ';
		j++;
	}
	scene->map.tab_map[i][j - 1] = '\0';
	return (0);
}

int	utils_c_w(char c, int car)
{
	if (car == 0)
	{
		if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
			return (1);
	}
	if (car == 1)
	{
		if (ft_isprint(c) != 1 || c == ' ')
			return (1);
	}
	return (0);
}
