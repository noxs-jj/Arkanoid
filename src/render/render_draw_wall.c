/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:00:29 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/01 23:00:30 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

void	render_draw_wall(t_data *d, int posx, int posy)
{
	glColor3ub(50, 50, 50);

	glBegin(GL_QUADS);
		glVertex2i(0, 0);
		glVertex2i(WIN_WIDHT, WIN_HEIGHT);
		glVertex2i(WIN_WIDHT, 0);
		glVertex2i(0, WIN_HEIGHT);
	glEnd();
}
