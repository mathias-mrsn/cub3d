/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:41:36 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/20 13:02:26 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	init_gun_textures(t_cub *s)
{
	uint32_t	idx;
	const char *gun_paths[NBR_GUN_SPRITE] = {
		"./textures/gun_assets/01.xpm"
		,"./textures/gun_assets/02.xpm"
		,"./textures/gun_assets/03.xpm"
		,"./textures/gun_assets/04.xpm"
		,"./textures/gun_assets/05.xpm"
		,"./textures/gun_assets/06.xpm"};

	idx = 0;
	while (idx < NBR_GUN_SPRITE)
	{
		s->gun->gun_txtr[idx].ptr = mlx_xpm_file_to_image(s->mlx, (char *)gun_paths[idx], &s->gun->gun_txtr[idx].x, &s->gun->gun_txtr[idx].y);
		if (NULL == s->gun->gun_txtr[idx].ptr)
				__unable_to_open_xpm__(__LINE__, __FILE__);
		s->gun->gun_txtr[idx].addr = mlx_get_data_addr(s->gun->gun_txtr[idx].ptr, &s->gun->gun_txtr[idx].bpp, &s->gun->gun_txtr[idx].size_line, &s->gun->gun_txtr[idx].endian);
		if (NULL == s->gun->gun_txtr[idx].addr)
			__unable_to_open_xpm__(__LINE__, __FILE__);
		idx++;
	}
}