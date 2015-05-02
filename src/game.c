/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:31:06 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 18:52:08 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"



int		adv_move(t_data *d, int side)
{
	if (side == 0)
	{
		if (d->ball.dir == 0)
			d->ball.dir = 4;
		else if (d->ball.dir == 1)
			d->ball.dir = 3;
		else if (d->ball.dir == 7)
			d->ball.dir = 5;
		else
			return (99);
	}
	else if (side == 1 && d->ball.dir == 1)
		d->ball.dir = 5;
	else if (side == 2)
	{
		if (d->ball.dir == 1)
			d->ball.dir = 7;
		else if (d->ball.dir == 3)
			d->ball.dir = 5;
		else
			return (99);
	}
	else if (side == 3 || side == 5)
		return (-1);
	else if (side == 4) // Player
	{
		if (d->map[d->ball.posy + 1][d->ball.posx].type != PLAYER)
			return (-1); // loose
		if (d->ball.dir == 5)
			d->ball.dir = 7;
		else if (d->ball.dir == 4)
			d->ball.dir = 0;
		else if (d->ball.dir == 3)
			d->ball.dir = 1;
		else
			return (99);
	}
	else if (side == 6)
	{
		if (d->ball.dir == 5)
			d->ball.dir = 3;
		else if (d->ball.dir == 7)
			d->ball.dir = 1;
		else
			return (99);
	}
	else if (side == 7 && d->ball.dir == 7)
		d->ball.dir = 3;
	else
		return (99);
	return (0);
}

void	basic_move(t_data *d)
{
	if (d->ball.dir == 0) // UP
	
		d->ball.posy--;
	else if (d->ball.dir == 1) // UP - RIGHT
	{
		d->ball.posy--;
		d->ball.posx++;
	}
	else if (d->ball.dir == 3) // DOWN - RIGHT
	{
		d->ball.posy++;
		d->ball.posx++;
	}
	else if (d->ball.dir == 4) // DOWN
		d->ball.posy++;
	else if (d->ball.dir == 5) // DOWN - LEFT
	{
		d->ball.posy++;
		d->ball.posx--;
	}
	else if (d->ball.dir == 7) // UP - LEFT
	{
		d->ball.posy--;
		d->ball.posx--;
	}
}


int		collide(t_data *d)
{
	int side;

	side = -1;
	if (d->map[d->ball.posy][d->ball.posx + 1].type != EMPTY
		&& d->map[d->ball.posy + 1][d->ball.posx].type != EMPTY)
		side = 3;
	else if (d->map[d->ball.posy + 1][d->ball.posx].type != EMPTY
		&& d->map[d->ball.posy][d->ball.posx - 1].type != EMPTY)
		side = 5;
	else if (d->map[d->ball.posy - 1][d->ball.posx].type != EMPTY
		&& d->map[d->ball.posy][d->ball.posx + 1].type != EMPTY)
		side = 1;
	else if (d->map[d->ball.posy][d->ball.posx - 1].type != EMPTY
		&& d->map[d->ball.posy - 1][d->ball.posx].type != EMPTY)
		side = 7;
	else if (d->map[d->ball.posy][d->ball.posx + 1].type != EMPTY)
		side = 2;
	else if (d->map[d->ball.posy][d->ball.posx - 1].type != EMPTY)
		side = 6;
	else if (d->map[d->ball.posy + 1][d->ball.posx].type != EMPTY)
		side = 4;
	else if (d->map[d->ball.posy - 1][d->ball.posx].type != EMPTY)
		side = 0;
	return (side);
}

void		game(t_data *d)
{
	int side;
	int ret;

	ret = 0;
	side = collide(d);
	if (side >= 0)
		ret = adv_move(d, side);
	if (ret == 99 || side < 0)
		basic_move(d);
	if (ret < 0)
		d->run = 0;
}









