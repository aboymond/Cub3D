/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:23:21 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/18 20:56:54 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned long long int n)
{
	unsigned int			i;
	unsigned long int		nb;

	nb = n;
	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putnbrhexa_p(unsigned long long int n)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n <= 15)
		ft_putcharf(hexa[n]);
	else
	{
		ft_putnbrhexa_p(n / 16);
		ft_putnbrhexa_p(n % 16);
	}
	return (ft_intlen(n));
}
