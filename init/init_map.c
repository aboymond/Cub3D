#include "../cube3d.h"

void	compt_map_haut(char *args, t_map *map)
{
	char	*tmp;
	int		fd;
	int		haut;

	haut = 0;
	fd = open(args, O_RDONLY);
	tmp = get_next_line(fd);
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
		
		map->tab_map[i] = get_next_line(fd);
		printf("map tab = %s\n", map->tab_map[i]);
		i++;
		//map->tab_map[i][larg[i]] = '\n';
	}
	printf("map = %s , i = %d, len = %d\n", map->tab_map[i], i, (int)ft_strlen(map->tab_map[i]));
	//map->tab_map[i][larg[i - 1]] = '\n';
	close(fd);
}