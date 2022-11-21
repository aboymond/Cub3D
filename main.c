
#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->player = malloc(sizeof(t_player));
	map->mlx = malloc(sizeof(t_map));
	map->mlx->mlx = mlx_init();
	erreur_args(argc, argv);
	init(map);
	compt_map_haut(argv[1], map);
	free_main(map);

	return (0);
}

int	free_main(t_map *map)
{
	int	i;

	i = 0;
	while (map->tab_map[i])
	{
		free(map->tab_map[i]);
		i++;
	}
	free(map->tab_map);
	free(map->player);
	free(map->mlx->mlx);
	free(map->mlx);
	free(map);
	return (0);
}