/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:31:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:46:14 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

void 	move(t_data *d, int move)
{
	if (move == LEFT && d->player_pos > 2)
	{
		d->map[MAP_Y - 1][d->player_pos + 1].type = EMPTY;
		d->player->pos--;
		d->map[MAP_Y - 1][d->player_pos - 1].type = PLAYER;
	}
	else if (move == RIGHT && d->player_pos < MAP_X - 2)
	{
		d->map[MAP_Y - 1][d->player_pos - 1].type = EMPTY;
		d->player->pos++;
		d->map[MAP_Y - 1][d->player_pos + 1].type = PLAYER;
	}
}