// int		game(t_data *d)
// {
// 	if (d->ball.dir == 0) // UP
// 	{
// 		if (d->map[d->ball.posy - 1][d->ball.posx].type == EMPTY)
// 			d->ball.posy--;
// 		else if ((d->map[d->ball.posy - 1][d->ball.posx].type == WALL)
// 			|| (d->map[d->ball.posy - 1][d->ball.posx].type == OBSTACLE))
// 			d->ball.dir = 4;
// 		else
// 		{
// 			d->ball.dir = 4;
// 			d->map[d->ball.posy - 1][d->ball.posx].state--;
// 			if (d->map[d->ball.posy - 1][d->ball.posx].state == 0)	// add score here
// 				d->map[d->ball.posy - 1][d->ball.posx].type = EMPTY;
// 		}
// 	}
// 	else if (d->ball.dir == 1) // UP - RIGHT
// 	{
// 		if (d->map[d->ball.posy - 1][d->ball.posx + 1].type == EMPTY)
// 		{
// 			d->ball.posy--;
// 			d->ball.posx--;
// 		}
// 		else if ((d->map[d->ball.posy - 1][d->ball.posx + 1].type == WALL)
// 			|| (d->map[d->ball.posy - 1][d->ball.posx + 1].type == OBSTACLE))
// 			//d->ball.dir = 3;
// 		else
// 		{
// 			d->ball.dir = 3;
// 			d->map[d->ball.posy - 1][d->ball.posx + 1].state--;
// 			if (d->map[d->ball.posy - 1][d->ball.posx + 1].state == 0)	// add score here
// 				d->map[d->ball.posy - 1][d->ball.posx + 1].type = EMPTY;
// 		}
// 	}
// 	else if (d->ball.dir == 3) // DOWN - RIGHT
// 	{
// 		if (d->map[d->ball.posy + 1][d->ball.posx + 1].type == EMPTY)
// 			d->ball.posy++;
// 		else if (d->map[d->ball.posy + 1][d->ball.posx + 1].type == PLAYER)
// 		{
// 			if (d->ball.posx == d->player_pos)
// 				d->ball.dir = 0;
// 			else if (d->ball.posx < d->player_pos)
// 				d->ball.dir = 7;
// 			else if (d->ball.posx > d->player_pos)
// 				d->ball.dir = 1;
// 		}
// 		else if (d->map[d->ball.posy + 1][d->ball.posx + 1].type == WALL)
// 			d->ball.dir = -1;
// 	}
// 	else if (d->ball.dir == 4) // DOWN
// 	{
// 		if (d->map[d->ball.posy + 1][d->ball.posx].type == EMPTY)
// 			d->ball.posy++;
// 		else if (d->map[d->ball.posy + 1][d->ball.posx].type == PLAYER)
// 		{
// 			if (d->ball.posx == d->player_pos)
// 				d->ball.dir = 0;
// 			else if (d->ball.posx < d->player_pos)
// 				d->ball.dir = 7;
// 			else if (d->ball.posx > d->player_pos)
// 				d->ball.dir = 1;
// 		}
// 		else if (d->map[d->ball.posy + 1][d->ball.posx].type == WALL)
// 			d->ball.dir = -1;
// 	}
// 	else if (d->ball.dir == 5) // DOWN - LEFT
// 	{
// 		if (d->map[d->ball.posy + 1][d->ball.posx - 1].type == EMPTY)
// 			d->ball.posy++;
// 		else if (d->map[d->ball.posy + 1][d->ball.posx - 1].type == PLAYER)
// 		{
// 			if (d->ball.posx == d->player_pos)
// 				d->ball.dir = 0;
// 			else if (d->ball.posx < d->player_pos)
// 				d->ball.dir = 7;
// 			else if (d->ball.posx > d->player_pos)
// 				d->ball.dir = 1;
// 		}
// 		else if (d->map[d->ball.posy + 1][d->ball.posx - 1].type == WALL)
// 			d->ball.dir = -1;
// 	}
// 	else if (d->ball.dir == 7) // UP - LEFT
// 	{
// 		if (d->map[d->ball.posy - 1][d->ball.posx - 1].type == EMPTY)
// 		{
// 			d->ball.posy--;
// 			d->ball.posx--;
// 		}
// 		else if ((d->map[d->ball.posy - 1][d->ball.posx - 1].type == WALL)
// 			|| (d->map[d->ball.posy - 1][d->ball.posx - 1].type == OBSTACLE))
// 			d->ball.dir = 3;
// 		else
// 		{
// 			d->ball.dir = 3;
// 			d->map[d->ball.posy - 1][d->ball.posx - 1].state--;
// 			if (d->map[d->ball.posy - 1][d->ball.posx - 1].state == 0)	// add score here
// 				d->map[d->ball.posy - 1][d->ball.posx - 1].type = EMPTY;
// 		}
// 	}
// 	return (0);
// }
