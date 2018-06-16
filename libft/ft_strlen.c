/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <msakovyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:43:14 by msakovyc          #+#    #+#             */
/*   Updated: 2018/03/27 16:09:00 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s && *(s + len))
		len++;
	return (len);
}
