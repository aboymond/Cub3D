/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggentil <ggentil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:51:54 by aboymond          #+#    #+#             */
/*   Updated: 2022/11/09 19:30:34 by ggentil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *f, const char *s, size_t l)
{
	unsigned int	i;

	i = 0;
	while (f[i] != '\0' && s[i] != '\0' && i < l)
	{
		if (f[i] != s[i])
			return (f[i] - s[i]);
		++i;
	}
	if (i != l)
		return (f[i] - s[i]);
	return (0);
}
