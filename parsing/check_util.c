/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:44:36 by smlamali          #+#    #+#             */
/*   Updated: 2023/04/14 16:51:33 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_outwalls(int x, int y, t_data *mlx)
{
	while (mlx->map[x][y])
	{
		while (y < mlx->columns)
		{
			if (!mlx->map[x][y] || mlx->map[x][y] != '1')
				return (1);
			y++;
		}
	}
	return (0);
}

int	ft_walls(t_data *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (ft_outwalls(x, y, mlx))
		return (1);
	while (++x < mlx->lines - 1)
	{
		if (mlx->map[x][0] != '1' || mlx->map[x][mlx->columns - 1] != '1')
			return (1);
	}
	if (ft_outwalls(x, y, mlx))
		return (1);
	return (0);
}

//Cherche le nb de fois qu'un objet apparait dans map
int	ft_search(t_data *mlx, char caracter)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (mlx->map[x])
	{
		while (mlx->map[x][y])
		{
			if (mlx->map[x][y] == caracter)
				count++;
			y++;
		}
		x++;
		y = 0;
	}
	if (count != 1)
		return (1);
	return (0);
}

//cherche si map contient le bon nombre de sortie et de joueurs
int	ft_contain(t_data *mlx)
{
	if (ft_search(mlx, 'E'))
	{
		ft_error("too many or no exit :c");
		return (1);
	}
	if (ft_search(mlx, 'P'))
	{
		ft_error("too many or no player :c");
		return (1);
	}	
	return (0);
}

//compte le nb de collectibles et l'ajoute a mlx->obj
//si map -> 0 collectible -> WRONG >:c
int	ft_collect(t_data *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx->objs = 0;
	while (mlx->map[x])
	{
		while (mlx->map[x][y])
		{
			if (mlx->map[x][y] == 'C')
				mlx->objs++;
			y++;
		}
		x++;
		y = 0;
	}
	if (mlx->objs == 0)
		return (1);
	return (0);
}
