/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:26:33 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/26 14:33:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	ray_hit_ver(t_cub *s, t_raycasting *rayc, t_ray *ray, char *limiters)
{
	int64_t	wall_to_check;

	wall_to_check = __trn64(((int)ray->x - rayc->is_left < 0),
			0, (int)ray->x - rayc->is_left);
	if (__is_charset(s->map[(int)ray->y][wall_to_check], limiters)
			|| (s->map[(int)ray->y][wall_to_check] == 'D'
			&& through_door(s, ray, (int)ray->y, (int)wall_to_check)))
		return (1);
	if (__is_charset(s->map[(int)ray->y][wall_to_check], "2"))
		init_new_sprite(s, rayc, ray);
	return (0);
}

int
	ray_hit_hor(t_cub *s, t_raycasting *rayc, t_ray *ray, char *limiters)
{
	int64_t	wall_to_check;

	wall_to_check = __trn64(((int)ray->y - rayc->is_up < 0),
			0, (int)ray->y - rayc->is_up);
	if (__is_charset(s->map[wall_to_check][(int)ray->x], limiters)
			|| (s->map[wall_to_check][(int)ray->x] == 'D'
			&& through_door(s, ray, (int)wall_to_check, (int)ray->x)))
		return (1);
	if (__is_charset(s->map[wall_to_check][(int)ray->x], "2"))
		init_new_sprite(s, rayc, ray);
	return (0);
}

void
	ray_hit_wall(t_cub *s, t_raycasting *rayc, t_ray *ray, char *limiters)
{
	while (ray->x >= 0 && ray->x <= s->map_width
		&& ray->y >= 0 && ray->y <= s->map_height)
	{
		if (ray->vert)
		{
			if (ray_hit_ver(s, rayc, ray, limiters))
				return ;
		}
		else
		{
			if (ray_hit_hor(s, rayc, ray, limiters))
				return ;
		}
		ray->x += ray->x_to_add;
		ray->y += ray->y_to_add;
	}
}

void
	compute_distance(t_raycasting *rayc, t_ray *hor, t_ray *ver)
{
	if (hor->distance < ver->distance)
	{
		rayc->distance = hor->distance;
		rayc->hit_x = hor->x;
		rayc->hit_y = hor->y;
		rayc->hit_door = hor->hit_door;
		rayc->door = hor->door;
		rayc->vert = false;
	}
	else
	{
		rayc->distance = ver->distance;
		rayc->hit_x = ver->x;
		rayc->hit_y = ver->y;
		rayc->hit_door = ver->hit_door;
		rayc->door = ver->door;
		rayc->vert = true;
	}
	if (rayc->hit_x - (int)rayc->hit_x == 0)
		rayc->wall_type = __trn32(rayc->is_left, WEST_SIDE, EST_SIDE);
	else if (rayc->hit_y - (int)rayc->hit_y == 0)
		rayc->wall_type = __trn32(rayc->is_up, NORTH_SIDE, SOUTH_SIDE);
}

void
	cast_ray(t_cub *s, t_raycasting *rayc)
{
	t_ray	hor;
	t_ray	ver;

	__memset(&ver, 0, sizeof(t_ray));
	__memset(&hor, 0, sizeof(t_ray));
	ver.vert = 1;
	hor.vert = 0;
	init_ray(s, rayc, &ver);
	init_ray(s, rayc, &hor);
	ray_hit_wall(s, rayc, &hor, "1x");
	ray_hit_wall(s, rayc, &ver, "1x");
	hor.distance = __pythagore(s->player->p_x, s->player->p_y, hor.x, hor.y);
	ver.distance = __pythagore(s->player->p_x, s->player->p_y, ver.x, ver.y);
	compute_distance(rayc, &hor, &ver);
	set_error_sprite(rayc);
}
