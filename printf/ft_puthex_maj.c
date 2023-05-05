/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_maj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:17:41 by smlamali          #+#    #+#             */
/*   Updated: 2022/12/15 13:18:59 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_maj2(unsigned int n, int *len)
{
	const char	*hex;

	hex = "0123456789ABCDEF";
	if (n <= 15)
	{
		ft_putchar(hex[n]);
		(*len)++;
	}
	else
	{
		ft_puthex_maj2(n / 16, len);
		ft_putchar(hex[n % 16]);
		(*len)++;
	}
}

int	ft_puthex_maj(unsigned int nbr)
{
	int	l;

	l = 0;
	ft_puthex_maj2(nbr, &l);
	return (l);
}
