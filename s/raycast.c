/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:20:39 by jfleisch          #+#    #+#             */
/*   Updated: 2018/10/29 16:20:39 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../i/wolf3d.h"

void			set_delta_dist(t_raycast *rc)
{
	t_2d		ray_dir_sq;

	ray_dir_sq.x = rc->ray_dir.x * rc->ray_dir.x;
	ray_dir_sq.y = rc->ray_dir.y * rc->ray_dir.y;
	rc->delta_dist.x = sqrt(1 + (ray_dir_sq.y) / (ray_dir_sq.x));
	rc->delta_dist.y = sqrt(1 + (ray_dir_sq.x) / (ray_dir_sq.y));

}

void			set_step_and_side_dist(t_raycast *rc)
{
	if (rc->ray_dir.x < 0)
	{
		rc->step_x = -1;
		rc->side_dist.x = (rc->ray_pos.x - rc->map_x) * rc->delta_dist.x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist.x = (rc->map_x + 1.0 - rc->ray_pos.x) * rc->delta_dist.x;
	}
	if (rc->ray_dir.y < 0)
	{
		rc->step_y = -1;
		rc->side_dist.y = (rc->ray_pos.y - rc->map_y) * rc->delta_dist.y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist.y = (rc->map_y + 1.0 - rc->ray_pos.y) * rc->delta_dist.y;
	}
}

void			raycast_init(t_view *v, t_raycast *rc, int x)
{
	rc->camera.x = 2 * x / (double)v->w - 1;
	rc->ray_pos.x = v->pos.x;
	rc->ray_pos.y = v->pos.y;
	rc->ray_dir.x = v->dir.x + v->plane.x * rc->camera.x;
	rc->ray_dir.y = v->dir.y + v->plane.y * rc->camera.x;
	rc->map_x = (int)v->pos.x;
	rc->map_y = (int)v->pos.y;
	rc->tile = TILE_AT(rc->map_x, rc->map_y);
	rc->hit = 0;
}

void			raycast_dda(t_view *v, t_raycast *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta_dist.x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta_dist.y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		rc->tile = TILE_AT(rc->map_x, rc->map_y);
		if (rc->tile > 0)
			rc->hit = 1;
	}
}
