/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:47:02 by smlamali          #+#    #+#             */
/*   Updated: 2023/04/27 13:40:34 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include "getnextline/get_next_line.h"
# include "printf/ft_printf.h"

//STRUCT :

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

// x y : player position
//objs : total collectible
//exit : verify in the path check if exit was found once
// c   : number of collectibles found in the game
//mvmts: movements counter
typedef struct s_data
{
	int			x;
	int			y;
	int			mvmts;
	int			lines;
	int			columns;
	int			exit;
	int			objs;
	int			c;
	int			size;
	char		**map;
	char		*count;
	void		*ptr;
	void		*window;
	void		*wall_img;
	void		*path_img;
	void		*obj_img;
	void		*player_img;
	void		*exit_img;
	char		*w_img;
	t_player	player;

}	t_data;

//PARSE & UTILS
void	ft_strkcpy(char *dst, const char *src, size_t size);
char	**ft_map(char *all, t_data *mlx);
char	**ft_parse(int fd, t_data *mlx);
void	ft_error(char *str);
int		ft_strlen0(char *s);
void	ft_free(char **map);
int		ft_position(t_data *mlx);

//CHECK & UTILS
int		ft_check(char **map, t_data *mlx);
int		ft_strange(t_data *mlx);
int		ft_outwalls(int x, int y, t_data *mlx);
int		ft_contain(t_data *mlx);
int		ft_walls(t_data *mlx);
int		ft_search(t_data *mlx, char caracter);
int		ft_collect(t_data *mlx);
char	**ft_cpymap(t_data *mlx);
int		ft_path(char **map, int x, int y, int *collectibles);

//EVENTS & UTILS
int		ft_close_x(t_data *mlx);
int		ft_event(t_data *mlx);
int		ft_key(int keycode, t_data *mlx);

//MOVES && UTILS
void	ft_up(t_data *mlx);
void	ft_down(t_data *mlx);
void	ft_left(t_data *mlx);
void	ft_right(t_data *mlx);
size_t	ft_size(int n, size_t size);
void	ft_reverse(char *s);
char	*ft_itoa(int nb);
void	ft_count(t_data *mlx);
int		ft_end(t_data *mlx);

// PUT IMGS
void	ft_putobj(t_data *mlx);
int		ft_putimgs(t_data *mlx);
void	ft_putwall(t_data *mlx);
void	ft_putpath(t_data *mlx);
void	ft_putexit(t_data *mlx);
void	ft_putplayer(t_data *mlx);

// SECURITY + CLEANING  (clear, free..)
void	mr_propre(t_data *mlx);
void	img_destroyer(t_data *mlx);

#endif