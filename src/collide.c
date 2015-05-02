/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 20:50:54 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 22:05:14 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

static int	collide2(t_data *d, int ret)
{
	if (ret == 99 && d->map[d->ball.posy][d->ball.posx - 1].type != EMPTY
		&& d->map[d->ball.posy - 1][d->ball.posx].type != EMPTY)
		ret = adv_move(d, 7);
	if (ret == 99 && d->map[d->ball.posy][d->ball.posx + 1].type != EMPTY)
		ret = adv_move(d, 2);
	if (ret == 99 && d->map[d->ball.posy][d->ball.posx - 1].type != EMPTY)
		ret = adv_move(d, 6);
	if (ret == 99 && d->map[d->ball.posy + 1][d->ball.posx].type != EMPTY)
		ret = adv_move(d, 4);
	if (ret == 99 && d->map[d->ball.posy - 1][d->ball.posx].type != EMPTY)
		ret = adv_move(d, 0);
	return (ret);
}

int			collide(t_data *d)
{
	int		ret;

	ret = 99;
	if (d->map[d->ball.posy][d->ball.posx + 1].type != EMPTY
		&& d->map[d->ball.posy + 1][d->ball.posx].type != EMPTY
		&& d->ball.dir == 3)
		ret = adv_move(d, 3);
	if (d->map[d->ball.posy + 1][d->ball.posx].type != EMPTY
		&& d->map[d->ball.posy][d->ball.posx - 1].type != EMPTY
		&& d->ball.dir == 5)
		ret = adv_move(d, 5);
	if (d->map[d->ball.posy - 1][d->ball.posx].type != EMPTY
		&& d->map[d->ball.posy][d->ball.posx + 1].type != EMPTY)
		ret = adv_move(d, 1);
	if (ret == 99)
		ret = collide2(d, ret);
	if (ret == 99)
		return (99);
	return (ret);
}
