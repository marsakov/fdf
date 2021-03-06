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

# define HEIGHT 1200
# define WIDTH 2000
# define ABS(x) (x < 0) ? x * (-1) : x
# define MAX(x, y) (x < y) ? y : x

typedef struct			s_fdf
{
	double				x;
	double				y;
	double				z;
	double				x_str;
	double				y_str;
	double				z_str;
	double				x_r;
	double				y_r;
	double				z_r;
	int					color;
	struct s_fdf		*next;
}						t_fdf;

typedef struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	double				x_sr;
	double				y_sr;
	double				sdvig_x;
	double				sdvig_y;
	double				k;
	double				a;
	double				b;
	double				c;
	t_fdf				*fdf;
	t_fdf				*str_fdf;
}						t_window;

int						*validation(char *name, int i, int fd, char *str);
t_fdf					*create_coordinate(double x, double y, char *str);
t_fdf					*writer(char *name, int fd, int y);

t_fdf					*jump_to(t_fdf *fdf, int n);
void					drawer(t_window *window);
int						deal_key(int key, t_window *wnd);
t_window				*create_wind(t_fdf *fdf, int *size);

void					line(t_window *wnd, t_fdf fdf1, t_fdf fdf2);

void					change_sr(t_window *wnd);
void					change(t_window *wnd);
void					change_angles(t_window *wnd, int value, int op);
void					rotate_coordinate(t_window *wnd, int value, int op);
void					start_coordinate(t_window *wnd);

#endif
