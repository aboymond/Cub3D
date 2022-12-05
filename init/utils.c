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
	// printf("map = %s\n", scene->map.tab_map[i]);
	return (0);
}