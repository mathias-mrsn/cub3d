/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:50 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/26 17:17:25 by mamaurai         ###   ########.fr       */
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

void
	__get_map__(t_cub *s, ssize_t *idx)
{
	s->parser->map = __malloc(sizeof(char *), PARSER_STACK);
	while((*idx) > -1 && 0 == __strcmp(s->parser->file[(*idx)], "\0"))
		(*idx)--;
	while((*idx) > -1 && 0 != __strcmp(s->parser->file[(*idx)], "\0"))
	{
		__mstrs_add_front(&s->parser->map, s->parser->file[(*idx)], PARSER_STACK);
		(*idx)--;
	}
	while((*idx) > -1 && 0 == __strcmp(s->parser->file[(*idx)], "\0"))
		(*idx)--;
}

t_boolean
	parsing(t_cub *s)
{
	ssize_t	idx;
	
	s->parser->file = __fd_to_strs__(s->parser->fd);
	idx = __strslen(s->parser->file) - 1;
	__get_map__(s, &idx);
	__putstrs("file", s->parser->map, 1);
	return (__SUCCESS);
}