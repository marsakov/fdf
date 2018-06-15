/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:59:03 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/11 20:59:05 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*jump_to(t_fdf *fdf, int n)
{
	t_fdf *tmp;

	tmp = fdf;
	while (tmp && n--)
		tmp = tmp->next;
	return (tmp);
}

void		drawer(t_window *wnd)
{
	int		i;
	t_fdf	*tmp;

	i = 0;
	tmp = wnd->fdf;
	while (tmp->next && ++i)
	{
		mlx_pixel_put(wnd->mlx_ptr, wnd->win_ptr, tmp->x, tmp->y, 0xEFFA61);
		if (i % wnd->width != 0)
			line(wnd, *tmp, *(tmp->next));
		if (i < wnd->width * (wnd->height - 1) + 1)
			line(wnd, *tmp, *(jump_to(tmp, wnd->width)));
		tmp = tmp->next;
	}
	mlx_pixel_put(wnd->mlx_ptr, wnd->win_ptr, tmp->x, tmp->y, 0xEFFA61);
}

void		change_sr(t_window *wnd)
{
	t_fdf	*tmp;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;

	tmp = wnd->fdf;
	max_y = tmp->y_r;
	min_y = tmp->y_r;
	max_x = tmp->x_r;
	min_x = tmp->x_r;
	while (tmp)
	{
		if (tmp->x_r > max_x)
			max_x = tmp->x_r;
		else if (tmp->x_r < min_x)
			min_x = tmp->x_r;
		if (tmp->y_r > max_y)
			max_y = tmp->y_r;
		else if (tmp->y_r < min_y)
			min_y = tmp->y_r;
		tmp = tmp->next;
	}
	wnd->x_sr = (max_x - min_x) / 2;
	wnd->y_sr = (max_y - min_y) / 2;
}

int			deal_key(int key, t_window *wnd)
{
	mlx_clear_window(wnd->mlx_ptr, wnd->win_ptr);
	if (key == 126)
		wnd->sdvig_y -= 5;
	if (key == 125)
		wnd->sdvig_y += 5;
	if (key == 123)
		wnd->sdvig_x -= 5;
	if (key == 124)
		wnd->sdvig_x += 5;
	if (key == 69)
		wnd->k *= 1.025;
	if (key == 78)
		wnd->k /= 1.025;
	if (key == 89 || key == 83)
		rotate_coordinate(wnd, 1, (key == 89) ? 1 : 0);
	if (key == 91 || key == 84)
		rotate_coordinate(wnd, 2, (key == 91) ? 1 : 0);
	if (key == 92 || key == 85)
		rotate_coordinate(wnd, 3, (key == 92) ? 1 : 0);
	change_sr(wnd);
	change(wnd);
	drawer(wnd);
	return (0);
}

t_window	*create_wind(t_fdf *fdf, int *size)
{
	t_window	*wnd;

	wnd = (t_window*)malloc(sizeof(t_window));
	wnd->mlx_ptr = mlx_init();
	wnd->win_ptr = mlx_new_window(wnd->mlx_ptr, WIDTH, HEIGHT, "fdf");
	wnd->height = size[0];
	wnd->width = size[1];
	wnd->fdf = fdf;
	wnd->a = 0;
	wnd->b = 0;
	wnd->c = 0;
	wnd->color = 0xEFFA61;
	wnd->sdvig_x = 0;
	wnd->sdvig_y = 0;
	wnd->x_sr = size[1] / 2;
	wnd->y_sr = size[0] / 2;
	wnd->k = fmin(WIDTH / (size[0] + 1), HEIGHT / (size[1] + 1));
	change(wnd);
	drawer(wnd);
	mlx_hook(wnd->win_ptr, 2, 5, deal_key, wnd);
	mlx_loop(wnd->mlx_ptr);
	return (wnd);
}
