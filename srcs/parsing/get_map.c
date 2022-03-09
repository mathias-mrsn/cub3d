/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:35:14 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/09 17:57:09 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	get_map(t_cub *s, ssize_t *idx)
{
	size_t	new_idx;

	new_idx = 0;
	s->parser->map = __malloc(sizeof(char *) * (__strslen(&s->parser->file[(*idx)]) + 2), PARSER_STACK);
	while (s->parser->file[(*idx)] && __strcmp(s->parser->file[(*idx)], "\0"))
	{
		s->parser->map[new_idx++] = __strdup(s->parser->file[(*idx)]);
		(*idx)++;	
	}
	while (s->parser->file[(*idx)] && !__strcmp(s->parser->file[(*idx)], "\0"))
	{
		s->parser->map[new_idx++] = __strdup(s->parser->file[(*idx)]);
		(*idx)++;	
	}
	if (s->parser->file[(*idx)])
		__strdup("error"); // error invalid map (map split) -----------------------------
	s->parser->map[new_idx] = NULL;
}

void	__error__(void)
{
	printf("error\n");
	return ;
}

void
	check_map_charset(t_cub *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s->parser->map[i])
	{
		j = 0;
		while (s->parser->map[i][j])
		{
			if (__FALSE == __is_charset(s->parser->map[i][j], MAP_CHARSET))
				__error__(); //Invalid argument in map --------------------------------
			j++;
		}
		i++;
	}
}