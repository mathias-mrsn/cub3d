/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_f.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:05 by mamaurai          #+#    #+#             */
/*   Updated: 2022/02/26 16:52:09 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_F_H
# define CUB3D_F_H

/*
**	PARSING
*/

t_boolean			__check_args__(int ac, char **av, t_cub *s);

t_boolean			parsing(t_cub *s);

/*
**	SINGLETON
*/

t_cub				*s(void);

/*
**	ERRORS
*/

void				__p_file_ext_error__(char *file);
void				__p_wrong_arg_nbr__(int ac);
void				__p_wrong_option__(char *option);
void				__p_file_cant_be_opened__(char *str);

#endif