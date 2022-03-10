/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:05:24 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/10 15:42:30 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub
	*s(void)
{
	static t_cub	*s;

	if (!s)
	{
		s = __malloc(sizeof(t_cub), SINGLETON_STACK);
		s->parser = __malloc(sizeof(t_parser), SINGLETON_STACK);
		s->textures = __malloc(sizeof(t_textures), SINGLETON_STACK);
		s->player = __malloc(sizeof(t_player), SINGLETON_STACK);
		s->moves = __malloc(sizeof(t_moves), SINGLETON_STACK);
	}
	return (s);
}
