/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:17:11 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 15:17:12 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../i/wolf3d.h"

static void		key_init_num(t_keys *key)
{
	key->one = 0;
	key->two = 0;
	key->three = 0;
	key->four = 0;
	key->five = 0;
	key->six = 0;
	key->seven = 0;
	key->eight = 0;
	key->nine = 0;
	key->zero = 0;
}

void			key_init(t_keys *key)
{
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	key->q = 0;
	key->e = 0;
	key->z = 0;
	key->x = 0;
	key->c = 0;
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
	key->space = 0;
	key->esc = 0;
	key_init_num(key);
}

static void		toggle_one(t_keys *key, int keycode, int toggle)
{
	if (keycode == KEY_W)
		key->w = toggle;
	if (keycode == KEY_A)
		key->a = toggle;
	if (keycode == KEY_S)
		key->s = toggle;
	if (keycode == KEY_D)
		key->d = toggle;
	if (keycode == KEY_Q)
		key->q = toggle;
	if (keycode == KEY_E)
		key->e = toggle;
	if (keycode == KEY_Z)
		key->z = toggle;
	if (keycode == KEY_X)
		key->x = toggle;
	if (keycode == KEY_C)
		key->c = toggle;
	if (keycode == KEY_SPACE)
		key->space = toggle;
	if (keycode == KEY_ESC)
		key->esc = toggle;
}

static void		toggle_num(t_keys *key, int keycode, int toggle)
{
	if (keycode == KEY_1)
		key->one = toggle;
	if (keycode == KEY_2)
		key->two = toggle;
	if (keycode == KEY_3)
		key->three = toggle;
	if (keycode == KEY_4)
		key->four = toggle;
	if (keycode == KEY_5)
		key->five = toggle;
	if (keycode == KEY_6)
		key->six = toggle;
	if (keycode == KEY_7)
		key->seven = toggle;
	if (keycode == KEY_8)
		key->eight = toggle;
	if (keycode == KEY_9)
		key->nine = toggle;
	if (keycode == KEY_0)
		key->zero = toggle;
}

void			toggle_key(t_keys *key, int keycode, int toggle)
{

	if (keycode == KEY_UP)
		key->up = toggle;
	if (keycode == KEY_DOWN)
		key->down = toggle;
	if (keycode == KEY_LEFT)
		key->left = toggle;
	if (keycode == KEY_RIGHT)
		key->right = toggle;
	if (((keycode >= 26 && keycode <= 31) || (keycode >= 33 && keycode <= 37))
			&& keycode != 32 && keycode != 35)
		toggle_num(key, keycode, toggle);
	else
		toggle_one(key, keycode, toggle);
}
