/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:53:49 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 22:13:46 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

static int	adv_move4(t_data *d)
{
	if (d->ball.dir == 5)
		do_dmg(d, 3, d->ball.posx - 1, d->ball.posy + 1);
	else if (d->ball.dir == 7)
		do_dmg(d, 1, d->ball.posx - 1, d->ball.posy - 1);
	else
		return (99);
	return (0);
}

static int	adv_move3(t_data *d)
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
	return (0);
}

static int	adv_move2(t_data *d)
{
	if (d->ball.dir == 1)
		do_dmg(d, 7, d->ball.posx + 1, d->ball.posy - 1);
	else if (d->ball.dir == 3)
		do_dmg(d, 5, d->ball.posx + 1, d->ball.posy + 1);
	else
		return (99);
	return (0);
}

static int	adv_move1(t_data *d)
{
	if (d->ball.dir == 0)
		do_dmg(d, 4, d->ball.posx, d->ball.posy - 1);
	else if (d->ball.dir == 1)
		do_dmg(d, 3, d->ball.posx + 1, d->ball.posy - 1);
	else if (d->ball.dir == 7)
		do_dmg(d, 5, d->ball.posx - 1, d->ball.posy - 1);
	else
		return (99);
	return (0);
}

int			adv_move(t_data *d, int side)
{
	if (side == 0)
		return (adv_move1(d));
	else if (side == 1 && d->ball.dir == 1)
	{
		do_dmg(d, 5, d->ball.posx, d->ball.posy - 1);
		do_dmg(d, 5, d->ball.posx, d->ball.posy - 1);
	}
	else if (side == 2)
		return (adv_move2(d));
	else if (side == 3 || side == 5)
		return (-1);
	else if (side == 4)
		return (adv_move3(d));
	else if (side == 6)
		return (adv_move4(d));
	else if (side == 7 && d->ball.dir == 7)
	{
		do_dmg(d, 3, d->ball.posx, d->ball.posy - 1);
		do_dmg(d, 3, d->ball.posx - 1, d->ball.posy - 1);
	}
	else
		return (99);
	return (0);
}
