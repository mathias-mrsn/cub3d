/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:09:26 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/26 16:37:50 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_boolean
	__check_args__(int ac, char **av, t_cub *s)
{
	if (ac != 2 && (ac != 3 || __strncmp(av[2], "--", 2)))
		return (__p_wrong_arg_nbr__(ac), __FAILURE);
	if (__FALSE == __file_extention(av[1], ".cub"))
		return (__p_file_ext_error__(av[1]), __FAILURE);
	if (ac == 3 && __strcmp(av[2], SAVE_OPTION))
		return (__p_wrong_option__(av[2]), __FAILURE);
	if (__FALSE == __file_exist(av[1]))
		return (__p_file_cant_be_opened__(av[1]), __FAILURE);
	s->parser->fd = open(av[1], O_RDONLY);
	s->save = __trnu8((ac == 3), __TRUE, __FALSE);
	return (__SUCCESS);
}
