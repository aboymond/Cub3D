#include "../cube3d.h"

void	init(t_map *map)
{
	init_map(map);
	init_player(map);
}

void	init_map(t_map *map)
{
	map->tab_map = NULL;
	map->lon = 0;
	map->larg = 0;
}

void	init_player(t_map *map)
{
	map->player->pos_x = 0;
	map->player->pos_y = 0;
}