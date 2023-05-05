/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:43:43 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/01 15:56:46 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//verifie si extension .ber dans argument
int	ft_extension(char *arg)
{
	int		i;
	int		j;
	char	*ext;

	j = 0;
	ext = ".ber";
	i = ft_strlen(arg) - 4;
	if (!arg)
		return (1);
	while (arg[i])
	{
		if (arg[i] != ext[j++])
			return (1);
		i++;
	}
	return (0);
}

void	ft_window(t_data *mlx)
{
	mlx->window = mlx_new_window(mlx->ptr,
			64 * mlx->columns, 64 * mlx->lines, "kawaii so_long");
	if (mlx->window == NULL)
	{
		free(mlx->ptr);
		free(mlx->window);
		return ;
	}
	ft_event(mlx);
	ft_putimgs(mlx);
	mlx_loop(mlx->ptr);
}

int	main(int argc, char *argv[])
{
	int				fd;
	static t_data	mlx = {0};

	mlx.count = NULL;
	if (argc == 1)
		return (ft_error("no file :c"), 0);
	fd = open(argv[1], O_RDONLY);
	if (!argv[1])
		return (0);
	if (fd == -1 || argc != 2)
		return (ft_error("retry with a good file pls ^^"), 0);
	ft_parse(fd, &mlx);
	if (mlx.map == NULL || ft_extension(argv[1]) != 0)
	{
		get_buffer(1);
		return (ft_error("invalid file :c"), 0);
	}
	if (ft_check(mlx.map, &mlx) == 1)
		return (ft_free(mlx.map), 0);
	mlx.ptr = mlx_init();
	if (mlx.ptr == NULL)
		return (ft_free(mlx.map), 0);
	ft_window(&mlx);
	mr_propre(&mlx);
	return (0);
}
