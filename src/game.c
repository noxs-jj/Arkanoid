/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:31:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 16:41:19 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int		game(t_data *d)
{
	if (d->ball.dir == 0) // UP
	{
		if (d->map[d->ball.posy - 1][d->ball.posx].type == EMPTY)
			d->ball.posy--;
		else if ((d->map[d->ball.posy - 1][d->ball.posx].type == WALL)
			|| (d->map[d->ball.posy - 1][d->ball.posx].type == OBSTACLE))
			d->ball.dir = 4;
		else
		{
			d->ball.dir = 4;
			d->map[d->ball.posy - 1][d->ball.posx].state--;
			if (d->map[d->ball.posy - 1][d->ball.posx].state == 0)	// add score here
				d->map[d->ball.posy - 1][d->ball.posx].type = EMPTY;
		}

	}
	// else if (d->ball.dir == 1) // UP - RIGHT
		// ;
	// else if (d->ball.dir == 2) // RIGHT	// impossible
	// 	;
	// else if (d->ball.dir == 3) // DOWN - RIGHT
		// ;
	else if (d->ball.dir == 4) // DOWN
	{
		if (d->map[d->ball.posy + 1][d->ball.posx].type == EMPTY)
			d->ball.posy++;
		else if (d->map[d->ball.posy + 1][d->ball.posx].type == PLAYER)	// maybe other dir (7|1)
			d->ball.dir = 0;
		else if (d->map[d->ball.posy + 1][d->ball.posx].type == WALL)
			d->ball.dir = -1;
	}
	// else if (d->ball.dir == 5) // DOWN - LEFT
		// ;
	// else if (d->ball.dir == 6) // LEFT	// impossible
	// 	;
	// else // UP - LEFT
		// ;
	return (0);
}