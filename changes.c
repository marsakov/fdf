/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:58:20 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/11 20:58:22 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change(t_window *wnd)
{
	t_fdf *tmp;

	tmp = wnd->fdf;
	while (tmp)
	{
		tmp->x = ((WIDTH / 2) + (tmp->x_r - wnd->x_sr) * wnd->k) + wnd->sdvig_x;
		tmp->y = ((HEIGHT / 2) + (tmp->y_r - wnd->y_sr) * wnd->k) + wnd->sdvig_y;
		tmp = tmp->next;
	}
}

void	rotate_coordinate(t_window *wnd, int value, int op)
{
	double	tx;
	double	ty;
	double	tz;
	t_fdf	*p;

	p = wnd->fdf;
	if (value == 1)
		wnd->a = (op) ? wnd->a + 0.1 : wnd->a - 0.1;
	else if (value == 2)
		wnd->b = (op) ? wnd->b + 0.1 : wnd->b - 0.1;
	else
		wnd->c = (op) ? wnd->c + 0.1 : wnd->c - 0.1;
	while (p)
	{
		tx = p->x_str;
		ty = p->y_str;
		tz = p->z_str;
		p->y_r = ty * cos(wnd->a) + tz * -sin(wnd->a);
		p->z_r = ty * sin(wnd->a) + tz * cos(wnd->a);
		tz = p->z_r;
		p->x_r = tx * cos(wnd->b) + tz * sin(wnd->b);
		p->z_r = tx * -sin(wnd->b) + tz * cos(wnd->b);
		ty = p->y_r;
		tx = p->x_r;
		p->x_r = tx * cos(wnd->c) + ty * -sin(wnd->c);
		p->y_r = tx * sin(wnd->c) + ty * cos(wnd->c);
		p = p->next;
	}
}