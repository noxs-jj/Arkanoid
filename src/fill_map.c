/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:27:24 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:47:57 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

static int	fill_map2(t_data *d, char *line, int x, int y)
{
	if (line[x] == WALL)
		d->map[y][x].type = WALL;
	else if (line[x] == SIMPLE)
	{
		d->map[y][x].type = SIMPLE;
		d->map[y][x].state = 1;
	}
	else if (line[x] == OBSTACLE)
		d->map[y][x].type = OBSTACLE;
	else if (line[x] >= '1' && line[x] <= '9')
	{
		d->map[y][x].type = SPEC;
		d->map[y][x].state = line[x] - '0';
	}
	else if (line[x] == EMPTY)
		d->map[y][x].type = EMPTY;
	else
		return (-1);
	if ((x == 0 || x == MAP_X -1 || y == 0 || y == MAP_Y - 1)
		&& line[x] != WALL)
		return (-1);
	return (x + 1);
}

int		fill_map(t_data *d)
{
	char	*line;
	int		x;
	int		y;

	if (get_level_file(d) < 0)
		return (-1);
	y = 0;
	line = NULL;
	while (y < MAP_Y)
	{
		x = 0;
		d->map[y][x].state = 0;
		if (get_next_line(d->fd_level, &line) < 0)
			return (-1);
		while (x < MAP_X)
		{
			if ((x = fill_map2(d, line, x, y)) < 0)
				return (-1);	
		}
		if (line [x] != '\0')
			return (-1);
		ft_memdel((void **)&line);
		y++;
	}
	return (0);
}