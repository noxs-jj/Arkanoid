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

int	render_init(t_data *d)
{
	if (!glfwInit())
	{
		w_log("render_init:: glfwInit error");
		return (-1);
	}
	d->windows = glfwCreateWindow(WIN_WIDHT, WIN_HEIGHT,
				"Arkanoid jmoiroux & vjacquie",
				NULL, NULL);
	if (!d->windows)
	{
		w_log("render_init:: glfwCreateWindow error");
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(d->windows);
	glfwSwapInterval(1);
	glfwSetKeyCallback(d->windows, render_keyboard);
	return (0);
}
