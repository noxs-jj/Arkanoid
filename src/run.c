/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 00:19:28 by vjacquie          #+#    #+#             */
/*   Updated: 2015/05/02 16:01:39 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/projet.h"

int run_the_game(t_data *d)
{
	while (d->run == 1)
	{
		if (d->pause == 0)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glScalef(0.001550f, 0.00350f, 0.001550f);

			game(d);
			render_draw(d);

			glfwSwapBuffers(d->windows);
			glFlush();
			usleep(100000);
		}
		else {
			usleep(100000);
		}

		glfwPollEvents();
		glLoadIdentity();
	}
	render_close(d);
	return (0);
}