/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:43:04 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 15:43:05 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i/wolf3d.h"

static void		init_vars(t_view *v)
{
	v->pos.x = v->map.h / 2;
	v->pos.y = v->map.w / 2;
	v->dir.x = -1;
	v->dir.y = 0;
	v->plane.x = 0;
	v->plane.y = 0;
	v->cur_sec = 0;
	v->cur_time = 0;
	v->old_time = 0;
	v->mouse_x = 0;
	v->mouse_y = 0;
	v->rot_speed = 0.00016666;
	v->move_speed = 0.00016666;
}

void			init_view(int h, int w, char *name)
{
	t_view		*v;

	if (!(v = (t_view *)ft_memalloc(sizeof(t_view))))
		ft_error_unknown("wolf3d: ");
	v->mlx = mlx_init();
	v->map = bb_parse_map("../maps/basic_room.map");
	v->win = mlx_new_window(v->mlx, h, w, name);
	v->h = h;
	v->w = w;
	v->z_buf = (double*)ft_memalloc(sizeof(double) * WIN_WIDTH);
	init_vars(v);
	key_init(&v->key);
	set_hooks(v);
	mlx_loop_hook(v->mlx, loop_hook, v);
	mlx_loop(v->mlx);

}
