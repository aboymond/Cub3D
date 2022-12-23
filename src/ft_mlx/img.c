/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboymond <aboymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:39:37 by aboymond          #+#    #+#             */
/*   Updated: 2022/12/23 15:39:39 by aboymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

t_img	*ftmlx_new_img(void *mlx, int width, int height)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->h = height;
	img->w = width;
	img->img = mlx_new_image(mlx, img->w, img->h);
	if (img->img == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

t_img	*ftmlx_new_xpm_img(void *mlx, char *file)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_xpm_file_to_image(mlx, file, &img->w, &img->h);
	if (img->img == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

void	ftmlx_free_img(void *mlx, t_img *img)
{
	if (img == NULL)
		return ;
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	free(img);
}
