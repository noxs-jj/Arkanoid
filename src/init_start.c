/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:41:29 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/01 23:32:55 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int	init_start(t_data **d, int ac, char **av)
{
	(void)ac;
	(void)av;
	if (ac < 2)
		return(error("init_start:: Require 2 args minimum"));
	*d = get_data();
	if (NULL == d)
		return (error("init_start:: t_data init is NULL, malloc failed"));
	if (open_log(*d) < 0)
		return (error("init_start:: Open_log error"));
	(*d)->level = 1;
	(*d)->fd_level = -1;
	(*d)->player_pos = 25;
	if (init_map(*d) < 0)
		return (error("init_start:: Init_map error"));
	return (0);
}
