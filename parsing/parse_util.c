/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:02:26 by smlamali          #+#    #+#             */
/*   Updated: 2023/04/29 17:06:57 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	write(1, "Error : ", 8);
	write(1, str, ft_strlen0(str));
	write(1, "\n", 1);
}

int	ft_strlen0(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_strkcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (size > 0 && i < size))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
