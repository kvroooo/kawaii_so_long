/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:20:04 by smlamali          #+#    #+#             */
/*   Updated: 2022/12/15 12:35:10 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr2(unsigned int nbr, int *len)
{
	if (nbr <= 9)
		*len += ft_putchar(nbr + '0');
	else
	{
		ft_putunbr2(nbr / 10, len);
		*len += ft_putchar((nbr % 10) + '0');
	}
}

int	ft_putunbr(unsigned int nbr)
{
	int	l;

	l = 0;
	ft_putunbr2(nbr, &l);
	return (l);
}
