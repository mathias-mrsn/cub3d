/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:58:50 by mamaurai          #+#    #+#             */
/*   Updated: 2022/03/16 14:17:02 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double
	__pythagore__(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double
	get_decimal(double nbr)
{
	return (nbr - (int)nbr);
}

double
	trigo_cercle(double angle)
{
	if (angle < 0.0)
		return (T_2PI + angle);
	if (angle > T_2PI)
		return (angle - T_2PI);
	else
		return (angle);
}
