/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:31:35 by smlamali          #+#    #+#             */
/*   Updated: 2022/12/15 13:19:34 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *s);
int		ft_putnbr(int nbr);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putunbr(unsigned int nbr);
int		ft_puthex_min(unsigned int nbr);
int		ft_puthex_maj(unsigned int nbr);
int		ft_putadd(unsigned long long n);

#endif