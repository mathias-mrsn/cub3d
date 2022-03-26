/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:08:51 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/26 14:33:35 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	init_rayc_moves(t_cub *s, t_raycasting *rayc, int move_dirx)
{
	rayc->init_angle = s->player->angle;
	rayc->dirx = trigo_cercle(rayc->init_angle + (move_dirx * T_PI_2));
	rayc->is_up = __trnd((rayc->dirx >= 0.0
				&& rayc->dirx <= T_PI), true, false);
	rayc->is_left = __trnd((rayc->dirx >= T_PI_2
				&& rayc->dirx <= T_3PI_2), true, false);
}

void
	change_drix(t_cub *s, int drix)
{
	if (drix == LOOK_LEFT)
		s->player->angle = trigo_cercle(s->player->angle + CAMERA_SPEED);
	if (drix == LOOK_RIGHT)
		s->player->angle = trigo_cercle(s->player->angle - CAMERA_SPEED);
}

void
	compute_if_can_move(t_cub *s, int move_dirx, t_raycasting *rayc)
{
	t_ray	hor;
	t_ray	ver;

	__memset(&ver, 0, sizeof(t_ray));
	__memset(&hor, 0, sizeof(t_ray));
	ver.vert = 1;
	hor.vert = 0;
	init_rayc_moves(s, rayc, move_dirx);
	init_ray(s, rayc, &ver);
	init_ray(s, rayc, &hor);
	ray_hit_wall(s, rayc, &hor, "1x");
	ray_hit_wall(s, rayc, &ver, "1x");
	hor.distance = __pythagore(s->player->p_x, s->player->p_y, hor.x, hor.y);
	ver.distance = __pythagore(s->player->p_x, s->player->p_y, ver.x, ver.y);
	compute_distance(rayc, &hor, &ver);
}

void
	move_player(t_cub *s, int move_dirx)
{
	t_raycasting	rayc;

	__memset(&rayc, 0, sizeof(t_raycasting));
	compute_if_can_move(s, move_dirx, &rayc);
	if (fabs(s->player->p_x - rayc.hit_x) > MOVING_DISTANCE + 0.1)
		s->player->p_x += cos(rayc.dirx) * MOVING_DISTANCE;
	if (fabs(s->player->p_y - rayc.hit_y) > MOVING_DISTANCE + 0.1)
		s->player->p_y -= sin(rayc.dirx) * MOVING_DISTANCE;
}

void
	moves(t_cub *s)
{
	if (s->moves->m_forward)
		move_player(s, MOVE_FORWARD);
	if (s->moves->m_back)
		move_player(s, MOVE_BACK);
	if (s->moves->m_left)
		move_player(s, MOVE_LEFT);
	if (s->moves->m_right)
		move_player(s, MOVE_RIGHT);
	if (s->moves->l_left)
		change_drix(s, LOOK_LEFT);
	if (s->moves->l_right)
		change_drix(s, LOOK_RIGHT);
}
