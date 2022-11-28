#include "../cube3d.h"

void	init(t_scene *scene)
{
	init_struct_map(scene);
	init_player(scene);
	init_asset_var(scene);
}

void	init_struct_map(t_scene *scene)
{
	scene->map.tab_map = NULL;
}

void	init_player(t_scene *scene)
{
	scene->player.pos_x = 0;
	scene->player.pos_y = 0;
}

void	init_asset_var(t_scene *scene)
{

	scene->asset.cmpt_asset = 0;
	scene->asset.cmpt_asset_tab = 0;
	scene->asset.asset_color = ft_calloc(10, sizeof(char));
	scene->asset.int_color = 0;
	scene->asset.asset_NSWE = ft_calloc(10, sizeof(char));
	scene->asset.int_NSWE = 0;
}

void	callocmap(t_scene *scene, int haut)
{
	scene->map.tab_map = ft_calloc(haut, sizeof(char));
}
