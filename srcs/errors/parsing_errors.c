/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:03:23 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/28 14:32:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	__print_error_line__(t_cub *s, ssize_t error_line)
{
	const size_t	strslen = __strslen(s->parser->file);
	size_t			idx;

	idx = 0;
	while (idx < strslen)
	{
		__printf("line n.%-5d --> \"", idx);
		if (idx == (size_t)error_line)
			__printf("%s%s%s", __RED, s->parser->file[idx], __RESET);
		else if (idx > (size_t)error_line)
			__printf("%s%s%s", __WHITE, s->parser->file[idx], __RESET);
		else
			__printf("%s%s%s", __GREEN, s->parser->file[idx], __RESET);
		__printf("\"\n");		
		idx++;
	}
	__printf("\n");
}

void
	__texture_error__(t_cub *s, ssize_t idx, t_boolean error_type, char *str)
{
	__print_error_line__(s, idx);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	if (error_type == 1)
	{
		__putstr(": ", STDERR_FILENO);
		__putstr(str, STDERR_FILENO);
		if (errno == 13)
			__putstr(": permission denied\n", STDERR_FILENO);
		else
			__putstr(": no such file or directory\n", STDERR_FILENO);
	}
	else
	{
		__putstr(": wrong file extension\n", STDERR_FILENO);
	}
	__putstr("norme: \"[NO | SO | WE | EA] [filename.xpm]\"\n", STDERR_FILENO);
	__exit(0);
}

void
	__resolution_error__(t_cub *s, ssize_t idx)
{
	__print_error_line__(s, idx);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": invalid resolution values\n", STDERR_FILENO);
	__printf("norme: \"R [0-%d] [0-%d]\"\n", WIN_X_MAX, WIN_Y_MAX);
	__exit(0);
}

void
	__color_error__(t_cub *s, ssize_t idx)
{
	__print_error_line__(s, idx);
	__putstr(PROGRAM_NAME, STDERR_FILENO);
	__putstr(": invalid color values\n", STDERR_FILENO);
	__putstr("norme: \"[C | F] [0-255],[0-255],[0-255]\"\n", STDERR_FILENO);
	__exit(0);
}
