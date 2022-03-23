/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:21:46 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/12 12:15:58 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	__data_missing_error__(t_cub *s)
{
	const char	*string[NBR_ARGS] = {"resolution [R]",
		"ceil color [C]", "floor color [F]", "sprite texture [S]",
		"north texture [NO]", "east texture [EA]", "south texture [SO]",
		"west texture [WE]"};
	uint8_t		idx;

	idx = 0;
	__puterr(PROGRAM_NAME);
	__putstr(": some data are missing :\n", STDERR_FILENO);
	while (idx < NBR_ARGS)
	{
		if (s->parser->check[idx] == 0)
			__printf("\t%s is missing\n", string[idx]);
		idx++;
	}
	__exit(0);
}

void
	__invalid_info__(t_cub *s, ssize_t idx)
{
	__puterr(NULL);
	__print_error_line__(s, idx);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": invalid data\n", STDERR_FILENO);
	__putstr("norme: \"[R | C | F | S | NO | SO | EA | WE]\"", STDERR_FILENO);
	__exit(0);
}

void
	__duplicate_data_error__(t_cub *s, ssize_t idx)
{
	__puterr(NULL);
	__print_error_line__(s, idx);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": duplicated information in the file\n", STDERR_FILENO);
	__exit(0);
}

void
	__unable_to_open_xpm__(int line, char *file)
{
	__puterr(PROGRAM_NAME);
	__printf(": (\"%s\" l.%d)", file, line);
	__putstr(": unable to open xpm file\n", STDERR_FILENO);
	__exit(0);
}
