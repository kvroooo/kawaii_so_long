/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:41:27 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 14:54:35 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putwall(t_data *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mlx->map[i])
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->wall_img,
					mlx->size * j, mlx->size * i);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_putpath(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i] && mlx->path_img)
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '0')
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->path_img,
					64 * j, 64 * i);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_putobj(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i] && mlx->obj_img)
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->obj_img,
					64 * j, 64 * i);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_putexit(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i] && mlx->path_img)
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'E' && mlx->c == mlx->objs)
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->exit_img,
					64 * j, 64 * i);
			else if (mlx->map[i][j] == 'E' && mlx->c != mlx->objs)
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->path_img,
					64 * j, 64 * i);
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_putplayer(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[i] && mlx->path_img)
	{
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->x = i;
				mlx->y = j;
				mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->player_img,
					64 * mlx->y, 64 * mlx->x);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
