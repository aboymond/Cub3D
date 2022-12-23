#include "cub3D.h"

void	free_tab(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->asset.tab_path[i])
	{
		free(scene->asset.tab_path[i]);
		i++;
	}
	free(scene->asset.tab_path);
	i = 0;
}
