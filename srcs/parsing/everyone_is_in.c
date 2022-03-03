/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   everyone_is_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:53:27 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/03 12:21:27 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define	TOO_MANY_PLAYER "too many player on the map\n"

void
	__set_player__(t_cub *s, size_t	idx)
{
	size_t	pos_x;

	pos_x = 0;
	while (s->parser->map[idx][pos_x])
	{
		if (true == __is_charset(s->parser->map[idx][pos_x], "NSEW"))
		{
			s->player->p_x = (double)(pos_x + 1) + 0.5;
			s->player->p_y = (double)(idx + 1) + 0.5;
			if (true == __is_charset(s->parser->map[idx][pos_x], "NS"))
				s->player->angle = __trnd((s->parser->map[idx][pos_x] == 'N'), T_PI_2, T_3PI_2);
			else if (true == __is_charset(s->parser->map[idx][pos_x], "EW"))
				s->player->angle = __trnd((s->parser->map[idx][pos_x] == 'E'), 0.0, T_PI);
		}
		pos_x++;
	}
}

void
	is_player_in(t_cub *s)
{
	uint64_t		nbr_players;
	size_t			i;

	i = 0;
	nbr_players = 0;
	while (s->parser->map[i])
	{
		nbr_players += __str_count_cs(s->parser->map[i++], "NSEW");
		if (__str_count_cs(s->parser->map[i], "NSEW"))
			__set_player__(s, i++);
	}
	// if (!nbr_players)
	// 	__error__(); //error no player
}
