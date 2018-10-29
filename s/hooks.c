/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:46:56 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 14:46:56 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../i/wolf3d.h"

int				key_press_hook(t_view *v, int keycode)
{
	if (keycode == KEY_ESC)
		exit_hook(v);
	toggle_key(&v->key, keycode, 1);
	return (0);
}

int				key_release_hook(t_view *v, int keycode)
{
	toggle_key(&v->key, keycode, 0);
	return (0);
}

int				mouse_press_hook(t_view *v, int keycode, int x, int y)
{
	(void)keycode;
	v->mouse_x = x;
	v->mouse_y = y;
	return (0);
}

int				mouse_release_hook(t_view *v, int keycode, int x, int y)
{
	(void)keycode;
	v->mouse_x = x;
	v->mouse_y = y;
	return (0);
}

int				motion_hook(t_view *v, int x, int y)
{
	if (v->mouse_x < x)
		player_turn(v, -1, 0.5);
	else if (v->mouse_x > x)
		player_turn(v, 1, 0.5);
	v->mouse_x = x;
	v->mouse_y = y;
	return (0);
}
