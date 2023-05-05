/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:05:56 by smlamali          #+#    #+#             */
/*   Updated: 2023/04/17 18:15:17 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//so_long destroyer
void	mr_propre(t_data *mlx)
{
	mlx_loop_end(mlx->ptr);
	img_destroyer(mlx);
	mlx_clear_window(mlx->ptr, mlx->window);
	mlx_destroy_window(mlx->ptr, mlx->window);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	ft_free(mlx->map);
}

//comme l'explique le nom de la fonction ^^'
void	img_destroyer(t_data *mlx)
{
	if (mlx->wall_img)
		mlx_destroy_image(mlx->ptr, mlx->wall_img);
	if (mlx->path_img)
		mlx_destroy_image(mlx->ptr, mlx->path_img);
	if (mlx->obj_img)
		mlx_destroy_image(mlx->ptr, mlx->obj_img);
	if (mlx->exit_img)
		mlx_destroy_image(mlx->ptr, mlx->exit_img);
	if (mlx->player_img)
		mlx_destroy_image(mlx->ptr, mlx->player_img);
}
