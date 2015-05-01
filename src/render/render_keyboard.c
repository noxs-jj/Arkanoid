/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:39:16 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/01 22:39:17 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

void	render_keyboard(GLFWwindow* window, int key, int scancode,
						int action, int mods)
{
	if ((key == GLFW_KEY_ESCAPE || GLFW_KEY_Q) && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		// PAUSE
	}
	else if ((key == GLFW_KEY_A || key == GLFW_KEY_LEFT)
		&& action == GLFW_PRESS)
	{
		// LEFT
	}
	else if ((key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
		&& action == GLFW_PRESS)
	{
		// RIGHT
	}
	(void)scancode;
	(void)mods;
}
