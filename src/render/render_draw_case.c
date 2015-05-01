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
	if (type == 1)
		glColor3ub(137, 20, 237);
	else if (type == 2)
		glColor3ub(137, 50, 237);
	else if (type == 3)
		glColor3ub(137, 80, 237);
	else if (type == 4)
		glColor3ub(137, 110, 237);
	else if (type == 5)
		glColor3ub(137, 140, 237);
	else if (type == 10)
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
