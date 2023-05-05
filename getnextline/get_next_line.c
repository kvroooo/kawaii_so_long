/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:15:48 by smlamali          #+#    #+#             */
/*   Updated: 2023/05/01 15:39:17 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*ft_norm(int r, char *buf, char *stock)
{
	char	*tmp;

	buf[r] = '\0';
	tmp = stock;
	stock = ft_strjoin2(tmp, buf);
	free(tmp);
	return (stock);
}

char	**get_buffer(int freelol)
{
	static char	*stock;

	if (freelol)
	{
		free(stock);
		stock = 0;
		return (0);
	}
	return (&stock);
}

char	*get_next_line2(int fd, int r)
{	
	char			**stock;
	char			*line;
	char			*buf;

	stock = get_buffer(0);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(*stock, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free(buf), NULL);
		*stock = ft_norm(r, buf, *stock);
	}
	free(buf);
	if (!*stock)
		return (NULL);
	line = ft_line(*stock);
	*stock = ft_save(*stock);
	return (line);
}

char	*get_next_line(int fd)
{	
	return (get_next_line2(fd, 1));
}

// int	main(void)
// {
// 	int		fd;
// 	int		r;
// 	char	*buf;

// 	r = 0;
// 	fd = open("map.ber", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	printf("--------- MAIN ---------\n");
// 	while (buf = get_next_line(fd))
// 	{
// 		printf("%s", buf);
// 		free(buf);
// 		r++;
// 	}
// 	printf("\n--------- FIN ---------\n");
// 	close(fd);
// }
