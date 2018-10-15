/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:03:04 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:03:05 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				motion_hook(int x, int y, t_view *view)
{
	// if (view->mouse_x < x)
	// 	player_turn(view, -1, 0.5);
	// else if (view->mouse_x > x)
	// 	player_turn(view, 1, 0.5);
	view->mouse_x = x;
	view->mouse_y = y;
	return (0);
}

int				mouse_press_hook(int button, int x, int y, t_view *view)
{
	(void)button;
	view->mouse_x = x;
	view->mouse_y = y;
	return (0);
}

int				mouse_release_hook(int button, int x, int y, t_view *view)
{
	(void)button;
	view->mouse_x = x;
	view->mouse_y = y;
	return (0);
}
