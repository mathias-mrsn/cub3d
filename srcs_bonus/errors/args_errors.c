/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:14:23 by mamaurai          #+#    #+#             */
/*   Updated: 2022/04/03 14:59:42 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	__file_ext_error__(char *file)
{
	__puterr(PROGRAM_NAME);
	__putstr(": ", STDERR_FILENO);
	__putstr(file, STDERR_FILENO);
	__putstr(": wrong file extension\n", STDERR_FILENO);
	quit(1);
}

void
	__wrong_arg_nbr__(int ac)
{
	__puterr(PROGRAM_NAME);
	__putstr(": argc = ", STDERR_FILENO);
	__putnbr(ac, STDERR_FILENO);
	__putstr(" : incorrect number of arguments\n", STDERR_FILENO);
	quit(1);
}

void
	__wrong_option__(char *option)
{
	__puterr(PROGRAM_NAME);
	__putstr(": ", STDERR_FILENO);
	__putstr(option, STDERR_FILENO);
	__putstr(": invalid option\n", STDERR_FILENO);
	quit(1);
}

void
	__file_cant_be_opened__(char *str)
{
	__puterr(PROGRAM_NAME);
	__putstr(": ", STDERR_FILENO);
	__putstr(str, STDERR_FILENO);
	if (errno == 13)
		__putstr(": permission denied\n", STDERR_FILENO);
	else
		__putstr(": no such file or directory\n", STDERR_FILENO);
	quit(1);
}

void
	__sprite_error__(char *str)
{
	__puterr(PROGRAM_NAME);
	__putstr(": ", STDERR_FILENO);
	__putstr(str, STDERR_FILENO);
	__putstr(": directory can't be opened\n", STDERR_FILENO);
	quit(EXIT_FAILURE);
}
