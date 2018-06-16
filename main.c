/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:26:48 by msakovyc          #+#    #+#             */
/*   Updated: 2018/05/25 17:26:50 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int			*size;
	t_fdf		*fdf;
	t_window	*wnd;

	if (argc != 2)
	{
		write(1, "NO ARGS\n", 8);
		return (0);
	}
	if ((size = validation(argv[1], 0, 0, "")) != NULL)
	{
		fdf = writer(argv[1], 0, 0);
		wnd = create_wind(fdf, size);
	}
	else
		write(1, "NOT VALID\n", 10);
	return (0);
}
