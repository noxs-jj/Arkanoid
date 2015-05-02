/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:31:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 16:40:30 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

void 	move(t_data *d, int move)
{
	if (move == LEFT && d->player_pos > 2)
	{
		d->map[MAP_Y - 2][d->player_pos + 1].type = EMPTY;
		d->player_pos--;
		d->map[MAP_Y - 2][d->player_pos - 1].type = PLAYER;
	}
	else if (move == RIGHT && d->player_pos < MAP_X - 3)
	{
		d->map[MAP_Y - 2][d->player_pos - 1].type = EMPTY;
		d->player_pos++;
		d->map[MAP_Y - 2][d->player_pos + 1].type = PLAYER;
	}
}