/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:43:33 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/12 12:15:38 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	__extra_map_error__(t_cub *s, ssize_t idx)
{
	__puterr(NULL);
	__print_error_line__(s, idx);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": end of map isn't end of file\n", STDERR_FILENO);
	__exit(0);
}

void
	__print_error_line_elem__(t_cub *s, size_t line, size_t nbr)
{
	const size_t	strslen = __strslen(s->parser->map);
	size_t			idx;
	size_t			idx2;

	idx = 0;
	while (idx < strslen)
	{
		idx2 = 0;
		__printf("line n.%-5d --> \"", idx);
		while (s->parser->map[idx][idx2])
		{
			if (idx < line || (idx == line && idx2 < nbr))
				__printf("%s%c%s", __GREEN, s->parser->map[idx][idx2], __RESET);
			else if (idx == line && idx2 == nbr)
				__printf("%s%c%s", __RED, s->parser->map[idx][idx2], __RESET);
			else
				__printf("%s%c%s", __WHITE, s->parser->map[idx][idx2], __RESET);
			idx2++;
		}
		__printf("\"\n");
		idx++;
	}
	__printf("\n");
}

void
	__invalid_char__(t_cub *s, size_t line, size_t nbr)
{
	__puterr(NULL);
	__print_error_line_elem__(s, line, nbr);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": invalid character on map\n", STDERR_FILENO);
	__putstr("map charset: \""MAP_CHARSET"\"", STDERR_FILENO);
	__exit(0);
}

void
	__no_player_error__(void)
{
	__puterr(PROGRAM_NAME);
	__putstr(": no player on map\n", STDERR_FILENO);
	__exit(0);
}

void
	__leak_on_map_error__(t_cub *s, size_t line, size_t nbr)
{
	__puterr(NULL);
	__print_error_line_elem__(s, line, nbr);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": leak(s) on map\n", STDERR_FILENO);
	__exit(0);
}
