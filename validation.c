/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:59:12 by msakovyc          #+#    #+#             */
/*   Updated: 2018/05/25 15:59:14 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		*validation(char *name, int i, int fd, char *str)
{
	int		*size;
	char	**split;

	fd = open(name, O_RDONLY);
	size = (int*)malloc(sizeof(int) * 2);
	ft_bzero(size, 2 * sizeof(int));
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &str) == 1 && (i = -1) == -1 && (++size[0]))
	{
		split = ft_strsplit(str, ' ');
		while(split[++i])
		{
			if (ft_atoi(split[i]) == 0 && split[i][0] != '0')
				return (0);
			free(split[i]);
		}
		if (size[0] != 1 && i != size[1])
			return (0);
		if (size[0] == 1)
			size[1] = i;
		free(split);
		free(str);
	}
	return (!size[0] || !size[1]) ? (0) : (size);
}

t_fdf	*create_coordinate(double x, double y, double z)
{
	t_fdf *elem;

	elem = (t_fdf*)malloc(sizeof(t_fdf));
	elem->x_str = x;
	elem->y_str = y;
	elem->z_str = z;
	elem->x = x;
	elem->y = y;
	elem->z = z;
	elem->x_r = x;
	elem->y_r = y;
	elem->z_r = z;
	elem->next = NULL;
	return (elem);
}

t_fdf	*writer(char *name, int fd, int y)
{
	int		x;
	char	**split;
	t_fdf	*fdf;
	t_fdf	*begin;

	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &name) == 1 && (++y) && !(x = 0))
	{
		split = ft_strsplit(name, ' ');
		if (y == 1 && ++x == 1)
		{
			fdf = create_coordinate((double)x, (double)y, ft_atoi(split[x - 1]));
			free(split[x - 1]);
			begin = fdf;
		}
		while(split[++x - 1])
		{
			fdf->next = create_coordinate((double)x, (double)y, ft_atoi(split[x - 1]));
			fdf = fdf->next;
			free(split[x - 1]);
		}
		free(split);
		free(name);
	}
	return (begin);
}
