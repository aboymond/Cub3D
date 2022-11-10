/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piow00 <piow00@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:28:02 by aboymond          #+#    #+#             */
/*   Updated: 2022/10/18 20:57:33 by piow00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int n)
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

int	ft_putnbrhexa(unsigned int n, int t)
{
	char	*hexa;

	if (t == 0)
		hexa = "0123456789abcdef";
	if (t == 1)
		hexa = "0123456789ABCDEF";
	if (n <= 15)
		ft_putcharf(hexa[n]);
	else
	{
		ft_putnbrhexa(n / 16, t);
		ft_putnbrhexa(n % 16, t);
	}
	return (ft_intlen(n));
}
