/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:30:26 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 19:49:00 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int		get_level_file(t_data *d)
{
	struct stat type;

	stat(d->p_av[1], &type);
	if (S_ISDIR(type.st_mode))
	{
		ft_putendl_fd("Wrong File Format", 2);
		return (-1);
	}
	if ((d->fd_level = open(d->p_av[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("Failed Opening level", 2);
		return (-1);
	}
	return (0);
}
