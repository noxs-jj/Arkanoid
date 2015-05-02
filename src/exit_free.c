/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:30:29 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 19:46:06 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

void	exit_free(void)
{
	t_data	*d;
	int		y;

	if ((d = get_data()) == NULL)
		_exit(0);
	if (d->fd_log > 0)
		close(d->fd_log);
	if (d->map != NULL)
	{
		y = 0;
		while (y < MAP_Y && d->map[y] != NULL)
		{
			ft_memdel((void **)&d->map[y]);
			y++;
		}
		ft_memdel((void **)&d->map);
	}
	_exit(0);
}
