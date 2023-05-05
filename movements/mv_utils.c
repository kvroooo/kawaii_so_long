/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:43:10 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 15:10:00 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//compte le nombre de chiffres qu'il y a dans n
//pour connaitre la longueur de la chaine a retourner. 
size_t	ft_size(int n, size_t size)
{
	size++;
	if (n >= 10)
		size = ft_size(n / 10, size);
	return (size);
}

//reverse str
void	ft_reverse(char *s)
{
	char	tmp;
	size_t	i;
	size_t	size;

	i = 0;
	tmp = 0;
	size = ft_strlen0(s) - 1;
	while (i < size)
	{
		tmp = s[i];
		s[i] = s[size];
		s[size] = tmp;
		i++;
		size--;
	}
}

//int to array, to print number ^^
char	*ft_itoa(int nb)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char *) * ft_size(nb, 0) + 1);
	if (!str)
	{
		free(str);
		return (0);
	}
	while (nb >= 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		if (nb == 0)
			nb -= 1;
		i++;
	}
	str[i] = 0;
	ft_reverse(str);
	return (str);
}

void	ft_count(t_data *mlx)
{
	mlx->mvmts += 1;
	mlx->count = ft_itoa(mlx->mvmts);
	if (!mlx->count)
		return ;
	ft_printf("%s\n", mlx->count);
	free(mlx->count);
}

int	ft_end(t_data *mlx)
{
	if (mlx->c == mlx->objs)
	{
		ft_putexit(mlx);
	}
	if (mlx->map[mlx->x][mlx->y] == 'E' && mlx->c == mlx->objs)
	{
		mlx_loop_end(mlx->ptr);
		return (1);
	}
	return (0);
}
