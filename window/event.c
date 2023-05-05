/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:16:36 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/04 16:40:58 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_event(t_data *mlx)
{
	mlx_key_hook(mlx->window, ft_key, mlx);
	mlx_hook(mlx->window, 17, 0L, ft_close_x, mlx);
	return (0);
}

int	ft_close_x(t_data *mlx)
{
	ft_printf("Closing with MOUSE !\n");
	mlx_loop_end(mlx->ptr);
	return (0);
}

int	ft_key(int keycode, t_data *mlx)
{
	if (keycode == 0xff1b)
	{
		ft_printf("Closing with ESC !\n");
		mlx_loop_end(mlx->ptr);
	}
	if (keycode == 0x0077)
		ft_up(mlx);
	if (keycode == 0x0061)
		ft_left(mlx);
	if (keycode == 0x0073)
		ft_down(mlx);
	if (keycode == 0x0064)
		ft_right(mlx);
	ft_putpath(mlx);
	ft_putplayer(mlx);
	return (0);
}
