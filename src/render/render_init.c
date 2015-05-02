/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:38:56 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 00:21:52 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>

void	framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
	(void)window;
}

int		render_init(t_data *d)
{
	int	width;
	int	height;

	if (!glfwInit())
	{
		w_log("render_init:: glfwInit error");
		return (-1);
	}
	d->windows = glfwCreateWindow(WIN_WIDHT, WIN_HEIGHT,
				"Arkanoid jmoiroux & vjacquie", NULL, NULL);
	if (!d->windows)
	{
		w_log("render_init:: glfwCreateWindow error");
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(d->windows);
	glfwSwapInterval(1);
	glfwSetKeyCallback(d->windows, render_keyboard);
	glfwGetFramebufferSize(d->windows, &width, &height);
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(d->windows, framebuffer_size_callback);
	glClearColor(0.1f, 0.1f, 0.1f, 1);
	glLoadIdentity();
	return (0);
}
