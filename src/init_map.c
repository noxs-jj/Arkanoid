/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:04 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:48:08 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int		init_map(t_data *d)
{
	int		y;

	y = 0;
	if ((d->map = (t_case **)malloc(sizeof(t_case *) * MAP_Y)) == NULL)
		return (-1);
	while (y < MAP_Y)
	{
		if ((d->map[y] = (t_case *)malloc(sizeof(t_case) * MAP_X)) == NULL)
			return (-1);
		y++;
	}
	if (fill_map(d) < 0)
		return (-1);
	d->map[MAP_Y - 1][d->player_pos - 1].type = PLAYER;
	d->map[MAP_Y - 1][d->player_pos].type = PLAYER;
	d->map[MAP_Y - 1][d->player_pos + 1].type = PLAYER;
	return (0);
}