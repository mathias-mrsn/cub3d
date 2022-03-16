/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:18:48 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/16 14:27:20 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	mouse_move(t_cub *s)
{
	int	x;
	int	y;

	mlx_mouse_hide();
	mlx_mouse_get_pos(s->win, &x, &y);
	s->player->angle = trigo_cercle(s->player->angle
			+ (s->moves->last_x_mouse - x) * RAD_PER_PIXEL);
	s->moves->last_x_mouse = s->win_x / 2;
	mlx_mouse_move(s->win, s->win_x / 2, s->win_y / 2);
}

int
	key_handler(int key, t_cub *s)
{
	mouse_move(s);
	if (key == KEY_UP)
		s->moves->m_forward = 1;
	else if (key == KEY_DOWN)
		s->moves->m_back = 1;
	else if (key == KEY_LEFT)
		s->moves->m_left = 1;
	else if (key == KEY_RIGHT)
		s->moves->m_right = 1;
	else if (key == KEY_D_LEFT)
		s->moves->l_left = 1;
	else if (key == KEY_D_RIGHT)
		s->moves->l_right = 1;
	else if (key == KEY_ESC)
		quit();
	return (0);
}

int
	key_release(int key, t_cub *s)
{
	if (key == KEY_UP)
		s->moves->m_forward = 0;
	else if (key == KEY_DOWN)
		s->moves->m_back = 0;
	else if (key == KEY_LEFT)
		s->moves->m_left = 0;
	else if (key == KEY_RIGHT)
		s->moves->m_right = 0;
	else if (key == KEY_D_LEFT)
		s->moves->l_left = 0;
	else if (key == KEY_D_RIGHT)
		s->moves->l_right = 0;
	return (0);
}
