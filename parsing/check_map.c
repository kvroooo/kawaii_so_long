/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:43:52 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 17:21:59 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check(char **map, t_data *mlx)
{
	if (!map)
		return (1);
	if (ft_walls(mlx) != 0)
	{
		ft_error("no wall :x");
		return (1);
	}
	if (ft_strange(mlx) != 0)
	{
		ft_error("strange element detected :s");
		return (1);
	}
	if (ft_collect(mlx))
	{
		ft_error("no collectibles");
		return (1);
	}
	if (ft_contain(mlx))
		return (1);
	if (!ft_position(mlx))
	{
		ft_error("invalid path");
		return (1);
	}
	return (0);
}

int	ft_strange(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i])
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != '1' && mlx->map[i][j] != '0' &&
				mlx->map[i][j] != 'C' && mlx->map[i][j] != 'P' &&
				mlx->map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

char	**ft_cpymap(t_data *mlx)
{
	int		x;
	char	**tmp;

	x = 0;
	tmp = malloc(sizeof(char **) * (mlx->lines + 1));
	if (!tmp)
		return (NULL);
	while (x < mlx->lines)
	{
		tmp[x] = malloc(sizeof(char *) * mlx->columns);
		if (!tmp[x])
		{
			ft_free(tmp);
			return (0);
		}
		ft_strkcpy(tmp[x], mlx->map[x], mlx->columns);
		x++;
	}
	tmp[x] = 0;
	return (tmp);
}
