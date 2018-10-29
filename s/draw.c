/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:11:18 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 16:11:18 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i/wolf3d.h"

void			draw_ptoi(t_img *img, int x, int y, int color)
{
	int			i;

	if (x > 0 && x < img->w && y > 0 && y < img->h)
	{
		i = (x * (img->bpp / 8)) + (y * img->line_size);
		img->pxl[i] = color;
		img->pxl[++i] = color >> 8;
		img->pxl[++i] = color >> 16;
	}
}

void			draw_filled_rect(t_view *v, t_rect r, int color)
{
	int			x;
	int			y;

	y = -1;
	while (++y < r.h)
	{
		x = -1;
		while (++x < r.w)
			draw_ptoi(&v->img, x + r.x, y + r.y, color);
	}
}

// void			draw_filled_sq(t_view *v, t_2d p, int size, int color)
// {
// 	int			x;
// 	int			y;

// 	y = -1;
// 	while (++y < size)
// 	{
// 		x = -1;
// 		while (++x < size)
// 			draw_ptoi(&v->img, x + p.x, y + p.y, color);
// 	}
// }

t_rect			set_rect(int x, int y, int h, int w)
{
	t_rect		r;

	r.x = x;
	r.y = y;
	r.h = h;
	r.w = w;
	return (r);
}
