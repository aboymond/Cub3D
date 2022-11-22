#include "../cube3d.h"

void	init(t_map *map)
{
	init_struct_map(map);
	init_player(map);
}

void	init_struct_map(t_map *map)
{
	map->tab_map = NULL;
}

void	init_player(t_map *map)
{
	map->player->pos_x = 0;
	map->player->pos_y = 0;
}

void	callocmap(t_map *map, int haut)
{
	map->tab_map = ft_calloc(haut, sizeof(char));
}
