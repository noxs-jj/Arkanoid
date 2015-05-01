/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:31:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:41:32 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

void 	move(t_data *d, int move)
{
	if (move == LEFT && d->player->pos > 2)
	{
		d->map[MAP_Y - 1][d->player_pos + 1].type = 5;
		d->player->pos--;
		d->map[MAP_Y - 1][d->player_pos - 1].type = 6;
	}
	else if (move == RIGHT && d->player->pos < MAP_X - 2)
	{
		d->map[MAP_Y - 1][d->player_pos - 1].type = 5;
		d->player->pos++;
		d->map[MAP_Y - 1][d->player_pos + 1].type = 6;
	}
}