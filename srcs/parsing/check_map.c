/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:03:09 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/11 11:16:58 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t
	__strs_maxlen__(char **strs)
{
	size_t			idx;
	size_t			maxlen;

	idx = 0;
	maxlen = 0;
	while (strs[idx])
	{
		if (__strlen(strs[idx]) > maxlen)
			maxlen = __strlen(strs[idx]);	
		idx++;
	}
	return (maxlen);
}

char
	*__full_cross_line__(size_t	len)
{
	char	*str;
	size_t	idx;

	str = __malloc(sizeof(char) * len + 3, RAYCASTING_STACK);
	idx = 0;
	while (idx < len + 2)
		str[idx++] = 'x';
	str[idx] = 0;
	return (str);
}

char
	*__space_to_cross__(char *str, size_t len)
{
	char	*new_str;
	size_t	idx;
	size_t	str_idx;	

	new_str = __malloc(sizeof(char) * len + 3, RAYCASTING_STACK);
	str_idx = 0;
	idx = 0;
	new_str[idx++] = 'x';
	while (str[str_idx])
	{
		if (str[str_idx] == ' ')
			new_str[idx] = 'x';
		else if (__is_charset(str[str_idx], "NSEW"))
			new_str[idx] = '0'; 
		else
			new_str[idx] = str[str_idx];
		str_idx++;
		idx++;	
	}
	while (idx < len + 2)
		new_str[idx++] = 'x';
	new_str[idx] = 0;
	return ((void)str, (void)len, new_str);
}

void
	check_cross(t_cub *s, char **strs)
{
	const size_t	_height = __strslen(strs);
	const size_t	_width = __strlen(strs[0]);
	size_t			i;
	size_t			j;

	i = 0;
	while (i < _height)
	{
		j = 0;
		while (j < _width)
		{
			if (strs[i][j] == 'x')
			{
				if (j < _width - 1 > 0 && strs[i][j + 1] != '1' && strs[i][j + 1] != 'x')
					__leak_on_map_error__(s, i, j);
				if (i > 0 && strs[i - 1][j] != '1' && strs[i - 1][j] != 'x')
					__leak_on_map_error__(s, i - 2, j);
				if (i < _height - 1 && strs[i + 1][j] != '1' && strs[i + 1][j] != 'x')
					__leak_on_map_error__(s, i, j);
				if (j > 0 && strs[i][j - 1] != '1' && strs[i][j - 1] != 'x')
					__leak_on_map_error__(s, i, j);
			}
			j++;
		}
		i++;
	}
}

void
	check_map_walls(t_cub *s)
{
	char			**strs;
	const size_t	_size = __strslen(s->parser->map);
	const size_t	_size_max = __strs_maxlen__(s->parser->map);
	size_t			idx;

	strs = __malloc(sizeof(char *) * (_size + 3), RAYCASTING_STACK);
	idx = 0;
	strs[idx++] = __full_cross_line__(_size_max);
	while (idx < _size + 1)
	{
		strs[idx] = __space_to_cross__(s->parser->map[idx - 1], _size_max);
		idx++;
	}
	strs[idx] = __full_cross_line__(_size_max);
	check_cross(s, strs);
	s->map = strs;
	s->map_height = _size + 2;
	s->map_width = _size_max + 2; 
}