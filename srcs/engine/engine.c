/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/03 14:11:13 by mamaurai         ###   ########.fr       */
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
	rayc->init_angle = trigo_cercle(s->player->angle + (FOV / 2));
	rayc->dirx = trigo_cercle(rayc->init_angle - ((((double)FOV) / ((double)s->win_x)) * (double)col));
	rayc->is_up = __trnd((rayc->dirx >= 0.0 && rayc->dirx <= T_PI), true, false);
	rayc->is_left = __trnd((rayc->dirx >= T_PI_2 && rayc->dirx <= T_3PI_2), true, false);
	if (rayc->is_up)
	{
		rayc->dirx = 
	}
	else
	{
		
	}
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
	ray->angle = rayc->dirx;
	ray->sin = sin(rayc->dirx);
	if (ray->vert)
	{
		ray->x = (int)s->player->p_x + __trn32(rayc->is_left, 0, 1);
		ray->y = s->player->p_y - (ray->x - s->player->p_x) * tan(ray->angle);
		ray->x_to_add = __trn8(rayc->is_left, -1, 1);
		ray->y_to_add = ray->x_to_add * tan(ray->angle);
		ray->y_to_add *= __trn8(rayc->is_up, 1, -1);
	}
	else
	{
		ray->y = (int)s->player->p_y + __trn32(rayc->is_up, 0, 1);
		ray->x = s->player->p_x + (ray->y - s->player->p_y) * tan(ray->angle);
		ray->y_to_add = __trn8(rayc->is_up, -1, 1);
		ray->x_to_add = ray->y_to_add * tan(ray->angle);
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
	ray_hor(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	(void)s;(void)rayc;(void)ray;
	while(ray->x >= 0 && ray->x < s->map_width && ray->y >= 0 && ray->y < s->map_height)
	{
		printf("in");
		ray->x += ray->x_to_add;
		ray->y += ray->y_to_add;
	}
	// printf("cos = %f\n", sin(pi2degree(rayc->dirx)));
	// printf("abs = %f\n", (double)((double)abs_sup(ray->x) - ray->x));
	// printf("rayon = %f", ray->x);
	// if (rayc->dirx >= 0.0 && rayc->dirx <= T_PI_2)
	// {
		// printf("sin = %f\n", ray->sin);
		// printf("x = %f\n", ray->x);
		// printf("y = %f\n", ray->y);
	// }
}

void
	ray_ver(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	(void)s;(void)rayc;(void)ray;
	while(ray->x >= 0 && ray->x < s->map_width && ray->y >= 0 && ray->y < s->map_height)
	{
		ray->x += ray->x_to_add;
		ray->y += ray->y_to_add;
	}
	// printf("cos = %f\n", sin(pi2degree(rayc->dirx)));
	// printf("abs = %f\n", (double)((double)abs_sup(ray->x) - ray->x));
	// printf("rayon = %f", ray->x);
	// if (rayc->dirx >= 0.0 && rayc->dirx <= T_PI_2)
	// {
		// printf("sin = %f\n", ray->sin);
		// printf("x = %f\n", ray->x);
		// printf("y = %f\n", ray->y);
	// }
}

void
	compute_distance(t_cub *s, t_raycasting *rayc, t_ray *hor, t_ray *ver)
{
	double	distance_x;
	double	distance_y;

	distance_x = __pythagore(s->player->p_x, s->player->p_y, hor->x, hor->y);
	distance_y = __pythagore(s->player->p_x, s->player->p_y, ver->x, ver->y);
	printf("d_x = %f | d_y = %f --- p_x = %f | p_y = %f\n", distance_x, distance_y, hor->x - 1, hor->y - 1);
	if (distance_x < distance_y)
		rayc->distance = distance_x;
	else
		rayc->distance = distance_y;
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
	horizontal.vert = 0;
	init_ray(s, rayc, &vertical);
	init_ray(s, rayc, &horizontal);
	// ray_hor(s, rayc, &horizontal);
	// ray_ver(s, rayc, &vertical);
	compute_distance(s, rayc, &horizontal, &vertical);
	// rayc->distance = __pythagore(s->player->p_x, s->player->p_y, vertical.x, vertical.y);
	// printf("distance = %f\n", rayc->distance);
	// ray_hori(s, rayc, &rayc->horizontal);
}

void
	put_ray_on_img(t_cub *s, t_raycasting *rayc, int col)
{
	// double	is_in;
	int	idx;
	int	lineheight;

	lineheight = s->win_y / rayc->distance;
	

	idx = 0;
	printf("distance = %f\n\n", rayc->distance); 
	while (idx < s->win_y)
	{
		// printf("here\n");
		// is_in = 1 / rayc->distance;
		
		if (((idx / 2) - lineheight) < 0)
			__put_pixel_on_img(&s->img, col, idx, (int)(14325));
		idx++;
	}
}

void
	engine(t_cub *s)
{
	int			col;
	t_raycasting	ray;

	(void)s;
	col = 0;
	printf("x = %f\n", s->player->p_x);
	printf("y = %f\n", s->player->p_y);
	printf("angle = %f\n", pi2degree(s->player->angle));
	printf("char = %c", s->map[(int)s->player->p_y][(int)s->player->p_x]);
	while (col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		// put_ray_on_img(s, &ray, col);
		col++;
	}
	// mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
}

