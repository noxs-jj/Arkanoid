/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:59:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/01 22:59:54 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

void	render_draw_case(t_data *d, int life, int posx, int posy)
{
	if (type == 0)
		glColor3ub(137, 0, 237);
	else if (type == 2)
		glColor3ub(137, 30, 237);
	else if (type == 3)
		glColor3ub(137, 60, 237);
	else if (type == 4)
		glColor3ub(137, 90, 237);
	else if (type == 5)
		glColor3ub(137, 120, 237);
	else if (type == 6)
		glColor3ub(137, 150, 237);
	else if (type == 15)
		glColor3ub(0, 255, 255);
	else
		glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
		glVertex2i(posx, posy);
		glVertex2i(posx + BLOCK_WIDTH, posy);
		glVertex2i(posx + BLOCK_WIDTH, posy + BLOCK_HEIGHT);
		glVertex2i(posx, posy + BLOCK_HEIGHT);
	glEnd();
}
