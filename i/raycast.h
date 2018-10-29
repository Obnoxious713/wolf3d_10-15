/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:38:02 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 13:38:02 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct	s_2d
{
	double		x;
	double		y;
}				t_2d;

typedef struct s_raycast
{
	int			map_x;
	int			map_y;
	t_2d		camera;
	t_2d		ray_pos;
	t_2d		ray_dir;
	t_2d		side_dist;
	t_2d		delta_dist;
	double		perp_wall_dist;
	double		wall_x;
	int			hit;
	int			step_x;
	int			step_y;
	int			tex_x;
	int			tex_y;
	int			side;
	int			tile;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_raycast;

#endif
