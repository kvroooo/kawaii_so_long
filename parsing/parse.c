/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:00:06 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 17:12:59 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**ft_map(char *all, t_data *mlx)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char **) * (mlx->lines + 1));
	if (!map)
	{
		ft_free(map);
		return (0);
	}
	while (i < mlx->lines)
	{
		map[i] = malloc(sizeof(char *) * mlx->columns);
		if (!map[i])
		{
			ft_free(map);
			return (0);
		}
		ft_strkcpy(map[i], all + (mlx->columns * i) + i, mlx->columns);
		i++;
	}
	map[i] = 0;
	return (map);
}

static int	isempty(char *tmp, t_data *mlx)
{
	int	i;

	i = 0;
	while (tmp && i < mlx->columns)
	{
		if (!tmp[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_parse(int fd, t_data *mlx)
{
	char	*tmp;
	char	*all;
	char	*tst;

	all = NULL;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (NULL);
	mlx->columns = ft_strlen0(tmp);
	while (tmp)
	{
		tst = all;
		all = ft_strjoin2(all, tmp);
		free(tst);
		free(tmp);
		mlx->lines++;
		tmp = get_next_line(fd);
		if (isempty(tmp, mlx) != 0)
			return (free(tmp), free(all), NULL);
	}
	mlx->map = ft_map(all, mlx);
	return (free(tmp), free(all), mlx->map);
}
