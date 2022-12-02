#include "../cub3D.h"

int	init_asset(char *args, t_scene *scene)
{
	char	*tmp;
	int		fd;

	fd = open(args, O_RDONLY);
	printf("fd = %d\n", fd);
	compt_asset(args, scene);
	tmp = get_next_line(fd);
	if (tmp == NULL || check_asset(scene, tmp) == 1)
	{
		free (tmp);
		close (fd);
		return (1);
	}
	scene->asset.cmpt_asset_tab++;
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		if (tmp == NULL || check_asset(scene, tmp) == 1)
		{
			free (tmp);
			close (fd);
			return (1);
		}
		scene->asset.cmpt_asset_tab++;
	}
	free (tmp);
	close (fd);
	return (0);
}

int check_asset(t_scene *scene, char *line)
{
	if (init_asset_tab(scene, line) == 1)
	{
		if (!scene->asset.asset_color || !scene->asset.asset_NSWE)
		{
			p_error("Error: \n\tMap asset = NULL !");
		}
		return (1);
	}
	return (0);
}

int	init_asset_tab(t_scene *scene, char *line)
{
	int	i;
	(void)scene;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("NSWE", line[i]))
		{
			scene->asset.asset_NSWE[scene->asset.int_NSWE] = ft_strdup(line);
			scene->asset.int_NSWE++;
			scene->asset.cmpt_asset++;
			return (0);
		}
		if (ft_strchr("FC", line[i]))
		{
			scene->asset.asset_color[scene->asset.int_color] = ft_strdup(line);
			scene->asset.int_color++;
			scene->asset.cmpt_asset++;
			return (0);
		}
		if (ft_strchr("01", line[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}