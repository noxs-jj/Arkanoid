/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 23:00:00 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/01 23:00:01 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>

void	render_draw_player(t_data *d, int posx, int posy)
{
	glColor3ub(255, 255, 0);

	glBegin(GL_QUADS);
		glVertex2f(posx - (WIN_WIDHT / 2), posy - (WIN_HEIGHT / 2)); // bas gauche
		glVertex2f(posx - (WIN_WIDHT / 2), posy + BLOCK_HEIGHT - (WIN_HEIGHT / 2)); // haut gauche
		glVertex2f(posx + (BLOCK_WIDTH * 3) - (WIN_WIDHT / 2), posy + BLOCK_HEIGHT - (WIN_HEIGHT / 2)); // haut droite
		glVertex2f(posx + (BLOCK_WIDTH * 3) - (WIN_WIDHT / 2), posy - (WIN_HEIGHT / 2)); // bas droite
	glEnd();
	(void)d;
}
