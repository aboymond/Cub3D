
#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	scene->mlx.mlx = mlx_init();
	erreur_args(argc, argv);
	init(scene);
	if (init_asset(argv[1], scene) == 1)
		asset_is_valid(&scene->asset);
	compt_map(argv[1], scene);
	map_is_close(scene);
	open_win(scene);
	mlx_loop(scene->mlx.mlx);
	//free_main(scene);

	return (0);
}

int	free_main(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->map.tab_map[i])
	{
		free(scene->map.tab_map[i]);
		i++;
	}
	free(scene->map.tab_map);
	free(scene->mlx.mlx);
	free(scene);
	return (0);
}