/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   everyone_is_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:53:27 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/20 12:41:29 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				s->player->angle = __trnd((s->parser->map[idx][pos_x] == 'N'),
						T_PI_2, T_3PI_2);
			else if (true == __is_charset(s->parser->map[idx][pos_x], "EW"))
				s->player->angle = __trnd((s->parser->map[idx][pos_x] == 'E'),
						0.0, T_PI);
		}
		pos_x++;
	}
}
	

void
	stock_doors(t_cub *s)
{
	size_t			i;
	size_t			j;
	size_t			idx;
	
	idx = 0;
	if (0 == s->nbr_door)
		return ;
	s->doors = __malloc(sizeof(t_door) * s->nbr_door, PARSER_STACK);
	i = 0;
	while (i < __strslen(s->map))
	{
		j = -1;
		while (++j < __strlen(s->map[i]))
		{
			if (s->map[i][j] == 'D')
			{
				s->doors[idx].x = j + 0.5;
				s->doors[idx].y = i + 0.5;
				idx++;
			}
		}
		i++;
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
		nbr_players += __str_count_cs(s->parser->map[i], "NSEW");
		if (__str_count_cs(s->parser->map[i], "NSEW"))
			__set_player__(s, i);
		s->nbr_door += __str_count_cs(s->parser->map[i], "D");
		i++;
	}	
	if (!nbr_players)
		__no_player_error__();
}
