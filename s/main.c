/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 14:36:38 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 22:22:06 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i/wolf3d.h"
#include "../i/color.h"
#include <stdio.h>

int				expose_hook(t_view *v)
{
	(void)v;
	return (0);
}

int				exit_hook(t_view *v)
{
	int			i;

	if (v->z_buf)
		free(v->z_buf);
	if (v->texture)
	{
		i = -1;
		while (++i < TEX_COUNT)
			free(v->texture[i]);
		free(v->texture);
	}
	if (v->map.cell)
		bb_free_map(&(v->map));
	exit(0);
}

void			set_hooks(t_view *v)
{
	mlx_do_key_autorepeatoff(v->mlx);
	mlx_hook(v->win, 2, 0, key_press_hook, v);
	mlx_hook(v->win, 3, 0, key_release_hook, v);
	mlx_hook(v->win, 4, 0, mouse_press_hook, v);
	mlx_hook(v->win, 5, 0, mouse_release_hook, v);
	mlx_hook(v->win, 6, 0, motion_hook, v);
	mlx_hook(v->win, 12, 0, expose_hook, v);
	mlx_hook(v->win, 17, 0, exit_hook, v);
}
/*
** Duh
*/
int				main(void)
{
	init_view(WIN_HEIGHT, WIN_WIDTH, "Wolf3D");
	return (0);
}
