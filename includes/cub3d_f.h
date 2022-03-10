/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_f.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:50:05 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/10 15:55:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_F_H
# define CUB3D_F_H

/*
**	PARSING
*/

t_boolean			__check_args__(int ac, char **av, t_cub *s);

t_boolean			parsing(t_cub *s);
void				args_data_is_good(t_cub *s, char *str, uint8_t type_nbr, ssize_t idx);
void				get_map(t_cub *s, ssize_t *idx);
void				check_map_charset(t_cub *s);
void				check_map_walls(t_cub *s);
void				is_player_in(t_cub *s);


//	OPEN TEXTURE

void				open_textures(t_cub *s);


/*
**	ENGINE
*/

int				engine(t_cub *s);
double			trigo_cercle(double angle);
void			init_ray(t_cub *s, t_raycasting *rayc, t_ray *ray);
void			init_ray(t_cub *s, t_raycasting *rayc, t_ray *ray);
void			ray_hor(t_cub *s, t_raycasting *rayc, t_ray *ray);
void			ray_ver(t_cub *s, t_raycasting *rayc, t_ray *ray);
void			compute_distance(t_cub *s, t_raycasting *rayc, t_ray *hor, t_ray *ver);
/*
**	SINGLETON
*/

t_cub				*s(void);

/*
**	ERRORS
*/

void				__file_ext_error__(char *file);
void				__wrong_arg_nbr__(int ac);
void				__wrong_option__(char *option);
void				__file_cant_be_opened__(char *str);

void				__color_error__(t_cub *s, ssize_t idx);
void				__resolution_error__(t_cub *s, ssize_t idx);
void				__texture_error__(t_cub *s, ssize_t idx, t_boolean error_type, char *str);
void				__print_error_line__(t_cub *s, ssize_t error_line);

void				__duplicate_data_error__(t_cub *s, ssize_t idx);
void				__invalid_info__(t_cub *s, ssize_t idx);
void				__data_missing_error__(t_cub *s);
void				__unable_to_open_xpm__(int line, char *file);

/*
**	MATH
*/

double				__pythagore__(double x1, double y1, double x2, double y2);



/*
**	MOVES
*/

void				moves(t_cub *s);


void	__error__(void);



#endif