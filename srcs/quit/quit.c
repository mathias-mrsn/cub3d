/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:17:55 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/25 10:35:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	quit(int exit_code)
{
	int	i;

	i = -1;
	while (++i < NBR_WALL_SIDES)
		if (s()->textures->walls[i].ptr)
			mlx_destroy_image(s()->mlx, s()->textures->walls[i].ptr);
	if (s()->img.ptr)
		mlx_destroy_image(s()->mlx, s()->img.ptr);
	if (s()->win)
		mlx_destroy_window(s()->mlx, s()->win);
	free(s()->mlx);
	__clean_all();
	exit(exit_code);
	return (1);
}
