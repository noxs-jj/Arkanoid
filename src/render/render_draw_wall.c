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

#include <projet.h>

void	render_draw_wall(t_data *d)
{
	glColor3ub(10, 10, 10);

	glBegin(GL_QUADS);

		// glVertex2f(-0.9f, 0.9f); // haut gauche
		// glVertex2f(-0.9f, -0.9f); //bas gauche
		// glVertex2f(0.9f, -0.9f); // bas droite
		// glVertex2f(0.9f, 0.9f); // haut droite

		glVertex2f(-0.98f, -0.98f); // bas gauche
		glVertex2f(-0.98f, 0.98f); // haut gauche
		glVertex2f(0.98f, 0.98f); // haut droite
		glVertex2f(0.98f, -0.98f); // bas droite

		glVertex2f(0 - (WIN_WIDHT / 2), 0 - (WIN_HEIGHT / 2)); // bas gauche
		glVertex2f(0 - (WIN_WIDHT / 2), WIN_HEIGHT - (WIN_HEIGHT / 2)); // haut gauche
		glVertex2f(WIN_WIDHT - (WIN_WIDHT / 2), WIN_HEIGHT - (WIN_HEIGHT / 2)); // haut droite
		glVertex2f(WIN_WIDHT - (WIN_WIDHT / 2), 0 - (WIN_HEIGHT / 2)); // bas droite
		
		
	glEnd();
	(void)d;
}
