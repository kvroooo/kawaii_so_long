/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:57:58 by smlamali          #+#    #+#             */
/*   Updated: 2022/12/15 13:18:25 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_min2(unsigned int n, int *len)
{
	const char	*hex;

	hex = "0123456789abcdef";
	if (n <= 15)
	{
		ft_putchar(hex[n]);
		(*len)++;
	}
	else
	{
		ft_puthex_min2(n / 16, len);
		ft_putchar(hex[n % 16]);
		(*len)++;
	}
}

int	ft_puthex_min(unsigned int nbr)
{
	int	l;

	l = 0;
	ft_puthex_min2(nbr, &l);
	return (l);
}
