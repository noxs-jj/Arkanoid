/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:39:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 15:27:11 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>

void	render_keyboard(GLFWwindow* window, int key, int scancode,
						int action, int mods)
{
	static t_data	*d = NULL;

	if (d == NULL)
		d = get_data();
	if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		d->run = 0;
	}
	else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		// PAUSE
	}
	else if ((key == GLFW_KEY_A || key == GLFW_KEY_LEFT)
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		move(d, LEFT);
	}
	else if ((key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
	{
		move(d, RIGHT);
	}
	(void)scancode;
	(void)mods;
}
