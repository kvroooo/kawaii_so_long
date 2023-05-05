/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:25:32 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 15:11:31 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// On verifie si
// le joueur peut se deplacer sur l'emplacement c
int	ft_valid_char(char c)
{
	return (c != '1');
}

// Je pourrais rajouter cas si  joueur depasse
// positivement les limites de la map
//  si x > nb total de colonnes -> return (0)
//  si y > nb total de litmpgnes -> return (0)
int	is_valid(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !ft_valid_char(map[x][y]))
		return (0);
	return (1);
}

int	ft_path(char **map, int x, int y, int *collectibles)
{
	static int	exit = 0;

	if (!is_valid(map, x, y))
		return (0);
	if (map[x][y] == 'C')
		(*collectibles)--;
	if (map[x][y] == 'E')
		exit = 1;
	if (exit && *collectibles == 0)
		return (1);
	map[x][y] = '1';
	if (is_valid(map, x + 1, y))
		if (ft_path(map, x + 1, y, collectibles))
			return (1);
	if (is_valid(map, x - 1, y))
		if (ft_path(map, x - 1, y, collectibles))
			return (1);
	if (is_valid(map, x, y + 1))
		if (ft_path(map, x, y + 1, collectibles))
			return (1);
	if (is_valid(map, x, y - 1))
		if (ft_path(map, x, y - 1, collectibles))
			return (1);
	return (0);
}

int	ft_position(t_data *mlx)
{
	t_player	pos;
	int			val;
	char		**tmp;

	val = 1;
	pos.x = 0;
	pos.y = 0;
	mlx->c = mlx->objs;
	tmp = ft_cpymap(mlx);
	while (pos.y < mlx->lines)
	{
		while (pos.y < mlx->columns)
		{
			if (mlx->map[pos.x][pos.y] == 'P')
			{
				val = ft_path(tmp, pos.x, pos.y, &mlx->c);
				return (ft_free(tmp), val);
			}
			pos.y++;
		}
		pos.x++;
		pos.y = 0;
	}
	ft_free(tmp);
	return (val);
}
