/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:30 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 15:56:41 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	compt_map(char *args, t_scene *scene)
{
	char	*tmp;
	int		fd;
	int		haut;
	int		j;

	haut = 0;
	j = -1;
	fd = open(args, O_RDONLY);
	while (++j < scene->asset.cmpt_asset_tab)
	{
		tmp = get_next_line(fd);
		free (tmp);
	}
	tmp = get_next_line(fd);
	comp_size_len(scene, tmp);
	haut++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		comp_size_len(scene, tmp);
		haut++;
	}
	close(fd);
	compt_map_2(scene, haut, args);
}

void	compt_map_2(t_scene *scene, int haut, char *args)
{
	callocmap(scene, haut);
	init_tab_map(args, scene);
}

void	init_tab_map(char *args, t_scene *scene)
{
	int		fd;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	printf("\n\t\033[4;32mINIT MINIMAP :\033[00m\n\n");
	fd = open(args, O_RDONLY);
	while (j < scene->asset.cmpt_asset_tab)
	{
		tmp = get_next_line(fd);
		free(tmp);
		j++;
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		cpy_map_to_tab(scene, tmp, i);
		free (tmp);
		i++;
		tmp = get_next_line(fd);
	}
	printf("\n\n");
	close(fd);
}

int	map_is_close(t_scene *scene)
{
	int	i;
	int	j;
	int	comp;

	i = -1;
	comp = 0;
	while (++i < ft_tablen(scene->map.tab_map))
	{
		j = -1;
		comp = map_is_close_2(scene, j, i, comp);
	}
	if (comp < 1)
		return (p_error("Error :\n\tNo player"));
	return (0);
}

int	check_wall(char **tab, int i, int j)
{
	if (tab[0][j] == '0' || tab[ft_tablen(tab) - 1][j] == '0')
		return (p_error("Error:\n\tThe map is not closed 0"));
	else if (tab[i][0] == '0' || tab[i][(int)ft_strlen(tab[i] - 1)] == '0')
	{
		return (p_error("Error:\n\tThe map is not closed 1"));
	}
	else if (utils_c_w(tab[0][j], 0) == 1)
		return (p_error("Error:\n\tThe map is not closed 3"));
	else if (utils_c_w(tab[i][0], 0) == 1
		|| utils_c_w(tab[i][(int)ft_strlen(tab[i] - 1)], 0) == 1)
	{
		return (p_error("Error:\n\tThe map is not closed 4"));
	}
	else if (utils_c_w(tab[i][j], 0) == 1 || tab[i][j] == '0')
	{
		if ((utils_c_w(tab[i - 1][j], 1) == 1
			|| utils_c_w(tab[i + 1][j], 1) == 1)
			|| (utils_c_w(tab[i][j - 1], 1) == 1
				|| utils_c_w(tab[i][j + 1], 1) == 1))
			return (p_error("Error:\n\tThe map is not closed 5"));
	}
	return (0);
}
