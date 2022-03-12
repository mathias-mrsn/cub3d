/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:32:17 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/12 12:11:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void
	__check_resolution__(t_cub *s, char *str, ssize_t idx)
{
	char	**strs;

	if (__FALSE == __str_is(str, __IS_DIGIT | __IS_EMPTY))
		__resolution_error__(s, idx);
	strs = __msplit(str, ' ', TRASH_STACK);
	if (__strslen(strs) != 2)
		__resolution_error__(s, idx);
	if (10 < __strlen(strs[0]) || 10 < __strlen(strs[1]))
		__resolution_error__(s, idx);
	s->win_x = __atol(strs[0]);
	s->win_y = __atol(strs[1]);
	if (s->win_x > WIN_X_MAX || s->win_y > WIN_Y_MAX)
		__resolution_error__(s, idx);
}

static void
	__check_colors__(t_cub *s, char *str, ssize_t idx, uint8_t type_nbr)
{
	char	**strs;

	if (11 < __strlen(str))
		__color_error__(s, idx);
	strs = __msplit(str, ',', TRASH_STACK);
	if (__strslen(strs) != 3)
		__color_error__(s, idx);
	if (3 < __strlen(strs[0]) || 3 < __strlen(strs[1]) || 3 < __strlen(strs[2])
		|| !__str_is(strs[0], __IS_DIGIT) || !__str_is(strs[1], __IS_DIGIT)
		|| !__str_is(strs[2], __IS_DIGIT) || 255 < __atoi(strs[0])
		|| 255 < __atoi(strs[1]) || 255 < __atoi(strs[2]))
		__color_error__(s, idx);
	if (type_nbr != 1)
		s->parser->floor = __create_color(0, (uint8_t)__atoi(strs[0]),
				(uint8_t)__atoi(strs[1]), (uint8_t)__atoi(strs[2]));
	else
		s->parser->ceil = __create_color(0, (uint8_t)__atoi(strs[0]),
				(uint8_t)__atoi(strs[1]), (uint8_t)__atoi(strs[2]));
}

static void
	__check_file__(t_cub *s, char *str, ssize_t idx, uint8_t type_nbr)
{
	if (__FALSE == __file_exist(str))
		__texture_error__(s, idx, 1, str);
	if (__FALSE == __file_extention(str, ".xpm"))
		__texture_error__(s, idx, 0, str);
	s->parser->walls_path[type_nbr - 4] = __mstrdup(str, RAYCASTING_STACK);
}

void
	args_data_is_good(t_cub *s, char *str, uint8_t type_nbr, ssize_t idx)
{
	if (s->parser->check[type_nbr] == __TRUE)
		__duplicate_data_error__(s, idx);
	else
		s->parser->check[type_nbr] = __TRUE;
	if (type_nbr == 0)
		__check_resolution__(s, str, idx);
	else if (type_nbr > 0 && type_nbr < 3)
		__check_colors__(s, str, idx, type_nbr);
	else
		__check_file__(s, str, idx, type_nbr);
}
