/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:30:26 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:57:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int		get_level_file(t_data *d)
{
	if ((d->fd_level = open(d->p_av[1], O_RDONLY)) < 0)
		return (-1);
	return (0);
}