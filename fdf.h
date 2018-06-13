/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:41:19 by msakovyc          #+#    #+#             */
/*   Updated: 2018/05/25 18:41:21 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "mlx.h"
# include "math.h"
#include <stdio.h>

# define ABS(x) (x < 0) ? x * (-1) : x
# define MAX(x, y) (x < y) ? y : x

typedef struct			s_fdf
{
	double				x;
	double				y;
	double				z;
	double				k;
	struct s_fdf		*next;
}						t_fdf;

typedef struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	double				k;
	double				c_x;
	double				c_y;
	double				c_z;
	double				a;
	double				b;
	double				c;
	t_fdf				*fdf;
}						t_window;

int			main(int argc, char **argv);
int			*validation(char *name, int i, int fd, char *str);
t_fdf		*create_coordinate(double x, double y, double z, double k);
t_fdf		*writer(char *name, int fd, int y, int k);
t_fdf		*jump_to(t_fdf *fdf, int n);
void		drawer(t_window *window);
int			deal_key(int key, t_window *wnd);
t_window	*create_wind(t_fdf *fdf, int *size);
void		line(void *mlx_ptr, void *win_ptr, t_fdf fdf1, t_fdf fdf2);
void		share_coordinate(t_fdf *fdf, int value, int op);
void		mult_coordinate(t_fdf *fdf, int op);
void		rotate_coordinate(t_window *wnd, int value, int op);

#endif
