/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:05:58 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/15 13:05:59 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "minilibx/mlx.h"
# include "keys.h"
# include "libft/libft.h"

# include <time.h>
# include <mach/clock.h>
# include <mach/mach.h>

# define TEX_COUNT 8
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define TITLE_AT(x, y) view->map.cell[(int)(x)][(int)(y)]

typedef struct		s_2d
{
	double			x;
	double			y;
}					t_2d;

typedef struct		s_rect
{
	int				x;
	int				y;
	int				w;
	int				h;
}					t_rect;

typedef struct		s_img
{
	int				id;
	void			*img;
	char			*pxls;
	int				bpp;
	int				size_line;
	int				endian;
	int				x_off;
	int				y_off;
	int				w;
	int				h;
}					t_img;

typedef struct		s_map
{
	int				width;
	int				height;
	int				**cell;
}					t_map;

typedef struct		s_view
{
	void			*mlx;
	void			*win;
	void			*mini_win;
	int				**texture;
	int				w;
	int				h;
	int				mouse_x;
	int				mouse_y;
	int				tex_w;
	int				tex_h;
	int				cur_sec;
	int				past;
	double			old_time;
	double			cur_time;
	double			frame_time;
	double			rot_speed;
	double			move_speed;
	double			*z_buf;
	t_map			map;
	t_2d			pos;
	t_2d			dir;
	t_2d			plane;
	t_img			img;
	t_img			mini_img;
	t_keys			key;
}					t_view;

typedef struct		s_floorcast
{
	t_2d			wall;
	t_2d			pos;
	int				tex_x;
	int				tex_y;
	int				texture;
	double			weight;
}					t_floorcast;

typedef struct		s_raycast
{
	t_2d			cam;
	t_2d			ray_pos;
	t_2d			ray_dir;
	t_2d			side_dist;
	t_2d			delta_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				tex_x;
	int				tex_y;
	int				tile;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	double			perp_wall_dist;
}					t_raycast;

int					expose_hook(t_view *view);
int					exit_hook(t_view *view);
void				set_hooks(t_view *view);

int					key_release_hook(int keycode, t_view *view);
int					key_press_hook(int keycode, t_view *view);
void				key_toggle(t_keys *key, int keycode, int toggle);

int					motion_hook(int x, int y, t_view *view);
int					mouse_press_hook(int button, int x, int y, t_view *view);
int					mouse_release_hook(int button, int x, int y, t_view *view);



#endif

