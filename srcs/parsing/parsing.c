/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:50 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/09 18:01:53 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char
	**__fd_to_strs__(int fd)
{
	char	**strs;
	char	*str;

	printf("%d\n", fd);
	str = __gnl(fd);
	strs = __malloc(sizeof(char *) * 1, 76);
	while (str)
	{
		__mstrs_add_back(&strs, str, 75);
		str = __gnl(fd);
	}
	close(fd);
	return (strs);
}

static t_boolean
	__find_every_values__(t_cub *s)
{
	uint8_t	idx;

	idx = 0;
	while (idx < NBR_ARGS)
	{
		if (s->parser->check[idx] == 0)
			return (__FALSE);
		idx++;
	}
	return (__TRUE);
}

void  
	check_game_data(t_cub *s, ssize_t *idx)
{
	const char 	*_types[NBR_ARGS] = {"R ", "C ", "F ", "S ", "NO ",
		"EA ", "SO ", "WE "};
	uint8_t		type_nbr;

	while (s->parser->file[++(*idx)] && (!__find_every_values__(s) || !__strcmp(s->parser->file[(*idx)], "\0")))
	{
		type_nbr = -1;
		while (++type_nbr < NBR_ARGS)
			if (0 == __strncmp(s->parser->file[(*idx)], _types[type_nbr], __strlen(_types[type_nbr])))
				break ;
		if (0 == __strcmp(s->parser->file[(*idx)], "\0"))
			continue;
		if (type_nbr == NBR_ARGS)
			__invalid_info__(s, (*idx));
		else
			args_data_is_good(s, __mstrtrim(s->parser->file[(*idx)] + __strlen(_types[type_nbr]), " ", 54), type_nbr, (*idx));
	}
	if (__FALSE == __find_every_values__(s))
		__data_missing_error__(s);
}

t_boolean
	parsing(t_cub *s)
{
	ssize_t	idx;
	
	idx = -1;
	s->parser->file = __fd_to_strs__(s->parser->fd);
	check_game_data(s, &idx);
	open_textures(s);
	get_map(s, &idx);
	check_map_charset(s);
	check_map_walls(s);
	is_player_in(s);
	return (__SUCCESS);
}
