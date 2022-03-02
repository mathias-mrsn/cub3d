/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/02 15:26:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double
	trigo_cercle(double angle)
{
	if (angle < 0.0)
		return (T_2PI + angle);
	if (angle > T_2PI)
		return (angle - T_2PI);
	else
		return (angle);
}

void
	init_raycasting(t_cub *s, t_raycasting *rayc, int col)
{
	rayc->init_angle = s->player->angle - (FOV / 2);
	rayc->dirx = trigo_cercle(rayc->init_angle + ((((double)FOV / 2) / ((double)s->win_x / 2)) * (double)col));
	rayc->is_up = __trnd((rayc->dirx >= 0.0 && rayc->dirx <= T_PI), true, false);
	rayc->is_left = __trnd((rayc->dirx >= T_PI_2 && rayc->dirx <= T_3PI_2), true, false);
}



double
	pi2degree(double pi)
{
	return (pi * (180 / T_PI));
}

double
	degree2pi(double ang)
{
	return (ang * (T_PI / 180));
}

int
	abs_sup(double n)
{
	return ((int)n + 1);
}

void
	init_ray(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	ray->x = s->player->p_x;
	ray->y = s->player->p_y;
	ray->angle = rayc->dirx;
	ray->sin = sin(rayc->dirx);
	if (ray->vert)
	{
		ray->x_to_add = __trn8(rayc->is_left, -1, 1);
		ray->y_to_add = tan(pi2degree(rayc->dirx));
		ray->y_to_add *= __trn8(rayc->is_up, 1, -1);
	}
	else
	{
		ray->y_to_add = __trn8(rayc->is_up, 1, -1);
		ray->x_to_add = tan(pi2degree(rayc->dirx));
		ray->x_to_add *= __trn8(rayc->is_left, -1, 1);
	}
}

/*




*/

// void
// 	ray_hori(t_cub *s, t_raycasting *rayc, t_ray *ray)
// {
	
// }


void
	ray_vert(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	(void)s;(void)rayc;(void)ray;
	while(ray->x >= 0 && ray->x < s->map_width - 1 && ray->y >= 0 && ray->y < s->map_height - 1)
	{
		if (s->map[(int)ray->x][(int)ray->y] == '1')
			printf("mur\n");
		ray->distance += 1 / ray->sin;
		ray->x += ray->x_to_add;
		ray->y += ray->y_to_add;
	}
	// printf("cos = %f\n", sin(pi2degree(rayc->dirx)));
	// printf("abs = %f\n", (double)((double)abs_sup(ray->x) - ray->x));
	// printf("rayon = %f", ray->x);
	if (rayc->dirx >= 0.0 && rayc->dirx <= T_PI_2)
	{
		printf("sin = %f\n", ray->sin);
		printf("degree = %f\n", pi2degree(rayc->dirx));
		printf("\ndistance = %f\n\n", ray->distance);
	}
}

void
	cast_ray(t_cub *s, t_raycasting *rayc)
{
	t_ray	horizontal;
	t_ray	vertical;

	(void)s;(void)rayc;
	memset(&vertical, 0, sizeof(t_ray));
	memset(&horizontal, 0, sizeof(t_ray));
	vertical.vert = 1;
	init_ray(s, rayc, &vertical);
	init_ray(s, rayc, &horizontal);
	ray_vert(s, rayc, &vertical);
	// ray_hori(s, rayc, &rayc->horizontal);
}

void
	engine(t_cub *s)
{
	int			col;
	t_raycasting	ray;

	(void)s;
	col = 0;
	while (col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		col++;
	}
}

