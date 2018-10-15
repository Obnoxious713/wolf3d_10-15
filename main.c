/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:05:45 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/15 13:05:46 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			expose_hook(t_view *view)
{
	(void)view;
	return (0);
}

int			exit_hook(t_view *view)
{
	int			i;

	i = -1;
	if (view->z_buf)
		free(view->z_buf);
	if (view->texture)
	{
		while (++i < TEX_COUNT)
			free(view->texture[i]);
		free(view->texture);
	}
	// if (view->map.cell)
	// 	free_map(&(view->map));
	exit(0);
}

void		set_hooks(t_view *view)
{
	mlx_do_key_autorepeatoff(view->mlx);
	mlx_hook(view->win, 2, 0, key_press_hook, view);
	mlx_hook(view->win, 3, 0, key_release_hook, view);
	mlx_hook(view->win, 4, 0, mouse_press_hook, view);
	mlx_hook(view->win, 5, 0, mouse_release_hook, view);
	mlx_hook(view->win, 6, 0, motion_hook, view);
	mlx_hook(view->win, 12, 0, expose_hook, view);
	mlx_hook(view->win, 17, 0, exit_hook, view);
}

int			main(int ac, char **av)
{
	if (ac != 1 && av)
		exit(1);
	// init_view(WIN_WIDTH, WIN_HEIGHT, "Wolf3d");
	return (0);
}
