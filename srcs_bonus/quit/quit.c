/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:17:55 by mamaurai          #+#    #+#             */
/*   Updated: 2022/04/03 15:01:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	quit(int exit_code)
{
	uint32_t	i;

	i = -1;
	while (++i < NBR_WALL_SIDES)
		if (s()->textures->walls[i].ptr)
			mlx_destroy_image(s()->mlx, s()->textures->walls[i].ptr);
	i = -1;
	while (++i < NBR_GUN_SPRITE)
		if (s()->gun->gun_txtr[i].ptr)
			mlx_destroy_image(s()->mlx, s()->gun->gun_txtr[i].ptr);
	i = -1;
	while (++i < s()->parser->nbr_sprite && s()->textures->sprite)
		if (s()->textures->sprite[i].ptr)
			mlx_destroy_image(s()->mlx, s()->textures->sprite[i].ptr);
	if (s()->img.ptr)
		mlx_destroy_image(s()->mlx, s()->img.ptr);
	if (s()->win)
		mlx_destroy_window(s()->mlx, s()->win);
	if (s()->mlx)
		free(s()->mlx);
	__clean_all();
	exit(exit_code);
	return (1);
}
