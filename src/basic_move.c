/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:53:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 21:57:27 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

void		basic_move(t_data *d)
{
	if (d->ball.dir == 0)
		d->ball.posy--;
	else if (d->ball.dir == 1)
	{
		d->ball.posy--;
		d->ball.posx++;
	}
	else if (d->ball.dir == 3)
	{
		d->ball.posy++;
		d->ball.posx++;
	}
	else if (d->ball.dir == 4)
		d->ball.posy++;
	else if (d->ball.dir == 5)
	{
		d->ball.posy++;
		d->ball.posx--;
	}
	else if (d->ball.dir == 7)
	{
		d->ball.posy--;
		d->ball.posx--;
	}
	d->score += 1;
}
