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
	t_fdf *tmp;
	t_window	*wnd;

	if (argc != 2)
	{
		printf("NOT ARGS\n");
		return (0);
	}
	if ((size = validation(argv[1], 0, 0, "")) != NULL)
	{
		printf("validation OK | %d x %d\n", size[0], size[1]);
		fdf = writer(argv[1], 0, 0);//, fmin(WIDTH / (size[0] + 1), HEIGHT / (size[1] + 1)));
		// tmp = fdf;
		// while (tmp)
		// {
		// 	printf(" z = %f \n", tmp->z);
		// 	tmp = tmp->next;
		// }
		wnd = create_wind(fdf, size);
	}
	else
		printf("NOT VALID\n");
	return (0);
}