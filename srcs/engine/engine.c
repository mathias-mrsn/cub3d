/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/09 16:12:27 by mamaurai         ###   ########.fr       */
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
}

// add in libft

void
	init_ray(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	ray->angle = (rayc->dirx);
	ray->sin = sin(rayc->dirx);
	if (ray->vert)
	{
		ray->x = (int)s->player->p_x + __trn32(rayc->is_left, 0, 1);
		ray->y = s->player->p_y - (ray->x - s->player->p_x) * tan(ray->angle);
		ray->x_to_add = __trn8(rayc->is_left, -1, 1);
		ray->y_to_add = ray->x_to_add * tan(ray->angle) * -1;
		// ray->y_to_add *= __trn8(rayc->is_up, 1, -1);
	// printf("ray specs : y_to_add = %f --- x_to_add = %f --- angle = %f\n", ray->y_to_add, ray->x_to_add, pi2degree(rayc->dirx));
	}
	else
	{
		ray->y = (int)s->player->p_y + __trn32(rayc->is_up, 0, 1);
		ray->x = s->player->p_x - (ray->y - s->player->p_y) / tan(ray->angle);
		ray->y_to_add = __trn8(rayc->is_up, -1, 1);
		ray->x_to_add = 1 / tan(ray->angle);
		ray->x_to_add *= __trn8((rayc->is_up) , 1, -1);
	}
}

/*




*/

// void
// 	ray_hori(t_cub *s, t_raycasting *rayc, t_ray *ray)
// {
	
// }

t_boolean
	__vertical_hit_wall__(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	int64_t	wall_to_check;
	
	wall_to_check = (int)ray->x - rayc->is_left;
	if (wall_to_check < 0)
		wall_to_check = 0;
	// printf(" [%c] ", s->map[(int)ray->y][wall_to_check]);
	if (__is_charset(s->map[(int)ray->y][wall_to_check], "1x"))
		return (true);
	return (false);
}

t_boolean
	__horizontal_hit_wall__(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	int64_t	wall_to_check;
	
	wall_to_check = (int)ray->y - rayc->is_up;
	if (wall_to_check < 0)
		wall_to_check = 0;
	if (__is_charset(s->map[wall_to_check][(int)ray->x], "x1"))
		return (true);
	return (false);
}

void
	ray_hor(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	(void)s;(void)rayc;(void)ray;
	while(ray->x >= 0 && ray->x <= s->map_width && ray->y >= 0 && ray->y <= s->map_height)
	{
		if (true == __horizontal_hit_wall__(s, rayc, ray))
		{
			// printf("vertical wall has been hit");
			return;
		}
		ray->x += ray->x_to_add;
		ray->y += ray->y_to_add;
	}
}



void
	ray_ver(t_cub *s, t_raycasting *rayc, t_ray *ray)
{
	(void)s;(void)rayc;(void)ray;
	while(ray->x >= 0 && ray->x <= s->map_width && ray->y >= 0 && ray->y <= s->map_height)
	{
		if (true == __vertical_hit_wall__(s, rayc, ray))
		{
			// printf("vertical wall has been hit");
			return;
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

	(void)s;(void)rayc;
	memset(&vertical, 0, sizeof(t_ray));
	memset(&horizontal, 0, sizeof(t_ray));
	vertical.vert = 1;
	horizontal.vert = 0;
	init_ray(s, rayc, &vertical);
	init_ray(s, rayc, &horizontal);
	ray_hor(s, rayc, &horizontal);
	ray_ver(s, rayc, &vertical);
	compute_distance(s, rayc, &horizontal, &vertical);
	// printf("distance = %f\n", rayc->distance);
}











double
	get_decimal(double nbr)
{
	return (nbr - (int)nbr);
}

int
	__get_color_at__(t_cub *s, t_raycasting *rayc, double scale, double idx)
{
	const int 		*txtr = (int *)s->textures->walls[rayc->wall_type].addr;
	const double	ratio_y = scale / s->textures->walls[rayc->wall_type].y;
	const double	x = get_decimal(rayc->hit_x) * s->textures->walls[rayc->wall_type].x;
	const double	y = idx / ratio_y;

	// printf("x = %f --- y = %f\n", x, y);
	

	return (txtr[(int)(y * s->textures->walls[rayc->wall_type].x + x)]);
}

double
	__find_x_value__(t_raycasting *rayc)
{
	if (rayc->wall_type == NORTH_SIDE || rayc->wall_type == SOUTH_SIDE)
		return (rayc->hit_x);
	else
		return (rayc->hit_y);
}

// simplifier cette fonction (txtr + byte_per_pixel)

void
	put_texture(t_cub *s, t_raycasting *rayc, double start, double end, int col)
{
	(void)rayc;(void)col;
	const double ratio_y = (double)s->textures->walls[rayc->wall_type].y / (double)(end - start);
	double idx;

	idx = 0.0;
	uint32_t	*color;

	while (start < end && start < s->win_y)
	{
		color = ((uint32_t *)(s->textures->walls[rayc->wall_type].addr + ((((int)idx * s->textures->walls[rayc->wall_type].bpp / 8) * s->textures->walls[rayc->wall_type].y)) + (int)(get_decimal(__find_x_value__(rayc)) * s->textures->walls[rayc->wall_type].x) * s->textures->walls[rayc->wall_type].bpp / 8));



		__put_pixel_on_img(&s->img, col, start, *color);

		start++;
		idx += ratio_y;

	}42/cu
}

void
	put_ray_on_img(t_cub *s, t_raycasting *rayc, int col)
{
	// double	is_in;
	int	idx;
	
	(void)col;
	idx = 0;
	// printf("distance = %f\n", rayc->distance); 
	double scale = s->win_y / (rayc->distance * cos(rayc->dirx - s->player->angle));
	double draw_start = (-scale / 2) + (s->win_y / 2);
	double draw_end = (scale / 2) + (s->win_y / 2);
	while(idx < draw_start)
	{
		__put_pixel_on_img(&s->img, col, idx, (int)s->textures->ceil);
		idx++;
	}
	put_texture(s, rayc, draw_start, draw_end, col);
	// // printf("distortion = %f\n", scale);
	idx = draw_end;
	while (idx < s->win_y)
	{
		__put_pixel_on_img(&s->img, col, idx, (int)s->textures->floor);
		idx++;
	}
}














int
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
		put_ray_on_img(s, &ray, col);
		col++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	return (__SUCCESS);
}

