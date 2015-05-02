/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:31:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 21:45:01 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

static void	do_dmg(t_data *d, int newdir, int posx, int posy)
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

int			adv_move(t_data *d, int side)
{
	if (side == 0)
	{
		if (d->ball.dir == 0)
			do_dmg(d, 4, d->ball.posx, d->ball.posy - 1);
		else if (d->ball.dir == 1)
			do_dmg(d, 3, d->ball.posx + 1, d->ball.posy - 1);
		else if (d->ball.dir == 7)
			do_dmg(d, 5, d->ball.posx - 1, d->ball.posy - 1);
		else
			return (99);
	}
	else if (side == 1 && d->ball.dir == 1)
	{
		do_dmg(d, 5, d->ball.posx, d->ball.posy - 1);
		do_dmg(d, 5, d->ball.posx, d->ball.posy - 1);
	}
	else if (side == 2)
	{
		if (d->ball.dir == 1)
			do_dmg(d, 7, d->ball.posx + 1, d->ball.posy - 1);
		else if (d->ball.dir == 3)
			do_dmg(d, 5, d->ball.posx + 1, d->ball.posy + 1);
		else
			return (99);
	}
	else if (side == 3 || side == 5)
		return (-1);
	else if (side == 4)
	{
		if (d->map[d->ball.posy + 1][d->ball.posx].type == WALL)
			return (-1);
		if (d->ball.dir < 3 || d->ball.dir > 5)
			return (99);
		if (d->ball.posx == d->player_pos)
			do_dmg(d, 0, d->ball.posx - 1, d->ball.posy + 1);
		else if (d->ball.posx == d->player_pos - 1)
			do_dmg(d, 7, d->ball.posx - 1, d->ball.posy + 1);
		else if (d->ball.posx == d->player_pos + 1)
			do_dmg(d, 1, d->ball.posx - 1, d->ball.posy + 1);
	}
	else if (side == 6)
	{
		if (d->ball.dir == 5)
			do_dmg(d, 3, d->ball.posx - 1, d->ball.posy + 1);
		else if (d->ball.dir == 7)
			do_dmg(d, 1, d->ball.posx - 1, d->ball.posy - 1);
		else
			return (99);
	}
	else if (side == 7 && d->ball.dir == 7)
	{
		do_dmg(d, 3, d->ball.posx, d->ball.posy - 1);
		do_dmg(d, 3, d->ball.posx - 1, d->ball.posy - 1);
	}
	else
		return (99);
	return (0);
}

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

void		game(t_data *d)
{
	int		ret;

	ret = collide(d);
	if (ret == 99)
		basic_move(d);
	if (ret < 0)
		d->run = 0;
}
