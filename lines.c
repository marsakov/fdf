/* ************************************************************************** */
/*                                                                         */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:42:48 by msakovyc          #+#    #+#             */
/*   Updated: 2018/06/08 15:42:50 by msakovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(void *mlx_ptr, void *win_ptr, t_fdf fdf1, t_fdf fdf2)
{
      int dx = (fdf2.x - fdf1.x >= 0 ? 1 : -1);
      int dy = (fdf2.y - fdf1.y >= 0 ? 1 : -1);
 
      int lengthX = ABS(fdf2.x - fdf1.x);
      int lengthY = ABS(fdf2.y - fdf1.y);
 
      int length = MAX(lengthX, lengthY);
 
      if (length == 0)
      {
            mlx_pixel_put(mlx_ptr, win_ptr, fdf1.x, fdf1.y, 0xEFFA61);
      }
 
      if (lengthY <= lengthX)
      {
            // Начальные значения
            int x = fdf1.x;
            int y = fdf1.y;
            int d = -lengthX;
 
            // Основной цикл
            length++;
            while(length--)
            {
                  mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xEFFA61);
                  x += dx;
                  d += 2 * lengthY;
                  if (d > 0) {
                        d -= 2 * lengthX;
                        y += dy;
                  }
            }
      }
      else
      {
            // Начальные значения
            int x = fdf1.x;
            int y = fdf1.y;
            int d = - lengthY;
 
            // Основной цикл
            length++;
            while(length--)
            {
                  mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xEFFA61);
                  y += dy;
                  d += 2 * lengthX;
                  if (d > 0) {
                        d -= 2 * lengthY;
                        x += dx;
                  }
            }
      }
}

