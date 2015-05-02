/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:59:53 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 16:05:57 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>

void	render_draw_case(t_data *d, int type, int posx, int posy)
{
	if (type == 0)
		glColor3ub(50, 50, 50);
	else if (type == 1)
		glColor3ub(255, 0, 0);
	else if (type == 2)
		glColor3ub(0, 255, 0);
	else if (type == 3)
		glColor3ub(0, 0, 255);
	else if (type == 4)
		glColor3ub(100, 0, 0);
	else if (type == 5)
		glColor3ub(0, 100, 0);
	else if (type == 15)
		glColor3ub(0, 255, 255);
	else if (type == 99)
		glColor3ub(80, 71, 22);
	else
		glColor3ub(150, 150, 150);
	glBegin(GL_QUADS);
		glVertex2f(posx - (WIN_WIDHT / 2), posy - (WIN_HEIGHT / 2)); // bas gauche
		glVertex2f(posx - (WIN_WIDHT / 2), posy + BLOCK_HEIGHT - (WIN_HEIGHT / 2)); // haut gauche
		glVertex2f(posx + BLOCK_WIDTH - (WIN_WIDHT / 2), posy + BLOCK_HEIGHT - (WIN_HEIGHT / 2)); // haut droite
		glVertex2f(posx + BLOCK_WIDTH - (WIN_WIDHT / 2), posy - (WIN_HEIGHT / 2)); // bas droite
	glEnd();
	(void)d;
}
