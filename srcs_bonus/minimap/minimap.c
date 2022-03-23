/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:53:28 by malouvar          #+#    #+#             */
/*   Updated: 2022/03/21 16:45:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_elem(t_cub *s, int y, int x, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i <= 2)
// 	{
// 		j = 0;
// 		while (j <= 2)
// 		{
// 			__put_pixel_on_img(&s->img, MINIMAP_OFFSET_X + (x * 4) + i,
// 				MINIMAP_OFFSET_Y + (y * 4) + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	map2d(t_cub *s)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (s->map[y])
// 	{
// 		x = 0;
// 		while (s->map[y][x])
// 		{
// 			if (s->map[y][x] == '1')
// 				draw_elem(s, y, x, WALL_COLOR);
// 			else if (s->map[y][x] == '0' || s->map[y][x] == '2')
// 				draw_elem(s, y, x, EMPTY_COLOR);
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_elem(s, s->player->p_y, s->player->p_x, PLAYER_COLOR);
// }

void
	draw_elem(t_cub *s, int pxl_x, int pxl_y)
{
	double	x;
	double	y;

	// pxl_x = 30;
	x = (double)(DIST_PER_PIXEL * (CENTER_X - (CENTER_X - pxl_x)));
	y = (double)(DIST_PER_PIXEL * (CENTER_Y - (CENTER_Y - pxl_y)));
	x = s->player->p_x - x;
	y = s->player->p_y + y;
	// printf("x = %f -- y = %f\n", x, y);
	if (x > 0.0 && y > 0.0 && x < s->map_width && y < s->map_height && s->map[(int)y][(int)x] == '1')
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X), (pxl_y + PADDING_Y), 0xFF0000);
	else
		__put_pixel_on_img(&s->img, (pxl_x + PADDING_X), (pxl_y + PADDING_Y), 0x00FF00);
	
}

void
	map2d(t_cub *s)
{
	int	pxl_x;
	int	pxl_y;

	pxl_x = 0;
	while (pxl_x < MINIMAP_W)
	{
		pxl_y = 0;
		while (pxl_y < MINIMAP_H)
		{
			draw_elem(s, pxl_x, pxl_y);
			pxl_y++;	
		}
		pxl_x++;
	}
}
