#include "../cub3D.h"

int	compt_map(char *args, t_scene *scene)
{
	char	*tmp;
	int		fd;
	int		haut;
	int		j;

	haut = 0;
	j = 0;
	fd = open(args, O_RDONLY);
	printf("fd = %d\n", fd);
	while (j < scene->asset.cmpt_asset_tab)
	{
		get_next_line(fd);
		j++;
	}
	tmp = get_next_line(fd);
	comp_size_len(scene, tmp);
	haut++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		comp_size_len(scene, tmp);
		haut++;
	}
	close(fd);
	callocmap(scene, haut);
	printf("tablen compt map(%d)\n", ft_tablen(scene->map.tab_map));
	init_tab_map(args, scene, haut);
	return (0);
}

void	init_tab_map(char *args, t_scene *scene, int haut)
{
	int		fd;
	int		i;
	int		j;
	char	*tmp;
	(void)haut;

	i = 0;
	j = 0;
	fd = open(args, O_RDONLY);
	while (j < scene->asset.cmpt_asset_tab)
	{
		tmp = get_next_line(fd);
		free(tmp);
		j++;
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		cpy_map_to_tab(scene, tmp, i);
		free (tmp);
		i++;
		tmp = get_next_line(fd);
	}
	close(fd);
}

int	map_is_close(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_tablen(scene->map.tab_map))
	{
		j = 0;
		while (j < (int)ft_strlen(scene->map.tab_map[i]))
		{
			check_wall(scene, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(t_scene *scene, int i, int j)
{
	//printf("i = %d, j = %d\n", i, j);
	if (scene->map.tab_map[0][j] == '0' || scene->map.tab_map[ft_tablen(scene->map.tab_map) - 1][j] == '0')
		return (p_error("Error:\n\tThe map is not closed"));
	else if (scene->map.tab_map[i][0] == '0' || scene->map.tab_map[i][(int)ft_strlen(scene->map.tab_map[i] - 1)] == '0')
	{
		return (p_error("Error:\n\tThe map is not closed"));
	}
	else if (scene->map.tab_map[i][j] == '0')
	{
		if (scene->map.tab_map[i - 1][j] == ' ' || scene->map.tab_map[i + 1][j] == ' ' || scene->map.tab_map[i][j - 1] == ' ' || scene->map.tab_map[i][j + 1] == ' ')
			return (p_error("Error:\n\tThe map is not closed"));
	}

	return (0);
}