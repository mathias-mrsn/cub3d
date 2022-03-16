/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/16 14:14:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	engine(t_cub *s)
{
	int				col;
	t_raycasting	ray;

	col = 0;
	mouse_move(s);
	moves(s);
	while (col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		put_ray_on_img(s, &ray, col);
		col++;
	}
	map2d(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	return (__SUCCESS);
}
