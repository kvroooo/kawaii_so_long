/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:49:38 by smlamali          #+#    #+#             */
/*   Updated: 2023/04/12 13:56:10 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//initialisation des images
int	ft_putimgs(t_data *mlx)
{
	mlx->wall_img = mlx_xpm_file_to_image(mlx->ptr, "img/wall.xpm",
			&mlx->size, &mlx->size);
	mlx->obj_img = mlx_xpm_file_to_image(mlx->ptr, "img/obj.xpm",
			&mlx->size, &mlx->size);
	mlx->path_img = mlx_xpm_file_to_image(mlx->ptr, "img/path.xpm",
			&mlx->size, &mlx->size);
	mlx->exit_img = mlx_xpm_file_to_image(mlx->ptr, "img/exit.xpm",
			&mlx->size, &mlx->size);
	mlx->player_img = mlx_xpm_file_to_image(mlx->ptr, "img/zero.xpm",
			&mlx->size, &mlx->size);
	if (mlx->wall_img != NULL && mlx->obj_img != NULL && mlx->path_img != NULL
		&& mlx->exit_img != NULL && mlx->player_img != NULL)
	{
		ft_putwall(mlx);
		ft_putobj(mlx);
		ft_putpath(mlx);
		ft_putexit(mlx);
		ft_putplayer(mlx);
	}
	else
		mlx_loop_end(mlx->ptr);
	return (0);
}
