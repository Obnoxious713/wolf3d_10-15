/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:29:52 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/05 13:29:53 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				key_release_hook(int keycode, t_view *view)
{
	key_toggle(&view->key, keycode, 0);
	return (0);
}

int				key_press_hook(int keycode, t_view *view)
{
	if (keycode == KEY_ESC)
		exit(0);
	key_toggle(&view->key, keycode, 1);
	if (keycode == KEY_R)
		view->plane.y = .66; //* .77
	if (keycode == KEY_T)
		view->plane.x = 0;
	return (0);
}

void			key_toggle(t_keys *key, int keycode, int toggle)
{
	if (keycode < 27)
		key_toggle_1(key, keycode, toggle);
	else
		key_toggle_2(key, keycode, toggle);
}
