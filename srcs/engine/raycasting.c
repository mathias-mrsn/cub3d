/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:26:33 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/14 13:34:29 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	init_raycasting(t_cub *s, t_raycasting *rayc, int col)
{
	rayc->init_angle = trigo_cercle(s->player->angle + (FOV / 2));
	rayc->dirx = trigo_cercle(rayc->init_angle
			- ((((double)FOV) / ((double)s->win_x)) * (double)col));
	rayc->is_up = __trnd((rayc->dirx >= 0.0
				&& rayc->dirx <= T_PI), true, false);
	rayc->is_left = __trnd((rayc->dirx >= T_PI_2
				&& rayc->dirx <= T_3PI_2), true, false);
}

void
	init_ray(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	ray->angle = (rayc->dirx);
	ray->sin = sin(rayc->dirx);
	ray->tan = tan(rayc->dirx);
	ray->cos = cos(rayc->dirx);
	if (ray->vert)
	{
		ray->x = (int)s->player->p_x + __trn32(rayc->is_left, 0, 1);
		ray->y = s->player->p_y - (ray->x - s->player->p_x) * ray->tan;
		ray->x_to_add = __trn8(rayc->is_left, -1, 1);
		ray->y_to_add = ray->x_to_add * ray->tan * -1;
	}
	else
	{
		ray->y = (int)s->player->p_y + __trn32(rayc->is_up, 0, 1);
		ray->x = s->player->p_x - (ray->y - s->player->p_y) / ray->tan;
		ray->y_to_add = __trn8(rayc->is_up, -1, 1);
		ray->x_to_add = 1 / ray->tan;
		ray->x_to_add *= __trn8((rayc->is_up), 1, -1);
	}
}

void
	ray_hit_wall(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	int64_t	wall_to_check;

	while (ray->x >= 0 && ray->x <= s->map_width
		&& ray->y >= 0 && ray->y <= s->map_height)
	{
		if (1 == ray->vert)
		{
			wall_to_check = (int)ray->x - rayc->is_left;
			if (wall_to_check < 0)
				wall_to_check = 0;
			if (__is_charset(s->map[(int)ray->y][wall_to_check], "1x"))
				return ;
		}
		else
		{
			wall_to_check = (int)ray->y - rayc->is_up;
			if (wall_to_check < 0)
				wall_to_check = 0;
			if (__is_charset(s->map[wall_to_check][(int)ray->x], "x1"))
				return ;
		}
		ray->x += ray->x_to_add;
		ray->y += ray->y_to_add;
	}
}

void
	compute_distance(t_cub *s, t_raycasting *rayc, t_ray *hor, t_ray *ver)
{
	double	distance_x;
	double	distance_y;

	distance_x = __pythagore(s->player->p_x, s->player->p_y, hor->x, hor->y);
	distance_y = __pythagore(s->player->p_x, s->player->p_y, ver->x, ver->y);
	if (distance_x < distance_y)
	{
		rayc->distance = distance_x;
		rayc->hit_x = hor->x;
		rayc->hit_y = hor->y;
	}
	else
	{
		rayc->distance = distance_y;
		rayc->hit_x = ver->x;
		rayc->hit_y = ver->y;
	}
	if (rayc->hit_x - (int)rayc->hit_x == 0)
		rayc->wall_type = __trn32(rayc->is_left, WEST_SIDE, EST_SIDE);
	else if (rayc->hit_y - (int)rayc->hit_y == 0)
		rayc->wall_type = __trn32(rayc->is_up, NORTH_SIDE, SOUTH_SIDE);
}

void
	cast_ray(t_cub *s, t_raycasting *rayc)
{
	t_ray	horizontal;
	t_ray	vertical;

	__memset(&vertical, 0, sizeof(t_ray));
	__memset(&horizontal, 0, sizeof(t_ray));
	vertical.vert = 1;
	horizontal.vert = 0;
	init_ray(s, rayc, &vertical);
	init_ray(s, rayc, &horizontal);
	ray_hit_wall(s, rayc, &horizontal);
	ray_hit_wall(s, rayc, &vertical);
	compute_distance(s, rayc, &horizontal, &vertical);
}
