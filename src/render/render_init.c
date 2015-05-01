/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:38:56 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/01 22:38:57 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

int	render_init(t_data *d)
{
	if (!glfwInit())
	{
		w_log("render_init:: glfwInit error");
		return (-1);
	}
	d->window = glfwCreateWindow(WIN_WIDHT, WIN_HEIGHT,
				"Arkanoid jmoiroux & vjacquie",
				NULL, NULL);
	if (!d->window)
	{
		w_log("render_init:: glfwCreateWindow error");
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(d->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(d->window, key_callback);
	return (0);
}
