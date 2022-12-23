/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:40:23 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 15:57:18 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	comp_size_len(t_scene *scene, char *line)
{
	int	i;

	i = 0;
	i = (int)ft_strlen(line);
	if (i > scene->map.len_map)
		scene->map.len_map = i;
	return (0);
}

int	cpy_map_to_tab(t_scene *scene, char *line, int i)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(line))
	{
		if (line[j] == '1')
			printf("\033[1;31m%c\033[00m", line[j]);
		else
			printf("%c", line[j]);
		scene->map.tab_map[i][j] = line[j];
		j++;
	}
	j--;
	while (j < scene->map.len_map)
	{
		scene->map.tab_map[i][j] = ' ';
		j++;
	}
	scene->map.tab_map[i][j - 1] = '\0';
	return (0);
}

int	utils_c_w(char c, int car)
{
	if (car == 0)
	{
		if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
			return (1);
	}
	if (car == 1)
	{
		if (ft_isprint(c) != 1 || c == ' ')
			return (1);
	}
	return (0);
}

int	map_is_close_2(t_scene *scene, int j, int i, int comp)
{
	while (++j < (int)ft_strlen(scene->map.tab_map[i]))
	{
		if (utils_c_w(scene->map.tab_map[i][j], 0) == 1)
		{
			scene->player.cardi = scene->map.tab_map[i][j];
			comp++;
			scene->player.pos.x = j;
			scene->player.pos.y = i;
			if (comp > 1)
				return (p_error("Error :\n\tTo many player"));
		}
		check_wall(scene->map.tab_map, i, j);
	}
	return (comp);
}
