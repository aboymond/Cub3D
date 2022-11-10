
#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	(void)argv;
	(void)argc;
	map = malloc(sizeof(t_map));
	map->mlx = malloc(sizeof(t_map));
	map->mlx->mlx = mlx_init();
	init(map);


	return (0);
}
