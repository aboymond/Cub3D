#include "../cub3D.h"

void	init_assets(t_asset *assets)
{
	assets->tex_n = NULL;
	assets->tex_s = NULL;
	assets->tex_w = NULL;
	assets->tex_e = NULL;
}

int	load_assets(void *mlx, t_asset *assets)
{
	assets->tex_n = ftmlx_new_xpm_img(mlx, assets->tab_path[0]);
	assets->tex_s = ftmlx_new_xpm_img(mlx, assets->tab_path[1]);
	assets->tex_w = ftmlx_new_xpm_img(mlx, assets->tab_path[2]);
	assets->tex_e = ftmlx_new_xpm_img(mlx, assets->tab_path[3]);
	if (assets->tex_n == NULL || assets->tex_e == NULL
		|| assets->tex_s == NULL || assets->tex_w == NULL)
	{
		free_assets(mlx, assets);
		return (1);
	}
	return (0);
}

void	free_assets(void *mlx, t_asset *assets)
{
	ftmlx_free_img(mlx, assets->tex_n);
	ftmlx_free_img(mlx, assets->tex_s);
	ftmlx_free_img(mlx, assets->tex_w);
	ftmlx_free_img(mlx, assets->tex_e);
}
