/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:50:33 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 16:50:52 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	dodge_exit(t_data *mlx, int pos_x, int pos_y)
{
	if (mlx->map[pos_x][pos_y] != 'E')
		mlx->map[pos_x][pos_y] = '0';
	else if (mlx->map[pos_x][pos_y] == 'E')
		ft_putexit(mlx);
	if (mlx->c == mlx->objs)
		ft_putexit(mlx);
	if (mlx->map[mlx->x][mlx->y] == 'E')
	{
		if (mlx->c == mlx->objs)
		{
			mlx_loop_end(mlx->ptr);
			return ;
		}
		mlx->map[pos_x][pos_y] = '0';
		mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->player_img,
			mlx->size * mlx->y, mlx->size * mlx->x);
	}
}

//UP || (mlx->map[mlx->x][mlx->y] == 'E' && mlx->c != mlx->objs)
void	ft_up(t_data *mlx)
{
	mlx->x -= 1;
	if (mlx->map[mlx->x][mlx->y] == '1')
	{
		mlx->x += 1;
		return ;
	}
	ft_count(mlx);
	if (mlx->map[mlx->x][mlx->y] == 'C')
	{
		mlx->c += 1;
		dodge_exit(mlx, mlx->x + 1, mlx->y);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	if (mlx->map[mlx->x][mlx->y] == '0')
	{
		dodge_exit(mlx, mlx->x + 1, mlx->y);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	dodge_exit(mlx, mlx->x + 1, mlx->y);
	ft_end(mlx);
}

//LEFT
void	ft_left(t_data *mlx)
{
	mlx->y -= 1;
	if (mlx->map[mlx->x][mlx->y] == '1')
	{
		mlx->y += 1;
		return ;
	}
	ft_count(mlx);
	if (mlx->map[mlx->x][mlx->y] == 'C')
	{
		mlx->c += 1;
		dodge_exit(mlx, mlx->x, mlx->y + 1);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	if (mlx->map[mlx->x][mlx->y] == '0')
	{
		dodge_exit(mlx, mlx->x, mlx->y + 1);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	dodge_exit(mlx, mlx->x, mlx->y + 1);
	ft_end(mlx);
}

//DOWN
void	ft_down(t_data *mlx)
{
	mlx->x += 1;
	if (mlx->map[mlx->x][mlx->y] == '1')
	{
		mlx->x -= 1;
		return ;
	}
	ft_count(mlx);
	if (mlx->map[mlx->x][mlx->y] == 'C')
	{
		mlx->c += 1;
		if (mlx->map[mlx->x - 1][mlx->y] != 'E')
			mlx->map[mlx->x - 1][mlx->y] = '0';
		else if (mlx->map[mlx->x - 1][mlx->y] == 'E')
			ft_putexit(mlx);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	if (mlx->map[mlx->x][mlx->y] == '0')
	{
		if (mlx->map[mlx->x - 1][mlx->y] != 'E')
			mlx->map[mlx->x - 1][mlx->y] = '0';
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	if (mlx->map[mlx->x][mlx->y] == 'E')
		dodge_exit(mlx, mlx->x - 1, mlx->y);
	ft_end(mlx);
}

//RIGHT
void	ft_right(t_data *mlx)
{
	mlx->y += 1;
	if (mlx->map[mlx->x][mlx->y] == '1')
	{
		mlx->y -= 1;
		return ;
	}
	ft_count(mlx);
	if (mlx->map[mlx->x][mlx->y] == 'C')
	{
		mlx->c += 1;
		dodge_exit(mlx, mlx->x, mlx->y - 1);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	if (mlx->map[mlx->x][mlx->y] == '0')
	{
		dodge_exit(mlx, mlx->x, mlx->y - 1);
		mlx->map[mlx->x][mlx->y] = 'P';
	}
	dodge_exit(mlx, mlx->x, mlx->y - 1);
	ft_end(mlx);
}
