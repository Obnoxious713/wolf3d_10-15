/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@42.us.org>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:50 by gwood             #+#    #+#             */
/*   Updated: 2018/10/24 22:21:35 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include <math.h>
# include "../minilibx/mlx.h"
# include "keys.h"
# include "raycast.h"

# define TEX_COUNT 8
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# define TILE_AT(x, y) v->map.cell[(int)(x)][(int)(y)]

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_map
{
	int			w;
	int			h;
	int			**cell;
}				t_map;

typedef struct	s_img
{
	void		*img;
	char		*pxl;
	int			id;
	int			bpp;
	int			line_size;
	int			endian;
	int			x_off;
	int			y_off;
	int			h;
	int			w;
}				t_img;

typedef struct	s_view
{
	void		*mlx;
	void		*win;
	int			h;
	int			w;
	int			mouse_x;
	int			mouse_y;
	int			**texture;
	int			tex_h;
	int			tex_w;
	int			cur_sec;
	int			past;
	double		old_time;
	double		cur_time;
	double		frame_time;
	double		rot_speed;
	double		move_speed;
	double		*z_buf;
	t_img		img;
	t_map		map;
	t_2d		pos;
	t_2d		dir;
	t_2d		plane;
	t_keys		key;
}				t_view;

/*
** main.c
*/
void			set_hooks(t_view *v);
int				exit_hook(t_view *v);
int				expose_hook(t_view *v);

/*
** draw.c
*/
t_rect			set_rect(int x, int y, int h, int w);
void			draw_ptoi(t_img *img, int x, int y, int color);
void			draw_filled_rect(t_view *v, t_rect r, int color);


/*
** init.c
*/
void			init_view(int h, int w, char *name);

/*
** parser.c
*/
void			bb_free_map(t_map *map);
t_map			bb_parse_map(const char *file);

/*
** hooks.c
*/
int				key_press_hook(t_view *v, int keycode);
int				key_release_hook(t_view *v, int keycode);
int				mouse_press_hook(t_view *v, int keycode, int x, int y);
int				mouse_release_hook(t_view *v, int keycode, int x, int y);
int				motion_hook(t_view *v, int x, int y);

/*
** key.c
*/
void			key_init(t_keys *key);
void			toggle_key(t_keys *key, int keycode, int toggle);

/*
** image.c
*/
void			use_image(t_view *v);
void			create_image(void *mlx, t_img *img, int h, int w);

#endif
