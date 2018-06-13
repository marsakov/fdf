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
			line(wnd->mlx_ptr, wnd->win_ptr, *tmp, *(tmp->next));
		if (i < wnd->width * (wnd->height - 1) + 1)
			line(wnd->mlx_ptr, wnd->win_ptr, *tmp, *(jump_to(tmp, wnd->width)));
		tmp = tmp->next;
	}
	mlx_pixel_put(wnd->mlx_ptr, wnd->win_ptr, tmp->x, tmp->y, 0xEFFA61);

}

int			deal_key(int key, t_window *wnd)
{
	mlx_clear_window(wnd->mlx_ptr, wnd->win_ptr);
	if (key == 126)
		share_coordinate(wnd->fdf, 0, 0);
	if (key == 125)
		share_coordinate(wnd->fdf, 0, 1);
	if (key == 123)
		share_coordinate(wnd->fdf, 1, 0);
	if (key == 124)
		share_coordinate(wnd->fdf, 1, 1);
	if (key == 69)
		mult_coordinate(wnd->fdf, 1);
	if (key == 78)
		mult_coordinate(wnd->fdf, 0);
	if (key == 89)
		rotate_coordinate(wnd, 1, 1);
	if (key == 83)
		rotate_coordinate(wnd, 1, 0);
	if (key == 91)
		rotate_coordinate(wnd, 2, 1);
	if (key == 84)
		rotate_coordinate(wnd, 2, 0);
	if (key == 92)
		rotate_coordinate(wnd, 3, 1);
	if (key == 85)
		rotate_coordinate(wnd, 3, 0);
	drawer(wnd);
	return (0);
}

t_window	*create_wind(t_fdf *fdf, int *size)
{
	t_window	*wnd;

	wnd = (t_window*)malloc(sizeof(t_window));
	wnd->mlx_ptr = mlx_init();
	wnd->win_ptr = mlx_new_window(wnd->mlx_ptr, 2000, 1200, "fdf");
	wnd->height = size[0];
	wnd->width = size[1];
	wnd->fdf = fdf;
	wnd->a = 0;
	wnd->b = 0;
	wnd->c = 0;
	drawer(wnd);
	mlx_hook(wnd->win_ptr, deal_key, wnd);
	mlx_loop(wnd->mlx_ptr);
	return (wnd);
}
