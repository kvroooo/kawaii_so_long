/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:28:25 by smlamali          #+#    #+#             */
/*   Updated: 2022/12/15 12:52:51 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_min2(unsigned long long n, int *len)
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

int	ft_putadd(unsigned long long n)
{
	int	l;

	l = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	ft_putstr("0x");
	ft_puthex_min2(n, &l);
	return (l + 2);
}
