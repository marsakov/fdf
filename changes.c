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

void	mult_coordinate(t_fdf *fdf, int op)
{
	t_fdf *tmp;

	tmp = fdf;
	while (tmp && tmp->x > 20)
	{
		if (op)
		{
			tmp->x *= 1.025;// - tmp->k / n;
			tmp->y *= 1.025;// - tmp->k / n;
		}
		else
		{
			tmp->x /= 1.025;// - tmp->k / n;
			tmp->y /= 1.025;// - tmp->k / n;
		}
		tmp = tmp->next;
	}
}

void	share_coordinate(t_fdf *fdf, int value, int op)
{
	t_fdf *tmp;

	tmp = fdf;
	while (tmp)
	{
		if (value)
			tmp->x = (op) ? tmp->x + 5 : tmp->x - 5;
		else
			tmp->y = (op) ? tmp->y + 5 : tmp->y - 5;
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
		tx = p->x;
		ty = p->y;
		tz = p->z;
		p->y = ty * cos(wnd->a) + tz * -sin(wnd->a);
		p->z = ty * sin(wnd->a) + tz * cos(wnd->a);
		tz = p->z;
		p->x = tx * cos(wnd->b) + tz * sin(wnd->b);
		p->z = tx * -sin(wnd->b) + tz * cos(wnd->b);
		ty = p->y;
		tx = p->x;
		p->x = tx * cos(wnd->c) + ty * -sin(wnd->c);
		p->y = tx * sin(wnd->c) + ty * cos(wnd->c);
		p = p->next;
	}
}