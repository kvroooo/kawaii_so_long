/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:28:48 by smlamali          #+#    #+#             */
/*   Updated: 2022/12/15 13:09:43 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_subnbr(void)
{
	int	len;

	write(1, "-2147483648", 11);
	len = 11;
	return (len);
}

static void	ft_putnbr2(int nbr, int *len)
{
	if (nbr == -2147483648)
		*len = ft_subnbr();
	else if (nbr >= 0 && nbr <= 9)
		*len += ft_putchar(nbr + '0');
	else if (nbr < 0)
	{
		nbr *= -1;
		(*len) += ft_putchar('-');
		ft_putnbr2(nbr, len);
	}
	else
	{
		ft_putnbr2(nbr / 10, len);
		*len += ft_putchar((nbr % 10) + '0');
	}
}

int	ft_putnbr(int nbr)
{
	int	l;

	l = 0;
	ft_putnbr2(nbr, &l);
	return (l);
}
