/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:01:59 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 16:01:59 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i/wolf3d.h"

void			use_image(t_view *v)
{
	mlx_put_image_to_window(v->mlx, v->win, v->img.img,
								v->img.x_off, v->img.y_off);
	mlx_destroy_image(v->mlx, v->img.img);
}

void			create_image(void *mlx, t_img *img, int h, int w)
{
	img->h = h;
	img->w = w;
	img->img = mlx_new_image(mlx, w, h);
	img->pxl = mlx_get_data_addr(img->img, &(img->bpp),
									&(img->line_size), &(img->endian));
}
