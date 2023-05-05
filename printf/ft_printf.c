/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:10:02 by smlamali          #+#    #+#             */
/*   Updated: 2023/02/01 18:04:05 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_subprintf1(const char *str, va_list args, int i, int len)
{
	if (str[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (str[i] == 'p')
		len += ft_putadd((unsigned long long)(va_arg(args, void *)));
	else if (str[i] == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (str[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (str[i] == '%')
		len += ft_putchar('%');
	else if (str[i] == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		len += ft_puthex_min(va_arg(args, int));
	else if (str[i] == 'X')
		len += ft_puthex_maj(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = ft_subprintf1(str, args, i, len);
		}
		else
		{
			len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
