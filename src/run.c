/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 00:19:28 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 00:33:25 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int run_the_game(t_data *d)
{
	while (d->run == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		render_draw(d);
		glfwSwapBuffers(d->window);
		glLoadIdentity();
		glfwPollEvents();
	}
	render_close(d);
	return (0);
}