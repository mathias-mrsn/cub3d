/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:18:48 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/14 13:06:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	key_handler(int key, t_cub *s)
{
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
