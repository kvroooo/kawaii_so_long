# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 12:48:27 by smlamali          #+#    #+#              #
#    Updated: 2023/05/04 13:39:05 by smlamali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  main.c 										\
		parsing/parse.c 							\
		parsing/parse_util.c						\
		parsing/check_map.c 						\
		parsing/check_util.c 						\
		parsing/path.c 								\
		window/event.c 								\
		window/images.c								\
		window/images_utils.c 						\
		window/utils.c 								\
		movements/mouvs.c 							\
		movements/mv_utils.c 						\
		getnextline/get_next_line.c			 		\
		getnextline/get_next_line_utils.c 			\
		printf/ft_printf.c 							\
		printf/ft_putadd.c 							\
		printf/ft_putchar.c							\
		printf/ft_puthex_maj.c	 					\
		printf/ft_puthex_min.c 						\
		printf/ft_putnbr.c 							\
		printf/ft_putunbr.c 						\
		printf/ft_putstr.c 							\
		printf/ft_strlen.c 							\
		
OBJS = $(SRCS:.c=.o)

MLIBX = ./minilibx-linux/libmlx.a

CC = clang 

CFLAGS = -Wall -Wextra -Werror -g3

NAME = so_long

all: $(MLIBX) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(MLIBX):
	cd ./minilibx-linux && ${MAKE}
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) -lX11 -lXext -Lminilibx-linux -lmlx -o $(NAME) 

clean: 
	rm -f ${OBJS}
	cd ./minilibx-linux/ && ${MAKE} clean
	
fclean: clean
	rm -f ${NAME} 
	
re: fclean all