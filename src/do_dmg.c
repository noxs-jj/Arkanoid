/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dmg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:53:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 21:54:23 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

void	do_dmg(t_data *d, int newdir, int posx, int posy)
{
	if (d->map[posy][posx].type == SIMPLE)
	{
		d->map[posy][posx].type = EMPTY;
		d->map[posy][posx].state--;
	}
	else if (d->map[posy][posx].type == SPEC)
	{
		d->map[posy][posx].state--;
		if (d->map[posy][posx].state <= 0)
			d->map[posy][posx].type = EMPTY;
	}
	d->ball.dir = newdir;
	d->score += 100;
}
