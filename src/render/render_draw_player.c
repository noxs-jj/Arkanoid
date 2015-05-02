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
		glVertex2i(posx, posy);
		glVertex2i(posx + (BLOCK_WIDTH * 3), posy);
		glVertex2i(posx + (BLOCK_WIDTH * 3), posy + BLOCK_HEIGHT);
		glVertex2i(posx, posy + BLOCK_HEIGHT);
	glEnd();
	(void)d;
}
