/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/24 14:40:33 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	engine(t_cub *s)
{
	int				col;
	t_raycasting	ray;

	col = -1;
	mouse_move(s);
	moves(s);
	update_sprite_to_print(s);
	update_doors(s);
	update_gun_sprite(s);
	while (++col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		if (col == s->win_x / 2)
			kill_sprite(s, &ray);
		put_ray_on_img(s, &ray, col);
		put_sprite_on_img(s, &ray, col);
	}
	put_gun_cursor(s);
	put_gun_on_img(s, 0.0, 0.0);
	map2d(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	__clean(SPRITE_STACK);
	return (__SUCCESS);
}
