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
	float 	ratio;
	ratio = WIN_WIDHT / (float) WIN_HEIGHT;
	int width, height;
	glfwGetFramebufferSize(d->windows, &width, &height);
	glViewport(0, 0, WIN_WIDHT, WIN_HEIGHT);
	glClearColor(0.5f, 0.1f, 0.5f, 1);

	//glOrtho(0, 0, 0, 0, 0, 0);
	glLoadIdentity();
	while (d->run == 1)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glScalef(0.00155f, 0.00155f, 0.00155f);


		render_draw(d);

		glfwSwapBuffers(d->windows);
		glFlush();
		glfwPollEvents();
		glLoadIdentity();
	}
	render_close(d);
	return (0);
}