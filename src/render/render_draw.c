/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:39:03 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 00:22:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

void render_draw(t_data *d)
{
	int x;
	int y;
	int player;

	render_draw_wall(d, 0, 0);
	y = 0;
	player = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (d->map[y][x]->type == OBSTACLE)
				render_draw_case(d, 15, x * WIN_WIDHT, y * WIN_HEIGHT);
			else if (d->map[y][x]->type == SIMPLE)
				render_draw_case(d, 0, x * WIN_WIDHT, y * WIN_HEIGHT);
			else if (d->map[y][x]->type == SPEC)
				render_draw_case(d, d->map[y][x]->state, x * WIN_WIDHT, y * WIN_HEIGHT);
			else if (d->map[y][x]->type == PLAYER)
			{
				render_draw_player(d, x * WIN_WIDHT, y * WIN_HEIGHT);
				player++;
			}
			x++;
		}
		y++;
	}
}
