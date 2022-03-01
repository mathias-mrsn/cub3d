/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:05:34 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/01 11:46:09 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int
	main(int ac, char **av)
{
	t_cub *cub = s();

	(void)cub;
	cub->mlx = mlx_init();
	if (NULL == cub->mlx)
		return (EXIT_FAILURE); //mlx start error
	if (__FAILURE == __check_args__(ac, av, cub))
		__exit(EXIT_FAILURE);
	if (__FAILURE == parsing(cub))
		__exit(EXIT_FAILURE);
	__clean_all();
}