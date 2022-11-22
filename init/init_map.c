#include "../cube3d.h"

void	compt_map_haut(char *args, t_map *map)
{
	char	*tmp;
	int		fd;
	int		haut;

	haut = 0;
	fd = open(args, O_RDONLY);
	tmp = get_next_line(fd);
	haut++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		haut++;
	}
	close(fd);
	compt_map(args, map, haut);
}

void	compt_map(char *args, t_map *map, int haut)
{
	char	*tmp;
	int		*larg;
	int		fd;
	int		i;

	i = 0;
	larg = ft_calloc(haut, sizeof(int));
	fd = open(args, O_RDONLY);
	tmp = get_next_line(fd);
	larg[i] = (int)ft_strlen(tmp);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		larg[++i] = (int)ft_strlen(tmp);
	}
	larg[i - 1]++;
	close(fd);
	callocmap(map, haut);
	init_tab_map(args, map, larg, haut);
	free(larg);
}

void	init_tab_map(char *args, t_map *map, int *larg, int haut)
{
	int		fd;
	int		i;
	(void)larg;

	i = 0;
	fd = open(args, O_RDONLY);
	map->tab_map[i] = get_next_line(fd);
	printf("map tab = %s\n", map->tab_map[i]);
	i++;
	while (i < haut)
	{
		printf("haut = %d\n", haut);
		map->tab_map[i] = get_next_line(fd);
		printf("map tab = %s\n", map->tab_map[i]);
		i++;
	}
	printf("tablen init tab = %d\n", ft_tablen(map->tab_map));
	close(fd);
}

int	map_is_close(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab_map[i])
	{
		j = 0;
		while (map->tab_map[i][j])
		{
			check_wall(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(t_map *map, int i, int j)
{
	//printf("i = %d, j = %d\n", i, j);
	if (map->tab_map[0][j] == '0' || map->tab_map[ft_tablen(map->tab_map) - 1][j] == '0')
		printf("error map '0' !\n");
	if (map->tab_map[i][0] == '0' || map->tab_map[i][(int)ft_strlen(map->tab_map[i] - 1)] == '0')
	{
		printf("error map '0' !\n");
	}
	if (map->tab_map[i][j] == '0')
	{
		if (map->tab_map[i - 1][j] == ' ' || map->tab_map[i + 1][j] == ' ' || map->tab_map[i][j - 1] == ' ' || map->tab_map[i][j + 1] == ' ')
			printf("error map, i = %d, j = %d ' ' \n", i, j);
	}

	return (0);
}