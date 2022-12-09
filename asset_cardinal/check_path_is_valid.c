#include "../cub3D.h"

int	path_not_valid(t_asset *asset)
{
	int 	i;
	int		j;
	char 	**tab_path;

	i = 0;
	j = 0;
	tab_path = ft_calloc(asset->nbr_NSWE + 1, sizeof(char *));
	while (asset->asset_NSWE[i])
	{
		//printf("asset->asset_NSWE[i] = %p\n", asset->asset_NSWE[i]);
		tab_path[i] = ft_strdup(asset->asset_NSWE[i]);
		//printf("tab_path[i] = %p\n", tab_path[i]);
		free(asset->asset_NSWE[i]);
		i++;
	}
	delete_p_cardinal(tab_path, asset);
	if (two_same_path(asset->tab_path) == -1)
	{
		//free_d_tab(tab_path);
		return (p_error("Error:\n\tthere is same path"));
	}
	return (0);
}

void	delete_p_cardinal(char **tab_path, t_asset *asset)
{
	//char	*tmp;
	int		i;

	i = 0;
	asset->tab_path = ft_calloc(asset->nbr_NSWE + 1, sizeof(char *));
	while (tab_path[i])
	{
		asset->tab_path[i] = ft_substr(tab_path[i], 3, ft_strlen(tab_path[i]));
		free(tab_path[i]);
		i++;
	}
	free(tab_path);
}

int two_same_path(char **path)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (path[i])
	{
		while (path[j])
		{
			if (ft_strcmp(path[i], path[j]) == 0)
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
