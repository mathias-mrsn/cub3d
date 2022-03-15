/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:19:40 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/15 15:38:58 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_elem(t_cub *s, int y, int x, int color)
{
	int i;
	int	j;
	
	i = 0;
	j = 0;
	while (i <= 2)
	{
		j = 0;
		while (j <= 2)
		{
			mlx_pixel_put(s->mlx, s->win, 21 + (x * 4) + i , 21 + (y * 4) + j, color);
			j++;
		}
		i++;
	}
}


void	map2d(t_cub *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	//map
	while (s->map[y])
	{
		x = 0;
		while (s->map[y][x])
		{
			if (s->map[y][x] == '1')
				draw_elem(s, y, x, 0X00FF00);
			else if (s->map[y][x] == '0' || s->map[y][x] == '2')
				draw_elem(s, y, x, 0XFFFFFF );
			x++;
		}
		y++;
	}
	//player 
	draw_elem(s, s->player->p_y, s->player->p_x, 0XFF0000);
}

int
	engine(t_cub *s)
{
	int				col;
	t_raycasting	ray;

	col = 0;
	moves(s);
	while (col < s->win_x)
	{
		__memset(&ray, 0, sizeof(t_raycasting));
		init_raycasting(s, &ray, col);
		cast_ray(s, &ray);
		put_ray_on_img(s, &ray, col);
		col++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img.ptr, 0, 0);
	map2d(s);
	return (__SUCCESS);
}
