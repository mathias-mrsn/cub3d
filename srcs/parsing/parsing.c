/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:50 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/27 19:04:17 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char
	**__fd_to_strs__(int fd)
{
	char	**strs;
	char	*str;

	str = __gnl(fd);
	strs = __malloc(sizeof(char *) * 1, PARSER_STACK);
	while (str)
	{
		__mstrs_add_back(&strs, str, PARSER_STACK);
		str = __gnl(fd);
	}
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
	const char 	*types[NBR_ARGS] = {"R ", "C ", "F ", "S ", "NO ",
		"EA ", "SO ", "WE "};
	uint8_t		type_nbr;

	while (s->parser->file[++(*idx)] && !__find_every_values__(s))
	{
		type_nbr = -1;
		while (++type_nbr < NBR_ARGS)
			if (0 == __strncmp(s->parser->file[(*idx)], types[type_nbr], __strlen(types[type_nbr])))
				break ;
		if (0 == __strcmp(s->parser->file[(*idx)], "\0"))
			continue;
		if (type_nbr == NBR_ARGS)
			__invalid_info__(s, (*idx));
		else
			args_data_is_good(s, __mstrtrim(s->parser->file[(*idx)] + __strlen(types[type_nbr]), " ", PARSER_STACK), type_nbr, (*idx));
	}
	if (__FALSE == __find_every_values__(s))
		__data_missing_error__(s);
}

t_boolean
	parsing(t_cub *s)
{
	ssize_t	idx;
	
	idx = -1;
	s->parser->file = __fd_to_strs__(s->parser->fd);;
	check_game_data(s, &idx);
	// open_textures(s);

	return (__SUCCESS);
}